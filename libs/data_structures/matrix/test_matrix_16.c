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

void test_thirdTask_squareMatrix(){
    matrix m = createMatrixFromArray(
            (int[]) {
                    7, 3, 10,
                    8, 0, 5,
                    6, 2, 11
            }, 3, 3);

    matrix m_return = createMatrixFromArray(
            (int[]) {
                    3, 10, 7,
                    0, 5, 8,
                    2, 11, 6
            }, 3, 3);

    thirdTask(m);

    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            assert(m.values[i][j] == m_return.values[i][j]);
        }
    }

    freeMemMatrix(&m);
    freeMemMatrix(&m_return);
}

void test_thirdTask_oneMin(){
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    0, 1, 0, 8,
                    1, 0, 1, 4,
                    3, 2, 1, 0
            }, 3, 4);

    matrix m1_return = createMatrixFromArray(
            (int[]) {
                    0, 1, 0, 8,
                    1, 0, 1, 4,
                    3, 2, 1, 0
            }, 3, 4);

    thirdTask(m1);

    for (int i = 0; i < m1.nRows; i++) {
        for (int j = 0; j < m1.nCols; j++) {
            assert(m1.values[i][j] == m1_return.values[i][j]);
        }
    }

    freeMemMatrix(&m1);
    freeMemMatrix(&m1_return);
}

void test_thirdTask(){
    test_thirdTask_squareMatrix();
    test_thirdTask_oneMin();
}

void test_fourthTask_SymmetricMatrix(){
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    2, 5, 6,
                    3, 6, 9
            }, 3, 3);

    matrix m1_return = createMatrixFromArray(
            (int[]) {
                    14, 30, 42,
                    30, 65, 90,
                    42, 90, 126
            }, 3, 3);

    matrix m1_square = fourthTask(m1);

    for (int i = 0; i < m1.nRows; i++) {
        for (int j = 0; j < m1.nCols; j++) {
            assert(m1_square.values[i][j] == m1_return.values[i][j]);
        }
    }

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    7, 20, 20,
                    20, 10, 20,
                    20, 20, 15
            }, 3, 3);

    matrix m2_return = createMatrixFromArray(
            (int[]) {
                    849, 740, 840,
                    740, 900, 900,
                    840, 900, 1025
            }, 3, 3);

    matrix m2_square = fourthTask(m2);

    for (int i = 0; i < m2.nRows; i++) {
        for (int j = 0; j < m2.nCols; j++) {
            assert(m2_square.values[i][j] == m2_return.values[i][j]);
        }
    }

    freeMemMatrix(&m1);
    freeMemMatrix(&m1_return);
    freeMemMatrix(&m1_square);
    freeMemMatrix(&m2);
    freeMemMatrix(&m2_return);
    freeMemMatrix(&m2_square);
}

void test_fourthTask_notSymmetricMatrix(){
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    4, 5, 6,
                    7, 8, 9
            }, 3, 3);

    matrix m1_square = fourthTask(m1);

    assert(m1_square.nRows == 0 && m1_square.nCols == 0);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    1, 2,
                    4, 5,
                    7, 8
            }, 3, 2);

    matrix m2_square = fourthTask(m1);

    assert(m2_square.nRows == 0 && m2_square.nCols == 0);

    freeMemMatrix(&m1);
    freeMemMatrix(&m1_square);
    freeMemMatrix(&m2);
    freeMemMatrix(&m2_square);
}

void test_fourthTask(){
    test_fourthTask_SymmetricMatrix();
    test_fourthTask_notSymmetricMatrix();
}

void test_fifthTask_notSquareMatrix(){
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 2, 3, 0,
                    4, 5, 6, 0,
                    7, 8, 9, 0
            }, 3, 4);

    matrix m_return = createMatrixFromArray(
            (int[]) {
                    1, 2, 3, 0,
                    4, 5, 6, 0,
                    7, 8, 9, 0
            }, 3, 4);

    fifthTask(&m);

    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            assert(m.values[i][j] == m_return.values[i][j]);
        }
    }

    freeMemMatrix(&m);
    freeMemMatrix(&m_return);
}

