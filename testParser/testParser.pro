TEMPLATE = app
CONFIG += console
QT     += core sql
CONFIG -= app_bundle
QMAKE_CXXFLAGS += -std=c++11

SOURCES += main.cpp \
    ../../Parser/Tokenizer/stokenize.cpp \
    ../../Parser/Tokenizer/token.cpp \
    ../../Parser/Tagger/word.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    ../../Parser/Tokenizer/stokenize.h \
    ../../Parser/Tokenizer/token.h \
    ../../Parser/Tagger/word.h \
    ../../Parser/Tagger/converter.h \
    ../../CONFIG/config.h
