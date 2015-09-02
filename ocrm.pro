#-------------------------------------------------
#
# Project created by QtCreator 2012-11-06T22:30:52
#
#-------------------------------------------------

QT       += core gui

TARGET = ocrm
TEMPLATE = app

SOURCES +=  main.cpp            \
    CBlankImageCreator.cpp      \
    CHostWidget.cpp             \
    NErrorHandling.cpp          \
    CVideoCapturingThread.cpp   \
    CVideoCapturer.cpp          \
    CVideoCaptureData.cpp       \
    CRangeMeterConfig.cpp       \
    CImageProcessingThread.cpp  \
    CImageProcessingResult.cpp  \
    NImageConversion.cpp

HEADERS  +=                     \
    CBlankImageCreator.hpp      \
    CHostWidget.hpp             \
    NErrorHandling.hpp          \
    CVideoCapturingThread.hpp   \
    CVideoCaptureData.hpp       \
    CVideoCapturer.hpp          \
    CRangeMeterConfig.hpp       \
    CImageProcessingThread.hpp  \
    CImageProcessingResult.hpp  \
    NImageConversion.hpp

FORMS    += \
    CHostWidget.ui

INCLUDEPATH +=  D:\opencv\build\include         \
                D:\opencv\build\include\opencv

LIBS +=     D:\opencv\build\x86\vc10\lib\opencv_calib3d243.lib      \
            D:\opencv\build\x86\vc10\lib\opencv_contrib243.lib      \
            D:\opencv\build\x86\vc10\lib\opencv_core243.lib         \
            D:\opencv\build\x86\vc10\lib\opencv_features2d243.lib   \
            D:\opencv\build\x86\vc10\lib\opencv_flann243.lib        \
            D:\opencv\build\x86\vc10\lib\opencv_gpu243.lib          \
            D:\opencv\build\x86\vc10\lib\opencv_highgui243.lib      \
            D:\opencv\build\x86\vc10\lib\opencv_imgproc243.lib      \
            D:\opencv\build\x86\vc10\lib\opencv_legacy243.lib       \
            D:\opencv\build\x86\vc10\lib\opencv_ml243.lib           \
            D:\opencv\build\x86\vc10\lib\opencv_nonfree243.lib      \
            D:\opencv\build\x86\vc10\lib\opencv_objdetect243.lib    \
            D:\opencv\build\x86\vc10\lib\opencv_photo243.lib        \
            D:\opencv\build\x86\vc10\lib\opencv_stitching243.lib    \
            D:\opencv\build\x86\vc10\lib\opencv_video243.lib        \
            D:\opencv\build\x86\vc10\lib\opencv_videostab243.lib    \
            D:\opencv\build\x86\vc10\lib\opencv_videostab243.lib    \
            D:\opencv\build\x86\vc10\lib\opencv_nonfree243.lib
