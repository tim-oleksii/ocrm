/********************************************************************************
** Form generated from reading UI file 'COCRMFeaturesWidget.ui'
**
** Created: Mon 12. Nov 22:53:05 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COCRMFEATURESWIDGET_H
#define UI_COCRMFEATURESWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFormLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSpinBox>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mFeaturesWidget
{
public:
    QHBoxLayout *mHorFeaturesLayout;
    QGroupBox *mFeaturesBox;
    QHBoxLayout *horizontalLayout;
    QFormLayout *mFeaturesGridLayout;
    QLabel *mVertAngleLabel;
    QSpinBox *mVertAngleSpinBox;
    QLabel *mHorAngleLabel;
    QSpinBox *mHorAngleSpinBox;
    QLabel *mShiftDistance;
    QSpinBox *mShiftDistanceSpinBox;

    void setupUi(QWidget *mFeaturesWidget)
    {
        if (mFeaturesWidget->objectName().isEmpty())
            mFeaturesWidget->setObjectName(QString::fromUtf8("mFeaturesWidget"));
        mFeaturesWidget->resize(165, 125);
        mHorFeaturesLayout = new QHBoxLayout(mFeaturesWidget);
        mHorFeaturesLayout->setObjectName(QString::fromUtf8("mHorFeaturesLayout"));
        mFeaturesBox = new QGroupBox(mFeaturesWidget);
        mFeaturesBox->setObjectName(QString::fromUtf8("mFeaturesBox"));
        horizontalLayout = new QHBoxLayout(mFeaturesBox);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        mFeaturesGridLayout = new QFormLayout();
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


        mHorFeaturesLayout->addWidget(mFeaturesBox);


        retranslateUi(mFeaturesWidget);

        QMetaObject::connectSlotsByName(mFeaturesWidget);
    } // setupUi

    void retranslateUi(QWidget *mFeaturesWidget)
    {
        mFeaturesWidget->setWindowTitle(QApplication::translate("mFeaturesWidget", "Form", 0, QApplication::UnicodeUTF8));
        mFeaturesBox->setTitle(QApplication::translate("mFeaturesWidget", "Features", 0, QApplication::UnicodeUTF8));
        mVertAngleLabel->setText(QApplication::translate("mFeaturesWidget", "Vertical angle", 0, QApplication::UnicodeUTF8));
        mVertAngleSpinBox->setSpecialValueText(QString());
        mVertAngleSpinBox->setPrefix(QString());
        mHorAngleLabel->setText(QApplication::translate("mFeaturesWidget", "Horizontal angle", 0, QApplication::UnicodeUTF8));
        mShiftDistance->setText(QApplication::translate("mFeaturesWidget", "Shift distance", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class mFeaturesWidget: public Ui_mFeaturesWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COCRMFEATURESWIDGET_H
