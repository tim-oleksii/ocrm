/**
 * Project      One camera range meter
 * Date         13.11.2012
 * File         CHostWidget.hpp
 * About        An implementation of the host widget.
 */

///----------------------------------------------------------------------------
///                             Includes
///----------------------------------------------------------------------------

/// QT
#include <QFile>
#include <QMessageBox>
#include <QFileDialog>

/// OCRM
#include "CHostWidget.hpp"
#include "ui_CHostWidget.h"
#include "CVideoCapturer.hpp"
#include "NErrorHandling.hpp"
#include "CRangeMeterConfig.hpp"
#include "CBlankImageCreator.hpp"

///----------------------------------------------------------------------------
///                               Defines
///----------------------------------------------------------------------------
#define __DEBUG_OCRM__ /// include some debugging data

///----------------------------------------------------------------------------
///                               Usings
///----------------------------------------------------------------------------

using namespace NOCRM;

///----------------------------------------------------------------------------
///                           Static declarations
///----------------------------------------------------------------------------

/**
 * @brief check whether range meter config has all fields filled.
 * @return reus if it was successful.
 */
static bool isValidRangeMeterConfig( CRangeMeterConfig &config );

///----------------------------------------------------------------------------
///                          CHostWidget definition
///----------------------------------------------------------------------------

///----------------------------------------------------------------------------
CHostWidget::CHostWidget( QWidget *parent )
: QWidget( parent )
, ui( new Ui::CHostWidget )
, mVideoThread( this )
, mImageProcThread( this )
, mImages( 0 )
, mSample( 0 )
, mTempImage( 0 )
///----------------------------------------------------------------------------
{
    ui->setupUi( this );

    mVideoThread.moveToThread( &mVideoThread );
    mImageProcThread.moveToThread( &mImageProcThread );

    /// hide all widgets so form will be compact on look
    ui->mFeaturesBox->hide( );
    ui->mGraphicsLabel->hide( );

    connect( ui->mVideoButton,          SIGNAL(toggled(bool)),  this, SLOT(adjustWidgetSize())      );
    connect( ui->mVideoButton,          SIGNAL(toggled(bool)),  this, SLOT(captureVideo(bool))      );
    connect( ui->mCapturePhotoButton,   SIGNAL(clicked()),      this, SLOT(takePhoto())             );
    connect( ui->mFeaturesBox,          SIGNAL(toggled(bool)),  this, SLOT(adjustWidgetSize())      );
    connect( ui->mGetDistanceButton,    SIGNAL(clicked()),      this, SLOT(invokeImageProcessing()) );
    connect( ui->mLoadSampleButton,     SIGNAL(clicked()),      this, SLOT(loadImageSample())       );

    connect( ui->mHorAngleSpinBox,      SIGNAL(valueChanged(int)), this, SLOT(setHorAngle(int))      );
    connect( ui->mVertAngleSpinBox,     SIGNAL(valueChanged(int)), this, SLOT(setVertAngle(int))     );
    connect( ui->mShiftDistanceSpinBox, SIGNAL(valueChanged(int)), this, SLOT(setShiftDistance(int)) );

    connect( this, SIGNAL(startVideoCapturing(bool)), &mVideoThread,     SLOT(capturingContol(bool)) );
    connect( this, SIGNAL(beginImageProcessing()),    &mImageProcThread, SLOT(imageProcessing())     );

    QImage cameraFrame;
    CVideoCapturer videoCapturer;

    if ( NErrorHandling::EErrorCode_OK == videoCapturer.getImage(cameraFrame) )
    {
        ui->mGraphicsLabel->setFixedSize( cameraFrame.width(), cameraFrame.height() );
    }

    /// TODO:
    /// 1. resizing problem should be fixed. (toggle feature, than toggle again, no size decrement).
    /// 2. A window should have minimum size to show a title "One camera range meter".
    /// 3. blank space between video label and controls.

    adjustWidgetSize( );
    setWindowFlags( Qt::Dialog );
    setWindowTitle( "One camera range meter" );
}

///----------------------------------------------------------------------------
void CHostWidget::adjustWidgetSize( )
///----------------------------------------------------------------------------
{
    adjustSize( );
}

///----------------------------------------------------------------------------
CHostWidget::~CHostWidget( )
///----------------------------------------------------------------------------
{
    for ( int i = 0; i < mImages.size(); ++i )
    {
        delete mImages[ i ];
    }

    delete mSample;

    delete ui;
}

///----------------------------------------------------------------------------
void CHostWidget::captureVideo( bool isEnabled )
///----------------------------------------------------------------------------
{
    if ( true  == isEnabled )
    {
        mVideoThread.start( );
        emit startVideoCapturing( isEnabled );
    }
    else if ( false == isEnabled )
    {
        emit startVideoCapturing( isEnabled );
        mVideoThread.quit( );
        mVideoThread.wait( );
    }

    ui->mCapturePhotoButton->setEnabled( isEnabled );
}

///----------------------------------------------------------------------------
void CHostWidget::videoUpdate( CVideoCaptureData videoData )
///----------------------------------------------------------------------------
{
    if ( 0 != videoData.getImage() )
    {
        QPixmap pixMap = QPixmap::fromImage( *videoData.getImage() );
        ui->mGraphicsLabel->setPixmap( pixMap );
    }
    else
    {
        CBlankImageCreator emptyImage( ui->mGraphicsLabel->width(), ui->mGraphicsLabel->height() );
        ui->mGraphicsLabel->setPixmap( emptyImage.getPixmap() );
        ui->mVideoButton->setChecked( false );
        emit startVideoCapturing( false );
        ui->mCapturePhotoButton->setEnabled( false );
        raiseError( videoData.getErrorCode() );
    }

    if ( false == mImages.contains(mTempImage) )
    {
        delete mTempImage;
    }

    mTempImage = videoData.getImage( );
}

