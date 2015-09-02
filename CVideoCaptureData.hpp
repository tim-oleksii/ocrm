/**
 * Project      One camera range meter
 * Date         28.11.2012
 * File         CVideoCaptureData.hpp
 * About        A class to wrap data and status of video caprturing process.
 */

#ifndef CVIDEOCAPTUREDATA_HPP
#define CVIDEOCAPTUREDATA_HPP

///----------------------------------------------------------------------------
///                             Includes
///---------------------------------------------------------------------------

/// QT
#include <QImage>
#include <QMetaType>

/// OCRM
#include "NErrorHandling.hpp"

///----------------------------------------------------------------------------
///                     CVideoCaptureData declaration
///----------------------------------------------------------------------------

namespace NOCRM
{

/**
 * @class CVideoCaptureData "CVideoCaptureData.hpp"
 */
class CVideoCaptureData
{
public:
    CVideoCaptureData() {}
    explicit CVideoCaptureData( QImage *image,
                                NOCRM::NErrorHandling::EErrorCode errorCode );

    QImage                           *getImage( );
    NOCRM::NErrorHandling::EErrorCode getErrorCode( );

private:
    QImage                            *mImage;
    NOCRM::NErrorHandling::EErrorCode  mErrorCode;
};

}

Q_DECLARE_METATYPE( NOCRM::CVideoCaptureData )

#endif /// CVIDEOCAPTUREDATA_HPP
