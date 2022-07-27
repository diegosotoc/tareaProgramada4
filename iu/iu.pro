QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    agregarformulario.cpp \
    main.cpp \
    mainwindow.cpp \
    modificarformulario.cpp

HEADERS += \
    agregarformulario.h \
    mainwindow.h \
    modificarformulario.h

FORMS += \
    agregarformulario.ui \
    mainwindow.ui \
    modificarformulario.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../libreria/release/ -llibreria
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../libreria/debug/ -llibreria
else:unix: LIBS += -L$$OUT_PWD/../libreria/ -llibreria

INCLUDEPATH += $$PWD/../libreria
DEPENDPATH += $$PWD/../libreria

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../libreria/release/liblibreria.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../libreria/debug/liblibreria.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../libreria/release/libreria.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../libreria/debug/libreria.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../libreria/liblibreria.a

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../libreria/release/ -llibreria
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../libreria/debug/ -llibreria
else:unix: LIBS += -L$$OUT_PWD/../libreria/ -llibreria

INCLUDEPATH += $$PWD/../libreria
DEPENDPATH += $$PWD/../libreria

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../libreria/release/liblibreria.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../libreria/debug/liblibreria.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../libreria/release/libreria.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../libreria/debug/libreria.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../libreria/liblibreria.a
