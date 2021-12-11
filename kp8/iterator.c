#include <stdlib.h>
#include <stdio.h>
#include "iterator.h"

listIterator *iteratorCreate(list *lst) // создание итератора
{
    if(lst != NULL){
        listIterator *it = (listIterator*) malloc(sizeof(listIterator));
        it->node = lst->head;
        return it;
    } else return NULL;
}

void iteratorNext(listIterator *it) // получение следующего индекса элемента
{
    if (it->node->next == NULL) 
    {
        printf("You've hit the last element!\n");
    } else {
        it->node = it->node->next;
    }
}

list_node* iteratorGet(listIterator *it) // получение значения
{
    return it->node;
}

void iteratorSet(list_node* lst, listIterator* it) // установка итератора в определёное состояние
{
    it->node = lst;
}

void iteratorPrew(listIterator *it) // получение предыдущего элемента
{
    if (it->node->prew == NULL) 
    {
        printf("You are in the first element, go to the next one!\n");
    } else {
        it->node = it->node->prew;
    }
}


