#include <assert.h>
#include <malloc.h>
#include <stdio.h>
#include "libs\data_structures\matrix\matrix.c"

void test_getMemMatrix_DifColsRows() {
    matrix m = getMemMatrix(1, 2);

    assert(m.nCols == 2);
    assert(m.nRows == 1);
    assert(m.values != NULL);
}

void test_getMemMatrix_SameColsRows() {
    matrix m = getMemMatrix(5, 5);

    assert(m.nCols == 5);
    assert(m.nRows == 5);
    assert(m.values != NULL);
}

void test_getMemMatrix(){
    test_getMemMatrix_DifColsRows();
    test_getMemMatrix_SameColsRows();
}

void test_getMemArrayOfMatrices_One(){
    int nMatrices = 1;

    matrix *ms = getMemArrayOfMatrices(nMatrices, 2, 3);
    for (int i = 0; i < nMatrices; i++) {
        assert(ms[i].nCols == 3);
        assert(ms[i].nRows == 2);
        assert(ms[i].values != NULL);
    }
}

void test_getMemArrayOfMatrices_Many(){
    int nMatrices = 1000;

    matrix *ms = getMemArrayOfMatrices(nMatrices, 500, 700);
    for (int i = 0; i < nMatrices; i++) {
        assert(ms[i].nCols == 700);
        assert(ms[i].nRows == 500);
        assert(ms[i].values != NULL);
    }
}

void test_getMemArrayOfMatrices(){
    test_getMemArrayOfMatrices_One();
    test_getMemArrayOfMatrices_Many();
}

void test_freeMemMatrix_SquareMatrixTotalValues(){
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 1, 1,
                    0, 0, 1,
                    4, 3, 2
            }, 3, 3);

    freeMemMatrix(&m);
    assert(m.nCols == 3);
    assert(m.nRows == 3);
    assert(m.values != NULL);
}

void test_freeMemMatrix_TotalMatrixUnitValues(){
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 1, 1, 1, 1, 1, 1,
                    1, 1, 1, 1, 1, 1, 1,
                    1, 1, 1, 1, 1, 1,1
            }, 7, 3);

    freeMemMatrix(&m);
    assert(m.nCols == 3);
    assert(m.nRows == 7);
    assert(m.values != NULL);
}

void test_freeMemMatrix(){
    test_freeMemMatrix_SquareMatrixTotalValues();
    test_freeMemMatrix_TotalMatrixUnitValues();
}

void test_freeMemMatrices_SquareMatrices(){
    matrix m1;
    m1.nRows = 1;
    m1.nCols = 1;
    m1.values = malloc(sizeof(int) * m1.nRows * m1.nCols);

    matrix m2;
    m2.nRows = 2;
    m2.nCols = 2;
    m2.values = malloc(sizeof(int) * m2.nRows * m2.nCols);

    matrix m3;
    m3.nRows = 3;
    m3.nCols = 3;
    m3.values = malloc(sizeof(int) * m3.nRows * m3.nCols);

    int nMatrices = 3;
    matrix ms[3] = {m1, m2, m3};

    freeMemMatrices(ms, nMatrices);

    for (int i = 0; i < nMatrices; i++) {
        assert(ms[i].values != NULL);
    }
}

void test_freeMemMatrices_DifManyMatrices() {
    matrix m1;
    m1.nRows = 90;
    m1.nCols = 30;
    m1.values = malloc(sizeof(int) * m1.nRows * m1.nCols);

    matrix m2;
    m2.nRows = 500;
    m2.nCols = 700;
    m2.values = malloc(sizeof(int) * m2.nRows * m2.nCols);

    matrix m3;
    m3.nRows = 18;
    m3.nCols = 3;
    m3.values = malloc(sizeof(int) * m3.nRows * m3.nCols);

    matrix m4;
    m4.nRows = 15000;
    m4.nCols = 400;
    m4.values = malloc(sizeof(int) * m4.nRows * m4.nCols);

    matrix m5;
    m5.nRows = 800;
    m5.nCols = 3;
    m5.values = malloc(sizeof(int) * m5.nRows * m5.nCols);

    int nMatrices = 5;
    matrix ms[5] = {m1, m2, m3, m4, m5};

    freeMemMatrices(ms, nMatrices);

    for (int i = 0; i < nMatrices; i++) {
        assert(ms[i].values != NULL);
    }
}

void test_freeMemMatrices(){
    test_freeMemMatrices_SquareMatrices();
    test_freeMemMatrices_DifManyMatrices();
}

