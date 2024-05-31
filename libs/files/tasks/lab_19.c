#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include "C:/Users/darya/CLionProjects/Basics-of-programming-labs/libs/data_structures/matrix/matrix.c"

#define MAX_FILE_SIZE 1024
#define MAX_LENGTH 100

//сравнивает два файла на равенство
void assertTXT(const char *file1, const char *file2) {
    FILE *f1 = fopen(file1, "r");
    FILE *f2 = fopen(file2, "r");

    if (f1 == NULL || f2 == NULL) {
        printf("Ошибка...\n");

        return;
    }

    char buffer1[MAX_FILE_SIZE];
    char buffer2[MAX_FILE_SIZE];

    while (fgets(buffer1, MAX_FILE_SIZE, f1) != NULL && fgets(buffer2, MAX_FILE_SIZE, f2) != NULL) {
        if (strcmp(buffer1, buffer2) != 0) {
            printf("Ошибка: файлы не одинаковые...\n");

            fclose(f1);
            fclose(f2);

            return;
        }
    }

    printf("Всё работает! \n");
}

//Задание 1: в файле, где хранятся квадратные матрицы, транспонировать их
int task_1(const char *str1) {
    FILE *inputFile, *outputFile;
    int n, i, j;


    //открываем исходный файл для чтения
    inputFile = fopen"C:/Users/Pasha/CLionProjects/OP/Lab.Basic.of.Programming/libs/files/txt/task_1(1).txt";"r");

    if (inputFile == NULL) {
        printf("Ошибка открытия файла\n");

        return 1;
    }

    //открываем новый файл для записи
    outputFile = fopen("C:/Users/Pasha/CLionProjects/OP/Lab.Basic.of.Programming/libs/files/txt/task_1(2).txt";"w");

    if (outputFile == NULL) {
        printf("Ошибка открытия файла\n");
        fclose(inputFile);

        return 1;
    }

    while (fscanf(inputFile, "%d", &n) == 1) {
        int matrix[n][n];

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                fscanf(inputFile, "%d", &matrix[i][j]);
            }
        }

        for (j = 0; j < n; j++) {
            for (i = 0; i < n; i++) {
                fprintf(outputFile, "%d ", matrix[i][j]);
            }

            fprintf(outputFile, "\n");
        }
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}


