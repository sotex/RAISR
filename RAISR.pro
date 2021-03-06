######################################################################
# Automatically generated by qmake (3.0) ?? 2? 14 13:36:31 2019
######################################################################

QT       += core gui widgets

TEMPLATE = app
TARGET = RAISR

# Input
HEADERS += HashBuckets.h    \
           RAISR.h          \
    raisrwidget.hpp

SOURCES += HashBuckets.cpp  \
           main.cpp         \
           RAISR.cpp        \
           raisrwidget.cpp

win32:!win32-g++: {
    QMAKE_CFLAGS_DEBUG += -MDd
    QMAKE_CXXFLAGS_DEBUG += -MDd

    INCLUDEPATH += $$PWD/../../../development_library/vcpkg/installed/x64-windows/include
    DEPENDPATH += $$PWD/../../../development_library/vcpkg/installed/x64-windows/include

    CONFIG(release, debug|release):{
        LIBS += -L$$PWD/../../../development_library/vcpkg/installed/x64-windows/lib/ -lopencv_highgui343 -lopencv_imgproc343 -lopencv_imgcodecs343 -lopencv_core343
    } else:win32:CONFIG(debug, debug|release):{
        LIBS += -L$$PWD/../../../development_library/vcpkg/installed/x64-windows/debug/lib/ -lopencv_highgui343d -lopencv_imgproc343d -lopencv_imgcodecs343d -lopencv_core343d
    }
} else:unix:!macx: {
    INCLUDEPATH += /usr/include/opencv3
    DEPENDPATH += /usr/include/opencv3

    LIBS += -lopencv_highgui -lopencv_imgproc -lopencv_imgcodecs -lopencv_core
}

FORMS += \
    raisrwidget.ui
