/**
 * delete_line.c -- функции для удаления строки
 * 
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include "_text.h"
#include "text.h"

/**
 *
 * Удаляет строку
 *
 * @param txt текст
 * @returns код ошибки
 */
int delete_line(text txt, int index){
    
    /* Выход за пределы списка */
    if((index < 0) || ((unsigned)index >= txt->length))
	return 1;
    /* Если есть только одна строчка, удаляем весь текст */
    if (txt->length == 1){
	remove_all(txt);
	return 0;
    }
    
    node* line = tracer(txt, index);
        
    /* Устанавливаем курсор в конец предыдущей строки */
    if(line == txt->cursor->line){
	if(line != txt->end)
	    txt->cursor->line = txt->cursor->line->next;
	else
	    txt->cursor->line = txt->cursor->line->previous;
	txt->cursor->position = 0;
    }
    if(line == txt->end){
	txt->end = txt->end->previous;
	txt->end->next = NULL;
    }
    else if(line == txt->begin){
	txt->begin = txt->begin->next;
	txt->begin->previous = NULL;
    }
    else{
	line->next->previous = line->previous;
	line->previous->next = line->next;
    }
    txt->length--;
    return 0;
}

