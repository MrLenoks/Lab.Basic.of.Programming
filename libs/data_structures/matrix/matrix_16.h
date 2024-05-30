#include "matrix.h"
#include "matrix.c"

#ifndef LAB_BASIC_OF_PROGRAMMING_MATRIX_16_H
#define LAB_BASIC_OF_PROGRAMMING_MATRIX_16_H

//Задание 1: меняет местами строки, в которых находятся максимальный и минимальный элементы.
void firstTask(matrix *m);

//Задание 2: упорядочивает строки матрицы по неубыванию наибольших элементов строк.
void secondTask(matrix m);

//Задание 3: упорядочивает столбцы матрицы по неубыванию минимальных элементов столбцов.
void thirdTask(matrix m);

//Задание 4: заменяет квадратную матрицу её квадратом.
matrix fourthTask(matrix m);

//Задание 5: транспонирует матрицу, если среди сумм элементов строк матрицы нет равных.
void fifthTask(matrix *m);

//Задание 6: определяет, являются ли две матрицы взаимообратными.
bool sixthTask(matrix m1, matrix m2);

//Задание 7: находит сумму максимальных элементов всех псевдодиагоналей.
long long seventhTask(matrix m);

//Задание 8: находит минимальный элемент в выделенной области.
int eighthTask(matrix m);

//Задание 9: сортирует точки по неубыванию их расстояний до начала координат.
void ninthTask(matrix m);

//Задание 10: определяет количество классов эквивалентных строк данной прямоугольной матрицы.
int tenthTask(matrix m);

//Задание 11: определяет количество особых элементов матрицы (элемент особый, если он больше суммы остальных элементов своего столбца).
int eleventhTask(matrix m);

//Задание 12: заменяет предпоследнюю строку матрицы первым
//из столбцов, в котором находится минимальный элемент матрицы.
void twelfthTask (matrix m);

//Задание 13: определяет число матриц, строки которых упорядочены по неубыванию элементов.
int thirteenthTask(matrix *ms, int nMatrix);

//Задание 14: выводит матрицы, имеющие наибольшее число нулевых строк.
void fourteenthTask(matrix *ms, int nMatrix);

//Задание 15: выводит матрицы с наименьшей нормой.
void fifteenthTask (matrix *ms, int nMatrix);

//Задание 16: считает количество особых элементов (элемент особый если в строке слева от него находятся только
//меньшие элементы, а справа – только бoльшие).
int sixteenthTask(matrix m);

//Задание 17: определяет индекс вектора в матрице, который имеет наибольший угол с заданным вектором.
int seventeenthTask (matrix m, int *b);

//Задача 18: Находит скалярное произведение строки, в которой находится наибольший элемент матрицы, на столбец с наименьшим элементом.
long long eighteenthTask(matrix m);

// функция-критерий для сравнения строк по максимальному элементу
int getMax(int* a, int n);

//сортирует строки по неубывнию наибольших элементов строк
void sortRowsByMaxElement(matrix m);

// функция-критерий для сравнения строк по минимальному элементу
int getMin(int *a, int n);

//упорядочивает столбцы матрицы по неубыванию минимальных элементов столбцов
void sortColsByMinElemnt(matrix m);

//умножает матрицы
matrix mulMatrices(matrix m1, matrix m2);

//возвращает квадрат матрицы, если она симметрична
matrix getSquareOfMatrixIfSymmetric(matrix m);

// функция-критерий для сравнения строк по сумме элементов
long long getSum(int* a, int nCols);

//проверяет элементы на уникальность
bool isUnique(long long *a, int n);

//транспонирует матрицу, если среди сумм элементов строк матрицы нет равных
void transposeIfMatrixHasNotEqualSumOfRows(matrix m);

//определяет, являются ли две матрицы взаимообратными
bool isMutuallyInverseMatrices(matrix m1, matrix m2);

//возвращает максимальное из двух чисел
int max(int a, int b);

//находит сумму максимальных элементов всех псевдодиагоналей
long long findSumOfMaxesOfPseudoDiagonal(matrix m);

//находит минимальный элемент в выделенной области
int getMinInArea(matrix m);

//вычисляет расстояние до начала координат
float getDistance(int *a, int n);

//сортирует строки матрицы по заданному критерию
void insertionSortRowsMatrixByRowCriteriaF(matrix m, float (*criteria)(int *, int));

//сортирует по расстоянию до начала координат
void sortByDistances(matrix m);

//функция сравнения, которая используется в функции qsort() для сортировки массива long long
int cmp_long_long(const void *pa, const void *pb);

//считает количество уникальных элементов в массиве a длиной n
int countNUnique(long long *a, int n);

//считает количество эквивалентных классов по суммам строк в матрице m
int countEqClassesByRowsSum(matrix m);

//определяет количество особых элементов матрицы (элемент особый, если он больше суммы остальных элементов своего столбца)
int getNSpecialElement(matrix m);

//ищет минимальный элемент в первой строке матрицы
position getLeftMin(matrix m);

//заменяет предпоследнюю строку матрицы первым из столбцов, в котором находится минимальный элемент матрицы
void swapPenultimateRow(matrix m);

//возвращает - "истина", если матрица отсортирована, иначе - "ложь"
bool isNonDescendingSorted(int *a, int n);

//если хотя бы одна строка не является неубывающей, функция возвращает false,
//иначе возвращает true.
bool hasAllNonDescendingRows(matrix m);

//определяет число матриц, строки которых упорядочены по неубыванию элементов
int countNonDescendingRowsMatrices(matrix *ms, int nMatrix);

//счетчик значений
int countValues(const int *a, int n, int value);

//счетчик нулевых строк
int countZeroRows(matrix m);

//выводит матрицы, имеющие наибольшее число нулевых строк
void printMatrixWithMaxZeroRows(matrix *ms, int nMatrix);

//находит максимальную норму матрицы
int getMaxNorm(matrix m);

//выводит матрицы с наименьшей нормой
void printMatricesWithMinNorm(matrix *ms, int nMatrix);

//находит минимальный элемент
int min2(int a, int b);

//определяет количество особых элементов в матрице
int getNSpecialElement2(matrix m);

//возвращает скалярное произведение двух векторов
double getScalarProduct(int *a, int *b, int n);

//находит длину вектора
double getVectorLength(int *a, int n);

//получает косинус угла между векторами
double getCosine(int *a, int *b, int n);

//определяет индекс вектора в матрице, который имеет наибольший угол с заданным вектором
int getVectorIndexWithMaxAngle(matrix m, int *b);

//вычисляет скалярное произведение строки i и столбца j матрицы m
long long getScalarProductRowAndCol(matrix m, int i, int j);

//находит скалярное произведение строки, в которой находится наибольший элемент матрицы, на столбец с наименьшим элементом.
long long getSpecialScalarProduct(matrix m);

#endif //LAB_BASIC_OF_PROGRAMMING_MATRIX_16_H
