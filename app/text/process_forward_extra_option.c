/**
 * process_forward_extra_option.c -- реализует обобщенную функцию обработки текста с дополнительным параметром
 *
 * Copyright (c) 2017, Artur Harkovchuk  <harkovch@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include "_text.h"

/**
 * Обрабатывает список, применяя заданную функцию к каждой строке
 *
 * @param txt текст
 * @param process функция-обработчик
 * @param *data доп-парамметр
 * @returns none
 */
void process_forward_extra_options(text txt, void (*process)(int index, char *contents,void *f), void *data)
{
    /* Проверяем, имеется ли текст */
    if (txt == NULL || txt->length == 0) {
        fprintf(stderr, "There are already no any lines in the text!\n");
        return;
    }

    /* Текст ненулевой длины должен содержать хотя бы одну строку */
    assert(txt->begin != NULL && txt->end != NULL);

    /* Стартуем с начальной строки текста */
    node *current = txt->begin;
    int index = 0;
    while(current){
        /* К каждой строке текста применяем обработчик */
        process(index, current->contents,data);
        current = current->next;
        index++;
    }
}

