#include <stdio.h>
#include "tree.h"


void print_menu() {
    printf("\nСписок команд:)\n");
    printf("+ - Добавить элемент в дерево\n");
    printf("p - Печать дерева\n");
    printf("d - Удаление элемента из дерева\n");
    printf("t - Выполнение задания\n");
    printf("h - Вывод высоты дерева\n");
    printf("0 - Выход\n");

}


int main(void)
{
    Tree *t = NULL;
    int value, father;
    char c;
    print_menu();
    while ((c = getchar()) != EOF) {
        value = 0;
        father = 0;
        if (c == '\n') continue;
        switch (c) {
        case '+':
            printf("\nНапишите значение и 'отца', к которому хотите добавить");
            scanf("%d %d", &value, &father);
            t = tree_add_element(t, father, value);
            break;
        case 'p':
            tree_print(t, 1);
            break;
        case 'd':
           printf("\nВведите элемент, который хотите удалить");
            scanf("%d", &value);
            delete_node_interface(&t, value);
            break;
        case 't':
            printf("\n Уровень дерева, на котором максимальное число вершин: %d", task_var34(t));
            break;
        case 'h':
            printf("Высота дерева: %d", height(t));
            break;
        case '0':
            printf("\n До встречи в следующей лабе! \n");
            return 0;
        default:
            printf("А такое мы не умеем:с\n");
            break;
        }
        print_menu();
    }
    destroy(t);
}
