TEMPLATE = app

CONFIG += c++11

QT += qml quick widgets

SOURCES += src/desktop/main.cpp \
    src/common/boardmodel.cpp \
    src/common/boardlistmodelwrapper.cpp \
    src/common/abstractboardcontroller.cpp \
    src/common/moveAnalysis.cpp

RESOURCES += qml/qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    src/common/boardmodel.h \
    src/common/boardlistmodelwrapper.h \
    src/common/abstractboardcontroller.h