void test_swapRows_SquareMatrices(){
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 0,
                    0, 1
            }, 2, 2);

    matrix m_return1 = createMatrixFromArray(
            (int[]) {
                    0, 1,
                    1, 0
            }, 2, 2);

    swapRows(m1, 0, 1);

    for (int i = 0; i < m1.nRows; i++) {
        for (int j = 0; j < m1.nCols; j++) {
            assert(m1.values[i][j] == m_return1.values[i][j]);
        }
    }

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    3, 7, 8,
                    10, 19, 35,
                    90, 150, 45
            }, 3, 3);

    matrix m_return2 = createMatrixFromArray(
            (int[]) {
                    90, 150, 45,
                    10, 19, 35,
                    3, 7, 8
            }, 3, 3);

    swapRows(m2, 0, 2);

    for (int i = 0; i < m2.nRows; i++) {
        for (int j = 0; j < m2.nCols; j++) {
            assert(m2.values[i][j] == m_return2.values[i][j]);
        }
    }

    matrix m3 = createMatrixFromArray(
            (int[]) {
                    1, 1, 1, 1, 1,
                    1, 1, 1, 1, 1,
                    1, 1, 1, 1, 1,
                    1, 1, 1, 1, 1,
                    1, 1, 1, 1, 1
            }, 5, 5);

    matrix m_return3 = createMatrixFromArray(
            (int[]) {
                    1, 1, 1, 1, 1,
                    1, 1, 1, 1, 1,
                    1, 1, 1, 1, 1,
                    1, 1, 1, 1, 1,
                    1, 1, 1, 1, 1
            }, 5, 5);

    swapRows(m3, 2, 3);
    swapRows(m3, 0, 1);
    swapRows(m3, 2, 4);

    for (int i = 0; i < m3.nRows; i++) {
        for (int j = 0; j < m3.nCols; j++) {
            assert(m3.values[i][j] == m_return3.values[i][j]);
        }
    }

    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
    freeMemMatrix(&m3);
    freeMemMatrix(&m_return1);
    freeMemMatrix(&m_return2);
    freeMemMatrix(&m_return3);
}

void test_swapRows_DifColsRows(){
    matrix m = createMatrixFromArray(
            (int[]) {
                    15, 1, 10, 20, 5,
                    3, 9, 81, 99, 21,
                    7, 21, 63, 42, 35
            }, 3, 5);


    matrix m_return = createMatrixFromArray(
            (int[]) {
                    3, 9, 81, 99, 21,
                    7, 21, 63, 42, 35,
                    15, 1, 10, 20, 5

            }, 3, 5);

    swapRows(m, 0, 2);
    swapRows(m, 0, 1);

    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            assert(m.values[i][j] == m_return.values[i][j]);
        }
    }

    freeMemMatrix(&m);
    freeMemMatrix(&m_return);
}

void test_swapRows(){
    test_swapRows_SquareMatrices();
    test_swapRows_DifColsRows();
}

void test_swapColumns_SquareMatrices(){
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 0,
                    0, 1
            }, 2, 2);

    matrix m_return1 = createMatrixFromArray(
            (int[]) {
                    0, 1,
                    1, 0
            }, 2, 2);

    swapColumns(m1, 0, 1);

    for (int i = 0; i < m1.nRows; i++) {
        for (int j = 0; j < m1.nCols; j++) {
            assert(m1.values[i][j] == m_return1.values[i][j]);
        }
    }

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    3, 7, 8,
                    10, 19, 35,
                    90, 150, 45
            }, 3, 3);

    matrix m_return2 = createMatrixFromArray(
            (int[]) {
                    8, 7, 3,
                    35, 19, 10,
                    45, 150, 90
            }, 3, 3);

    swapColumns(m2, 0, 2);

    for (int i = 0; i < m2.nRows; i++) {
        for (int j = 0; j < m2.nCols; j++) {
            assert(m2.values[i][j] == m_return2.values[i][j]);
        }
    }

    matrix m3 = createMatrixFromArray(
            (int[]) {
                    1, 1, 1, 1, 1,
                    1, 1, 1, 1, 1,
                    1, 1, 1, 1, 1,
                    1, 1, 1, 1, 1,
                    1, 1, 1, 1, 1
            }, 5, 5);

    matrix m_return3 = createMatrixFromArray(
            (int[]) {
                    1, 1, 1, 1, 1,
                    1, 1, 1, 1, 1,
                    1, 1, 1, 1, 1,
                    1, 1, 1, 1, 1,
                    1, 1, 1, 1, 1
            }, 5, 5);

    swapColumns(m3, 2, 3);
    swapColumns(m3, 0, 1);
    swapColumns(m3, 2, 4);

    for (int i = 0; i < m3.nRows; i++) {
        for (int j = 0; j < m3.nCols; j++) {
            assert(m3.values[i][j] == m_return3.values[i][j]);
        }
    }

    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
    freeMemMatrix(&m3);
    freeMemMatrix(&m_return1);
    freeMemMatrix(&m_return2);
    freeMemMatrix(&m_return3);
}

