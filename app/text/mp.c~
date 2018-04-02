/**
 * mp.c -- перемещает курсор в текущей строчке на заданную позицию
 *
 * Copyright (c) 2017, Kseniya Kuznetsova <kkuzneco@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include "_text.h"

int r_in_cur(text txt, int cpos){
    /* Если текста нет */
    int _line = currentline(txt);
    if(txt -> begin == NULL) return 3;
    node *line = tracer(txt, _line);
    /* Если tracer не сработал */
    if(line == NULL) return 1;
    /* Выход за пределы строки */
    if((cpos > (signed)strlen(line -> contents)) || (cpos < 0)) return 2;
    txt -> cursor -> line = line;
    txt -> cursor -> position = cpos;
    return 0;
}
