/**
 * Project      One camera range meter
 * Date         27.11.2012
 * File         CVideoCapturingThread.hpp
 * About        A class to wrap asyncronous access to camera
 */

#ifndef CVIDEOCAPTURINGTHREAD_HPP
#define CVIDEOCAPTURINGTHREAD_HPP

///----------------------------------------------------------------------------
///                             Includes
///----------------------------------------------------------------------------

/// QT
#include <QThread>

/// OCRM
#include "CVideoCaptureData.hpp"

namespace NOCRM
{

///----------------------------------------------------------------------------
///                        Forward declaration
///----------------------------------------------------------------------------

class CHostWidget;
class CVideoCapturer;

///----------------------------------------------------------------------------
///                    CVideoCapturingThread declaration
///----------------------------------------------------------------------------

/**
 * @class CVideoCapturingThread "CVideoCapturingThread.hpp"
 */
class CVideoCapturingThread : public QThread
{
    Q_OBJECT
public:
    explicit CVideoCapturingThread(CHostWidget *signalReceiver);

    ~CVideoCapturingThread( );

    /**
     * @brief The method that is executed in another thread context.
     */
    virtual void run();
signals:

    void startCapturing( );
    void capturingNotification( CVideoCaptureData );

public slots:

    /**
     * @brief a slot to start or stop capturing process.
     */
    void capturingContol( bool );

private slots:

    /**
     * @brief a slot to start or stop capturing process.
     */
    void capturingProcess( );

private:
    bool            mIsProcessing;
    CHostWidget    *mSignalReceiver;
    CVideoCapturer *mVideoCapturer;
};

}

#endif /// CVIDEOCAPTURINGTHREAD_HPP
