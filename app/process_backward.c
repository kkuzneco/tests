/**
 * process_backward.c -- реализует обобщенную функцию обработки текста
 *
 * Copyright (c) 2017, Mihail Alekseev <maleksee@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include "_text.h"

/**
 * Обрабатывает список, применяя заданную функцию к каждой строке
 * 
 * @param txt текст
 * @param process функция-обработчик
 * @returns none
 */
void process_backward(text txt, void (*process)(int index, char *contents))
{   
    /* Проверяем, имеется ли текст */
    if (txt == NULL || txt->length == 0) {
        fprintf(stderr, "There are already no any lines in the text!\n");
        return;
    } 
    
    /* Текст ненулевой длины должен содержать хотя бы одну строку */
    assert(txt->begin != NULL && txt->end != NULL);
    
    /* Стартуем с последней строки текста */
    node *current = txt->end;
    int index = 0;
    while(current){
	/* К каждой строке текста применяем обработчик */
	process(index, current->contents);
	current = current->previous;
        index++;
    }
}