void test_swapColumns_DifColsRows(){
    matrix m = createMatrixFromArray(
            (int[]) {
                    15, 1, 10, 20, 5,
                    3, 9, 81, 99, 21,
                    7, 21, 63, 42, 35
            }, 3, 5);


    matrix m_return = createMatrixFromArray(
            (int[]) {
                    20, 15, 5, 1, 10,
                    99, 3, 21, 9, 81,
                    42, 7, 35, 21, 63

            }, 3, 5);

    swapColumns(m, 0, 3);
    swapColumns(m, 2, 4);
    swapColumns(m, 1, 3);

    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            assert(m.values[i][j] == m_return.values[i][j]);
        }
    }

    freeMemMatrix(&m);
    freeMemMatrix(&m_return);
}

void test_swapColumns(){
    test_swapColumns_SquareMatrices();
    test_swapColumns_DifColsRows();
}

// функция-критерий для сравнения строк по сумме элементов
long long getSum(int* a, int nCols) {
    long long sum = 0;
    for (int i = 0; i < nCols; i++) {
        sum += a[i];
    }

    return sum;
}

void test_insertionSortRowsMatrixByRowCriteria(){
    matrix m = createMatrixFromArray(
            (int[]) {
                    5, 2, 1, 4,
                    3, 7, 6, 9,
                    0, 8, 2, 5
            }, 3, 4);

    matrix m_return = createMatrixFromArray(
            (int[]) {
                    3, 7, 6, 9,
                    0, 8, 2, 5,
                    5, 2, 1, 4,
            }, 3, 4);

    insertionSortRowsMatrixByRowCriteria(m, getSum);

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            assert(m.values[i][j] == m_return.values[i][j]);
        }
    }

    freeMemMatrix(&m);
    freeMemMatrix(&m_return);
}

void test_selectionSortColsMatrixByColCriteria() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    4, 3, 1, 2,
                    2, 4, 3, 1,
                    1, 2, 4, 3
            }, 3, 4);

    matrix m_return = createMatrixFromArray(
            (int[]) {
                    2, 4, 1, 3,
                    1, 2, 3, 4,
                    3, 1, 4, 2
            }, 3, 4);

    selectionSortColsMatrixByColCriteria(m, getSum);

    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            assert(m.values[i][j] == m_return.values[i][j]);
        }
    }

    freeMemMatrix(&m);
    freeMemMatrix(&m_return);
}

void test_isSquareMatrix(){
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    3, 7, 8,
                    10, 19, 35,
                    90, 150, 45
            }, 3, 3);

    assert(isSquareMatrix(&m1) == 1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    4, 3, 1, 2,
                    2, 4, 3, 1,
                    1, 2, 4, 3
            }, 3, 4);

    assert(isSquareMatrix(&m2) == 0);

    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_areTwoMatricesEqual(){
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    3, 7, 8,
                    10, 19, 35,
                    90, 150, 45
            }, 3, 3);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    3, 7, 8,
                    10, 19, 35,
                    90, 150, 45
            }, 3, 3);

    matrix m3 = createMatrixFromArray(
            (int[]) {
                    4, 3, 1, 2,
                    2, 4, 3, 1,
                    1, 2, 4, 3
            }, 3, 4);

    assert(areTwoMatricesEqual(&m1, &m2) == 1);
    assert(areTwoMatricesEqual(&m1, &m3) == 0);
    assert(areTwoMatricesEqual(&m2, &m3) == 0);

    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
    freeMemMatrix(&m3);
}

void test_isEMatrix(){
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 0, 0,
                    0, 1, 0,
                    0, 0, 1
            }, 3, 3);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    1, 0, 0,
                    0, 0, 0,
                    0, 0, 1
            }, 3, 3);

    matrix m3 = createMatrixFromArray(
            (int[]) {
                    1, 0, 0, 0,
                    0, 0, 0, 0,
                    0, 0, 1, 0
            }, 3, 4);

    assert(isEMatrix(&m1) == 1);
    assert(isEMatrix(&m2) == 0);
    assert(isEMatrix(&m3) == 0);

    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
    freeMemMatrix(&m3);
}

