/**
 * mcb.c -- осуществляет сдвиг курсора влево на один символ
 *
 * Copyright (c) 2017, Mihail Alekseev <maleksee@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include "_text.h"

/**
 * Перемещает курсор влево на один символ
 * 
 * @param txt текст
 */
void mcb(text txt)
{
    if (txt -> cursor -> position > 0)
	txt -> cursor -> position--;
    else
	printf("Cursor is at the beginning of the file");
}
