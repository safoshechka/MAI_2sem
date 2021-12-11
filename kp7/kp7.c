#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "vector.h"


int findStart(Vector* CIP, int m) { // Возвращает элемент, с которого начинаем искать
    int start = vectorGetByIndex(CIP, m - 1);
    return start;
}

int findEnd(Vector* CIP, int m, int size) { // Возвращает элемент, с которого заканчиваем искать
    int end = vectorGetByIndex(CIP, m);
    if (end == 0) {
        end = size - 1;
    }
    if (end == -1) {
        end = findEnd(CIP, m + 1, size);
    }
    return end;
}

int calculate(Vector* CIP, Vector* PI, Vector* YE, int m, int n) { // Вычисляет значение элемента по номеру строки и столбца, основываясь на внутреннем представлении матрицы
    int start = findStart(CIP, m);
    int end = findEnd(CIP, m, PI->size);
    int temp;
    bool found = false;;
    if (start == -1) {
        temp = 0;
        return temp;
    }
    else {
        for (int i = start; i < end; i++) {
            if (vectorGetByIndex(PI, i) == n) {
                found = true;
                temp = vectorGetByIndex(YE, i);
                return temp;
            }
        }
    }
    if (!found) {
        temp = 0;
        return temp;
    }
}

bool skew_symmetric(Vector* CIP, Vector* PI, Vector* YE, int m, int n) { // Проверка на то, что матрица кососимметрическая
    if (n != m) {
        return false;
    }
    int temp1;
    int temp2;
    for (int i = 0; i < m; i++) {
        for (int j = i; j < n; j++) {
            temp1 = calculate(CIP, PI, YE, i + 1, j + 1);
            temp2 = calculate(CIP, PI, YE, j + 1, i + 1);
            if (i == j && temp1 != 0) {
                return false;
            }
            if (temp1 != -temp2) {
                return false;
            }
        }
    }
    return true;
}

void transpose(Vector* CIP, Vector* PI, Vector* YE, Vector* CIP_init, Vector* PI_init, Vector* YE_init, int m, int n) { // Транспонирование матрицы
    int cip_index = 0;
    int pi_index = 0;
    int temp;
    int count = 0;

    bool empty_row = false;
    bool found;
    int swap;
    for (int i = 0; i < m; i++) {
        if (empty_row) {
            swap = vectorGetByIndex(CIP, cip_index - 1);
            vectorPush(CIP, swap, cip_index);
            vectorPush(CIP, -1, cip_index - 1);
        }
        else {
            vectorPush(CIP, count, cip_index);
        }
        cip_index++;
        empty_row = true;
        for (int j = 0; j < n; j++) {

            temp = calculate(CIP_init, PI_init, YE_init, n - j, m - i);
            if (temp != 0) {
                empty_row = false;
                vectorPush(PI, j + 1, pi_index);
                vectorPush(YE, temp, pi_index);
                pi_index++;
                count++;
            }
        }
    }
}

void printMatrix(Vector* CIP, Vector* PI, Vector* YE, int m, int n) {
    int temp;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            temp = calculate(CIP, PI, YE, i + 1, j + 1);
            printf("%d ", temp);
        }
        printf("\n");
    }
}

int main(void) {
    Vector* CIP = malloc(sizeof(Vector));
    Vector* PI = malloc(sizeof(Vector));
    Vector* YE = malloc(sizeof(Vector));
    int m;
    int n;
    char FileName[17];
    FILE* f;
    printf("Введите имя файла\n");
    scanf("%s", FileName);
    f = fopen(FileName, "r");
    if(f == NULL) {
        printf("Файл не существует\n");
    } else {
            if (f) {
                fscanf(f, "%d%d", &m, &n);
        }

        vectorInit(CIP, m * n / 2 + 1);
        vectorInit(PI, m * n / 2 + 1);
        vectorInit(YE, m * n / 2 + 1);
        int temp_row[10];
        int cip_index = 0;
        int pi_index = 0;
        int temp;
        bool empty_row;
        if (f) { // Заполнение векторов
            for (int i = 0; i < m; i++) {
                empty_row = true;
                for (int j = 0; j < n; j++) {
                    fscanf(f, "%d", &temp);
                    temp_row[j] = temp;
                }
                for (int j = 0; j < n; j++) {
                    if (temp_row[j] != 0) {
                        empty_row = false;
                    }
                }
                if (empty_row) {
                    vectorPush(CIP, -1, i);
                }
                else {
                    vectorPush(CIP, cip_index, i);
                    for (int j = 0; j < n; j++) {
                        if (temp_row[j] != 0) {
                            vectorPush(PI, j + 1, pi_index);
                            vectorPush(YE, temp_row[j], pi_index);
                            pi_index++;
                            cip_index++;
                        }
                    }
                }
            }
        }
        printf("векторы начальные:\n");
        printf("CIP: ");
        vectorPrint(CIP, m);
        printf("\nPI: ");
        vectorPrint(PI, pi_index);
        printf("\nYE: ");
        vectorPrint(YE, pi_index);

        Vector* CIP2 = malloc(sizeof(Vector));
        Vector* PI2 = malloc(sizeof(Vector));
        Vector* YE2 = malloc(sizeof(Vector));

        vectorInit(CIP2, m * n / 2 + 1);
        vectorInit(PI2, m * n / 2 + 1);
        vectorInit(YE2, m * n / 2 + 1);
        printf("\nматрица начальная:\n");
        printMatrix(CIP, PI, YE, m, n);

        transpose(CIP2, PI2, YE2, CIP, PI, YE, n, m);

        printf("векторы конечные:\n");
        printf("CIP: ");
        vectorPrint(CIP2, n);
        printf("\nPI: ");
        vectorPrint(PI2, pi_index);
        printf("\nYE: ");
        vectorPrint(YE2, pi_index);
        printf("матрица конечная:\n");
        printMatrix(CIP2, PI2, YE2, n, m);
        if (skew_symmetric(CIP2, PI2, YE2, m, n)) {
            printf("транспонировання матрица - кососимметрическая\n");
        }
        else {
            printf("транспонированная матрица - не кососимметрическая\n");
        }
        return 0;
    }
}