void test_isSymmetricMatrix(){
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 0, 0,
                    0, 1, 0,
                    0, 0, 1
            }, 3, 3);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    1, 3, 2,
                    4, 1, 0,
                    5, 0, 1
            }, 3, 3);

    assert(isSymmetricMatrix(&m1) == 1);
    assert(isSymmetricMatrix(&m2) == 0);

    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_transposeSquareMatrix(){
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 0,
                    1, 0
            }, 2, 2);

    matrix m_return1 = createMatrixFromArray(
            (int[]) {
                    1, 1,
                    0, 0
            }, 2, 2);

    transposeMatrix(&m1);

    for (int i = 0; i < m1.nRows; i++) {
        for (int j = 0; j < m1.nCols; j++) {
            assert(m1.values[i][j] == m_return1.values[i][j]);
        }
    }

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    3, 7, 8,
                    10, 19, 35,
                    90, 150, 45
            }, 3, 3);

    matrix m_return2 = createMatrixFromArray(
            (int[]) {
                    3, 10, 90,
                    7, 19, 150,
                    8, 35, 45
            }, 3, 3);

    transposeMatrix(&m2);

    for (int i = 0; i < m2.nRows; i++) {
        for (int j = 0; j < m2.nCols; j++) {
            assert(m2.values[i][j] == m_return2.values[i][j]);
        }
    }

    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
    freeMemMatrix(&m_return1);
    freeMemMatrix(&m_return2);
}

void test_transposeMatrix(){
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    15, 1, 10, 20, 5,
                    3, 9, 81, 99, 21,
                    7, 21, 63, 42, 35
            }, 3, 5);

    matrix m_return1 = createMatrixFromArray(
            (int[]) {
                    15, 3, 7,
                    1, 9, 21,
                    10, 81, 63,
                    20, 99, 42,
                    5, 21, 35
            }, 5, 3);

    transposeMatrix(&m1);

    for (int i = 0; i < m1.nRows; i++) {
        for (int j = 0; j < m1.nCols; j++) {
            assert(m1.values[i][j] == m_return1.values[i][j]);
        }
    }

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    5, 6,
                    2, 80,
                    35, 7,
                    4, 85
            }, 4, 2);

    matrix m_return2 = createMatrixFromArray(
            (int[]) {
                    5, 2, 35, 4,
                    6, 80, 7, 85
            }, 2, 4);

    transposeMatrix(&m2);

    for (int i = 0; i < m2.nRows; i++) {
        for (int j = 0; j < m2.nCols; j++) {
            assert(m2.values[i][j] == m_return2.values[i][j]);
        }
    }

    matrix m3 = createMatrixFromArray(
            (int[]) {
                    3, 7, 8,
                    10, 19, 35,
                    90, 150, 45
            }, 3, 3);

    matrix m_return3 = createMatrixFromArray(
            (int[]) {
                    3, 10, 90,
                    7, 19, 150,
                    8, 35, 45
            }, 3, 3);

    transposeMatrix(&m2);

    for (int i = 0; i < m3.nRows; i++) {
        for (int j = 0; j < m3.nCols; j++) {
            assert(m3.values[i][j] == m_return3.values[i][j]);
        }
    }

    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
    freeMemMatrix(&m3);
    freeMemMatrix(&m_return1);
    freeMemMatrix(&m_return2);
    freeMemMatrix(&m_return3);
}

void test_getMinValuePos_multipleValues(){
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 0, 0,
                    0, 1, 1,
                    0, 0, 1
            }, 3, 3);

    position expectedPos1 = {2, 1};
    position minPos1 = getMinValuePos(m1);
    assert(minPos1.rowIndex == expectedPos1.rowIndex && minPos1.colIndex == expectedPos1.colIndex);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    4, 67, 89,
                    78, 56, 4,
                    56, 32, 5
            }, 3, 3);

    position expectedPos2 = {1, 2};
    position minPos2 = getMinValuePos(m2);
    assert(minPos2.rowIndex == expectedPos2.rowIndex && minPos2.colIndex == expectedPos2.colIndex);

    matrix m3 = createMatrixFromArray(
            (int[]) {
                    15, 3, 7,
                    1, 9, 21,
                    1, 81, 63,
                    20, 1, 1,
                    5, 21, 35
            }, 5, 3);

    position expectedPos3 = {3, 2};
    position minPos3 = getMinValuePos(m3);
    assert(minPos3.rowIndex == expectedPos3.rowIndex && minPos3.colIndex == expectedPos3.colIndex);

    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
    freeMemMatrix(&m3);
}

