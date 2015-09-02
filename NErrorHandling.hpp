/**
 * Project      One camera range meter
 * Date         22.11.2012
 * File         NErrorHandling.hpp
 * About        A helper unit to represent error codes and translate them to strings.
 */

#ifndef NERRORHANDLING_HPP
#define NERRORHANDLING_HPP

///----------------------------------------------------------------------------
///                             Includes
///----------------------------------------------------------------------------

#include <QString>

///----------------------------------------------------------------------------
///                   NErrorHandling declaration
///----------------------------------------------------------------------------

namespace NOCRM
{
/**
 * @namespace NErrorHandling "NErrorHandling.hpp"
 */
namespace NErrorHandling
{
    /// if you expand this enum, please do the same for toString()
    /// unless you want an assertion rised.
    enum EErrorCode
    {
        EErrorCode_OK                       = 0,
        EErrorCode_NoCameraConnection       = 1,
        EErrorCode_UnableToGetFrame         = 2,
        EErrorCode_WrongChannelsAmount      = 3,
        EErrorCode_WrongColourDepth         = 4,
        EErrorCode_WrongImageReference      = 5,
        EErrorCode_WrongNumberOfImages      = 6,
        EErrorCode_UnknownError             = 7,
        EErrorCode_ProcessingIsNotFinished  = 8,
        EErrorCode_NoSampleImage            = 9,
        EErrorCode_EnumSize                 = 10
    };

    /**
     * @brief Converts an enumeration value passed by @a errorCode
     * into a QString.
     * @param[in] errorCode An enumeration value should be == to 0 and < than
     * EErrorCode_EnumSize
     * @return String representation of an error code.
     */
    QString toString( const EErrorCode &errorCode );
}

}
#endif /// NERRORHANDLING_HPP
