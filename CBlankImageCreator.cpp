/**
 * Project      One camera range meter
 * Date         15.11.2012
 * File         CBlankImageCreator.cpp
 * About        A helper unit to create a black image of necessary size.
 */

///----------------------------------------------------------------------------
///                             Includes
///----------------------------------------------------------------------------

#include <QPixmap>
#include "CBlankImageCreator.hpp"

///----------------------------------------------------------------------------
///                              Usings
///----------------------------------------------------------------------------

using namespace NOCRM;

///----------------------------------------------------------------------------
///                       CBlankImageCreator definition
///----------------------------------------------------------------------------

///----------------------------------------------------------------------------
CBlankImageCreator::CBlankImageCreator( int width, int height )
: mPixmap( 0 )
, mIsInitialised( false )
///----------------------------------------------------------------------------
{
    mPixmap = new QPixmap( width, height );
}

///----------------------------------------------------------------------------
CBlankImageCreator::~CBlankImageCreator( )
///----------------------------------------------------------------------------
{
    delete mPixmap;
}

///----------------------------------------------------------------------------
QPixmap CBlankImageCreator::getPixmap( )
///----------------------------------------------------------------------------
{
    if ( false == mIsInitialised )
    {
        createBlankImage( );
        mIsInitialised = true;
    }

    return *mPixmap;
}

///----------------------------------------------------------------------------
void CBlankImageCreator::createBlankImage( )
///----------------------------------------------------------------------------
{
    if ( 0 != mPixmap )
    {
        mPixmap->fill( Qt::black );
    }
}
