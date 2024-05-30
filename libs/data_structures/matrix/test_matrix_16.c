void test_firstTask_squareMatrix(){
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    3, 4,
                    1, 2
            }, 2, 2);

    matrix m1_return = createMatrixFromArray(
            (int[]) {
                    1, 2,
                    3, 4
            }, 2, 2);

    firstTask(&m1);

    for (int i = 0; i < m1.nRows; i++) {
        for (int j = 0; j < m1.nCols; j++) {
            assert(m1.values[i][j] == m1_return.values[i][j]);
        }
    }

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    10, 20, 30, 40,
                    50, 60, 70, 80,
                    90, 100, 110, 120,
                    130, 140, 150, 160

            }, 4, 4);

    matrix m2_return = createMatrixFromArray(
            (int[]) {
                    130, 140, 150, 160,
                    50, 60, 70, 80,
                    90, 100, 110, 120,
                    10, 20, 30, 40,
            }, 4, 4);

    firstTask(&m2);

    for (int i = 0; i < m2.nRows; i++) {
        for (int j = 0; j < m2.nCols; j++) {
            assert(m2.values[i][j] == m2_return.values[i][j]);
        }
    }

    freeMemMatrix(&m1);
    freeMemMatrix(&m1_return);
    freeMemMatrix(&m2);
    freeMemMatrix(&m2_return);
}

void test_firstTask_difRowsColumns(){
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    0, 4, 8, 9, 5, 34,
                    1, 2, 15, 19, 78, 23,
                    7, 20, 70, 100, 14, 18
            }, 3, 6);

    matrix m1_return = createMatrixFromArray(
            (int[]) {
                    7, 20, 70, 100, 14, 18,
                    1, 2, 15, 19, 78, 23,
                    0, 4, 8, 9, 5, 34
            }, 3, 6);

    firstTask(&m1);

    for (int i = 0; i < m1.nRows; i++) {
        for (int j = 0; j < m1.nCols; j++) {
            assert(m1.values[i][j] == m1_return.values[i][j]);
        }
    }

    freeMemMatrix(&m1);
    freeMemMatrix(&m1_return);
}

void test_firstTask_maxMinOneLine(){
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 4,
                    3, 2
            }, 2, 2);

    matrix m1_return = createMatrixFromArray(
            (int[]) {
                    1, 4,
                    3, 2
            }, 2, 2);

    firstTask(&m1);

    for (int i = 0; i < m1.nRows; i++) {
        for (int j = 0; j < m1.nCols; j++) {
            assert(m1.values[i][j] == m1_return.values[i][j]);
        }
    }

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    120, 4, 8, 9, 10, 0,
                    1, 2, 15, 19, 5, 6,
                    7, 20, 70, 100, 34, 23
            }, 3, 6);

    matrix m2_return = createMatrixFromArray(
            (int[]) {
                    120, 4, 8, 9, 10, 0,
                    1, 2, 15, 19, 5, 6,
                    7, 20, 70, 100, 34, 23
            }, 3, 6);

    firstTask(&m1);

    for (int i = 0; i < m1.nRows; i++) {
        for (int j = 0; j < m1.nCols; j++) {
            assert(m1.values[i][j] == m1_return.values[i][j]);
        }
    }

    freeMemMatrix(&m1);
    freeMemMatrix(&m1_return);
    freeMemMatrix(&m2);
    freeMemMatrix(&m2_return);
}

void test_firstTask(){
    test_firstTask_squareMatrix();
    test_firstTask_difRowsColumns();
    test_firstTask_maxMinOneLine();
}

void test_secondTask_squareMatrix(){
    matrix m = createMatrixFromArray(
            (int[]) {
                    7, 1, 2,
                    1, 8, 1,
                    3, 2, 1
            }, 3, 3);

    matrix m_return = createMatrixFromArray(
            (int[]) {
                    3, 2, 1,
                    7, 1, 2,
                    1, 8, 1
            }, 3, 3);

    secondTask(m);

    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            assert(m.values[i][j] == m_return.values[i][j]);
        }
    }

    freeMemMatrix(&m);
    freeMemMatrix(&m_return);
}

void test_secondTask_oneMax(){
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    0, 1, 2, 8,
                    1, 8, 1, 4,
                    3, 2, 1, 8
            }, 3, 4);

    matrix m1_return = createMatrixFromArray(
            (int[]) {
                    0, 1, 2, 8,
                    1, 8, 1, 4,
                    3, 2, 1, 8
            }, 3, 4);

    secondTask(m1);

    for (int i = 0; i < m1.nRows; i++) {
        for (int j = 0; j < m1.nCols; j++) {
            assert(m1.values[i][j] == m1_return.values[i][j]);
        }
    }

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    9, 1, 2, 5,
                    1, 8, 1, 4,
                    3, 2, 9, 6
            }, 3, 4);

    matrix m2_return = createMatrixFromArray(
            (int[]) {
                    1, 8, 1, 4,
                    9, 1, 2, 5,
                    3, 2, 9, 6
            }, 3, 4);

    secondTask(m2);

    for (int i = 0; i < m2.nRows; i++) {
        for (int j = 0; j < m2.nCols; j++) {
            assert(m2.values[i][j] == m2_return.values[i][j]);
        }
    }

    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
    freeMemMatrix(&m1_return);
    freeMemMatrix(&m2_return);
}

void test_secondTask(){
    test_secondTask_squareMatrix();
    test_secondTask_oneMax();
}


void test(){
    test_firstTask();
    test_secondTask();
}

int main(){
    test();
}

