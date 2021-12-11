#ifndef DEQUE_H_INCLUDED
#define DEQUE_H_INCLUDED


#include <stdio.h>

typedef struct deque{
    int *elements; // ��������
    int capacity;  // �����������
    int number_of_elements; // ������
} deque;

void deque_create(deque *a); // �������� ����
int deque_is_empty(deque *a); // �������� �� �������
void resize(deque *a); // ����������� ������ �� 1
void deque_push_front(deque *a, int b); // ������� �������� � ������
void deque_push_back(deque *a, int b); // ������� �������� � �����
void deque_pop_front(deque *a); // ������ � ��� �� �������� �������� � ������
void deque_pop_back(deque *a); // ������ � ��� �� �������� �������� � �����
void deque_print(deque *a); // ������ ����
int deque_size( deque *a); // ���������� ������
void deque_insert_index(deque *a, int b, int index); // ������� �������� �� �������
void deque_erase(deque *a, int index); // �������� �������� �� �������

#endif // DEQUE_H_INCLUDED
