TEMPLATE = app

QMAKE_CC = gcc
QMAKE_CXX = gcc

QT += qml quick
CONFIG += c++17


SOURCES += main.cpp \
    app.cpp \
    chat.cpp \
    client.cpp \
    messagelistmodel.cpp \
    notificationservice.cpp \
    server.cpp \
    bytearray.cpp \
    usertable.cpp \
    utils.cpp \
    chatroom.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    app.h \
    chat.h \
    client.h \
    collectioninterfaces.h \
    iobserver.h \
    messagelistmodel.h \
    notificationservice.h \
    server.h \
    imessagehandler.h \
    ibytearray.h \
    ipackage.h \
    serverstate.h \
    bytearray.h \
    types.h \
    usertable.h \
    utils.h \
    chatroom.h

