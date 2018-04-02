/**
 * j.c -- объединяет строку с курсором со следующей строкой
 *
 * Copyright (c) 2017, Kseniya Kuznetsova <kkuzneco@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include "_text.h"

void j (text txt){
    int i = 0, k=0;
    node *line = txt->cursor->line;
    /* Проверяем, не находится ли курсор на последней строке, в этом случае
     * выводим предупредительное соообщение*/
    if (txt -> cursor -> line == txt -> end) {
	printf("Can not be combined: the cursor is in the last line\n");
	return;
    }

    if(strlen(line ->contents)+strlen (txt -> cursor ->line -> next -> contents) > MAXLINE) {
	printf("Limit of line symbols\n");
	return;
    }
    /* Ищем конец строки*/
    while (line->contents[i]!='\n')
	i++;
    /* Вместо символа конца строки ставим пробел*/
    line->contents[i] = ' ';
    /* Копируем всю следующую строку в массив текущей строки*/
    while (txt-> cursor -> line -> next -> contents[k]!='\n'){
	line -> contents[i+1+k] = txt-> cursor -> line -> next -> contents[k];
	k++;
    }
    /* Заканчиваем строку*/
    line -> contents[i+1+k] = '\n';
    line -> contents[i+1+k+1] = '\0';
    /* Удаляем следующую строку*/
    delete_line(txt, currentline(txt)+1);
}
