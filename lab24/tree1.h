#ifndef TREE_H
#define TREE_H

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef char* Item;

typedef struct tnode tnode;

struct tnode {
    Item data;
    tnode *childs;
    tnode *next;
};

tnode *tree_create(Item); // создание дерева
void tree_destroy(tnode*); // удаление дерева
void tree_add_node(tnode* a,tnode* b); // добавление к одной €чейке другую €чейку
void tree_add(tnode*,Item); // добавление ребЄнка к €чейке
tnode *tree_find(tnode*,Item); // поиск €чейки
void tree_delete(tnode*,tnode*); // удаление ребЄнка
void tree_print(tnode*); // вывод дерева

#endif

