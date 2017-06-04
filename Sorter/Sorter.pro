TEMPLATE = app
TARGET = CIS-17b_Final_Greg_Tandy

QT = core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    main.cpp \
    textedit.cpp \
    client.cpp

HEADERS += \
    textedit.h \
    client.h

FORMS += \
    textedit.ui
