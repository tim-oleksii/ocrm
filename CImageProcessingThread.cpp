/**
 * Project      One camera range meter
 * Date         03.01.2013
 * File         CImageProcessingThread.cpp
 * About        A class to implement image processing logic.
 */

///----------------------------------------------------------------------------
///                             Includes
///----------------------------------------------------------------------------

/// OpenCV
#include "opencv2/nonfree/nonfree.hpp"

/// QT
#include <QPair>
#include <QImage>
#include <QVector>
#include <QtCore>

/// OCRM
#include "CHostWidget.hpp"
#include "NImageConversion.hpp"
#include "CImageProcessingThread.hpp"

/// STD
#include <vector>
#include <string>
#include <cmath>

///----------------------------------------------------------------------------
///                              Defines
///----------------------------------------------------------------------------
#define __DEBUG_OCRM__ /// necessary to output some intmediate processing results.

///----------------------------------------------------------------------------
///                              Typedefs
///----------------------------------------------------------------------------

typedef std::vector< cv::KeyPoint  >  tKeyPoints;
typedef QPair< tKeyPoints, cv::Mat >  tSURFFeatures;
typedef std::vector< cv::DMatch    >  tMatches;
typedef std::vector< cv::Point2f   >  tPoints;

///----------------------------------------------------------------------------
///                              Constants
///----------------------------------------------------------------------------

static const int scRectangle = 4;

///----------------------------------------------------------------------------
///                              Static
///----------------------------------------------------------------------------

/**
 * @brief Convert all QImages to Mats.
 * @brief Input vectors must be the same size.
 * @param[in]   images      A vector of QImages to be converted.
 * @param[out]  mats        A vector of mats images to be filled.
 * @return Processing status.
 */
static bool convertQImages2Mats( QVector< QImage * > &images, QVector< cv::Mat > &mats);

/**
 * @brief Get the pair of keypoints and descriptors for IPL image.
 * @param[in]   image       A matrix to get features from.
 * @param[out]  descriptors A matrix of descriptors.
 * @return Processing status.
 */
static bool getSURFFeatures( cv::Mat &image, tSURFFeatures &features );

/**
 * @brief Get the matches between the pair of descriptors
 * @param[in]   x       Desriptors.
 * @param[in]   y       Desriptors.
 * @param[out]  matches Container with matched descriptors.
 * @return Processing status.
 */
static bool findMatches( cv::Mat &x, cv::Mat &y, tMatches &matches );

/**
 * @brief compute distance to an object.
 */
static int computeDistance( float widthBefore, float widthAfter, int a, int horAngle, int frameWidth );

#ifdef __DEBUG_OCRM__

///----------------------------------------------------------------------------
///                              Debug helpers
///----------------------------------------------------------------------------

/**
 * @brief Draw features matching between images.
 * @param[in] fileName where to save results.
 * @return true on success, false otherwise.
 */
static bool outputFeatureDetection( cv::Mat     &firstImage,
                                    cv::Mat     &secondImage,
                                    tKeyPoints  &firstKeypoints,
                                    tKeyPoints  &secondKeypoints,
                                    tMatches    &matches,
                                    std::string &fileName );
/**
 * @brief Draw bounding box of and object.
 * @param[in] image         An image to draw in.
 * @param[in] corners       Corners of an object.
 * @param[in] sampleSize    A size of the sample object.
 * @param[in] fileName      Where to save the image.
 */
static bool outputSampleDetection( cv::Mat &image, tPoints &corners, CvSize sampleSize, std::string &fileName );

#endif

///----------------------------------------------------------------------------
///                              Usings
///----------------------------------------------------------------------------

using namespace NOCRM;
using namespace NOCRM::NErrorHandling;
using namespace NOCRM::NImageConversion;

///----------------------------------------------------------------------------
///                   CImageProcessingThread definition
///----------------------------------------------------------------------------

///----------------------------------------------------------------------------
CImageProcessingThread::CImageProcessingThread( CHostWidget *signalReceiver )
: QThread( 0 )
, mSignalReceiver( signalReceiver )
, mImages( )
, mSample( 0 )
, mIsProcessing( false )
///----------------------------------------------------------------------------
{
    if ( 0 != mSignalReceiver )
    {
        connect( this, SIGNAL(doneProcessing(CImageProcessingResult)), signalReceiver, SLOT(processingResults(CImageProcessingResult)) );
    }
}

///----------------------------------------------------------------------------
void CImageProcessingThread::run( )
///----------------------------------------------------------------------------
{
    exec( );
}

