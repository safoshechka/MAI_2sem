#ifndef DEQUE_H_INCLUDED
#define DEQUE_H_INCLUDED


#include <stdio.h>

typedef struct deque{
    int *elements; // элементы
    int capacity;  // вместимость
    int number_of_elements; // размер
} deque;

void deque_create(deque *a); // создание дека
int deque_is_empty(deque *a); // проверка на пустоту
void resize(deque *a); // увеличивает размер на 1
void deque_push_front(deque *a, int b); // вставка элемента в начало
void deque_push_back(deque *a, int b); // вставка элемента в конец
void deque_pop_front(deque *a); // взятие и как бы удаление элемента в начале
void deque_pop_back(deque *a); // взятие и как бы удаление элемента в конце
void deque_print(deque *a); // печать дека
int deque_size( deque *a); // возвращает размер
void deque_insert_index(deque *a, int b, int index); // вставка элемента по индексу
void deque_erase(deque *a, int index); // удаление элемента по индексу

#endif // DEQUE_H_INCLUDED
