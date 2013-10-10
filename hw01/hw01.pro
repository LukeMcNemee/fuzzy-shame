TEMPLATE = app
CONFIG += console
CONFIG -= qt

SOURCES += \
    ascii85.c

QMAKE_CFLAGS += -std=c99 -pedantic -Wall -Wextra
