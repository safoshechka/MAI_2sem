#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "person.h"


void help(){
    printf("Выполняемые функции:\n");
    printf("-h - Вывод помощника\n");
    printf("-a - Запись данных\n");
    printf("-c - Создание файла\n");
    printf("-p - Печать файла\n");
    printf("-t - Выполнение варианта\n");
}

int main(int argc, char* argv[])
{    
    if (argc != 2) {
        printf("Ошибка, попробуйте ещё раз!\n");
        exit(1);
    }
    if (!strcmp(argv[1], "-h")) {
        help();
    } else if (!strcmp(argv[1], "-a")) { 
        add();
    } else if (!strcmp(argv[1], "-c")) {
	create();
    } else if (!strcmp(argv[1], "-p")) {
	print();
    } else if (!strcmp(argv[1], "-t")) {
	var32();
    } else {
	printf("Такой команды нет:с\n");
    }
    return 0;
}

