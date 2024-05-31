
#include <stdbool.h>
#include "../data_structures/matrix/matrix.h"
#include <signal.h>
#include <unistd.h>

//заполняет матрицу нулями
void matrixFillingZeros(matrix *m, int row, int col){
    for (int indRow = 0; indRow < row; indRow++){
        for (int indCol = 0; indCol < col; indCol++){
            m->values[indRow][indCol] = 0;
        }
    }
}

//Задание 1: дано n - порядок квадратной матрицы, заполненной нулями, и двумерный целочисленный массив query.
//Необходимо выполнить следующую операцию: query[i] = [row1i, col1i, row2i, col2i]
void firstTask(matrix *m, int countRequests, int *requestsArray[]){
    int row1, col1, row2, col2;

    for (int request = 0; request < countRequests; request++){
        row1 = requestsArray[request][0];
        col1 = requestsArray[request][1];
        row2 = requestsArray[request][2];
        col2 = requestsArray[request][3];

        for (int indRow = row1; indRow <= row2; indRow++){
            for (int indCol = col1; indCol <= col2; indCol++){
                m->values[indRow][indCol]++;
            }
        }
    }
}


