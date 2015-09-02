/**
 * Project      One camera range meter
 * Date         03.01.2013
 * File         CImageProcessingResult.hpp
 * About        A class to wrap resuts of image processing.
 */


#ifndef CIMAGEPROCESSINGRESULT_HPP
#define CIMAGEPROCESSINGRESULT_HPP

///----------------------------------------------------------------------------
///                             Includes
///---------------------------------------------------------------------------

/// QT
#include <QMetaType>

/// OCRM
#include "NErrorHandling.hpp"

///----------------------------------------------------------------------------
///                   CImageProcessingResult declaration
///----------------------------------------------------------------------------

namespace NOCRM
{

class CImageProcessingResult
{
public:

    /**
     * @brief Default ctor implementation for QT metatypes system.
     */
    CImageProcessingResult( );

    /**
     * @brief ctor to initialise class.
     * @param[in] distance  Measured distance. A value < 0 means that something went wrong.
     * @param[in] errorCode A status of processing. If it's != EErrorCode_OK, then distance should be < 0.
     */
    CImageProcessingResult( int distance, NErrorHandling::EErrorCode errorCode );

    /**
     * @brief Get distance between camera and object.
     * @return negative returned value means that processing was aborted.
     */
    int getDistance( ) const;

    /**
     * @brief Get processing status.
     * @return Processing results status @see @enum EErrorCode.
     */
    NErrorHandling::EErrorCode getErrorCode( ) const;

private:
    /** @var mDistance between camera and object */
    int mDistance;

    /** @var mErrorCode Image processing result */
    NErrorHandling::EErrorCode mErrorCode;
};

}

Q_DECLARE_METATYPE( NOCRM::CImageProcessingResult )

#endif /// CIMAGEPROCESSINGRESULT_HPP
