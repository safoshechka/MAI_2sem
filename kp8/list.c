#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "list.h"
#include "iterator.h"


list* listCreate() // создание списка
{
    list *lst = (list*) malloc(sizeof(list));
    lst->head = (list_node*) malloc(sizeof(list_node));
    lst->head->next = NULL;
    lst->head->data = INT_MIN;
    lst->head->prew = NULL; 
    return lst;
}


void listPrint(list* lst) // печать списка
{
    listIterator *it = iteratorCreate(lst);
    printf("NULL--> ");
    if (it->node) {
        while (it->node != NULL) {
            if(it->node->data != INT_MIN) printf("%d --> ", it->node->data);
            it->node = it->node->next;
        }
        printf("NULL");
        printf("\n");
    }
}


void listInsert(list *lst, item data) // вставка элемента в конец списка
{
    listIterator *it = iteratorCreate(lst);
    if(it->node){
        while(it->node->next) 
        {
            iteratorNext(it);   
        }
        list_node *tail = (list_node*) malloc(sizeof(list_node));
        tail->next = NULL;
        tail->data = INT_MIN;
        tail->prew = it->node; 
        it->node->data = data;
        it->node->next = tail;
    } else printf("The list does not exist:ñ\n");
    free(it);
}


void listRemove(list *lst, item data) // удаление элемента из списка
{
    int flag = 0;
    listIterator *it = iteratorCreate(lst);
    list_node *prew;
    if(it->node){
        if(it->node->data == data && it->node->prew == NULL){  // Случай, когда удаляемый элемент - голова(первый)
            lst->head = it->node->next; 
            it->node->next->prew = NULL; 
                                         
            free(it->node);
            it->node = NULL;
        } else {
            while(it->node->next){                           
                if(it->node->data == data) // Случай, когда наш элемент между двумя блоками 
                {
                    it->node->prew->next = it->node->next;
                    it->node->next->prew = it->node->prew; 
                    free(it->node);
                    it->node = NULL;
                    flag = 1;
                    break;
                }
                iteratorNext(it);
            }
        if(!flag) printf("There is no such element!\n");
        }
    } else printf("The list does not exist:ñ\n");
    free(it);
}

int listLen(list *lst) // длина списка
{
    int count = 0;
    listIterator *it = iteratorCreate(lst);
    if(it->node){
        while(it->node->next && it->node->data != INT_MIN) 
        {
            count++;
            iteratorNext(it);
        }
    } else printf("The list does not exist\n");
    free(it);
    return count;
}

void deleteK(list *lst, int k) // функция варианта
{
    listIterator *it = iteratorCreate(lst);
    if(k > listLen(lst)){
        printf("There are fewer items in the list! Try again\n");
        return;
    }
    for(int i = 0; i < k; i++){
        iteratorSet(lst->head, it);               
        for(int j = 0; j < listLen(lst) / 2 - 1; j++)
            iteratorNext(it);                 
        if(listLen(lst) % 2 == 1 && listLen(lst) != 1) iteratorNext(it);
        listRemove(lst, it->node->data);
    }
}