void test_fifthTask_equalSum(){
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    4, 5, 6,
                    3, 3, 0
            }, 3, 3);

    matrix m_return = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    4, 5, 6,
                    3, 3, 0
            }, 3, 3);

    fifthTask(&m);

    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            assert(m.values[i][j] == m_return.values[i][j]);
        }
    }

    freeMemMatrix(&m);
    freeMemMatrix(&m_return);
}

void test_fifthTask_notEqualSum(){
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    4, 5, 6,
                    7, 8, 9
            }, 3, 3);

    matrix m_return = createMatrixFromArray(
            (int[]) {
                    1, 4, 7,
                    2, 5, 8,
                    3, 6, 9
            }, 3, 3);

    fifthTask(&m);

    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            assert(m.values[i][j] == m_return.values[i][j]);
        }
    }

    freeMemMatrix(&m);
    freeMemMatrix(&m_return);
}

void test_fifthTask(){
    test_fifthTask_notSquareMatrix();
    test_fifthTask_equalSum();
    test_fifthTask_notEqualSum();
}

void test_sixthTask_mutuallyInverseMatrix(){
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 0, 0,
                    0, 1, 0,
                    0, 0, 1
            }, 3, 3);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    1, 0, 0,
                    0, 1, 0,
                    0, 0, 1
            }, 3, 3);

    assert(sixthTask(m1, m2) == 1);

    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_sixthTask_notMutuallyInverseMatrix(){
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 3,
                    4, 5
            }, 2, 2);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    7, 8,
                    9, 0
            }, 2, 2);

    assert(sixthTask(m1, m2) == 0);

    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_sixthTask(){
    test_sixthTask_mutuallyInverseMatrix();
    test_sixthTask_notMutuallyInverseMatrix();
}

void test_seventhTask_equalElements(){
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 1, 1,
                    1, 1, 1,
                    1, 1, 1
            }, 3, 3);

    assert(seventhTask(m1) == 4);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    0, 0, 0,
                    0, 0, 0,
                    0, 0, 0
            }, 3, 3);

    assert(seventhTask(m2) == 0);

    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_seventhTask_notSquareMatrix(){
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    3, 2, 5, 4,
                    1, 3, 6, 3,
                    3, 2, 1, 2
            }, 3, 4);

    assert(seventhTask(m1) == 20);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    2, 4, 7,
                    1, 3, 5
            }, 2, 3);

    assert(seventhTask(m2) == 13);

    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_seventhTask(){
    test_seventhTask_equalElements();
    test_seventhTask_notSquareMatrix();
}

void test_eighthTask_maxInFirstLine(){
    matrix m = createMatrixFromArray(
            (int[]) {
                    100, 2, 5, 4,
                    1, 3, 6, 10,
                    7, 15, 18, 20
            }, 3, 4);

    assert(eighthTask(m) == 100);

    freeMemMatrix(&m);
}

void test_eighthTask_maxNotInFirstLine(){
    matrix m = createMatrixFromArray(
            (int[]) {
                    10, 7, 5, 6,
                    3, 11, 8, 9,
                    4, 11, 12,2
            }, 3, 4);

    assert(eighthTask(m) == 5);

    freeMemMatrix(&m);
}

void test_eighthTask(){
    test_eighthTask_maxInFirstLine();
    test_eighthTask_maxNotInFirstLine();
}

void test_ninthTask_pointsWithOrigin(){
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    6,8,
                    0,0,
                    7,12
            }, 3, 2);

    matrix m1_return = createMatrixFromArray(
            (int[]) {
                    0,0,
                    6,8,
                    7,12
            }, 3, 2);

    ninthTask(m1);

    for (int i = 0; i < m1.nRows; i++) {
        for (int j = 0; j < m1.nCols; j++) {
            assert(m1.values[i][j] == m1_return.values[i][j]);
        }
    }

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    0,0,
                    0,0
            }, 2, 2);

    matrix m2_return = createMatrixFromArray(
            (int[]) {
                    0,0,
                    0,0
            }, 3, 2);

    ninthTask(m2);

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

void test_ninthTask_difPoints(){
    matrix m = createMatrixFromArray(
            (int[]) {
                    6,8,
                    0,0,
                    7,12,
                    8, 13,
                    34, 20,
                    3, 0,
                    3, 7,
                    9, 10
            }, 8, 2);

    matrix m_return = createMatrixFromArray(
            (int[]) {
                    0, 0,
                    3, 0,
                    3, 7,
                    6, 8,
                    9, 10,
                    7, 12,
                    8, 13,
                    34, 20
            }, 8, 2);

    ninthTask(m);

    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            assert(m.values[i][j] == m_return.values[i][j]);
        }
    }

    freeMemMatrix(&m);
    freeMemMatrix(&m_return);
}

