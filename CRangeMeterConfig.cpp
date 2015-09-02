/**
 * Project      One camera range meter
 * Date         03.12.2012
 * File         CRangeMeterConfig.cpp
 * About        A singleton that holds all necessary data to measure distance.
 */

///----------------------------------------------------------------------------
///                             Includes
///----------------------------------------------------------------------------

#include "CRangeMeterConfig.hpp"

///----------------------------------------------------------------------------
///                              Usings
///----------------------------------------------------------------------------
using namespace NOCRM;

///----------------------------------------------------------------------------
///                       CRangeMeterConfig declaration
///----------------------------------------------------------------------------

///----------------------------------------------------------------------------
CRangeMeterConfig::CRangeMeterConfig( )
: mHorAngle( 0 )
, mVertAngle( 0 )
, mShiftDistance( 0 )
, mLock( )
///----------------------------------------------------------------------------
{
    /// NONE
}

///----------------------------------------------------------------------------
CRangeMeterConfig &CRangeMeterConfig::create( )
///----------------------------------------------------------------------------
{
    static CRangeMeterConfig rangeMeterConfig;
    return rangeMeterConfig;
}

///----------------------------------------------------------------------------
void CRangeMeterConfig::setHorizontalAngle( unsigned int horAngle )
///----------------------------------------------------------------------------
{
    mLock.lockForWrite( );
    mHorAngle = horAngle;
    mLock.unlock( );
}

///----------------------------------------------------------------------------
void CRangeMeterConfig::setVerticalAngle( unsigned int vertAngle )
///----------------------------------------------------------------------------
{
    mLock.lockForWrite( );
    mVertAngle = vertAngle;
    mLock.unlock( );
}

///----------------------------------------------------------------------------
void CRangeMeterConfig::setShiftDistance( unsigned int shiftDistance )
///----------------------------------------------------------------------------
{
    mLock.lockForWrite( );
    mShiftDistance = shiftDistance;
    mLock.unlock( );
}

///----------------------------------------------------------------------------
int CRangeMeterConfig::getHorizontalAngle( )
///----------------------------------------------------------------------------
{
    mLock.lockForRead( );
    int horAngle = mHorAngle;
    mLock.unlock( );
    return horAngle;
}

///----------------------------------------------------------------------------
int CRangeMeterConfig::getVerticalAngle( )
///----------------------------------------------------------------------------
{
    mLock.lockForRead( );
    int vertAngle = mVertAngle;
    mLock.unlock( );
    return vertAngle;
}

///----------------------------------------------------------------------------
int CRangeMeterConfig::getShiftDistance( )
///----------------------------------------------------------------------------
{
    mLock.lockForRead( );
    int shiftDistance = mShiftDistance;
    mLock.unlock( );
    return shiftDistance;
}
