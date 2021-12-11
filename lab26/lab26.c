#include <stdio.h>
#include <string.h>
#include "deque.h"

int main(int argc,char *argv[])
{
	printf(
	"Справка:\n"
	"puf n - добавить n в начало\n"
	"pub n - добавить n в конец\n"
	"pof - вытащить элемент с начала\n"
	"pob - вытащить элемент с конца\n"
	"size - вывести размер дэка\n"
	"empty - проверить дэк на пустоту\n"
	"insidx n i - вставить элемент n по индексу i\n"
	"del i - удалить элемент по индексу i\n"
	"print - распечатать дэк\n"
	"sort - отсортировать дэк\n"
	"task - выполнить задание 4\n"
	"exit - выход\n"
	);
	deque deq;
	deque_create(&deq);
	char inp[32];
	int n1,n2;
	while(1)
	{
		scanf("%s",inp);
		if(strcmp(inp,"puf")==0)
		{
			scanf("%d\n",&n1);
			deque_push_front(&deq,n1);
		}
		else if(strcmp(inp,"pub")==0)
		{
			scanf("%d\n",&n1);
			deque_push_back(&deq,n1);
		}
		else if(strcmp(inp,"pof")==0)
			printf("%d\n",deque_pop_front(&deq));
		else if(strcmp(inp,"pob")==0)
			printf("%d\n",deque_pop_back(&deq));
		else if(strcmp(inp,"size")==0)
			printf("Размер: %d\n",deq.number_of_elements);
		else if(strcmp(inp,"empty")==0)
			printf(deque_is_empty(&deq) ? "Очередь пуста\n":"Очередь не пуста\n");
		else if(strcmp(inp,"insidx")==0)
		{
			scanf("%d %d\n",&n1,&n2);
			deque_insert_index(&deq,n1,n2);
		}
		else if(strcmp(inp,"del")==0)
		{
			scanf("%d\n",&n1);
			deque_erase(&deq,n1);
		}
		else if(strcmp(inp,"print")==0)
			deque_print(&deq);
		else if(strcmp(inp,"sort")==0)
			deque_sort(&deq);
		else if(strcmp(inp,"task")==0)
			deque_task(&deq);
		else if(strcmp(inp,"exit")==0)
			break;
	}
	printf("До встречи!\n");
	deque_destroy(&deq);
    return 0;
}

