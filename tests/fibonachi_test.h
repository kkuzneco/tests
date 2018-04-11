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

void compare(char *originFile, char *producedFile) {
    char *file = (char *)malloc(sizeof(char)*1024);
    sprintf(file, "%s/%s", INPUTDIR, originFile);

    int fdOrigin = open(file, O_RDONLY);
    ASSERT_NE(fdOrigin, -1);

    int fdProduced = open(producedFile, O_RDONLY);
    ASSERT_NE(fdProduced, -1);

    char *bufferOrigin =(char *) malloc(512);
    char *bufferProduced =(char *) malloc(512);

    int readOrigin = 0;
    int readProduced = 0;
    do {
        readOrigin = read(fdOrigin, bufferOrigin, 512);
        readProduced = read(fdProduced, bufferProduced, 512);

        ASSERT_EQ(readOrigin, readProduced);

        for (int i = 0; i < readOrigin; i++) {
            ASSERT_EQ(bufferOrigin[i], bufferProduced[i]);
        }
    } while (readOrigin > 0);

    free(bufferOrigin);
    close(fdOrigin);
    close(fdProduced);
}

TEST(group1, test1){
    char txt[] = "nnni dfffd r e";
    show_odd(8, txt);
    SUCCEED();
}

TEST(group1, test2){
        char *file = (char *)malloc(sizeof(char)*1024);
        sprintf(file, "%s/text1.txt", INPUTDIR);

        //2.Создать файл для рез-та
        errno=0;
        int outFd = open("testOutput0.txt", O_WRONLY|O_CREAT|O_TRUNC, S_IRUSR|S_IWUSR);
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
        //

        //5. Закрыть поток, открыть рез-т, сравнить с оригиналом
        SUCCEED();
}
TEST(group1, test3){
    char *file = (char *)malloc(sizeof(char)*1024);
    sprintf(file, "%s/text2.txt", INPUTDIR);

    //2.Создать файл для рез-та
    errno=0;
    int outFd = open("testOutput2.txt", O_WRONLY|O_CREAT|O_TRUNC, S_IRUSR|S_IWUSR);
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

    compare((char *)"outputnoodd.txt",(char *) "testOutput2.txt");
}
TEST(group1, test4){
    char *file = (char *)malloc(sizeof(char)*1024);
    sprintf(file, "%s/text3.txt", INPUTDIR);

    //2.Создать файл для рез-та
    errno=0;
    int outFd = open("testOutput3.txt", O_WRONLY|O_CREAT|O_TRUNC, S_IRUSR|S_IWUSR);
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

    compare((char *)"outputnoodd.txt",(char *) "testOutput3.txt");
}
#endif
