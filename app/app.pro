TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    showodd.c \
    cursors.c \
    delete_line.c \
    j.c \
    mcb.c \
    mp.c \
    process_backward.c \
    process_forward.c \
    remove_all.c \
    tracer.c \
    myfunc.c \
    main.c \
    load.c \
    create_text.c \
    append_line.c


HEADERS += \
    myfunc.h \
    common.h \
    text.h \
    _text.h

QMAKE_CFLAGS += -Wall -Wextra -Werror

# gcov
QMAKE_CFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov

DISTFILES += \
    text.txt \
    text.txt
