/********************************************************************************
** Form generated from reading UI file 'CHostWidget.ui'
**
** Created: Mon 21. Jan 23:19:00 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHOSTWIDGET_H
#define UI_CHOSTWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFormLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CHostWidget
{
public:
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *mLeftVBoxLayout;
    QVBoxLayout *mLeftMostVBoxLayout;
    QHBoxLayout *mControlsHBoxLayout;
    QVBoxLayout *mControlsVertLayout;
    QPushButton *mVideoButton;
    QPushButton *mCapturePhotoButton;
    QPushButton *mLoadSampleButton;
    QPushButton *mGetDistanceButton;
    QPushButton *mFeaturesButton;
    QSpacerItem *mVideoSpacerDelimeter;
    QGroupBox *mFeaturesBox;
    QHBoxLayout *horizontalLayout;
    QFormLayout *mFeaturesGridLayout;
    QLabel *mVertAngleLabel;
    QSpinBox *mVertAngleSpinBox;
    QLabel *mHorAngleLabel;
    QSpinBox *mHorAngleSpinBox;
    QLabel *mShiftDistance;
    QSpinBox *mShiftDistanceSpinBox;
    QSpacerItem *mGalleryDelimiter;
    QLabel *mGraphicsLabel;

    void setupUi(QWidget *CHostWidget)
    {
        if (CHostWidget->objectName().isEmpty())
            CHostWidget->setObjectName(QString::fromUtf8("CHostWidget"));
        CHostWidget->resize(858, 498);
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CHostWidget->sizePolicy().hasHeightForWidth());
        CHostWidget->setSizePolicy(sizePolicy);
        horizontalLayout_2 = new QHBoxLayout(CHostWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        mLeftVBoxLayout = new QVBoxLayout();
        mLeftVBoxLayout->setSpacing(6);
        mLeftVBoxLayout->setObjectName(QString::fromUtf8("mLeftVBoxLayout"));
        mLeftMostVBoxLayout = new QVBoxLayout();
        mLeftMostVBoxLayout->setSpacing(6);
        mLeftMostVBoxLayout->setObjectName(QString::fromUtf8("mLeftMostVBoxLayout"));
        mControlsHBoxLayout = new QHBoxLayout();
        mControlsHBoxLayout->setSpacing(6);
        mControlsHBoxLayout->setObjectName(QString::fromUtf8("mControlsHBoxLayout"));
        mControlsVertLayout = new QVBoxLayout();
        mControlsVertLayout->setSpacing(6);
        mControlsVertLayout->setObjectName(QString::fromUtf8("mControlsVertLayout"));
        mVideoButton = new QPushButton(CHostWidget);
        mVideoButton->setObjectName(QString::fromUtf8("mVideoButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(mVideoButton->sizePolicy().hasHeightForWidth());
        mVideoButton->setSizePolicy(sizePolicy1);
        mVideoButton->setMinimumSize(QSize(100, 23));
        mVideoButton->setCheckable(true);

        mControlsVertLayout->addWidget(mVideoButton);

        mCapturePhotoButton = new QPushButton(CHostWidget);
        mCapturePhotoButton->setObjectName(QString::fromUtf8("mCapturePhotoButton"));
        mCapturePhotoButton->setEnabled(false);
        sizePolicy1.setHeightForWidth(mCapturePhotoButton->sizePolicy().hasHeightForWidth());
        mCapturePhotoButton->setSizePolicy(sizePolicy1);
        mCapturePhotoButton->setMinimumSize(QSize(100, 23));

        mControlsVertLayout->addWidget(mCapturePhotoButton);

        mLoadSampleButton = new QPushButton(CHostWidget);
        mLoadSampleButton->setObjectName(QString::fromUtf8("mLoadSampleButton"));

        mControlsVertLayout->addWidget(mLoadSampleButton);

        mGetDistanceButton = new QPushButton(CHostWidget);
        mGetDistanceButton->setObjectName(QString::fromUtf8("mGetDistanceButton"));
        mGetDistanceButton->setEnabled(false);
        sizePolicy1.setHeightForWidth(mGetDistanceButton->sizePolicy().hasHeightForWidth());
        mGetDistanceButton->setSizePolicy(sizePolicy1);
        mGetDistanceButton->setMinimumSize(QSize(100, 23));

        mControlsVertLayout->addWidget(mGetDistanceButton);

        mFeaturesButton = new QPushButton(CHostWidget);
        mFeaturesButton->setObjectName(QString::fromUtf8("mFeaturesButton"));
        sizePolicy1.setHeightForWidth(mFeaturesButton->sizePolicy().hasHeightForWidth());
        mFeaturesButton->setSizePolicy(sizePolicy1);
        mFeaturesButton->setMinimumSize(QSize(100, 23));
        mFeaturesButton->setCheckable(true);

        mControlsVertLayout->addWidget(mFeaturesButton);


        mControlsHBoxLayout->addLayout(mControlsVertLayout);

        mVideoSpacerDelimeter = new QSpacerItem(50, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        mControlsHBoxLayout->addItem(mVideoSpacerDelimeter);


        mLeftMostVBoxLayout->addLayout(mControlsHBoxLayout);

        mFeaturesBox = new QGroupBox(CHostWidget);
        mFeaturesBox->setObjectName(QString::fromUtf8("mFeaturesBox"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(mFeaturesBox->sizePolicy().hasHeightForWidth());
        mFeaturesBox->setSizePolicy(sizePolicy2);
        horizontalLayout = new QHBoxLayout(mFeaturesBox);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        mFeaturesGridLayout = new QFormLayout();
        mFeaturesGridLayout->setSpacing(6);
        mFeaturesGridLayout->setObjectName(QString::fromUtf8("mFeaturesGridLayout"));
        mVertAngleLabel = new QLabel(mFeaturesBox);
        mVertAngleLabel->setObjectName(QString::fromUtf8("mVertAngleLabel"));
        mVertAngleLabel->setEnabled(true);

        mFeaturesGridLayout->setWidget(0, QFormLayout::LabelRole, mVertAngleLabel);

        mVertAngleSpinBox = new QSpinBox(mFeaturesBox);
        mVertAngleSpinBox->setObjectName(QString::fromUtf8("mVertAngleSpinBox"));
        mVertAngleSpinBox->setEnabled(true);
        mVertAngleSpinBox->setMaximum(180);

        mFeaturesGridLayout->setWidget(0, QFormLayout::FieldRole, mVertAngleSpinBox);

        mHorAngleLabel = new QLabel(mFeaturesBox);
        mHorAngleLabel->setObjectName(QString::fromUtf8("mHorAngleLabel"));

        mFeaturesGridLayout->setWidget(1, QFormLayout::LabelRole, mHorAngleLabel);

        mHorAngleSpinBox = new QSpinBox(mFeaturesBox);
        mHorAngleSpinBox->setObjectName(QString::fromUtf8("mHorAngleSpinBox"));
        mHorAngleSpinBox->setMaximum(180);

        mFeaturesGridLayout->setWidget(1, QFormLayout::FieldRole, mHorAngleSpinBox);

        mShiftDistance = new QLabel(mFeaturesBox);
        mShiftDistance->setObjectName(QString::fromUtf8("mShiftDistance"));
        mShiftDistance->setScaledContents(false);

        mFeaturesGridLayout->setWidget(2, QFormLayout::LabelRole, mShiftDistance);

        mShiftDistanceSpinBox = new QSpinBox(mFeaturesBox);
        mShiftDistanceSpinBox->setObjectName(QString::fromUtf8("mShiftDistanceSpinBox"));
        mShiftDistanceSpinBox->setMaximum(500);

        mFeaturesGridLayout->setWidget(2, QFormLayout::FieldRole, mShiftDistanceSpinBox);


        horizontalLayout->addLayout(mFeaturesGridLayout);


        mLeftMostVBoxLayout->addWidget(mFeaturesBox);


        mLeftVBoxLayout->addLayout(mLeftMostVBoxLayout);

        mGalleryDelimiter = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        mLeftVBoxLayout->addItem(mGalleryDelimiter);


        horizontalLayout_2->addLayout(mLeftVBoxLayout);

        mGraphicsLabel = new QLabel(CHostWidget);
        mGraphicsLabel->setObjectName(QString::fromUtf8("mGraphicsLabel"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(mGraphicsLabel->sizePolicy().hasHeightForWidth());
        mGraphicsLabel->setSizePolicy(sizePolicy3);
        mGraphicsLabel->setMinimumSize(QSize(640, 480));

        horizontalLayout_2->addWidget(mGraphicsLabel);


        retranslateUi(CHostWidget);
        QObject::connect(mFeaturesButton, SIGNAL(toggled(bool)), mFeaturesBox, SLOT(setVisible(bool)));
        QObject::connect(mVideoButton, SIGNAL(toggled(bool)), mGraphicsLabel, SLOT(setVisible(bool)));

        QMetaObject::connectSlotsByName(CHostWidget);
    } // setupUi

    void retranslateUi(QWidget *CHostWidget)
    {
        CHostWidget->setWindowTitle(QApplication::translate("CHostWidget", "COCRMHostWidget", 0, QApplication::UnicodeUTF8));
        mVideoButton->setText(QApplication::translate("CHostWidget", "Start video", 0, QApplication::UnicodeUTF8));
        mCapturePhotoButton->setText(QApplication::translate("CHostWidget", "Take photo", 0, QApplication::UnicodeUTF8));
        mLoadSampleButton->setText(QApplication::translate("CHostWidget", "Load sample", 0, QApplication::UnicodeUTF8));
        mGetDistanceButton->setText(QApplication::translate("CHostWidget", "Get distance", 0, QApplication::UnicodeUTF8));
        mFeaturesButton->setText(QApplication::translate("CHostWidget", "Features", 0, QApplication::UnicodeUTF8));
        mFeaturesBox->setTitle(QApplication::translate("CHostWidget", "Features", 0, QApplication::UnicodeUTF8));
        mVertAngleLabel->setText(QApplication::translate("CHostWidget", "Vertical angle", 0, QApplication::UnicodeUTF8));
        mVertAngleSpinBox->setSpecialValueText(QString());
        mVertAngleSpinBox->setPrefix(QString());
        mHorAngleLabel->setText(QApplication::translate("CHostWidget", "Horizontal angle", 0, QApplication::UnicodeUTF8));
        mShiftDistance->setText(QApplication::translate("CHostWidget", "Shift distance", 0, QApplication::UnicodeUTF8));
        mGraphicsLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CHostWidget: public Ui_CHostWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHOSTWIDGET_H
