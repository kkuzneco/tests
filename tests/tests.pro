include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

QMAKE_CXXFLAGS += -Wall -Wextra -Werror
QMAKE_CFLAGS += -Wall -Wextra -Werror

# gcov
QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage
QMAKE_CFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov

DEFINES +=INPUTDIR=\\\"$$PWD/tests\\\"

HEADERS +=     tst_test1.h \
    fibonachi_test.h \
../app/text.h

SOURCES +=     main.cpp \
    ../app/myfunc.c \
../app/showodd.c \
../app/cursors.c\
../app/process_forward.c \
../app/tracer.c \
../app/load.c \
../app/create_text.c \
../app/append_line.c \
../app/remove_all.c

INCLUDEPATH += ../app
