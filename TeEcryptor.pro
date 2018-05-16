#-------------------------------------------------
#
# Project created by QtCreator 2018-05-15T09:58:48
#
#-------------------------------------------------

QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++1z static

TARGET = TeEcryptor
TEMPLATE = app

INCLUDEPATH += /usr/local/ssl/include
LIBS += /usr/local/ssl/lib/libssl.a
LIBS += /usr/local/ssl/lib/libcrypto.a
LIBS += -ldl

SOURCES += main.cpp\
        mainwindow.cpp \
    fileEcryptionForm.cpp \
    plainTextEncryptionForm.cpp \
    tecipher.cpp

HEADERS  += mainwindow.hpp \
    fileEcryptionForm.hpp \
    plainTextEncryptionForm.hpp \
    tecipher.hpp

FORMS    += mainwindow.ui \
    fileecryptionform.ui \
    plaintextencryptionform.ui
