#ifndef BASICS_OF_PROGRAMMING_LABS_LAB_20_H
#define BASICS_OF_PROGRAMMING_LABS_LAB_20_H

#include <stdbool.h>
#include "../data_structures/matrix/matrix.h"
#include <signal.h>
#include <unistd.h>

typedef struct domain{
    size_t visits;
    char name[200];
} domain;

typedef struct node {
    int key;
    struct node *left;
    struct node *right;
} node;

//заполняет матрицу нулями
void matrixFillingZeros(matrix *m, int row, int col);

//Задание 1: дано n - порядок квадратной матрицы, заполненной нулями, и двумерный целочисленный массив query.
//Необходимо выполнить следующую операцию: query[i] = [row1i, col1i, row2i, col2i]
void firstTask(matrix *m, int countRequests, int *requestsArray[]);

//проверяет, находится ли переданный индекс в пределах матрицы заданных размеров (rows, cols)
bool isIndex(int rows, int cols, int indRow, int indCol);

//определяет состояние ячейки в новой матрице на основе правил игры "Жизнь" и количества соседей вокруг ячейки
int cellResultByPosition(matrix m, int indRow, int indCol, int countNeighbors);

//производит обновление матрицы newM на основе матрицы m, применяя правила игры "Жизнь" для каждой ячейки
int calculateCountNeighbors(matrix m, int rowInd, int colInd, int rows, int cols);

//Задание 2: вернуть следующее состояние ячейки, применяя правила игры "Жизнь"
void secondTask(matrix m, matrix *newM, int rows, int cols);

//сравнивает два числа, переданные через указатели
int sortedNumsCompare(const void * firstNum, const void * secondNum);

//заполняет массив чисел значениями из матрицы и сортирует его в порядке возрастания
void fillingNumFrameSorted(int *array, matrix m, int indRow, int indCol);

//Задание 3: обрабатывает матрицу медианным фильтром
void thirdTask(matrix *m, int size);

//выводит содержимое массива структур
void outputResultDomains(domain *results, int size);

//ищет заданное число в массиве целых чисел
bool searchNumFromArray(const int array[], int length, int num);

//ищет заданный домен в массиве структур и возвращает индекс этого домена
int searchDomainInResults(const domain results[], int size, char *s);

//обрабатывает случай, когда у домена есть точка, разделяющая домен верхнего уровня и поддомен
void handlerDotPrtNotNull(domain *array, int ind, char *dotPtr, domain results[], int *sizeResult);

//Задание 4: возвращает массив доменов с парным счетчиком для каждого поддомена во входных данных
void fourthTask(domain array[], int size);

//заполняет новую матрицу на основе данной
void fillingCalcMatrix(matrix m, matrix *calcMatrix, int rows, int cols);

//Задание 5: возвращает количество подматриц, в которых все единицы
void fifthTask(matrix m, int rows, int cols, int *result);

//Задание 6: дан строковый шаблон длины n с нулевым индексом, состоящий из символов «I», означающих
//увеличение, и «D», означающих уменьшение. Вернуть лексикографическую наименьшую возможную строку num, соответствующую условиям
void sixthTask(const char *s, int length, char *result, int *resultLength);

//создает новый узел дерева с заданным ключом
node *createNode(int k);

//находит индекс элемента с максимальным значением в заданном массиве между двумя заданными индексами
int searchMaxInd(int array[], int start, int end);

//строит дерево из узлов на основе заданного массива и текущего узла
void buildNodes(node *currentNode, int array[], int startInd, int endInd, bool isLeft);

//выполняет обход в ширину дерева и выводит значения узлов на экран
void breadthFirstTraversal(node *root);

//Задание 7: дан целочисленный массив nums. Верните максимальное двоичное дерево, построенное из nums.
void seventhTask(int array[], int lengthArray);

//Задание 8: даны строка s и целочисленный массив indices одинаковой длины. Строка s будет перетасована
//таким образом, что символ в позиции [i] переместится в перетасованную строку indices[i].
void eighthTask(const char *s, int length, const int indexes[], char *newS);

//открывает файл с заданным именем в заданном режиме и возвращает указатель на FILE
FILE* openFile(char *fileName, char *action);

//заполняет файл целочисленными значениями из массива
void fillingFile(int numsArray[], int lengthArray, char *fileName);

//считывает числа из файла, фильтрует их по значению controlNum, записывая их в вектор и одновременно в файл
void readingNumsFilteringAndWriting(vector *v, char *rFileName, int controlNum, char *wFileName);

//Задание 9: В файле записана последовательность целых чисел. Создать файл, состоящий из чисел данного файла, значения которых меньше N.
//Имена файлов и величина N задаются в командной строке.
void ninthTask(int numsArray[], int lengthArray, int controlNum, char *firstFileName, char *secondFileName, vector *v);

//записывает данный текст в указанный файл
void fillingFileWithText(char *fileName, char *text);

//Задание 10: выдает на экран содержимое файла порциями по N строк:
// каждая последующая порция выдается после нажатия клавиш Ctrl+C.
void tenthTask(char *fileName, size_t countOutputLines, char *text);

//Задание 11: Дан словарь из N различных слов, состоящих из строчных английских букв.
// Вам приходит Q запросов, i-й из которых состоит из строки pi из строчных английских букв и числа ki.
// В ответ на i-й запрос вы должны вывести ki-е в лексикографическом порядке слово
// из словаря среди слов, имеющих pi в качестве префикса.
void eleventhTask(char **dict, char **requests, int *num_in_req, int n, int q);

#endif //BASICS_OF_PROGRAMMING_LABS_LAB_20_H
