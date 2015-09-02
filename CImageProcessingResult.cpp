/**
 * Project      One camera range meter
 * Date         03.01.2013
 * File         CImageProcessingResult.cpp
 * About        A class to wrap resuts of image processing.
 */

///----------------------------------------------------------------------------
///                             Includes
///---------------------------------------------------------------------------

#include "CImageProcessingResult.hpp"

///----------------------------------------------------------------------------
///                             Usings
///----------------------------------------------------------------------------

using namespace NOCRM;

///----------------------------------------------------------------------------
///                     CImageProcessingResult definition
///----------------------------------------------------------------------------

///---------------------------------------------------------------------------
CImageProcessingResult::CImageProcessingResult( )
: mDistance( -1 )
, mErrorCode( NErrorHandling::EErrorCode_UnknownError )
///---------------------------------------------------------------------------
{
    qRegisterMetaType<CImageProcessingResult>( "CImageProcessingResult" );
}

///---------------------------------------------------------------------------
CImageProcessingResult::CImageProcessingResult( int distance, NErrorHandling::EErrorCode errorCode )
: mDistance( distance )
, mErrorCode( errorCode )
///---------------------------------------------------------------------------
{
    qRegisterMetaType<CImageProcessingResult>( "CImageProcessingResult" );
}

///---------------------------------------------------------------------------
int CImageProcessingResult::getDistance( ) const
///---------------------------------------------------------------------------
{
    return mDistance;
}

///---------------------------------------------------------------------------
NErrorHandling::EErrorCode CImageProcessingResult::getErrorCode( ) const
///---------------------------------------------------------------------------
{
    return mErrorCode;
}
