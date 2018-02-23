#-------------------------------------------------
#
# Project created by QtCreator 2015-04-07T17:26:52
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = Bildverarbeitung
TEMPLATE = app

INCLUDEPATH += /usr/local/include/

LIBS += `pkg-config opencv --cflags --libs`

CONFIG += C++11


SOURCES += main.cpp\
        mainwindow.cpp \
    cvimagewidget.cpp \
    filewidget.cpp \
    modification/linearscaling.cpp \
    modification/lookuptable.cpp \
    measure/basicmeasurment.cpp \
    modification/gammacorrection.cpp \
    modification/filter.cpp \
    qcustomplot.cpp \
    modification/dlggamma.cpp \
    commandline.cpp \
    modifier.cpp \
    modification/dlglinearscaling.cpp \
    measure/dlgmeasure.cpp \
    measure/dlghistogram.cpp \
    modification/histogramequalization.cpp \
    cmdlistviewitemwidget.cpp \
    cmdlistviewitemdelegate.cpp \
    modifierentry.cpp \
    modification/morphology.cpp \
    modification/dlgequaldensity.cpp \
    modification/equaldensity.cpp \
    modification/canny.cpp \
    modification/dlgcanny.cpp

HEADERS  += mainwindow.h \
    cvimagewidget.h \
    filewidget.h \
    modification/linearscaling.h \
    modification/lookuptable.h \
    measure/basicmeasurment.h \
    modification/gammacorrection.h \
    modification/filter.h \
    qcustomplot.h \
    modification/dlggamma.h \
    commandline.h \
    modifier.h \
    modification/dlglinearscaling.h \
    measure/dlgmeasure.h \
    measure/dlghistogram.h \
    modification/histogramequalization.h \
    cmdlistviewitemwidget.h \
    cmdlistviewitemdelegate.h \
    modifierentry.h \
    modification/morphology.h \
    modification/dlgequaldensity.h \
    modification/equaldensity.h \
    modification/canny.h \
    modification/dlgcanny.h

FORMS    += mainwindow.ui \
    filewidget.ui \
    calcwidget.ui \
    modification/dlggamma.ui \
    modification/dlglinearscaling.ui \
    measure/dlgmeasure.ui \
    measure/dlghistogram.ui \
    cmdlistviewitemwidget.ui \
    modification/dlgequaldensity.ui \
    modification/dlgcanny.ui
