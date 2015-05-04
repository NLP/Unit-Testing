##TEMPLATE = app
##CONFIG += console
##CONFIG -= app_bundle
###CONFIG -= qt
##CONFIG += c++11
##QT += sql
#TEMPLATE = app
#CONFIG += console
#QT     += core sql
#CONFIG -= app_bundle
#QMAKE_CXXFLAGS += -std=c++11

#CONFIG += c++11
#QT     += sql

#SOURCES += main.cpp \
#    ../../Grammatica/Syntax-Tree/parser.cpp \
#    ../../Grammatica/Syntax-Tree/syntaxtree.cpp \
#    ../../Grammatica/Syntax-Tree/syntaxword.cpp \
##    ../../Grammatica/Grammar Structure/Grammar-with-Map/cfgq.cpp \
#    ../../Grammatica/cfgq.cpp \
#    ../../Parser/Tagger/word.cpp \
#    ../../Parser/Tokenizer/stokenize.cpp \
#    ../../Parser/Tokenizer/token.cpp \
#    ../../Grammatica/cfgzero.cpp \
#    ../../Grammatica/grammar.cpp

#HEADERS += \
#    ../../Grammatica/Syntax-Tree/parser.h \
#    ../../Grammatica/Syntax-Tree/syntaxtree.h \
#    ../../Grammatica/Syntax-Tree/syntaxword.h \
##    ../../Grammatica/Grammar Structure/Grammar-with-Map/cfgq.h \
#    ../../Grammatica/cfgq.h \
#    ../../Parser/Tagger/converter.h \
#    ../../Parser/Tagger/word.h \
#    ../../Parser/Tokenizer/stokenize.h \
#    ../../Parser/Tokenizer/token.h \
#    ../../CONFIG/config.h \
#    ../../Grammatica/cfgzero.h \
#    ../../Grammatica/grammar.h
TEMPLATE = app
CONFIG += console
QT     += core sql
CONFIG -= app_bundle
QMAKE_CXXFLAGS += -std=c++11

CONFIG += c++11
QT     += sql

SOURCES += main.cpp \
    ../../Parser/Tokenizer/stokenize.cpp \
    ../../Parser/Tokenizer/token.cpp \
    ../../Parser/Tagger/word.cpp \
    ../../Grammatica/Syntax-Tree/parser.cpp \
    ../../Grammatica/Syntax-Tree/syntaxtree.cpp \
    ../../Grammatica/Syntax-Tree/syntaxword.cpp \
    ../../Grammatica/grammar.cpp \
    ../../Grammatica/cfgzero.cpp \
#    ../../Grammatica/Grammar Structure/Grammar-with-Map/cfgq.cpp \
    ../../Grammatica/cfgq.cpp

HEADERS += \
    ../../Parser/Tokenizer/stokenize.h \
    ../../Parser/Tokenizer/token.h \
    ../../Parser/Tagger/word.h \
    ../../Parser/Tagger/converter.h \
    ../../Grammatica/Syntax-Tree/parser.h \
    ../../Grammatica/Syntax-Tree/syntaxtree.h \
    ../../Grammatica/Syntax-Tree/Tree.h \
    ../../Grammatica/Syntax-Tree/syntaxword.h \
    ../../Grammatica/grammar.h \
    ../../Grammatica/cfgzero.h \
    ../../CONFIG/config.h \
#    ../../Grammatica/Grammar Structure/Grammar-with-Map/cfgq.h \
    ../../Grammatica/cfgq.h \
    ../../Granular-Extractor/Database/CorpusQueryGenerator.h \
    ../../Granular-Extractor/Database/OntologyDatabase.h

include(deployment.pri)
qtcAddDeployment()
