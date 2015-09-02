/**
 * Project      One camera range meter
 * Date         17.11.2012
 * File         main.cpp
 * About        Entry point of the programme.
 */

///----------------------------------------------------------------------------
///                              Includes
///----------------------------------------------------------------------------

/// QT
#include <QVector>
#include <QtGui/QApplication>

/// OCRM
#include "CHostWidget.hpp"
#include "NImageConversion.hpp"
#include "CRangeMeterConfig.hpp"

using namespace NOCRM;

///----------------------------------------------------------------------------
///                            Implementation
///----------------------------------------------------------------------------

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    NOCRM::CHostWidget w;
    w.show();

    return a.exec();
}
