#ifndef FIBONACHI_H
#define FIBONACHI_H

#include <gtest/gtest.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

extern "C" {
#include "common.h"
}

#define STDIN 0
#define STDOUT 1

TEST(group1, test1){
    char txt[] = "nnni dfffd r e";
    show_odd(8, txt);
    SUCCEED();
}

TEST(group1, test2){
        char *file = (char *)malloc(sizeof(char)*1024);
        sprintf(file, "%s/text.txt", INPUTDIR);

        //2.Создать файл для рез-та
        errno=0;
        int outFd = open("testOutput.txt", O_WRONLY|O_CREAT|O_TRUNC, S_IRUSR|S_IWUSR);
        if (outFd < 0)
            ASSERT_EQ(errno, 0);
        int oldOutput = dup(1);
        dup2(outFd, 1);
        ASSERT_EQ(errno, 0);
        close(outFd);


        //4.Запустить show_odd
        text txt = create_text();
        load (txt, file);
        showodd(txt);

        fflush(stdout);
        dup2(oldOutput, 1);

        //5. Закрыть поток, открыть рез-т, сравнить с оригиналом
        SUCCEED();
}

#endif
