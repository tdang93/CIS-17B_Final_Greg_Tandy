TEMPLATE = app
#TARGET = Sorter_TCP-Client_UDP-Receiver

QT = core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    main.cpp \
    consumer.cpp \
    textedit.cpp \
    client.cpp

HEADERS += \
    consumer.h \
    textedit.h \
    client.h

FORMS += \
    textedit.ui
