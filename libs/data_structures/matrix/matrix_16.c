#include "matrix.h"
#include "matrix.c"

//Задание 1: меняет местами строки, в которых находятся максимальный и минимальный элементы.
void firstTask(matrix *m){
    position min = getMinValuePos(*m);
    position max = getMaxValuePos(*m);

    int minPos = min.rowIndex;
    int maxPos = max.rowIndex;

    swapRows(*m, maxPos, minPos);
}

// функция-критерий для сравнения строк по максимальному элементу
int getMax(int* a, int n) {
    assert(n > 0);

    int max = a[0];

    for (int i = 1; i < n; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }

    return max;
}

//сортирует строки по неубывнию наибольших элементов строк
void sortRowsByMaxElement(matrix m) {
    int *max = (int*)malloc(sizeof(int) * m.nRows);

    for (int i = 0; i < m.nRows; i++) {
        max[i] = getMax(m.values[i], m.nCols);
    }

    for (int i = 0; i < m.nRows; i++) {
        int minIndex = i;

        for (int j = i + 1; j < m.nRows; j++) {
            if (max[j] < max[minIndex]) {
                minIndex = j;
            }
        }

        if (i != minIndex) {
            swap(&max[i], &max[minIndex]);
            swapRows(m, i, minIndex);
        }
    }

    free(max);
}

//Задание 2: упорядочивает строки матрицы по неубыванию наибольших элементов строк.
void secondTask(matrix m){
    for (int i = 0; i < m.nRows; i++) {
        sortRowsByMaxElement(m);
    }
}

// функция-критерий для сравнения строк по минимальному элементу
int getMin(int *a, int n) {
    assert(n > 0);

    int min = a[0];

    for (int i = 1; i < n; i++) {
        if (a[i] < min) {
            min = a[i];
        }
    }

    return min;
}

//упорядочивает столбцы матрицы по неубыванию минимальных элементов столбцов
void sortColsByMinElemnt(matrix m) {
    int *criteriaValues = (int*)malloc(sizeof(int) * m.nCols);
    int *column = (int*)malloc(sizeof(int) * m.nRows);

    for (int j = 0; j < m.nCols; j++) {
        for (int i = 0; i < m.nRows; i++) {
            column[i] = m.values[i][j];
        }

        criteriaValues[j] = getMin(column, m.nCols);
    }

    for (int i = 0; i < m.nCols; i++) {
        int minIndex = i;

        for (int j = i + 1; j < m.nCols; j++) {
            if (criteriaValues[j] < criteriaValues[minIndex]) {
                minIndex = j;
            }
        }

        if (i != minIndex) {
            swap(&criteriaValues[i], &criteriaValues[minIndex]);
            swapColumns(m, i, minIndex);
        }
    }

    free(column);
    free(criteriaValues);
}

//Задание 3: упорядочивает столбцы матрицы по неубыванию минимальных элементов столбцов.
void thirdTask(matrix m){
    sortColsByMinElemnt(m);
}

