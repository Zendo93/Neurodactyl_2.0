#-------------------------------------------------
#
# Project created by QtCreator 2017-03-12T13:07:27
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Neurodactyl_2
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    identification.cpp \
    verification.cpp \
    manual.cpp \
    FingerPrintScanner/fingerprintscanner.cpp

HEADERS  += mainwindow.h \
    identification.h \
    verification.h \
    manual.h \
    FingerPrintScanner/fingerprintscanner.h \
    FingerPrintScanner/fxISO_device.h \
    FingerPrintScanner/fxISO_engine.h \
    FingerPrintScanner/fxISO_Interchange.h \
    FingerPrintScanner/fxISOAFIS.h \
    FingerPrintScanner/fxISOdll.h \
    FingerPrintScanner/fxISOenrdlg.h

FORMS    += mainwindow.ui \
    identification.ui \
    verification.ui \
    manual.ui

DISTFILES += \
    icons/folder_chooser.ico

LIBS += "C:/TeamProject/Neurodactyl_2/FingerPrintScanner/lib/x64/fxISO_64.lib"
LIBS += "C:/TeamProject/Neurodactyl_2/FingerPrintScanner/lib/x64/fxISOenrdlg_64.lib"
LIBS += "C:/TeamProject/Neurodactyl_2/FingerPrintScanner/lib/x64/FingerPrintScannerDLL.lib"

win32-msvc*: QMAKE_LFLAGS += /DYNAMICBASE:NO
