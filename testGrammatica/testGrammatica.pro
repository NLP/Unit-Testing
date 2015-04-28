TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
#CONFIG -= qt

CONFIG += c++11
QT += sql

# NOTE:
# ../../ is NLP/
#

SOURCES += main.cpp \
    ../../Grammatica/Syntax-Tree/parser.cpp \
    ../../Grammatica/Syntax-Tree/syntaxtree.cpp \
    ../../Grammatica/Syntax-Tree/syntaxword.cpp \
    ../../Parser/Tagger/word.cpp \
    ../../Parser/Tokenizer/token.cpp \
    ../../Grammatica/grammar.cpp \
    ../../Grammatica/cfgzero.cpp
#    ../../Grammar Structure/Grammar-with-Map/cfgzero.cpp \

HEADERS += \
    ../../Grammatica/Syntax-Tree/parser.h \
    ../../Grammatica/Syntax-Tree/syntaxtree.h \
    ../../Grammatica/Syntax-Tree/Tree.h \
    ../../Grammatica/Syntax-Tree/syntaxword.h \
    ../../Parser/Tagger/word.h \
    ../../Parser/Tokenizer/token.h \
    ../../CONFIG/config.h \
    ../../Grammatica/grammar.h \
    ../../Grammatica/cfgzero.h
#    ../../Grammar Structure/Grammar-with-Map/cfgzero.h \
