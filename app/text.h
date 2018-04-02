/**
 * text.h -- внешний интерфейс библиотеки для работы с текстом
 *
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#ifndef TEXT_H
#define TEXT_H

#define MAXLINE 255

/**
 * Абстрактный тип текстовых объектов
 */
typedef struct _list *text;


/**
 * Создает новый текстовый объект
 * @returns текст
 */
text create_text();

/**
 * Добавляет одну строку к тексту
 * @param txt текст
 * @param contents новая строка
 * @returns none
 */
void append_line(text txt, const char *contents);

/**
 *
 * Удаляет строку
 *
 * @param txt текст
 * @returns код ошибки
 */
int delete_line(text txt, int index);

/**
 * Обрабатывает текст, применяя заданную функцию к каждой строке
 * 
 * @param txt текст
 * @param process функция-обработчик
 * @returns none
 */
void process_forward(text txt, void (*process)(int index, char *contents));
/**
 * Обрабатывает текст, применяя заданную функцию к каждой строке в обратном порядке
 * 
 * @param txt текст
 * @param process функция-обработчик
 * @returns none
 */
void process_backward(text txt, void (*process)(int index, char *contents));
/**
 * Обрабатывает текст, применяя заданную функцию к каждой строке
 *
 * @param txt текст
 * @param process функция-обработчик
 * @param *data доп-парамметр
 * @returns none
 */

void process_forward_extra_options(text txt, void (*process)(int index, char *contents,void *d), void *data);
/**
 * Удаляет весь текст
 * 
 * @param txt текст
 * @returns none
 */
void remove_all(text txt);

/**
 * Поставить курсор в линию line на позицию pos
 * @param txt текст
 * @param _line номер строки
 * @param pos позиция в строке
 * @returns код ошибки
 */
int c_to_pos(text txt, int line, int pos);

/**
 * Вставляем в текст курсор
 *
 * @param txt текст
 * @returns none
 *
 */
void print_cursor(text txt);


/**
 * Удаляем курсор из текста
 * 
 * @param txt текст
 * @returns none
 *
 */
void remove_cursor(text txt);

/**
 * Возвращает позицию курсора
 * 
 * @param txt текст
 * @returns позицию курсора
 */
int pos_return(text txt);

/**
 * Возвращает строку курсора
 * 
 * @param txt текст
 * @returns строку курсора
 */
struct _node *line_return(text txt);
/**
 * Возвращает ссылку на строку
 * 
 * @param txt текст
 * @param index индекс строки
 * @returns ref ссылка на строку
 */
struct _node *tracer(text txt, int index);

/**
 * Возвращает индекс строки курсора
 * @param txt
 * @return index
 *
 */
int currentline(text txt);

#endif
