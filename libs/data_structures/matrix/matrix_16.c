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

//определяет, являются ли две матрицы взаимообратными
bool isMutuallyInverseMatrices(matrix m1, matrix m2){
    if (m1.nRows != m2.nRows || m1.nCols != m2.nCols) {
        return 0;
    }

    for (int i = 0; i < m1.nRows; i++) {
        for (int j = 0; j < m2.nCols; j++) {
            int sum = 0;

            for (int k = 0; k < m1.nCols; k++) {
                sum += m1.values[i][k] * m2.values[k][j];
            }

            if (i == j && sum != 1) {
                return 0;
            } else if (i != j && sum != 0) {
                return 0;
            }
        }
    }

    return 1;
}

//Задача 6: определяет, являются ли две матрицы взаимообратными.
bool sixthTask(matrix m1, matrix m2){
    return isMutuallyInverseMatrices(m1, m2);
}

//возвращает максимальное из двух чисел
int max(int a, int b){
    return a > b ? a : b;
}

//находит сумму максимальных элементов всех псевдодиагоналей
long long findSumOfMaxesOfPseudoDiagonal(matrix m) {
    long long sum = 0;

    for (int i = 0; i < m.nRows; i++) {
        m.values[i][i] = 0;
    }

    for (int k = 0; k < m.nCols + m.nRows - 1; k++) {
        int maxInDiagonal = INT_MIN;
        int cols = max(0, k - m.nRows + 1);
        int rows = max(0, m.nRows - k - 1);

        while (cols < m.nCols && rows < m.nRows) {
            maxInDiagonal = max(maxInDiagonal, m.values[rows][cols]);
            cols++;
            rows++;
        }

        sum += maxInDiagonal;
    }

    return sum;
}

//Задача 7: находит сумму максимальных элементов всех псевдодиагоналей.
long long seventhTask(matrix m){
    return findSumOfMaxesOfPseudoDiagonal(m);
}

//находит минимальный элемент в выделенной области
int getMinInArea(matrix m){
    int maxRow = 0, maxCol = 0;
    int i, j;

    for (i = 0; i < m.nRows; i++) {
        for (j = 0; j < m.nCols; j++) {
            if (m.values[i][j] > m.values[maxRow][maxCol]) {
                maxRow = i;
                maxCol = j;
            }
        }
    }

    int min[m.nRows * m.nCols];
    int minVal = m.values[maxRow][maxCol];

    for (i = 0; i <= maxRow; i++) {
        for (j = 0; j < m.nCols; j++) {
            int difference = abs(maxRow - i);

            if ((abs(maxCol - j)) <= difference) {
                if (m.values[i][j] < minVal) {
                    minVal = m.values[i][j];
                }
            }
        }
    }

    return minVal;
}

//Задача 8: находит минимальный элемент в выделенной области.
int eighthTask(matrix m){
    return getMinInArea(m);
}

//вычисляет расстояние до начала координат
float getDistance(int *a, int n) {
    float distance = 0.0;

    for (int i = 0; i < n; i++) {
        distance += a[i] * a[i];
    }

    return sqrt(distance);
}

//сортирует строки матрицы по заданному критерию
void insertionSortRowsMatrixByRowCriteriaF(matrix m, float (*criteria)(int *, int)) {
    for (int i = 1; i < m.nRows; i++) {
        int *currentRow = m.values[i];
        int j = i - 1;

        while (j >= 0 && criteria(m.values[j], m.nCols) > criteria(currentRow, m.nCols)) {
            m.values[j + 1] = m.values[j];
            j--;
        }

        m.values[j + 1] = currentRow;
    }
}

//сортирует по расстоянию до начала координат
void sortByDistances(matrix m) {
    insertionSortRowsMatrixByRowCriteriaF(m, getDistance);
}

//Задание 9: сортирует точки по неубыванию их расстояний до начала координат.
void ninthTask(matrix m) {
    sortByDistances(m);
}

//функция сравнения, которая используется в функции qsort() для сортировки массива long long
int cmp_long_long(const void *pa, const void *pb) {
    const long long *a = (const long long *)pa;
    const long long *b = (const long long *)pb;

    return (*a > *b) - (*a < *b);
}

//считает количество уникальных элементов в массиве a длиной n
int countNUnique(long long *a, int n) {
    if (n == 0) {
        return 0;
    }

    int count = 0;
    long long prev = a[0];

    for (int i = 1; i < n; i++) {
        if (a[i] != prev) {
            count++;
            prev = a[i];
        }
    }

    return count + 1;
}


