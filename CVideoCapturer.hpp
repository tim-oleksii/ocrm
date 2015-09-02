/**
 * Project      One camera range meter
 * Date         21.11.2012
 * File         CVideoCapturer.hpp
 * About        A wrapper class for OpenCV video capture.
 */

#ifndef CVIDEOCAPTURER_HPP
#define CVIDEOCAPTURER_HPP

///----------------------------------------------------------------------------
///                             Includes
///----------------------------------------------------------------------------

/// OpenCV
/// disable warnings for OpenCV
#pragma warning( push, 1 )

#include <cv.h>
#include <highgui.h>

#pragma warning( pop )

/// QImage
#include <QImage>

/// OCRM
#include "NErrorHandling.hpp"

///----------------------------------------------------------------------------
///                    CVideoCapture declaration
///----------------------------------------------------------------------------

namespace NOCRM
{

/**
 * @class CVideoCapturer "CVideoCapturer.hpp"
 */
class CVideoCapturer
{
public:
    CVideoCapturer();

    /**
     * @brief  Get a video frame converted to QImage.
     * @return QImage with content if success,
     *         otherwise null image. (probably no camera connection).
     */
    NErrorHandling::EErrorCode getImage( QImage &image );

    ~CVideoCapturer();

private:

    /// forbid copies
    CVideoCapturer( const CVideoCapturer &);
    CVideoCapturer &operator=(const CVideoCapturer &);

    /**
     * @brief Query image from current camera connection
     * @param[out] iplImage Where to save an address for an image.
     * @return an error code.
     */
    NErrorHandling::EErrorCode queryImage(IplImage **iplImage);

    CvCapture *mCapture;
};

}
#endif /// CVIDEOCAPTURER_HPP
