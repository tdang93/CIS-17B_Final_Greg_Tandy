QT += network widgets

HEADERS       = sender.h
SOURCES       = main.cpp \
                sender.cpp

# install
target.path = $$[QT_INSTALL_EXAMPLES]/network/broadcastsender
INSTALLS += target
