/**
 * Project      One camera range meter
 * Date         25.11.2012
 * File         NErrorHandling.hpp
 * About        A helper unit to represent error codes and translate them to strings.
 */

///----------------------------------------------------------------------------
///                             Includes
///----------------------------------------------------------------------------

/// QT
#include <QtGlobal>

/// OCRM
#include "NErrorHandling.hpp"

///----------------------------------------------------------------------------
///                              Defines
///----------------------------------------------------------------------------
#define OCRM_ARRAYLEN(ARG)  sizeof(ARG) / sizeof(ARG[0])

///----------------------------------------------------------------------------
///                              Usings
///----------------------------------------------------------------------------

using namespace NOCRM;

///----------------------------------------------------------------------------
///                      NErrorHandling definition
///----------------------------------------------------------------------------

///----------------------------------------------------------------------------
QString NOCRM::NErrorHandling::toString( const EErrorCode &errorCode )
///----------------------------------------------------------------------------
{
    static const QString errorMessages[] =
    {
        "OK",
        "No camera connection",
        "Unable to get frame",
        "Wrong channgels amount",
        "Wrong colour depth",
        "Wrong image reference",
        "Wrong number of images. There should be only 2 images.",
        "Unknown error occured",
        "Processing is not finished",
        "No sample image"
    };

    const int intErrorCode      = static_cast< int >( errorCode                           );
    const int intMinErrorCode   = static_cast< int >( NErrorHandling::EErrorCode_OK       );
    const int intMaxErrorCode   = static_cast< int >( NErrorHandling::EErrorCode_EnumSize );

    Q_ASSERT_X( intMinErrorCode <= intErrorCode && intErrorCode < intMaxErrorCode,
                "value verification",
                "the value is not between EErrorCode_OK and EErrorCode_EnumSize");

    /// if enumeration EErrorCode has been expanded but not errorMessages
    Q_ASSERT_X( intErrorCode < OCRM_ARRAYLEN(errorMessages),
                "error messages access",
                "index is out of bound");

    return errorMessages[ intErrorCode ];
}
