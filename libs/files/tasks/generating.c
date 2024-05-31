#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORD_LENGTH 15
#define MAX_NUM_WORDS 5
#define NUM_LINES 10

//заполняет файл случайными квадратными матрицами
void generateFileWithRandomSquareMatrices(const char* filename, int numMatrices, int maxSize) {
    FILE *file = fopen(filename, "w");

    if (file == NULL) {
        printf("Ошибка открытия файла\n");
        return;
    }

    srand(time(NULL));

    for (int k = 0; k < numMatrices; k++) {
        int n = rand() % maxSize + 1;

        fprintf(file, "%d\n", n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                fprintf(file, "%d ", rand() % 100);
            }

            fprintf(file, "\n");
        }
    }

    fclose(file);
}

//заполняет файл случайными вещественными числами
void generateFileWithRandomDigits(const char* filename, int numNumbers) {
    FILE *file = fopen(filename, "w");

    if (file == NULL) {
        printf("Ошибка открытия файла\n");
        return;
    }

    srand(time(NULL));

    for (int i = 0; i < numNumbers; i++) {
        int precision = rand() % 6 + 1;
        float number = (float)rand() / RAND_MAX * 100;

        fprintf(file, "%.*f\n", precision, number);
    }

    fclose(file);
}

//заполняет файл случайным арифметическим выражением
void generateFileWithRandomMathExpression(const char* filename) {
    FILE *file = fopen(filename, "w");
    int num1, num2, num3;
    char operator, operator1;

    if (file == NULL) {
        printf("Ошибка открытия файла\n");
        return;
    }

    srand(time(NULL));

    num1 = rand() % 10;
    num2 = rand() % 10;
    operator = rand() % 4; // 0 - '+', 1 - '-', 2 - '*', 3 - '/'

    fprintf(file, "%d %c %d", num1, operator == 0 ? '+' : operator == 1 ? '-' : operator == 2 ? '*' : '/', num2);

    if (num1 < 5){
        num3 = rand() % 10;
        operator1 = rand() % 4;
        fprintf(file, " %c %d", operator1 == 0 ? '+' : operator1 == 1 ? '-' : operator1 == 2 ? '*' : '/', num3);
    }

    fclose(file);
}
