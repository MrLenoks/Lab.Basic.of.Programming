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


