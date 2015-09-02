/**
 * Project      One camera range meter
 * Date         28.11.2012
 * File         CVideoCapturingThread.cpp
 * About        A class to wrap asyncronous access to camera
 */

///----------------------------------------------------------------------------
///                             Includes
///----------------------------------------------------------------------------

#include "CHostWidget.hpp"
#include "CVideoCapturer.hpp"
#include "CVideoCapturingThread.hpp"

///----------------------------------------------------------------------------
///                              Usings
///----------------------------------------------------------------------------

using namespace NOCRM;

///----------------------------------------------------------------------------
///                   CVideoCapturingThread definition
///----------------------------------------------------------------------------

///----------------------------------------------------------------------------
CVideoCapturingThread::CVideoCapturingThread(CHostWidget *signalReceiver)
: QThread( 0 )
, mIsProcessing( false )
, mSignalReceiver( signalReceiver )
, mVideoCapturer( 0 )
///----------------------------------------------------------------------------
{
    connect( this, SIGNAL(startCapturing()),
             this, SLOT(capturingProcess()), Qt::QueuedConnection );

    connect( this,            SIGNAL(capturingNotification(CVideoCaptureData)),
             mSignalReceiver, SLOT(videoUpdate(CVideoCaptureData)) );
}

///----------------------------------------------------------------------------
CVideoCapturingThread::~CVideoCapturingThread( )
///----------------------------------------------------------------------------
{
    mVideoCapturer = 0;
}

///----------------------------------------------------------------------------
void CVideoCapturingThread::run( )
///----------------------------------------------------------------------------
{
    mVideoCapturer = new CVideoCapturer;

    exec( );

    delete mVideoCapturer;
    mVideoCapturer = 0;
}

///----------------------------------------------------------------------------
void CVideoCapturingThread::capturingContol( bool doStart )
///----------------------------------------------------------------------------
{
    if ( true == doStart && false == mIsProcessing )
    {
        mIsProcessing = true;
        emit startCapturing( );
    }
    else if ( true == doStart && true == mIsProcessing )
    {
        Q_ASSERT_X( false, "video capturing process", "process is already started" );
    }
    else
    {
        mIsProcessing = false;
    }
}

///----------------------------------------------------------------------------
void CVideoCapturingThread::capturingProcess( )
///----------------------------------------------------------------------------
{
    if ( true == mIsProcessing )
    {
        QImage *image = new QImage;
        NErrorHandling::EErrorCode errorCode = mVideoCapturer->getImage(*image);
        if ( NErrorHandling::EErrorCode_OK != errorCode )
        {
            delete image;
            image = 0;
        }

        CVideoCaptureData captureData( image, errorCode );
        emit capturingNotification( captureData );

        /// no capturing will continue, if errors occured
        if ( NErrorHandling::EErrorCode_OK != errorCode )
        {
            mIsProcessing = false;

        }
        else
        {
            emit startCapturing( );
        }
    }
}
