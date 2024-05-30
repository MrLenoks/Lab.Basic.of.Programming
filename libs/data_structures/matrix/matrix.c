#include <malloc.h>
#include <stdio.h>
#include <stdbool.h>
#include "matrix.h"

//размещает в динамической памяти матрицу размером nRows на nCols
matrix getMemMatrix(int nRows, int nCols){
    int **values = (int **) malloc(sizeof(int*) * nRows);

    for (int i = 0; i < nRows; i++){
        values[i] = (int *) malloc(sizeof(int) * nCols);
    }

    return (matrix){values, nRows, nCols};
}

//размещает в динамической памяти массив из nMatrices матриц размером nRows на nCols
matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols){
    matrix *ms = (matrix*) malloc(sizeof(matrix) * nMatrices);

    for (int i = 0; i < nMatrices; i++) {
        ms[i] = getMemMatrix(nRows, nCols);
    }

    return ms;
}

//освобождает память, выделенную под хранение матрицы m
void freeMemMatrix(matrix *m){
    free (m->values);
}

//освобождает память, выделенную под хранение массива ms из nMatrices матриц
void freeMemMatrices(matrix *ms, int nMatrices){
    for(int i = 0; i < nMatrices; i++) {
        free (ms[i].values);
    }
}


//ввод матрицы m
void inputMatrix(matrix *m){
    for (int i = 0; i < m->nRows; i++) {
        for (int j = 0; j < m->nCols; j++) {
            scanf("%d ", &m->values[i][j]);
        }

        scanf("\n");
    }
}

//ввод массива из nMatrices матриц, хранящейся по адресу ms
void inputMatrices(matrix *ms, int nMatrices){
    for (int k = 0; k < nMatrices; k++) {
        inputMatrix(&ms[k]);
    }
}

//вывод матрицы m
void outputMatrix(matrix m){
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            printf("%d ", m.values[i][j]);
        }

        printf("\n");
    }
}

//вывод массива из nMatrices матриц, хранящейся по адресу ms
void outputMatrices(matrix *ms, int nMatrices){
    for (int i = 0; i < nMatrices; i++) {
        outputMatrix(ms[i]);

        printf("\n");
    }
}

//обмен строк с порядковыми номерами i1 и i2 в матрице m
void swapRows(matrix m, int i1, int i2){
    if (0 <= i1 && i1 < m->nRows && 0 <= i2 && i2 < m->nRows) {
        int *temp = m->values[i1];
        m->values[i1] = m->values[i2];
        m->values[i2] = temp;
    }
}

//обмен колонок с порядковыми номерами j1 и j2 в матрице m
void swapColumns(matrix m, int j1, int j2){
    if(0 <= j1 && j1 < m->nCols && 0 <= j2 && j2 < m->nCols){
        for (int i = 0; i < m->nRows; i++) {
            int temp = m->values[i][j1];
            m->values[i][j1] = m->values[i][j2];
            m->values[i][j2] = temp;
        }
    }
}




