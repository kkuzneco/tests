/**
 * common.h -- прототипы функций реализации команд редактора
 *
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#ifndef COMMON_H
#define COMMON_H

#include "text.h"

/* Декларирует неиспользуемый аргумент,
 * корректно подавляя предупреждение вида "unused parameter" */
#define UNUSED(x) (void)(x)

/**
 * Выводит содержимое указанного файла на экран
 */
void show(text txt);

/**
 * Выводит содержимое указанного файла на экран и нумерует
 */
void shownum(text txt);

/**
 * Сохраняет в указанный файл
 */

void save(text txt,  char *f);
/**
 * Загружает содержимое указанного файла
 */
void load(text txt, char *filename);

/**
 * Выводит содержимое файла на экран в обратном порядке
 */

void showrev(text txt);

/**
 * Перемещает курсор на один символ влево
 */

void mcb(text txt);

/**
 * Удаляет последнюю строку
 */

/**
 * перемещает курсор в текущей строке на заданную позицию
 */
int r_in_cur(text txt, int cpos);

/**
 * Выводит нечетные строки файла
 */
void showodd(text txt);

/**
 * Соединяет строку с курором со следующей
 */
void j (text txt);

void show_odd(int index, char *contents);

#endif