///----------------------------------------------------------------------------
void CImageProcessingThread::setImagesToProcess( QVector< QImage* > &images )
///----------------------------------------------------------------------------
{
    mImages = images;
}

///----------------------------------------------------------------------------
void CImageProcessingThread::setSampleImage( QImage *sample )
///----------------------------------------------------------------------------
{
    mSample = sample;
}

///----------------------------------------------------------------------------
void CImageProcessingThread::imageProcessing( )
///----------------------------------------------------------------------------
{
    int distance = -1;
    EErrorCode errorCode = EErrorCode_UnknownError;

    if( CHostWidget::mcsMaxImages == mImages.size() && 0 != mSample )
    {
        if ( false == mIsProcessing )
        {
            mIsProcessing = true;
            const int cTotalImages = CHostWidget::mcsMaxImages + 1;
            const int cSampleIndex = cTotalImages - 1;

            mImages.push_back( mSample );
            /// converting images to matrixes
            QVector< cv::Mat > openCVImages( cTotalImages );
            /// all assertions should never ever happen
            assert( convertQImages2Mats( mImages, openCVImages ) );

            /// get SURF features
            QVector< tSURFFeatures > imagesFeatures( openCVImages.size() );
            for ( int i = 0; i < imagesFeatures.size(); ++i )
            {
                assert( getSURFFeatures(openCVImages[i], imagesFeatures[i]) );
            }

            /// find matches
            QVector< tMatches > matches( CHostWidget::mcsMaxImages );

            for ( int i = 0; i < CHostWidget::mcsMaxImages; ++i )
            {
                assert( findMatches(imagesFeatures[cSampleIndex].second, imagesFeatures[i].second, matches[i]) );
            }

            #ifdef __DEBUG_OCRM__

            /// output matching results
            for ( int i = 0; i < CHostWidget::mcsMaxImages; ++i )
            {
                std::string fileName = QString( "found_matches_%1.png" ).arg( i ).toStdString( );
                assert( outputFeatureDetection(openCVImages[cSampleIndex], openCVImages[i],
                                               imagesFeatures[cSampleIndex].first, imagesFeatures[i].first, matches[i], fileName) );
            }
            #endif

            /// find homography
            QVector< cv::Mat > H( CHostWidget::mcsMaxImages );

            for( int i = 0; i < H.size(); ++i )
            {
                tPoints sample;
                tPoints image;

                for ( int j = 0; j < matches[i].size(); ++j )
                {
                    sample.push_back( imagesFeatures[ cSampleIndex ].first[ matches[i][j].queryIdx ].pt );
                    image.push_back( imagesFeatures[ i ].first[ matches[i][j].trainIdx ].pt );
                }

                H[i] = cv::findHomography( sample, image, CV_RANSAC );
            }

            /// find corners using homography
            tPoints sampleCorners( scRectangle );

            sampleCorners[0] = cvPoint( 0                               , 0 );
            sampleCorners[1] = cvPoint( openCVImages[ cSampleIndex].cols, 0 );
            sampleCorners[2] = cvPoint( openCVImages[ cSampleIndex].cols, openCVImages[ cSampleIndex].rows );
            sampleCorners[3] = cvPoint( 0                               , openCVImages[ cSampleIndex].rows );

            QVector< tPoints > inScenesCorners( CHostWidget::mcsMaxImages, tPoints(scRectangle) );

            for ( int i = 0; i < inScenesCorners.size(); ++i )
            {
                cv::perspectiveTransform( sampleCorners, inScenesCorners[i], H[i] );
            }

            #ifdef __DEBUG_OCRM__
            /// detection output
            for ( int i = 0; i < inScenesCorners.size(); ++i)
            {
                std::string fileName = QString( "sample_detection_%1.png" ).arg(i).toStdString();
                assert( outputSampleDetection( openCVImages[i],
                                               inScenesCorners[i],
                                               cvSize(openCVImages[cSampleIndex].cols, openCVImages[cSampleIndex].rows ),
                                               fileName ) );
            }
            #endif

            errorCode = EErrorCode_OK;
            distance = computeDistance( fabs(inScenesCorners[0][0].x - inScenesCorners[0][1].x),
                                        fabs(inScenesCorners[1][0].x - inScenesCorners[1][1].x),
                                        70,
                                        105,
                                        4000);
        }
        else
        {
            errorCode = EErrorCode_ProcessingIsNotFinished;
        }
    }
    else
    {
        errorCode = EErrorCode_WrongNumberOfImages;
    }

    if ( 0 != mSignalReceiver )
    {
        CImageProcessingResult processingResults( distance, errorCode );
        emit doneProcessing( processingResults );
    }
}

