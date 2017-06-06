QT += network widgets
QT += network widgets core

HEADERS       = server.h \
    tcpportsender.h
SOURCES       = server.cpp \
                main.cpp \
    tcpportsender.cpp

# install
target.path = $$[QT_INSTALL_EXAMPLES]/network/fortuneserver
INSTALLS += target

# install
target.path = $$[QT_INSTALL_EXAMPLES]/network/broadcastsender
INSTALLS += target
