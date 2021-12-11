#include <stdio.h>
#include "vector.h"

int main()
{
	vector v;
	char name_of_keys_file[50];
	char name_of_vals_file[50];
	printf("Введите имя файла с ключами: ");
	scanf(" %s", name_of_keys_file);
	printf("Введите имя файла с значениями: ");
	scanf(" %s", name_of_vals_file);
	FILE *fk;
	fk = fopen(name_of_keys_file, "r");
	FILE *fv;
	fv = fopen(name_of_vals_file, "r");
	vector_create(&v);
	elem el;
	while(fscanf(fk,"%f\n",&(el.key))==1 && fscanf(fv,"%s\n",el.strval)==1)
		vector_push_back(&v,el);
	printf("\nДо сортировки:\n");
	vector_print(&v);
	printf("\nПосле сортировки:\n");
	linear_sort(&v);
	vector_print(&v);
	int w;
	printf("\nВведите количество искомых элементов методом бин. поиска: ");
	scanf("%d", &w);
	for(int i = 0; i < w; i++)
	{
		printf("Введите ключ искомого элемента: ");
		elem se;
		scanf("%f",&(se.key));
		int idx = binary_search(&v,se);
		if(idx == -1)
			printf("элемент с заданным ключом не найден\n");
		else
			printf("найденный элемент: %s\n",v.vals[idx].strval);
	}
	vector_destroy(&v);
	return 0;
}

