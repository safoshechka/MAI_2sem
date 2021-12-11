#ifndef _vector_h
#define _vector_h

typedef struct { // динамический массив
    int* data;
    int size;
} Vector;

void vectorResize(Vector* v); // Изменить размер
void vectorPush(Vector* v,int val,int index); // Поместить элемент
void vectorInit(Vector* v,int size); // Инициализация
int vectorGetByIndex(Vector* v, int index); // Получить элемент по индексу
void vectorDestroy(Vector* v); // Уничтожить массив
void vectorPrint(Vector* v, int m); // Распечатать вектор

#endif
