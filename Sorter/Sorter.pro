TEMPLATE = app
TARGET = CIS-17b_Final_Greg_Tandy

QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    main.cpp \
    textedit.cpp \
    consumer.cpp \
    producer.cpp

HEADERS += \
    textedit.h \
    consumer.h \
    producer.h

FORMS += \
    textedit.ui
