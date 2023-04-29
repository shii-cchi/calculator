QT       += core gui
QT       += charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    calculator.cpp \
    credit.cpp \
    custom_axis.cpp \
    graph.cpp \
    main.cpp \
    calc.c \
    pars.c \
    credit_calc.c \
    stack.c

HEADERS += \
    calculator.h \
    credit.h \
    custom_axis.h \
    graph.h \
    calc.h \
    pars.h \
    credit_calc.h \
    stack.h

FORMS += \
    calculator.ui \
    credit.ui \
    custom_axis.ui \
    graph.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
