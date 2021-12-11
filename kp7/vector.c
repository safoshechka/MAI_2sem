#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

void vectorResize(Vector* v) {
    v->data = realloc(v->data, sizeof(int) * 2 * (v->size));
    v->size = 2 * (v->size);
}

void vectorPush(Vector* v, int val, int index) {
    if (index + 1 >= v->size) {
        vectorResize(v);
    }
    v->data[index] = val;
}

void vectorInit(Vector* v, int size) {
    v->size = size;
    v->data = malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) {
        v->data[i] = 0;
    }
}

int vectorGetByIndex(Vector* v, int index) {

    if (index + 1 > v->size) {
        printf("Выход за пределы вектора \n");
        return 0;
    }
    return v->data[index];
}

void vectorDestroy(Vector* v) {
    free(v->data);
    free(v);
}

void vectorPrint(Vector* v, int m) {
    for (int i = 0; i < m; i++) {
        printf("%d ", v->data[i]);

    }
    printf("\n");
}
