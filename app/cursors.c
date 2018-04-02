/**
 * cursor.c -- реализует основные функции курсора
 *
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include "_text.h"

/**
 * Возвращает позицию курсора
 * 
 * @param txt текст
 * @returns позицию курсора
 */
int pos_return(text txt)
{
    return txt -> cursor -> position;
}


/**
 * Возвращает строку курсора
 * 
 * @param txt текст
 * @returns строку курсора
 */
node *line_return(text txt)
{
    return txt -> cursor -> line;
}

/**
 * Поставить курсор в линию line на позицию pos
 * @param txt текст
 * @param _line номер строки
 * @param pos позиция в строке
 * @returns код ошибки
 */
int c_to_pos(text txt, int _line, int pos){
    /* Если текста нет */
    if(txt -> begin == NULL) return 3;
    node *line = tracer(txt, _line);
    /* Если tracer не сработал */    
    if(line == NULL) return 1;
    /* Выход за пределы строки */
    if((pos > (signed)strlen(line -> contents)) || (pos < 0)) return 2;
    txt -> cursor -> line = line;
    txt -> cursor -> position = pos;
    return 0;
}

/**
 * Вставляем в текст курсор
 *
 * @param txt текст
 * @returns none
 *
 */
void print_cursor(text txt){
    int i;
    node *line = txt->cursor->line;
    /* Сдвиг части строки за курсором вправо */
    for(i = strlen(line->contents); i > txt->cursor->position; i--)
		line->contents[i]= line->contents[i - 1];

    (line->contents)[txt->cursor->position]='|';
}

/**
 * Удаляем курсор из текста
 * 
 * @param txt текст
 * @returns none
 *
 */
void remove_cursor(text txt){
    int i;
    node *line = txt->cursor->line;
    /* Сдвиг строки за курсором влево */
    for(i = txt->cursor->position; i < (signed)strlen(line->contents); i++)
	line->contents[i]= line->contents[i + 1];
}