///----------------------------------------------------------------------------
bool CImageProcessingThread::isProcessing( ) const
///----------------------------------------------------------------------------
{
    return mIsProcessing;
}

///----------------------------------------------------------------------------
///                           Static definition
///----------------------------------------------------------------------------

///----------------------------------------------------------------------------
bool convertQImages2Mats( QVector< QImage * > &images, QVector< cv::Mat > &mats)
///----------------------------------------------------------------------------
{
    bool isOK = true;

    assert( images.size() == mats.size() );

    for ( int i = 0; i < images.size() && true == isOK; ++i )
    {
        isOK = ( images[i] ) ? EErrorCode_OK == NImageConversion::QImage2Mat( *images[i], mats[i] )
                             : false ;
    }

    return isOK;
}

///----------------------------------------------------------------------------
bool getSURFFeatures( cv::Mat &image, tSURFFeatures &features )
///----------------------------------------------------------------------------
{
    /// Sorry, magic number, but I dunno the method to determine it.
    const double cHessianThreshold = 300.0;

    cv::SurfFeatureDetector detector( cHessianThreshold, 24, 8 );
    detector.detect( image, features.first );

    //cv::SurfDescriptorExtractor extractor;
    detector.compute( image, features.first, features.second );

    return 0 != features.first.size();
}

///----------------------------------------------------------------------------
bool findMatches( cv::Mat &x, cv::Mat &y, tMatches &matches )
///----------------------------------------------------------------------------
{
    bool isOK = false;

    if ( 0 < x.rows && 0 < y.rows)
    {
        //cv::FlannBasedMatcher matcher;
        cv::BFMatcher matcher( cv::NORM_L2 );
        tMatches flannMatches;
        matcher.match( x, y, flannMatches );

        if ( 0 < flannMatches.size() && flannMatches.size() <= x.rows )
        {
            double minDistance = 100;
            double maxDistance = 0;

            for ( int i = 0; i < x.rows; ++i )
            {
                double distance = flannMatches[i].distance;
                if ( distance < minDistance ) minDistance = distance;
                if ( distance > maxDistance ) maxDistance = distance;
            }

            const double cDistanceCorrection = 2.0;
            for ( int i = 0; i < x.rows; ++i )
            {
                if ( flannMatches[i].distance < cDistanceCorrection * minDistance )
                {
                    matches.push_back(flannMatches[i]);
                }
            }
        }

        isOK = flannMatches.size() && matches.size();
    }

    return isOK;
}

///----------------------------------------------------------------------------
int computeDistance( float widthBefore, float widthAfter, int a, int horAngle, int frameWidth )
///----------------------------------------------------------------------------
{
    assert( 0 != frameWidth );

    std::cout << "width before: " << widthBefore << std::endl;
    std::cout << "width after: " <<  widthAfter  << std::endl;

    float alpha = (((float)horAngle) * widthBefore) / ((float)frameWidth);
    float beta  = (((float)horAngle) * widthAfter)  / ((float)frameWidth);

    return abs( (a * tan(alpha)) / ( tan(beta) - tan(alpha)) );
}

#ifdef __DEBUG_OCRM__

///----------------------------------------------------------------------------
///                        Debug helpers definition
///----------------------------------------------------------------------------

///----------------------------------------------------------------------------
bool outputFeatureDetection( cv::Mat     &firstImage,
                             cv::Mat     &secondImage,
                             tKeyPoints  &firstKeypoints,
                             tKeyPoints  &secondKeypoints,
                             tMatches    &matches,
                             std::string &fileName )
///----------------------------------------------------------------------------
{
    cv::Mat outputImage;
    cv::drawMatches( firstImage, firstKeypoints, secondImage, secondKeypoints, matches, outputImage,
                     cv::Scalar::all(-1), cv::Scalar::all(-1), std::vector<char>(), cv::DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS );

    return fileName.size() > 0 && cv::imwrite( fileName, outputImage );
}

///----------------------------------------------------------------------------
bool outputSampleDetection( cv::Mat &image, tPoints &corners, CvSize sampleSize, std::string &fileName )
///----------------------------------------------------------------------------
{
    assert( corners.size() == scRectangle );

    cv::line( image, corners[0], corners[1], cv::Scalar( 0, 255, 0), 8 );
    cv::line( image, corners[1], corners[2], cv::Scalar( 0, 255, 0), 8 );
    cv::line( image, corners[2], corners[3], cv::Scalar( 0, 255, 0), 8 );
    cv::line( image, corners[3], corners[0], cv::Scalar( 0, 255, 0), 8 );

    return fileName.size() > 0 && cv::imwrite( fileName, image );
}

#endif
