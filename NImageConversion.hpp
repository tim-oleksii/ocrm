/**
 * Project      One camera range meter
 * Date         04.01.2013
 * File         NImageConversion.hpp
 * About        Converter from IplImage to QImage and vice versa.
 */


#ifndef NIMAGECONVERSION_HPP
#define NIMAGECONVERSION_HPP

///----------------------------------------------------------------------------
///                             Includes
///----------------------------------------------------------------------------

/// OpenCV
/// disable warnings for OpenCV
#pragma warning( push, 1 )

#include <cv.h>
#include <highgui.h>

#pragma warning( pop )

/// QT
#include <QImage>

/// OCRM
#include "NErrorHandling.hpp"

///----------------------------------------------------------------------------
///                   NImageConversion declaration
///----------------------------------------------------------------------------

namespace NOCRM
{

/**
 * @namespace NImageConversion "NImageConversion.hpp"
 */
namespace NImageConversion
{
    /**
     * @brief Convert IplImage to QImage. Converts only an iplImage with depth 8 and 3 channels into a 8/24-bit QImage.
     * @param[in]  iplImage IplImage to get data from. iplImage cannot be NULL.
     * @param[out] image An image in QImage format.
     * @return an error code.
     */
    NErrorHandling::EErrorCode IplImage2QImage( IplImage *iplImage, QImage &image );

    /**
     * @brief Convert IplImage to QImage.  Only 24-bit QImage::Format_RGB888 and the QImage::Format_RGB32 are accepted.
     * @brief Apha values in the 32-bit format will be removed during the conversion.
     * @brief An user should release the image after usage.
     * @param[in]   image       An image in QImage format.
     * @param[out]  iplImage    Output in IPL format. Cannot be NULL.
     * @return an error code.
     */
    NErrorHandling::EErrorCode QImage2IplImage( QImage &image, IplImage **iplImage );

    /**
     * @brief Convert Matrix to QImage.  @see NImageConversion#QImage2IplImage
     * @param[in]   image       An image in QImage format.
     * @param[out]  Mat         OpenV matrix.
     * @return an error code.
     */
    NErrorHandling::EErrorCode QImage2Mat( QImage &image, cv::Mat &mat );
}

}

#endif /// NIMAGECONVERSION_HPP
