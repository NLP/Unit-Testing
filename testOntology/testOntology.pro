TEMPLATE = app
CONFIG += console
QT     += core sql
CONFIG -= app_bundle
QMAKE_CXXFLAGS += -std=c++11

SOURCES += main.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    ../../Granular-Extractor/Database/OntologyDatabase.h
    ../../CONFIG/config.h

