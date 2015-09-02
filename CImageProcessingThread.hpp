/**
 * Project      One camera range meter
 * Date         03.01.2013
 * File         CImageProcessingThread.hpp
 * About        A class to implement image processing logic.
 */

#ifndef CIMAGEPROCESSINGTHREAD_HPP
#define CIMAGEPROCESSINGTHREAD_HPP

///----------------------------------------------------------------------------
///                             Includes
///----------------------------------------------------------------------------

/// QT
#include <QThread>
#include <QVector>

/// OCRM
#include "CImageProcessingResult.hpp"

///----------------------------------------------------------------------------
///                        Forward declaration
///----------------------------------------------------------------------------

class QImage;

///----------------------------------------------------------------------------
///                   CImageProcessingThread declaration
///----------------------------------------------------------------------------

namespace NOCRM
{

class CHostWidget;

/**
 * @class CImageProcessingThread "CImageProcessingThread.hpp"
 */
class CImageProcessingThread : public QThread
{
    Q_OBJECT
public:
    CImageProcessingThread( CHostWidget *signalReceiver );

    /**
     * @brief The method that is executed in another thread context.
     */
    virtual void run( );

    /**
     * @brief a container of images to be processed.
     */
    void setImagesToProcess( QVector< QImage* > &images );

    /**
     * @brief set an omage of the object to look for.
     */
    void setSampleImage( QImage *sample );

    /**
     * @brief A flag to see whether image processing has finished its routines.
     * @return @value true if processing is done.
     */
    bool isProcessing( ) const;

signals:

    /**
     * @brief signal containing processing results.
     */
    void doneProcessing( CImageProcessingResult );

public slots:

    /**
     * @brief start image processing
     */
    void imageProcessing( );

private:

    /** @var mSignalReceiver A receiver of emitted signals */
    CHostWidget             *mSignalReceiver;

    /** @var mImages A container to hold image references */
    QVector< QImage* >      mImages;

    /** @var mSample An object to look for */
    QImage                  *mSample;

    /** @var mIsProcessing  A flag to disable double invokations */
    bool                    mIsProcessing;
};

}
#endif /// CIMAGEPROCESSINGTHREAD_HPP