void test_getMinValuePos_OneValue(){
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 60, 5,
                    45, 4, 3,
                    3, 0, 1
            }, 3, 3);

    position expectedPos1 = {2, 1};
    position minPos1 = getMinValuePos(m1);
    assert(minPos1.rowIndex == expectedPos1.rowIndex && minPos1.colIndex == expectedPos1.colIndex);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    4, 67, 89,
                    78, 56, 3,
                    56, 32, 5
            }, 3, 3);

    position expectedPos2 = {0, 0};
    position minPos2 = getMinValuePos(m2);
    assert(minPos2.rowIndex == expectedPos2.rowIndex && minPos2.colIndex == expectedPos2.colIndex);

    matrix m3 = createMatrixFromArray(
            (int[]) {
                    15, 3, 7,
                    0, 90, 21,
                    4, 81, 63,
                    20, 9, 1,
                    5, 51, 35
            }, 5, 3);

    position expectedPos3 = {1, 0};
    position minPos3 = getMinValuePos(m3);
    assert(minPos3.rowIndex == expectedPos3.rowIndex && minPos3.colIndex == expectedPos3.colIndex);

    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
    freeMemMatrix(&m3);
}

void test_getMinValuePos(){
    test_getMinValuePos_multipleValues();
    test_getMinValuePos_OneValue();
}

void test_getMaxValuePos_multipleValues(){
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 0, 0,
                    0, 1, 1,
                    0, 0, 1
            }, 3, 3);

    position expectedPos1 = {2, 2};
    position maxPos1 = getMaxValuePos(m1);
    assert(maxPos1.rowIndex == expectedPos1.rowIndex && maxPos1.colIndex == expectedPos1.colIndex);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    4, 67, 89,
                    78, 89, 4,
                    89, 32, 5
            }, 3, 3);

    position expectedPos2 = {2, 0};
    position maxPos2 = getMaxValuePos(m2);
    assert(maxPos2.rowIndex == expectedPos2.rowIndex && maxPos2.colIndex == expectedPos2.colIndex);

    matrix m3 = createMatrixFromArray(
            (int[]) {
                    81, 3, 7,
                    1, 9, 81,
                    1, 81, 63,
                    20, 81, 1,
                    5, 21, 81
            }, 5, 3);

    position expectedPos3 = {4, 2};
    position maxPos3 = getMaxValuePos(m3);
    assert(maxPos3.rowIndex == expectedPos3.rowIndex && maxPos3.colIndex == expectedPos3.colIndex);

    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
    freeMemMatrix(&m3);
}

void test_getMaxValuePos_OneValue(){
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 60, 5,
                    45, 4, 3,
                    3, 0, 1
            }, 3, 3);

    position expectedPos1 = {0, 1};
    position maxPos1 = getMaxValuePos(m1);
    assert(maxPos1.rowIndex == expectedPos1.rowIndex && maxPos1.colIndex == expectedPos1.colIndex);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    4, 67, 89,
                    78, 56, 3,
                    56, 32, 5
            }, 3, 3);

    position expectedPos2 = {0, 2};
    position maxPos2 = getMaxValuePos(m2);
    assert(maxPos2.rowIndex == expectedPos2.rowIndex && maxPos2.colIndex == expectedPos2.colIndex);

    matrix m3 = createMatrixFromArray(
            (int[]) {
                    15, 3, 7,
                    0, 90, 21,
                    4, 81, 63,
                    20, 9, 1,
                    5, 51, 35
            }, 5, 3);

    position expectedPos3 = {1, 1};
    position maxPos3 = getMaxValuePos(m3);
    assert(maxPos3.rowIndex == expectedPos3.rowIndex && maxPos3.colIndex == expectedPos3.colIndex);

    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
    freeMemMatrix(&m3);
}

void test_getMaxValuePos(){
    test_getMaxValuePos_multipleValues();
    test_getMaxValuePos_OneValue();
}

void test(){
    test_getMemMatrix();
    test_getMemArrayOfMatrices();
    test_freeMemMatrix();
    test_freeMemMatrices();
    test_swapRows();
    test_swapColumns();
    test_insertionSortRowsMatrixByRowCriteria();
    test_selectionSortColsMatrixByColCriteria();
    test_isSquareMatrix();
    test_areTwoMatricesEqual();
    test_isEMatrix();
    test_isSymmetricMatrix();
    test_transposeSquareMatrix();
    test_transposeMatrix();
    test_getMinValuePos();
    test_getMaxValuePos();
}

int main(){
    test();
}