//считает количество эквивалентных классов по суммам строк в матрице m
int countEqClassesByRowsSum(matrix m) {
    long long sums[m.nRows];

    for (int i = 0; i < m.nRows; i++) {
        int sum = 0;

        for (int j = 0; j < m.nCols; j++) {
            sum += m.values[i][j];
        }

        sums[i] = sum;
    }

    qsort(sums, m.nRows, sizeof(long long), cmp_long_long);

    return countNUnique(sums, m.nRows);
}

//Задача 10: определяет количество классов эквивалентных строк данной прямоугольной матрицы.
int tenthTask(matrix m){
    return countEqClassesByRowsSum(m);
}

//определяет количество особых элементов матрицы (элемент особый, если он больше суммы остальных элементов своего столбца)
int getNSpecialElement(matrix m) {
    int count = 0;

    for (int j = 0; j < m.nCols; j++) {
        for (int i = 0; i < m.nRows; i++) {
            int sum = 0;
            for (int k = 0; k < m.nRows; k++) {
                if (k != i) {
                    sum += m.values[k][j];
                }
            }

            if (m.values[i][j] > sum) {
                count++;
            }
        }
    }

    return count;
}

//Задание 11: определяет количество особых элементов матрицы (элемент особый, если он больше суммы остальных элементов своего столбца).
int eleventhTask(matrix m){
    return getNSpecialElement(m);
}

//ищет минимальный элемент в первой строке матрицы
position getLeftMin(matrix m) {
    position minPos;
    minPos.rowIndex = 0;
    minPos.colIndex = 0;

    int minValue = m.values[0][0];

    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            if (m.values[i][j] < minValue) {
                minValue = m.values[i][j];
                minPos.rowIndex = i;
                minPos.colIndex = j;
            }
        }
    }

    return minPos;
}

//заменяет предпоследнюю строку матрицы первым из столбцов, в котором находится минимальный элемент матрицы
void swapPenultimateRow(matrix m) {
    position minPos = getLeftMin(m);

    int element = m.values[m.nRows - (m.nRows - 1)][minPos.colIndex];

    for (int i = 0; i < m.nCols; i++) {
        m.values[m.nRows - 2][i] = m.values[i][minPos.colIndex];
    }

    m.values[m.nRows - 2][1] = element;
}

//Задача 12: заменяет предпоследнюю строку квадратной матрицы первым
//из столбцов, в котором находится минимальный элемент матрицы.
void twelfthTask (matrix m){
    if (isSquareMatrix(&m)){
        swapPenultimateRow(m);
    }
}

//возвращает - "истина", если матрица отсортирована, иначе - "ложь"
bool isNonDescendingSorted(int *a, int n) {
    for (int i = 1; i < n; i++) {
        if (a[i] < a[i-1]) {
            return 0;
        }
    }

    return 1;
}

//если хотя бы одна строка не является неубывающей, функция возвращает false,
//иначе возвращает true.
bool hasAllNonDescendingRows(matrix m) {
    for (int i = 0; i < m.nRows; i++) {
        if (!isNonDescendingSorted(m.values[i], m.nCols)) {
            return 0;
        }
    }

    return 1;
}

//определяет число матриц, строки которых упорядочены по неубыванию элементов
int countNonDescendingRowsMatrices(matrix *ms, int nMatrix) {
    int count = 0;

    for (int i = 0; i < nMatrix; i++) {
        if (hasAllNonDescendingRows(ms[i])) {
            count++;
        }
    }

    return count;
}

//Задание 13: определяет число матриц, строки которых упорядочены по неубыванию элементов.
int thirteenthTask(matrix *ms, int nMatrix) {
    return countNonDescendingRowsMatrices(ms, nMatrix);
}

//счетчик значений
int countValues(const int *a, int n, int value) {
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] == value) {
            count++;
        }
    }

    return count;
}

//счетчик нулевых строк
int countZeroRows(matrix m) {
    int count = 0;

    for (int i = 0; i < m.nRows; i++) {
        int zeroCount = countValues(m.values[i], m.nCols, 0);

        if (zeroCount == m.nCols) {
            count++;
        }
    }

    return count;
}

//выводит матрицы, имеющие наибольшее число нулевых строк
void printMatrixWithMaxZeroRows(matrix *ms, int nMatrix) {
    int maxZeroRows = 0;

    for (int i = 0; i < nMatrix; i++) {
        int zeroRows = countZeroRows(ms[i]);

        if (zeroRows > maxZeroRows) {
            maxZeroRows = zeroRows;
        }
    }

    for (int i = 0; i < nMatrix; i++) {
        if (countZeroRows(ms[i]) == maxZeroRows) {
            outputMatrix(ms[i]);
        }

        printf("\n");
    }
}

//Задание 14: выводит матрицы, имеющие наибольшее число нулевых строк.
void fourteenthTask(matrix *ms, int nMatrix) {
    printMatrixWithMaxZeroRows(ms, nMatrix);
}

