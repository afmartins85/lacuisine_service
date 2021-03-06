QT -= gui

QT += sql

CONFIG += c++11 console
CONFIG -= app_bundle

include(gsoap/gsoap.pri)

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS \
           WITH_OPENSSL

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        authentication.cpp \
        databaseConnection.cpp \
        gsoapserverthread.cpp \
        loguru.cpp \
        main.cpp \
        operation.cpp \
        qutilitytools.cpp \
        simplecrypt.cpp \
        soapservice.cpp \
        userdata.cpp

TRANSLATIONS += \
    lacusineServer_pt_BR.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    authentication.h \
    databaseConnection.h \
    gsoapserverthread.h \
    loguru.hpp \
    operation.h \
    qutilitytools.h \
    simplecrypt.h \
    soapservice.h \
    userdata.h

OTHER_FILES += \
    gsoap/generate/common.xsd \
    gsoap/generate/lacuisine.wsdl \
    gsoap/generate/service.wsdl

LIBS += -lssl -lcrypto -ldl

target.path = /root/lacuisineServer
INSTALLS += target