void test_ninthTask(){
    test_ninthTask_pointsWithOrigin();
    test_ninthTask_difPoints();
}

void test_tenthTask_zeroMatrix(){
    matrix m = createMatrixFromArray(
            (int[]) {
                    0, 0,
                    0, 0,
                    0, 0
            }, 3, 2);

    assert(tenthTask(m) == 1);

    freeMemMatrix(&m);
}

void test_tenthTask_emptyMatrix(){
    matrix m = createMatrixFromArray(NULL, 0, 0);

    assert(tenthTask(m) == 0);

    freeMemMatrix(&m);
}

void test_tenthTask_simpleMatrix(){
    matrix m = createMatrixFromArray(
            (int[]) {
                    7, 1,
                    2, 7,
                    5, 4,
                    4, 3,
                    1, 6,
                    8, 0
            }, 6, 2);

    assert(tenthTask(m) == 3);

    freeMemMatrix(&m);
}

void test_tenthTask(){
    test_tenthTask_zeroMatrix();
    test_tenthTask_emptyMatrix();
    test_tenthTask_simpleMatrix();
}

void test_eleventhTask_noSpecialElements(){
    matrix m = createMatrixFromArray(
            (int[]) {
                    5, 5,
                    3, 6,
                    2, 1
            }, 3, 2);

    assert(eleventhTask(m) == 0);

    freeMemMatrix(&m);
}

void test_eleventhTask_zeroMatrix(){
    matrix m = createMatrixFromArray(
            (int[]) {
                    0, 0,
                    0, 0
            }, 2, 2);

    assert(eleventhTask(m) == 0);

    freeMemMatrix(&m);
}

void test_eleventhTask_simpleMatrix(){
    matrix m = createMatrixFromArray(
            (int[]) {
                    3, 5, 5, 4,
                    2, 3, 6, 7,
                    12, 2, 1, 2
            }, 3, 4);

    assert(eleventhTask(m) == 2);

    freeMemMatrix(&m);
}

void test_eleventhTask(){
    test_eleventhTask_noSpecialElements();
    test_eleventhTask_zeroMatrix();
    test_eleventhTask_simpleMatrix();
}

void test_twelfthTask_equalElements(){
    matrix m = createMatrixFromArray(
            (int[]) {
                    0, 0, 0,
                    0, 0, 0,
                    0, 0, 0
            }, 3, 3);

    matrix m_return = createMatrixFromArray(
            (int[]) {
                    0, 0, 0,
                    0, 0, 0,
                    0, 0, 0
            }, 3, 3);

    twelfthTask(m);

    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            assert(m.values[i][j] == m_return.values[i][j]);
        }
    }

    freeMemMatrix(&m);
    freeMemMatrix(&m_return);
}

void test_twelfthTask_notSquareMatrix(){
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 2, 3, 5,
                    4, 5, 6, 7,
                    7, 8, 1, 8,
            }, 3, 4);


    matrix m_return = createMatrixFromArray(
            (int[]) {
                    1, 2, 3, 5,
                    4, 5, 6, 7,
                    7, 8, 1, 8,
            }, 3, 4);

    twelfthTask(m);

    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            assert(m.values[i][j] == m_return.values[i][j]);
        }
    }

    freeMemMatrix(&m);
    freeMemMatrix(&m_return);
}

void test_twelfthTask_SquareMatrix(){
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    4, 5, 6,
                    7, 8, 1
            }, 3, 3);


    matrix m_return = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    1, 4, 7,
                    7, 8, 1
            }, 3, 3);

    twelfthTask(m);

    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            assert(m.values[i][j] == m_return.values[i][j]);
        }
    }

    freeMemMatrix(&m);
    freeMemMatrix(&m_return);
}

void test_twelfthTask(){
    test_twelfthTask_equalElements();
    test_twelfthTask_notSquareMatrix();
    test_twelfthTask_SquareMatrix();
}

