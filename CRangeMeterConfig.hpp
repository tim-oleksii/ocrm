/**
 * Project      One camera range meter
 * Date         03.12.2012
 * File         CRangeMeterConfig.hpp
 * About        A singleton that holds all necessary data to measure distance.
 */

#ifndef CRANGEMETERCONFIG_HPP
#define CRANGEMETERCONFIG_HPP

///----------------------------------------------------------------------------
///                             Includes
///----------------------------------------------------------------------------
#include <QReadWriteLock>

///----------------------------------------------------------------------------
///                       CRangeMeterConfig declaration
///----------------------------------------------------------------------------

namespace NOCRM
{

/**
 * @class CRangeMeterConfig "CRangeMeterConfig.hpp"
 */
class CRangeMeterConfig
{
public:

    /**
     * @brief get an instance of configuration.
     * Instance is only one in whole application.
     */
    static CRangeMeterConfig &create( );

    /**
     * @brief set horizontal angle for configuration.
     * The method is thread safe.
     */
    void setHorizontalAngle( unsigned int horAngle );

    /**
     * @brief set vertical angle for configuration.
     * The method is thread safe.
     */
    void setVerticalAngle( unsigned int vertAngle );

    /**
     * @brief set shift distance for configuration.
     * The method is thread safe.
     */
    void setShiftDistance( unsigned int shiftDistance );

    /**
     * @brief get horizontal angle for configuration.
     * The method is thread safe.
     */
    int getHorizontalAngle( );

    /**
     * @brief get vertical angle for configuration.
     * The method is thread safe.
     */
    int getVerticalAngle( );

    /**
     * @brief get shift distance for configuration.
     * The method is thread safe.
     */
    int getShiftDistance( );

private:

    CRangeMeterConfig( );

    int mHorAngle;
    int mVertAngle;
    int mShiftDistance;

    QReadWriteLock mLock;
};

}

#endif /// CRANGEMETERCONFIG_HPP
