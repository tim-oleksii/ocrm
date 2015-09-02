/**
 * Project      One camera range meter
 * Date         04.01.2013
 * File         NImageConversion.cpp
 * About        A wrapper class for OpenCV video capture.
 */

///----------------------------------------------------------------------------
///                             Includes
///----------------------------------------------------------------------------

#include "NImageConversion.hpp"

///----------------------------------------------------------------------------
///                              Static
///----------------------------------------------------------------------------

static const int csRGB_888 = 3;

///----------------------------------------------------------------------------
///                              Usings
///----------------------------------------------------------------------------

using namespace NOCRM;
using namespace NOCRM::NErrorHandling;

///----------------------------------------------------------------------------
///                      NImageConversion definition
///----------------------------------------------------------------------------

///----------------------------------------------------------------------------
EErrorCode NImageConversion::IplImage2QImage( IplImage *iplImage, QImage &image )
///----------------------------------------------------------------------------
{
    EErrorCode errorCode = EErrorCode_WrongImageReference;
    if ( 0 != iplImage )
    {
        if ( csRGB_888 == iplImage->nChannels )
        {
            const int cChannelColourDepth = 8;
            if ( cChannelColourDepth == iplImage->depth )
            {
                const uchar *qImageBuffer = (const uchar*)iplImage->imageData;

                image = QImage( qImageBuffer, iplImage->width, iplImage->height, QImage::Format_RGB888 ).rgbSwapped();
                errorCode = EErrorCode_OK;
            }
            else
            {
                errorCode = EErrorCode_WrongColourDepth;
            }
        }
        else
        {
            errorCode = EErrorCode_WrongChannelsAmount;
        }
    }

    return errorCode;
}


///----------------------------------------------------------------------------
EErrorCode NImageConversion::QImage2IplImage( QImage &image, IplImage **iplImage )
///----------------------------------------------------------------------------
{
    EErrorCode errorCode = EErrorCode_OK;

    int width  = image.width( );
    int height = image.height( );

    *iplImage = cvCreateImage( cvSize(width, height), IPL_DEPTH_8U, csRGB_888 );
    char *imgBuffer = (*iplImage)->imageData;

    /// Remove alpha channel. the size of pixel for RGB_888 is 32, but not 24!
    const int jump = 4;

    for ( int y = 0; y < (*iplImage)->height; y++ )
    {
        QByteArray a( (const char*) image.scanLine(y), image.bytesPerLine() );

        for ( int i = 0; i< a.size(); i += jump )
        {
            memcpy( imgBuffer, a.data() + i, csRGB_888 );
            imgBuffer += csRGB_888;
        }
    }

    return errorCode;
}

///----------------------------------------------------------------------------
EErrorCode NImageConversion::QImage2Mat( QImage &image, cv::Mat &mat )
///----------------------------------------------------------------------------
{
    EErrorCode errorCode = EErrorCode_WrongColourDepth;

    if ( false == image.isNull() && QImage::Format_RGB32 == image.format() )
    {
        cv::Mat auxMat( image.height(), image.width(), CV_8UC3 );
        unsigned char *data = auxMat.data;

        for (int y = 0; y < image.height(); ++y, data += auxMat.cols * auxMat.elemSize() )
        {
            for(int x = 0; x < image.width(); ++x )
            {
                QRgb rgb = image.pixel(x, y);
                data[x * csRGB_888 + 2] = qRed(rgb);
                data[x * csRGB_888 + 1] = qGreen(rgb);
                data[x * csRGB_888    ] = qBlue(rgb);
            }
        }

        mat = auxMat;
        errorCode = EErrorCode_OK;
    }

    return errorCode;
}

