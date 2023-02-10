TEMPLATE     = vcapp
TARGET       = testGraphicusGUI
CONFIG      += warn_on debug qt windows console
HEADERS     += monInterface.h
SOURCES     += testGraphicusGUI.cpp monInterface.cpp
INCLUDEPATH += .\GraphicusGUI
LIBS        += .\GraphicusGUI/graphicusGUI.lib
QT          += widgets
