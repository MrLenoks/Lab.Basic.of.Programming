
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

//заполняет новую матрицу на основе данной
void fillingCalcMatrix(matrix m, matrix *calcMatrix, int rows, int cols){
    for (int indRow = 0; indRow < rows; indRow++){
        for (int indCol = 0; indCol < cols; indCol++){
            if (m.values[indRow][indCol] == 1){
                if (indRow != 0){
                    calcMatrix->values[indRow][indCol] = calcMatrix->values[indRow - 1][indCol] + 1;
                }
                else{
                    calcMatrix->values[indRow][indCol] = 1;
                }
            } else {
                calcMatrix->values[indRow][indCol] = 0;
            }
        }
    }
}

//Задание 5: возвращает количество подматриц, в которых все единицы
void fifthTask(matrix m, int rows, int cols, int *result){
    matrix calcMatrix = getMemMatrix(rows, cols);
    fillingCalcMatrix(m, &calcMatrix, rows, cols);

    int calcResult = 0;

    for (int indCol = 0; indCol < cols; indCol++){
        for (int indRow = 0; indRow < rows; indRow++){
            for (int indK = indCol + 1; indK < cols + 1; indK++){
                int min = calcMatrix.values[indRow][indCol];

                for (int indFromColToK = indCol; indFromColToK < indK; indFromColToK++){
                    if (calcMatrix.values[indRow][indFromColToK] < min){
                        min = calcMatrix.values[indRow][indFromColToK];
                    }
                }

                calcResult += min;
            }
        }
    }

    *result = calcResult;
}

//Задание 6: дан строковый шаблон длины n с нулевым индексом, состоящий из символов «I», означающих
//увеличение, и «D», означающих уменьшение. Вернуть лексикографическую наименьшую возможную строку num, соответствующую условиям
void sixthTask(const char *s, int length, char *result, int *resultLength){
    char buffer[10];
    int bufferLength = 0;
    int calcResultLength = 0;

    char num = '1';
    for (int i = 0; i < length; i++) {
        buffer[bufferLength++] = num++;

        if (s[i] == 'I') {
            while (bufferLength > 0){
                result[calcResultLength++] = buffer[--bufferLength];
            }
        }
    }

    buffer[bufferLength++] = num;

    while (bufferLength > 0){
        result[calcResultLength++] = buffer[--bufferLength];
    }

    result[calcResultLength] = '\0';
    *resultLength = calcResultLength;
}

//создает новый узел дерева с заданным ключом
node *createNode(int k) {
    node *newNode = (node *) malloc(sizeof(node));
    newNode->key = k;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

//находит индекс элемента с максимальным значением в заданном массиве между двумя заданными индексами
int searchMaxInd(int array[], int start, int end) {
    int maxNum = array[start];
    int maxInd = start;

    for (int i = start + 1; i <= end; i++) {
        if (array[i] > maxNum) {
            maxNum = array[i];
            maxInd = i;
        }
    }

    return maxInd;
}

//строит дерево из узлов на основе заданного массива и текущего узла
void buildNodes(node *currentNode, int array[], int startInd, int endInd, bool isLeft) {
    if (startInd > endInd) {
        return;
    }

    int maxInd = searchMaxInd(array, startInd, endInd);
    node *newNode = createNode(array[maxInd]);

    if (isLeft) {
        currentNode->left = newNode;
    } else {
        currentNode->right = newNode;
    }

    buildNodes(newNode, array, startInd, maxInd - 1, true);
    buildNodes(newNode, array, maxInd + 1, endInd, false);
}

//выполняет обход в ширину дерева и выводит значения узлов на экран
void breadthFirstTraversal(node *root) {
    if (root == NULL) {
        return;
    }

    node *queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        node *current = queue[front++];

        if (current != root) {
            printf(",");
        }

        if (current == NULL) {
            printf("null");
        } else {
            printf("%d", current->key);
            if(current->left != NULL || current->right != NULL) {
                queue[rear++] = current->left;
                queue[rear++] = current->right;
            }
        }
    }
}

