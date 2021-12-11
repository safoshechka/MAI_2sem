#include "deque.h"
#include <stdlib.h>

void swap(int *a, int *b) // ������ ������� ��������
{
    int t = *a;
    *a = *b;
    *b = t;
}

void deque_create(deque *a){ // �������� ����
    a->elements =  malloc(sizeof(int));
    a->capacity = 1;
    a->number_of_elements = 0;
}

void deque_destroy(deque *a){ // �������� ����
    if(a->elements)
        free(a->elements);
}

int deque_is_empty(deque *a){ // �������� �� ������������� ���� (�� �������)
    return (a->number_of_elements == 0) ? 1 : 0;
}

void resize(deque *a){ // ����������� ������ �� ����
    a->capacity++;
    a->elements = realloc(a->elements, a->capacity * sizeof(int));
}

void deque_push_front(deque *a, int b){ // ������� �������� � ������
    if(a->number_of_elements == a->capacity){
        resize(a);
    }
    int tmp_1, tmp_2;
    tmp_1 = b;
    for(int i = 0; i < a->number_of_elements + 1; i++){
        tmp_2 = a->elements[i];
        a->elements[i] = tmp_1;
        tmp_1 = tmp_2;
    }
    a->number_of_elements++;
}

void deque_push_back(deque *a, int b){ // ������� �������� � �����
    if(a->number_of_elements == deque_size(a)){
        resize(a);
    }
    a->elements[a->number_of_elements] = b;
    a->number_of_elements++;
}

void deque_print(deque *a){ // ������ ����
    if(a->number_of_elements == 0){
        printf("Deque is already empty!\n");
        return;
    }
    for(int i = 0; i < a->number_of_elements; i++){
        if(i != a->number_of_elements - 1){
            printf("[%d] -> ", a->elements[i]);
        } else {
            printf("[%d]\n",a->elements[i]);
        }
    }
}

int deque_size(deque *a){ // �����������
    return a->capacity;
}

int deque_pop_back(deque *a){  // ������ � ��� �� �������� � �����
    if(a->number_of_elements > 0){
        int val = a->elements[a->number_of_elements-1];
        a->elements[a->number_of_elements] = 0;
        a->number_of_elements--;
        return val;
    } else {
        printf("Error deque is already empty!\n");
        return -1;
    }
}

int deque_pop_front(deque *a){ // ������ � ��� �� �������� � ������
    if(a->number_of_elements > 0){
        int val = a->elements[0];
        for(int i = 0; i < a->number_of_elements - 1; i++){
            a->elements[i] = a->elements[i + 1];
        }
        a->elements[a->number_of_elements - 1]= 0;
        a->number_of_elements--;
        return val;
    } else {
        printf("Error deque is already empty!\n");
        return -1;
    }
}

void deque_erase(deque *a, int index){ // �������� �������� �� �������
    if(a->number_of_elements > 0){
        for(int i = index; i < a->number_of_elements - 1; i++){
            a->elements[i] = a->elements[i + 1];
        }
        a->elements[a->number_of_elements - 1]= 0;
        a->number_of_elements--;
    } else {
        printf("Error deque is already empty!\n");
    }
}

void deque_insert_index(deque *a, int b, int index){ // ���������� �������� �� �������
    if(a->number_of_elements == a->capacity){
        resize(a);
    }
    int tmp_1, tmp_2;
    tmp_1 = b;
    for(int i = index; i < a->number_of_elements + 1; i++){
        tmp_2 = a->elements[i];
        a->elements[i] = tmp_1;
        tmp_1 = tmp_2;
    }
    a->number_of_elements++;
}

void deque_sort(deque *a){
    for(int i = 1; i < a->number_of_elements; i++)
    {
        for(int j = i; j > 0; j--)
        {
            if(a->elements[j] < a->elements[j - 1])
                swap(&(a->elements[j]), &(a->elements[j - 1]));
            else
                break;
        }
    }
}

void deque_task(deque *a){
    for(int i = 1; i < a->number_of_elements; i++)
        if(a->elements[i] < a->elements[i - 1])
        {
            swap(&(a->elements[i]), &(a->elements[i - 1]));
            break;
        }
}
