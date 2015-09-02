/**
 * Project      One camera range meter
 * Date         28.11.2012
 * File         CVideoCaptureData.cpp
 * About        A class to wrap data and status of video caprturing process.
 */

///----------------------------------------------------------------------------
///                             Includes
///----------------------------------------------------------------------------

#include "CVideoCaptureData.hpp"

///----------------------------------------------------------------------------
///                             Usings
///----------------------------------------------------------------------------

using namespace NOCRM;

///----------------------------------------------------------------------------
///                    CVideoCaptureData definition
///----------------------------------------------------------------------------

///----------------------------------------------------------------------------
CVideoCaptureData::CVideoCaptureData( QImage *image,
                                      NOCRM::NErrorHandling::EErrorCode errorCode )
: mImage( image )
, mErrorCode( errorCode )
///----------------------------------------------------------------------------
{
    qRegisterMetaType<CVideoCaptureData>( "CVideoCaptureData" );
}

///----------------------------------------------------------------------------
QImage *CVideoCaptureData::getImage( )
///----------------------------------------------------------------------------
{
    return mImage;
}

///----------------------------------------------------------------------------
NErrorHandling::EErrorCode CVideoCaptureData::getErrorCode( )
///----------------------------------------------------------------------------
{
    return mErrorCode;
}