//находит максимальную норму матрицы
int getMaxNorm(matrix m) {
    int maxNorm = 0;

    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            int absValue = abs(m.values[i][j]);

            if (absValue > maxNorm) {
                maxNorm = absValue;
            }
        }
    }

    return maxNorm;
}

//выводит матрицы с наименьшей нормой
void printMatricesWithMinNorm(matrix *ms, int nMatrix) {
    int minNorm = getMaxNorm(ms[0]);

    for (int i = 1; i < nMatrix; i++) {
        int norm = getMaxNorm(ms[i]);

        if (norm < minNorm) {
            minNorm = norm;
        }
    }

    for (int i = 0; i < nMatrix; i++) {
        if (getMaxNorm(ms[i]) == minNorm) {
            outputMatrix(ms[i]);

            printf("\n");
        }
    }
}

//Задание 15: выводит матрицы с наименьшей нормой.
void fifteenthTask (matrix *ms, int nMatrix) {
    printMatricesWithMinNorm(ms, nMatrix);
}

//находит минимальный элемент
int min2(int a, int b) {
    return (a < b) ? a : b;
}

//определяет количество особых элементов в матрице
int getNSpecialElement2(matrix m) {
    int special_elements = 0;

    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            int is_special = 1;

            for (int k = 0; k < j; k++) {
                if (m.values[i][k] >= m.values[i][j]) {
                    is_special = 0;

                    break;
                }
            }

            for (int k = j + 1; k < m.nCols; k++) {
                if (m.values[i][k] <= m.values[i][j]) {
                    is_special = 0;

                    break;
                }
            }

            if (is_special) {
                special_elements++;
            }
        }
    }

    return special_elements;
}

//Задание 16: считает количество особых элементов (элемент особый если в строке слева от него находятся только
//меньшие элементы, а справа – только бoльшие).
int sixteenthTask(matrix m) {
    return getNSpecialElement2(m);
}

//возвращает скалярное произведение двух векторов
double getScalarProduct(int *a, int *b, int n) {
    double product = 0;

    for (int i = 0; i < n; i++) {
        product += a[i] * b[i];
    }

    return product;
}

//находит длину вектора
double getVectorLength(int *a, int n) {
    double length = 0;

    for (int i = 0; i < n; i++) {
        length += a[i] * a[i];
    }

    return sqrt(length);
}

//получает косинус угла между векторами
double getCosine(int *a, int *b, int n) {
    double product = getScalarProduct(a, b, n);
    double lengthA = getVectorLength(a, n);
    double lengthB = getVectorLength(b, n);

    if (lengthA == 0 || lengthB == 0) {
        return -1;
    }

    return product / (lengthA * lengthB);
}

//определяет индекс вектора в матрице, который имеет наибольший угол с заданным вектором
int getVectorIndexWithMaxAngle(matrix m, int *b) {
    int maxIndex = -1;
    double maxAngle = -2;

    for (int i = 0; i < m.nRows; i++) {
        double angle = getCosine(b, m.values[i], m.nCols);

        if (angle > maxAngle) {
            maxAngle = angle;
            maxIndex = i;
        }
    }

    return maxIndex;
}

//Задание 17: определяет индекс вектора в матрице, который имеет наибольший угол с заданным вектором.
int seventeenthTask (matrix m, int *b) {
    return getVectorIndexWithMaxAngle(m, b);
}

//вычисляет скалярное произведение строки i и столбца j матрицы m
long long getScalarProductRowAndCol(matrix m, int i, int j) {
    long long result = 0;

    for (int k = 0; k < m.nCols; k++) {
        result += (long long)m.values[i][k] * m.values[k][j];
    }

    return result;
}

//находит скалярное произведение строки, в которой находится наибольший элемент матрицы, на столбец с наименьшим элементом.
long long getSpecialScalarProduct(matrix m) {
    int maxRowIndex = 0;
    int maxColIndex = 0;

    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            if (m.values[i][j] > m.values[maxRowIndex][maxColIndex]) {
                maxRowIndex = i;
                maxColIndex = j;
            }
        }
    }


    int minColIndex = 0;
    int minRowIndex = 0;

    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            if (m.values[i][j] < m.values[minRowIndex][minColIndex]) {
                minColIndex = j;
                minRowIndex = i;
            }
        }
    }

    return getScalarProductRowAndCol(m, maxRowIndex, minColIndex);
}

//Задача 18: Находит скалярное произведение строки, в которой находится наибольший элемент матрицы, на столбец с наименьшим элементом.
long long eighteenthTask(matrix m){
    if (isSquareMatrix(&m)) {
        return getSpecialScalarProduct(m);
    }
}

