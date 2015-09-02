/**
 * Project      One camera range meter
 * Date         15.11.2012
 * File         CBlankImageCreator.hpp
 * About        A helper unit to create a black image of necessary size.
 */

#ifndef CBLANKIMAGECREATOR_HPP
#define CBLANKIMAGECREATOR_HPP

///----------------------------------------------------------------------------
///                         Forward declaration
///----------------------------------------------------------------------------

class QPixmap;

///----------------------------------------------------------------------------
///                  COCRMBlankImageCreator declaration
///----------------------------------------------------------------------------

namespace NOCRM
{
/**
 * @class CBlankImageCreator "CBlankImageCreator.hpp"
 */
class CBlankImageCreator
{
public:

    /**
     * @brief Ctor to determing a size of an image.
     * @param[in] width  A width  of the image. Should be > 0.
     * @param[in] height A height of the image. Should be > 0.
     */
    CBlankImageCreator( int width, int height );

    /**
     * @brief Get constructed image.
     * @return correct image if width and height are correct.
     */
    QPixmap getPixmap( );

    ~CBlankImageCreator( );

    /// Private methods
private:

    /**
     * @brief Create a black image with a text "No video signal".
     */
    void createBlankImage( );

    /// Private members
private:
    QPixmap *mPixmap;
    bool    mIsInitialised;
};
}

#endif /// CBLANKIMAGECREATOR_HPP
