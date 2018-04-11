/**
 * showodd.c -- реализует команду вывода нечетных строк данного файла
 *
 * Copyright (c) 2017, Kseniya Kuznetsova <kkuzneco@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <assert.h>
#include "common.h"
#include "text.h"

 void show_odd(int index, char *contents);

/**
 * Выводит нечетные строки документа
 */
void showodd(text txt)
{
    /* Вставляет курсор в текст */
 //   print_cursor(txt);
    /* Применяем функцию show_odd к каждой строке текста */
    process_forward(txt, show_odd);
    /* Удаляет курсор из текста */
   // remove_cursor(txt);
}

/**
 * Выводит нечетные строки документа
 */
void show_odd(int index, char *contents)
{
    /* Функция обработчик всегда получает существующую строку */
    assert(contents != NULL);

    /* Если у строки нечетный индекс*/
    if(index % 2) {
	/* Выводим строку на экран */
	printf("%s", contents);
    }
}