//Задание 7: дан целочисленный массив nums. Верните максимальное двоичное дерево, построенное из nums.
void seventhTask(int array[], int lengthArray) {
    if (lengthArray == 0) {
        return;
    }

    int maxNumInd = searchMaxInd(array, 0, lengthArray - 1);
    node *root = createNode(array[maxNumInd]);

    buildNodes(root, array, 0, maxNumInd - 1, true);
    buildNodes(root, array, maxNumInd + 1, lengthArray - 1, false);

    breadthFirstTraversal(root);

    printf("\n");
}

//Задание 8: даны строка s и целочисленный массив indices одинаковой длины. Строка s будет перетасована
//таким образом, что символ в позиции [i] переместится в перетасованную строку indices[i].
void eighthTask(const char *s, int length, const int indexes[], char *newS){
    for (int i = 0; i < length; i++){
        newS[i] = s[indexes[i]];
    }

    newS[length] = '\0';
}

//открывает файл с заданным именем в заданном режиме и возвращает указатель на FILE
FILE* openFile(char *fileName, char *action){
    FILE *file = fopen(fileName, action);

    if (file == NULL) {
        printf("Ошибка при открытии файла\n");
        exit(1);
    }

    return file;
}

//заполняет файл целочисленными значениями из массива
void fillingFile(int numsArray[], int lengthArray, char *fileName){
    FILE *file = openFile(fileName, "w");

    for (int i = 0; i < lengthArray; i++){
        fprintf(file, "%d ", numsArray[i]);
    }

    fclose(file);
}

//считывает числа из файла, фильтрует их по значению controlNum, записывая их в вектор и одновременно в файл
void readingNumsFilteringAndWriting(vector *v, char *rFileName, int controlNum, char *wFileName){
    FILE *rFile = openFile(rFileName, "r");
    FILE *wFile = openFile(wFileName, "w");

    int num;

    while (fscanf(rFile, "%d", &num) == 1){
        if (num < controlNum){
            pushBack(v, num);

            fprintf(wFile, "%d ", num);
        }
    }

    fclose(rFile);
    fclose(wFile);
}

//Задание 9: В файле записана последовательность целых чисел. Создать файл, состоящий из чисел данного файла, значения которых меньше N.
//Имена файлов и величина N задаются в командной строке.
void ninthTask(int numsArray[], int lengthArray, int controlNum, char *firstFileName, char *secondFileName, vector *v){
    fillingFile(numsArray, lengthArray,firstFileName);
    readingNumsFilteringAndWriting(v, firstFileName, controlNum, secondFileName);
    shrinkToFit(v);
}

//записывает данный текст в указанный файл
void fillingFileWithText(char *fileName, char *text){
    FILE *file = openFile(fileName, "w");
    fprintf(file, "%s", text);
    fclose(file);
}

//Задание 10: выдает на экран содержимое файла порциями по N строк:
// каждая последующая порция выдается после нажатия клавиш Ctrl+C.
void tenthTask(char *fileName, size_t countOutputLines, char *text){
    fillingFileWithText(fileName, text);

    FILE *file = openFile(fileName, "r");

    char line[127];
    int count = 0;

    while (fgets(line, 127, file) != NULL) {
        printf("%s", line);
        count++;

        if (count == countOutputLines){
            printf("Please, press Ctrl + C\n");

            while (getch() != 3);
        }
    }
}

//Задание 11: Дан словарь из N различных слов, состоящих из строчных английских букв.
// Вам приходит Q запросов, i-й из которых состоит из строки pi из строчных английских букв и числа ki.
// В ответ на i-й запрос вы должны вывести ki-е в лексикографическом порядке слово
// из словаря среди слов, имеющих pi в качестве префикса.
void eleventhTask(char **dict, char **requests, int *num_in_req, int n, int q) {
    int temp_pepe = 0;
    int temp_pepe2 = 0;

    for (int i = 0; i < q; ++i) {
        for (int j = 0; j < n; ++j) {

            if (strstr(dict[j], requests[i]) != NULL) {
                temp_pepe++;
                temp_pepe2++;
            } else
                temp_pepe++;

            if (temp_pepe2 == num_in_req[i]) {
                printf("%d\n", temp_pepe);
                break;
            }
        }

        if (num_in_req[i] > temp_pepe2) {
            printf("-1\n");

            temp_pepe = 0;
            temp_pepe2 = 0;
        } else {
            temp_pepe = 0;
            temp_pepe2 = 0;
        }
    }
}



