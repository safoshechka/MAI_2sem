#include "vector.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void vector_create(vector *v)
{
	v->size = 0;
	v->vals = NULL;
}

void vector_destroy(vector *v)
{
	free(v->vals);
	v->vals = 0;
	v->size = 0;
}

void vector_push_back(vector *v,elem e)
{
	v->size++;
	v->vals = realloc(v->vals, sizeof(elem) * v->size);
	v->vals[v->size-1] = e;
}

void vector_print(vector *v)
{
	printf("------------------------------------------------------\n");
	printf("|             ключ|                          значение|\n");
	printf("------------------------------------------------------\n");
	for(int i=0;i<v->size;i++)
		printf("|%17f|%34s|\n",v->vals[i].key,v->vals[i].strval);
	printf("------------------------------------------------------\n");
	printf("| Всего элементов: %33d |\n",v->size);
	printf("------------------------------------------------------\n");
}

void vector_swap(vector *v, int a, int b)
{
	elem t = v->vals[a];
	v->vals[a] = v->vals[b];
	v->vals[b] = t;
}

void linear_sort(vector* v)
{
	int i, j;
	int count[v->size];
	for( i = 0; i < v->size; i++)
		count[i] = 0;
	for( i = 0; i < v->size - 1; i++)
	{
		for( j = i + 1; j < v->size; j++)
		{
			if( v->vals[i].key < v->vals[j].key)
				count[j]++;
			else
				count[i]++;
		}
	}
	for(int i=0;i<v->size;i++)
	{
		if(i!=count[i])
		{
			for(int j=i+1;j<v->size;j++)
				if(i==count[j])
				{
					vector_swap(v, i, j);
					int t = count[i];
					count[i] = count[j];
					count[j] = t;
					break;
				}
		}
	}
}

int binary_search(vector *v, elem e)
{
	int left = 0;
	int right = v->size;
	while(left < right)
	{
		int mid = (left + right) / 2;
		if(v->vals[mid].key > e.key)
			right = mid;
		else if(v->vals[mid].key < e.key)
			left = mid + 1;
		else
			return mid;
	}
	return -1;
}

