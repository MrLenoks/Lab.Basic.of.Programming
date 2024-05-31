
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

//проверяет, находится ли переданный индекс в пределах матрицы заданных размеров (rows, cols)
bool isIndex(int rows, int cols, int indRow, int indCol){
    if (indRow > -1 && indRow < rows && indCol > -1 && indCol < cols){
        return 1;
    }

    return 0;
}

//определяет состояние ячейки в новой матрице на основе правил игры "Жизнь" и количества соседей вокруг ячейки
int cellResultByPosition(matrix m, int indRow, int indCol, int countNeighbors){
    return ((m.values[indRow][indCol] == 1 && (countNeighbors == 2 || countNeighbors == 3)) || (m.values[indRow][indCol] == 0 && countNeighbors == 3));
}

//производит обновление матрицы newM на основе матрицы m, применяя правила игры "Жизнь" для каждой ячейки
int calculateCountNeighbors(matrix m, int rowInd, int colInd, int rows, int cols){
    int countNeighbors = 0;

    for (int indRowMath = rowInd - 1; indRowMath < rowInd + 2; indRowMath++){
        for (int indColMath = colInd - 1; indColMath < colInd + 2; indColMath++){
            if (isIndex(rows, cols, indRowMath, indColMath) &&
                m.values[indRowMath][indColMath] && (rowInd != indRowMath || colInd != indColMath)){

                countNeighbors++;
            }
        }
    }

    return countNeighbors;
}

//Задание 2: вернуть следующее состояние ячейки, применяя правила игры "Жизнь"
void secondTask(matrix m, matrix *newM, int rows, int cols){
    for (int indRow = 0; indRow < rows; indRow++){
        for (int indCol = 0; indCol < cols; indCol++){
            int countNeighbors = calculateCountNeighbors(m, indRow, indCol, rows, cols);

            newM->values[indRow][indCol] = cellResultByPosition(m, indRow, indCol, countNeighbors);
        }
    }
}

//сравнивает два числа, переданные через указатели
int sortedNumsCompare(const void * firstNum, const void * secondNum){
    return ( *(int*)firstNum - *(int*)secondNum );
}

//заполняет массив чисел значениями из матрицы и сортирует его в порядке возрастания
void fillingNumFrameSorted(int *array, matrix m, int indRow, int indCol){
    int arrayInd = 0;
    for (int mIndRow = indRow - 1; mIndRow < indRow + 2; mIndRow++){
        for(int mIndCol = indCol - 1; mIndCol < indCol + 2; mIndCol++){
            if (mIndRow != indRow || mIndCol != indCol){
                array[arrayInd++] = m.values[mIndRow][mIndCol];
            }
        }
    }

    qsort(array, 8, sizeof(int), sortedNumsCompare);
}

//Задание 3: обрабатывает матрицу медианным фильтром
void thirdTask(matrix *m, int size){
    int frame[8];
    for (int indRow = 1; indRow < size - 1; indRow++){
        for(int indCol = 1; indCol < size - 1; indCol++){
            fillingNumFrameSorted(frame, *m, indRow, indCol);

            int median = (frame[3] + frame[4]) / 2;

            m->values[indRow][indCol] = median;
        }
    }
}

//выводит содержимое массива структур
void outputResultDomains(domain *results, int size){
    for (int i = 0; i < size; i++){
        printf("%ld %s\n", results[i].visits, results[i].name);
    }
}

//ищет заданное число в массиве целых чисел
bool searchNumFromArray(const int array[], int length, int num){
    for (int i = 0; i < length; i++){
        if (num == array[i]){
            return 1;
        }
    }

    return 0;
}

//ищет заданный домен в массиве структур и возвращает индекс этого домена
int searchDomainInResults(const domain results[], int size, char *s){
    for (int i = 0; i < size; i++){
        if (strcmp(results[i].name, s) == 0){
            return i;
        }
    }

    return size;
}

//обрабатывает случай, когда у домена есть точка, разделяющая домен верхнего уровня и поддомен
void handlerDotPrtNotNull(domain *array, int ind, char *dotPtr, domain results[], int *sizeResult){
    strcpy(array[ind].name, dotPtr + 1);

    int pos = searchDomainInResults(results, *sizeResult,array[ind].name);

    if (pos == *sizeResult){
        results[*sizeResult] = array[ind];
        *sizeResult += 1;
    } else{
        results[pos].visits += array[ind].visits;
    }
}

//Задание 4: возвращает массив доменов с парным счетчиком для каждого поддомена во входных данных
void fourthTask(domain array[], int size){
    int closeIndexes[size];
    int countClose = 0;
    domain results[200];
    int sizeResult = 0;

    for (int i = 0; i < size; i++){
        results[sizeResult++] = array[i];
    }

    while(countClose != size){
        for (int i = 0; i < size; i++){
            if (!searchNumFromArray(closeIndexes, countClose, i)){
                char *dotPtr = strchr(array[i].name, '.');

                if (dotPtr != NULL){
                    handlerDotPrtNotNull(array, i, dotPtr, results, &sizeResult);
                } else{
                    closeIndexes[countClose++] = i;
                }
            }
        }
    }

    outputResultDomains(results, sizeResult);
}



