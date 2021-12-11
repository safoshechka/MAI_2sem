#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "person.h"

void create(){
    char FileName[17];
    FILE * f;
    printf("Введите имя файла\n");
    scanf("%s", FileName);
    f = fopen(FileName, "rb");
    if(f != NULL) {
        printf("Файл уже существует\n");
    } else {
        f = fopen(FileName, "ab");
    }
    fclose(f);
}

void print(){
    Person p1;
    char FileName[17];
    FILE * f;
    printf("Введите имя файла\n");
    scanf("%s", FileName);
    f = fopen(FileName, "rb");
    if(f == NULL) {
        printf("Файл не существует\n");
    } else {
        printf("+----------------------------------------------+------+-----+------------------+--------------+-------------------+--------------------+\n");
        printf("|                    ФИО                       | Вещи | Вес | Пункт назначения | Время вылета | Наличие пересадок | Информация о детях |\n");
        printf("+----------------------------------------------+------+-----+------------------+--------------+-------------------+--------------------+\n");

        while (fread(&p1, sizeof(Person), 1, f) == 1)
        {
            printf("|%46s|%6d|%5d|%18s|%14s|%19d|%20d|\n",
            p1.FullName,
            p1.items,
            p1.weight,
            p1.dest,
            p1.time,
            p1.trans,
            p1.child);
            printf("+----------------------------------------------+------+-----+------------------+--------------+-------------------+--------------------+\n");
        }
    }
    fclose(f);
}
void var32() {
    Person p1;
    char FileName[17];
    FILE * f;
    printf("Введите имя файла\n");
    scanf("%s", FileName);
    f = fopen(FileName, "rb");
    if(f == NULL) {
        printf("Файл не существует\n");
    } else {
        int p;
        printf("Введите p:\n");
        scanf("%d", &p);
        int max = 0;
        while (fread(&p1, sizeof(Person), 1, f) == 1)
        {
            if(max < p1.weight){
                max = p1.weight;
            }
        }
        fseek(f, SEEK_SET, 0);
        while (fread(&p1, sizeof(Person), 1, f) == 1)
        {
            if((max - p1.weight < p) && (max - p1.weight != 0)){
                printf("%s\n", p1.FullName);
            }
        }
    }
    fclose(f);
}

void add()
{
    Person p1;
    char FileName[17];
    FILE * f;
    printf("Введите имя файла\n");
    scanf("%s", FileName);
    f = fopen(FileName, "rb");
    if(f == NULL) {
        printf("Файл не существует\n");
    } else {
        f = fopen(FileName, "ab");
        getc(stdin);
        printf("Введите ФИО:\n");
        scanf("%[^\n]", p1.FullName);
        printf("Введите количество вещей:\n");
        scanf("%d", &p1.items);
        printf("Введите общий вес вещей:\n");
        scanf("%d", &p1.weight);
        printf("Введите пункт назначения:\n");
        scanf("%s", p1.dest);
        printf("Введите время вылета:\n");
        scanf("%s", p1.time);
        printf("Введите налиие пересадок:\n");
        scanf("%d", &p1.trans);
        printf("Введите сведения о детях (их количество):\n");
        scanf("%d", &p1.child);
        fwrite(&p1, sizeof(Person), 1, f);
    }
    fclose(f);
}






