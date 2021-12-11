#ifndef PERSON_H
#define PERSON_H 

typedef struct _Person {
	char FullName[60];  // ФИО
	int items;          // Кол-во вещей
	int weight;         // Общий вес вещей 
	char dest[30];      // Пункт назначения
	char time[5];       // Время вылета
	int trans;          // Наличие пересадок
	int child;          // Сведения о детях
} Person;

void create(); 
void print();
void var32();
void add();

#endif