void test_thirteenthTask_equalMatrices(){
    int a[] = {0, 0,
               0, 0,

               0, 0,
               0, 0,

               0, 0,
               0, 0,

               0, 0,
               0, 0};

    matrix *ms = createArrayOfMatrixFromArray(&a, 4, 2, 2);

    assert(thirteenthTask(ms, 4) == 4);

    freeMemMatrix(&ms);
}

void test_thirteenthTask_noSuitableMatrices(){
    int a[] = {7, 1,
               1, 1,

               5, 4,
               2, 3};

    matrix *ms = createArrayOfMatrixFromArray(&a, 2, 2, 2);

    assert(thirteenthTask(ms, 2) == 0);

    freeMemMatrix(&ms);
}

void test_thirteenthTask_SuitableMatrices(){
    int a[] = {7, 1,
               1, 1,

               1,6,
               2,2,

               5,4,
               2,3,

               1,3,
               7,9};

    matrix *ms = createArrayOfMatrixFromArray(&a, 4, 2, 2);

    assert(thirteenthTask(ms, 4) == 2);

    freeMemMatrix(&ms);
}

void test_thirteenthTask(){
    test_thirteenthTask_equalMatrices();
    test_thirteenthTask_noSuitableMatrices();
    test_thirteenthTask_SuitableMatrices();
}

void test_countZeroRows_notZeroRows(){
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 2,
                    0, 5,
                    7, 0
            }, 3, 2);

    assert(countZeroRows(m) == 0);

    freeMemMatrix(&m);
}

void test_countZeroRows_includeZeroRows(){
    matrix m = createMatrixFromArray(
            (int[]) {
                    0, 0,
                    0, 0,
                    7, 0
            }, 3, 2);

    assert(countZeroRows(m) == 2);

    freeMemMatrix(&m);
}

void test_fourteenthTask(){
    test_countZeroRows_notZeroRows();
    test_countZeroRows_includeZeroRows();
}

void test_getMaxNorm_zeroMatrix(){
    matrix m = createMatrixFromArray(
            (int[]) {
                    0, 0, 0,
                    0, 0, 0,
                    0, 0, 0
            }, 3, 3);

    assert(getMaxNorm(m) == 0);

    freeMemMatrix(&m);
}

void test_getMaxNorm_negativeElements(){
    matrix m = createMatrixFromArray(
            (int[]) {
                    -2, -9,
                    -15, -30
            }, 2, 2);

    assert(getMaxNorm(m) == 30);

    freeMemMatrix(&m);
}

void test_getMaxNorm_equalMaxNormElements(){
    matrix m = createMatrixFromArray(
            (int[]) {
                    -17, 5, 2,
                    -17, 10, 1,
                    -3, -17, 4
            }, 3, 3);

    assert(getMaxNorm(m) == 17);

    freeMemMatrix(&m);
}

void test_fifteenthTask(){
    test_getMaxNorm_zeroMatrix();
    test_getMaxNorm_negativeElements();
    test_getMaxNorm_equalMaxNormElements();
}

void test_sixteenthTask_equalElements(){
    matrix m = createMatrixFromArray(
            (int[]) {
                    2, 2,
                    2, 2,
                    2, 2
            }, 3, 2);

    assert(sixteenthTask(m) == 0);

    freeMemMatrix(&m);
}

void test_sixteenthTask_includeSpecialElements(){
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    2, 3, 5, 5, 4,
                    6, 2, 6, 8, 12,
                    12, 12, 2, 1, 2
            }, 3, 5);

    assert(sixteenthTask(m1) == 4);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    2, 3, 5, 5, 4,
                    6, 2, 7, 8, 12,
                    12, 12, 2, 1, 2
            }, 3, 5);

    assert(sixteenthTask(m2) == 5);

    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_sixteenthTask(){
    test_sixteenthTask_equalElements();
    test_sixteenthTask_includeSpecialElements();
}


void test(){
    test_firstTask();
    test_secondTask();
    test_thirdTask();
    test_fourthTask();
    test_fifthTask();
    test_sixthTask();
    test_seventhTask();
    test_eighthTask();
    test_ninthTask();
    test_tenthTask();
    test_eleventhTask();
    test_twelfthTask();
    test_thirteenthTask();
    test_fourteenthTask();
    test_fifteenthTask();
    test_sixteenthTask();
}

int main(){
    test();
}

