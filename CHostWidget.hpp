/**
 * Project      One camera range meter
 * Date         06.11.2012
 * File         CHostWidget.hpp
 * About        The main GUI unit that holds all the widgets.
 *              @see CHostWidget.ui for a content.
 */

#ifndef CHOSTWIDGET_HPP
#define CHOSTWIDGET_HPP

///----------------------------------------------------------------------------
///                             Includes
///----------------------------------------------------------------------------

/// QT
#include <QWidget>
#include <QVector>

/// OCRM
#include "NErrorHandling.hpp"

#include "CVideoCaptureData.hpp"            /// video capturing
#include "CVideoCapturingThread.hpp"

#include "CImageProcessingThread.hpp"       /// image processing
#include "CImageProcessingResult.hpp"

///----------------------------------------------------------------------------
///                             UI declaration
///----------------------------------------------------------------------------

namespace Ui
{
    class CHostWidget;
}

///----------------------------------------------------------------------------
///                       CHostWidget declaration
///----------------------------------------------------------------------------

namespace NOCRM
{

/**
 * @class CHostWidget "CHostWidget.hpp"
 */
class CHostWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CHostWidget(QWidget *parent = 0);
    ~CHostWidget();

    /** @var mcsMaxImages Max container size */
    static const int        mcsMaxImages = 2;

signals:

    /**
     * @brief A signal to start caprturing video frames
     */
    void startVideoCapturing( bool );

    /**
     * @brief event which starts image processing.
     */
    void beginImageProcessing( );

public slots:

    /**
     * @brief The slot is called when one more frame is captured.
     * This method is responsible for data deallocation.
     */
    void videoUpdate( CVideoCaptureData );

    /**
     * @brief Invoked when image processing is done by a corresponding thread.
     */
    void processingResults( CImageProcessingResult );

protected:

    /**
     * @brief reimplementing QWidget::closeEvent()
     * the idea is to wait for video capturing thread to be finished.
     */
    void closeEvent( QCloseEvent *event );

private slots:

    /**
     * @brief A slot to control widget size, when something goes hidden.
     */
    void adjustWidgetSize( );

    /**
     * @brief A slot to control video capture
     */
    void captureVideo( bool isEnabled );

    /**
     * @brief set horizontal angle for configuration singleton.
     */
    void setHorAngle( int horAngle );

    /**
     * @brief set vertical angle for configuration singleton.
     */
    void setVertAngle( int vertAngle );

    /**
     * @brief set shift distance for configuration singleton.
     */
    void setShiftDistance( int shiftDistance );

    /**
     * @brief take photo
     */
    void takePhoto( );

    /**
     * @brief start image processin thread
     */
    void invokeImageProcessing( );

    /**
     * @brief load image sample.
     */
    void loadImageSample( );

private:

    void raiseError( NErrorHandling::EErrorCode errorCode );

    /**
     * @brief check whether everything is ready for distance calculation.
     * @return true on success.
     */
    bool isReadyToCalculate( );

    /** @var ui GUI for the application */
    Ui::CHostWidget        *ui;

    /** @var mVideoThread A thread to capture video frames */
    CVideoCapturingThread   mVideoThread;

    /** @var mImageProcThread A thread to do image processing */
    CImageProcessingThread  mImageProcThread;

    /** @var mImages A container to hold image references */
    QVector< QImage* >      mImages;

    /** @var mSample An object to find in an image */
    QImage                  *mSample;

    QImage                  *mTempImage;
};

}
#endif /// CHOSTWIDGET_HPP
