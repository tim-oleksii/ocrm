/**
 * Project      One camera range meter
 * Date         21.11.2012
 * File         CVideoCapturerr.hpp
 * About        A wrapper class for OpenCV video capture.
 */

///----------------------------------------------------------------------------
///                             Includes
///----------------------------------------------------------------------------

#include "CVideoCapturer.hpp"
#include "NErrorHandling.hpp"
#include "NImageConversion.hpp"

///----------------------------------------------------------------------------
///                              Usings
///----------------------------------------------------------------------------

using namespace NOCRM;
using namespace NOCRM::NErrorHandling;
using namespace NOCRM::NImageConversion;

///----------------------------------------------------------------------------
///                      CVideoCapturer definition
///----------------------------------------------------------------------------

///----------------------------------------------------------------------------
CVideoCapturer::CVideoCapturer( )
: mCapture( cvCaptureFromCAM(CV_CAP_ANY) )
///----------------------------------------------------------------------------
{
    /// NONE
}

///----------------------------------------------------------------------------
CVideoCapturer::~CVideoCapturer( )
///----------------------------------------------------------------------------
{
    if ( 0 != mCapture )
    {
        cvReleaseCapture( &mCapture );
        mCapture = 0;
    }
}

///----------------------------------------------------------------------------
EErrorCode CVideoCapturer::getImage( QImage &image )
///----------------------------------------------------------------------------
{
    IplImage *iplImage = 0;
    EErrorCode errorCode = EErrorCode_NoCameraConnection;

    if ( 0 != mCapture )
    {
        errorCode = queryImage( &iplImage );

        if ( EErrorCode_OK == errorCode )
        {
            errorCode = IplImage2QImage( iplImage, image );
        }
    }

    return errorCode;
}

///----------------------------------------------------------------------------
EErrorCode CVideoCapturer::queryImage( IplImage **iplImage )
///----------------------------------------------------------------------------
{
    EErrorCode errorCode = EErrorCode_UnableToGetFrame;

    if ( 0 != mCapture &&
         0 != iplImage    )
    {
        *iplImage = cvQueryFrame( mCapture );

        if ( 0 != *iplImage )
        {
            errorCode = EErrorCode_OK;
        }
    }

    return errorCode;
}

