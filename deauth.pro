######################################################################
# Automatically generated by qmake (3.1) Sun May 19 16:55:40 2024
######################################################################

TEMPLATE = app
TARGET = deauth
INCLUDEPATH += .

# You can make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# Please consult the documentation of the deprecated API in order to know
# how to port your code away from it.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


# Define the CONFIG variable
CONFIG += console
CONFIG -= app_bundle

# Define the C++ standard
QMAKE_CXXFLAGS += -std=c++11

# Include the pthread library
LIBS += -lpthread

# Define the source files
SOURCES += deauth.cpp

# Add additional compiler flags
QMAKE_CXXFLAGS += -Wall