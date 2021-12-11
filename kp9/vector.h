#ifndef vector_h
#define vector_h

#include <stdlib.h>
#include <stdio.h>

typedef struct elem
{
	float key;
	char strval[32];
} elem;

typedef struct vector
{
	int size;
	elem* vals;
} vector;

// создание вектора
void vector_create(vector *v);
// удаление вектора
void vector_destroy(vector *v);
// добавление элемента в конец вектора
void vector_push_back(vector *v,elem e);
// распечатка таблицы
void vector_print(vector *v);
// отсортировать вектор методом линейного выбора и подсчета
void linear_sort(vector* v);
// поменять элементы с индексами A и B местами
void vector_swap(vector *v, int a, int b);
// найти индекс элемента бинарным поиском
int binary_search(vector *v, elem e);

#endif

