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

//умножает матрицы
matrix mulMatrices(matrix m1, matrix m2) {
    if (m1.nCols != m2.nRows) {
        matrix result = {NULL, 0, 0};
        return result;
    }

    matrix result;
    result.nRows = m1.nRows;
    result.nCols = m2.nCols;

    result.values = (int **)malloc(result.nRows * sizeof(int *));

    for (int i = 0; i < result.nRows; i++) {
        result.values[i] = (int *)malloc(result.nCols * sizeof(int));
    }

    for (int i = 0; i < result.nRows; i++) {
        for (int j = 0; j < result.nCols; j++) {
            result.values[i][j] = 0;

            for (int k = 0; k < m1.nCols; k++) {
                result.values[i][j] += m1.values[i][k] * m2.values[k][j];
            }
        }
    }

    return result;
}

//возвращает квадрат матрицы, если она симметрична
matrix getSquareOfMatrixIfSymmetric(matrix m) {
    if (isSymmetricMatrix(&m)) {
        return mulMatrices(m, m);
    } else {
        matrix result = {NULL, 0, 0};

        return result;
    }
}

//Задача 4: заменяет квадратную матрицу её квадратом.
matrix fourthTask(matrix m){
    return getSquareOfMatrixIfSymmetric(m);
}

// функция-критерий для сравнения строк по сумме элементов
long long getSum(int* a, int nCols) {
    long long sum = 0;
    for (int i = 0; i < nCols; i++) {
        sum += a[i];
    }

    return sum;
}

//проверяет элементы на уникальность
bool isUnique(long long *a, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] == a[j]) {
                return 0;
            }
        }
    }

    return 1;
}

//транспонирует матрицу, если среди сумм элементов строк матрицы нет равных
void transposeIfMatrixHasNotEqualSumOfRows(matrix m) {
    long long sum_rows[m.nRows];

    for (int i = 0; i < m.nRows; i++) {
        sum_rows[i] = getSum(m.values[i], m.nCols);
    }

    if (isUnique(&sum_rows, m.nRows)){
        for (int i = 0; i < m.nRows; i++) {
            long long sum = getSum(m.values[i], m.nCols);

            for (int j = i + 1; j < m.nRows; j++) {
                if (sum != getSum(m.values[j], m.nCols)) {
                    transposeSquareMatrix(&m);

                    return;
                }
            }
        }
    }
}

//Задача 5: транспонирует матрицу, если среди сумм элементов строк матрицы нет равных.
void fifthTask(matrix *m){
    transposeIfMatrixHasNotEqualSumOfRows(*m);
}