///----------------------------------------------------------------------------
void CHostWidget::raiseError( NErrorHandling::EErrorCode errorCode )
///----------------------------------------------------------------------------
{
    Q_ASSERT( NErrorHandling::EErrorCode_OK != errorCode );

    QString errorMessage = NErrorHandling::toString( errorCode );
    QMessageBox::critical( this, "Error", errorMessage);
}


///----------------------------------------------------------------------------
void CHostWidget::closeEvent( QCloseEvent *event )
///----------------------------------------------------------------------------
{
    if ( mVideoThread.isRunning() )
    {
        mVideoThread.quit( );
        mVideoThread.wait( );
    }

    if ( mImageProcThread.isRunning() )
    {
        mImageProcThread.quit( );
        mImageProcThread.wait( );
    }

    QWidget::closeEvent( event );
}

///----------------------------------------------------------------------------
void CHostWidget::setHorAngle( int horAngle )
///----------------------------------------------------------------------------
{
    CRangeMeterConfig &rangeMeterConfig = CRangeMeterConfig::create();
    rangeMeterConfig.setHorizontalAngle( horAngle );

    ui->mGetDistanceButton->setEnabled( isReadyToCalculate() );
}

///----------------------------------------------------------------------------
void CHostWidget::setVertAngle( int vertAngle )
///----------------------------------------------------------------------------
{
    CRangeMeterConfig &rangeMeterConfig = CRangeMeterConfig::create();
    rangeMeterConfig.setVerticalAngle( vertAngle );

    ui->mGetDistanceButton->setEnabled( isReadyToCalculate() );
}

///----------------------------------------------------------------------------
void CHostWidget::setShiftDistance( int shiftDistance )
///----------------------------------------------------------------------------
{
    CRangeMeterConfig &rangeMeterConfig = CRangeMeterConfig::create();
    rangeMeterConfig.setShiftDistance( shiftDistance );

    ui->mGetDistanceButton->setEnabled( isReadyToCalculate() );
}

///----------------------------------------------------------------------------
bool CHostWidget::isReadyToCalculate( )
///----------------------------------------------------------------------------
{
    CRangeMeterConfig &rangeMeterConfig = CRangeMeterConfig::create();

    return  mSample                                     &&
            mImages.size( ) == mcsMaxImages             &&
            isValidRangeMeterConfig( rangeMeterConfig );
}

///----------------------------------------------------------------------------
void CHostWidget::takePhoto( )
///----------------------------------------------------------------------------
{
    if ( 0 != mTempImage )
    {
        if ( mcsMaxImages == mImages.size() )
        {
            delete mImages[ 0 ];
            mImages.erase( mImages.begin() );
        }

        mImages.push_back( mTempImage );

        #ifdef __DEBUG_OCRM__
        /// need to save captured pics for debug
        if ( mcsMaxImages == mImages.size() )
        {
            for ( int i = 0; i < mImages.size(); ++i )
            {
                mImages[i]->save( QString("image_%1.png").arg(i) );
            }
        }
        #endif
    }

    ui->mGetDistanceButton->setEnabled( isReadyToCalculate() );
}

///----------------------------------------------------------------------------
void CHostWidget::invokeImageProcessing( )
///----------------------------------------------------------------------------
{
    if ( !mImageProcThread.isProcessing() )
    {
        mImageProcThread.setImagesToProcess( mImages );
        mImageProcThread.start( );
        emit beginImageProcessing( );
        ui->mGetDistanceButton->setEnabled( false );
    }
    else
    {
        QMessageBox::warning( this, "Warning", "Image processing is not finished. Please wait before start another one");
    }
}

///----------------------------------------------------------------------------
void CHostWidget::processingResults( CImageProcessingResult result )
///----------------------------------------------------------------------------
{
    ui->mGetDistanceButton->setEnabled( true );

    using namespace NErrorHandling;
    if ( EErrorCode_OK == result.getErrorCode() && -1 < result.getDistance() )
    {
        QString messagePrefix = QString( "The distance is: %1" ).arg( result.getDistance() );
        QMessageBox::information( this, "Distance", messagePrefix );
    }
    else
    {
        QMessageBox::critical( this, "Error", toString(result.getErrorCode()) );
    }
}

///----------------------------------------------------------------------------
void CHostWidget::loadImageSample( )
///----------------------------------------------------------------------------
{
    QString fileName = QFileDialog::getOpenFileName( this, "Load sample image", QString(), "Images (*.jpg *png)" );
    if ( false == fileName.isEmpty() )
    {
        mSample = new QImage( fileName );
        ui->mGetDistanceButton->setEnabled( isReadyToCalculate() );
    }
}

///----------------------------------------------------------------------------
///                           Static definition
///----------------------------------------------------------------------------

///----------------------------------------------------------------------------
bool isValidRangeMeterConfig( CRangeMeterConfig &config )
///----------------------------------------------------------------------------
{
    return  config.getHorizontalAngle() > 0 &&
            config.getVerticalAngle()   > 0 &&
            config.getShiftDistance()   > 0;
}

