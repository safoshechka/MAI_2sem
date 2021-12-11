#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "iterator.h"



void print_menu() {
    printf("\nOur function:\n");
    printf("-a - Adding an item\n");
    printf("-p - Printing our list\n");
    printf("-r - Removing from the list\n");
    printf("-l - List length\n");
    printf("-d - Completing our task\n");
    printf("-b - Exit\n");
}

int main(void)
{
    item data;
    list *lst = listCreate();
    listIterator *it = iteratorCreate(lst);
    int k;
    char c;
    print_menu();
    while ((c = getchar()) != EOF) {
        iteratorSet(lst->head,it);
        if (c == '\n' && c == ' ') continue;
        switch (c) {
        case 'a':
            printf("Enter the item you want to add: ");
            scanf("%d", &data);
            listInsert(lst, data);
            break;
        case 'p':
            listPrint(lst);
            break;
        case 'r':
            printf("Enter the item you want to remove: ");
            scanf("%d", &data);
            listRemove(lst, data);
            break;
        case 'l':
            printf("%d", listLen(lst));
            break;
        case 'd':
            printf("Enter k: ");
            scanf("%d", &k);
            deleteK(lst, k);
            break;
        case 'b':
            printf("\nSee you on your next assignment:)\n");
            free(it);
            free(lst);
            return 0;
        default:
            printf("Wrong! Try again!!!\n");
            break;
        }
        print_menu();
    }
}
