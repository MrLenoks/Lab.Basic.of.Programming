#include <stdio.h>
#include "lab_20.c"
#include "../string/tasks/string_.h"
#include <assert.h>
#include <windows.h>
#include <conio.h>
#include <signal.h>
#include <unistd.h>

void test_firstTask_exampleFromTextbook(){
    int n = 3;
    matrix got = getMemMatrix(n, n);
    matrixFillingZeros(&got, n, n);

    int countRequests = 2;
    int firstRequest[4] = {1, 1, 2, 2};
    int secondRequest[4] = {0, 0, 1, 1};
    int *requests[2] = {firstRequest, secondRequest};

    firstTask(&got, countRequests, requests);

    matrix expected = createMatrixFromArray(
            (int[]) {
                    1, 1, 0,
                    1, 2, 1,
                    0, 1, 1
            }, 3, 3
    );

    assert(areTwoMatricesEqual(&got, &expected));
}

void test_firstTask_secondOrderSquareMatrix(){
    int n = 2;
    matrix got = getMemMatrix(n, n);
    matrixFillingZeros(&got, n, n);

    int countRequests = 2;
    int firstRequest[4] = {0, 0, 1, 1};
    int secondRequest[4] = {0, 0, 0, 1};
    int *requests[2] = {firstRequest, secondRequest};

    firstTask(&got, countRequests, requests);

    matrix expected = createMatrixFromArray(
            (int[]) {
                    2, 2,
                    1,1
            }, 2, 2
    );

    assert(areTwoMatricesEqual(&got, &expected));
}

void test_firstTask_fourthOrderSquareMatrix(){
    int n = 4;
    matrix got = getMemMatrix(n, n);
    matrixFillingZeros(&got, n, n);

    int countRequests = 3;
    int firstRequest[4] = {0,0,3,3};
    int secondRequest[4] = {1,1,2,2};
    int thirdRequest[4] = {2,2,3,3};
    int *requests[3] = {firstRequest, secondRequest, thirdRequest};

    firstTask(&got, countRequests, requests);

    matrix expected = createMatrixFromArray(
            (int[]) {
                    1, 1, 1, 1,
                    1, 2, 2, 1,
                    1, 2, 3, 2,
                    1, 1, 2, 2
            }, 4, 4
    );

    assert(areTwoMatricesEqual(&got, &expected));
}

void test_firstTask(){
    test_firstTask_exampleFromTextbook();
    test_firstTask_secondOrderSquareMatrix();
    test_firstTask_fourthOrderSquareMatrix();
}


int test(){
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
}

int main(){
    SetConsoleOutputCP(CP_UTF8);

    test();

    return 0;
