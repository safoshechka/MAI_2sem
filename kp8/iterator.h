#ifndef ITERATOR_H
#define ITERATOR_H

#include "list.h"

typedef struct _listIterator{
    list_node *node;
} listIterator;

listIterator *iteratorCreate(list *lst);          // создание итератора
void iteratorNext(listIterator *it);              // получение следующего индекса элемента
list_node* iteratorGet(listIterator *it);         // получение значения
void iteratorSet(list_node* l, listIterator* it); // установка итератера в определёное состояние
void iteratorPrew(listIterator *it);              // получение предыдущего элемента 

#endif
