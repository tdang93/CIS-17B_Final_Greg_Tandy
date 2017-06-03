QT += network widgets

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

DISTFILES +=
