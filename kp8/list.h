#ifndef LIST_H
#define LIST_H


typedef int item;
typedef struct _list_node list_node;

typedef struct _list_node{ 
    item data;
    list_node *next;
    list_node *prew;
} list_node;

typedef struct{ 
    list_node *head;
} list;


list* listCreate(); // создание списка
void listPrint(list *l); // печать списка
void listInsert(list *lst, item data); // вставка элемента в конец списка
void listRemove(list *lst, item data); // удаление элемента из списка
int listLen(list *lst); // длина списка
void deleteK(list *lst, int k); // функция

#endif
