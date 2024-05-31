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

//Задание 2: в файле, где записаны вещественные числа с различным количеством цифр
// после запятой, оставить только две цифры после запятой
int task_2(const char *str) {
    FILE *inputFile, *outputFile;
    float number;

    inputFile = fopen("C:/Users/Pasha/CLionProjects/OP/Lab.Basic.of.Programming/libs/files/txt/task_2(1).txt";, "r");
    outputFile = fopen("C:/Users/Pasha/CLionProjects/OP/Lab.Basic.of.Programming/libs/files/txt/task_2(2).txt", "w");

    if (inputFile == NULL || outputFile == NULL) {
        printf("Ошибка открытия файлов.\n");
        return 1;
    }

    while (fscanf(inputFile, "%f", &number) == 1) {
        fprintf(outputFile, "%.2f\n", number);
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}

//вычисляет значение выражения, состоящего из двух операндов
int calculate(int num1, char op, int num2) {
    switch(op) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            if (num2 != 0) {
                return num1 / num2;
            } else {
                printf("\nОшибка деления на ноль!");
                return -1;
            }
        default:
            printf("\nОшибка: неверный оператор\n");
            return -1;
    }
}

//Задание 3: в файле, где записано одно арифметическое выражение с одной или двумя операциями,
//записать ответ, решив данное выражение (операнды - однозначные числа)
int task_3(const char *str) {
    FILE *file, *file1;
    char expression[100];
    int result;
    char ch;
    int count = 0;

    file = fopen("C:/Users/Pasha/CLionProjects/OP/Lab.Basic.of.Programming/libs/files/txt/task_3(1).txt", "r");
    if (file == NULL) {
        printf("Ошибка открытия файла\n");
        return 1;
    }

    while ((ch = fgetc(file)) != EOF) {
        count++;
    }

    fclose(file);

    file1 = fopen("C:/Users/Pasha/CLionProjects/OP/Lab.Basic.of.Programming/libs/files/txt/task_3(2).txt", "r+");

    int num1, num2, num3;
    char op1, op2;

    if (count == 5){
        fscanf(file1, "%d %c %d", &num1, &op1, &num2);

        result = calculate(num1, op1, num2);
    } else if (count == 9){
        fscanf(file1, "%d %c %d %c %d", &num1, &op1, &num2, &op2, &num3);

        result = calculate(num1, op1, num2);
        if (result != -1) {
            result = calculate(result, op2, num3);
        }
    } else {
        fclose(file1);
    }

    fprintf(file1, "\nРезультат: %d\n", result);

    fclose(file1);

    return 0;
}

//Задание 4: сохранить в файле только те слова, которые содержат данную последовательность символов
int task_4(const char* sourceFilename, const char* destinationFilename, const char* sequence) {
    FILE *sourceFile, *destinationFile;

    sourceFile = fopen(sourceFilename, "r");
    if (sourceFile == NULL) {
        printf("Ошибка открытия исходного файла\n");
        return 1;
    }

    destinationFile = fopen(destinationFilename, "w");
    if (destinationFile == NULL) {
        printf("Ошибка открытия файла назначения\n");
        fclose(sourceFile);
        return 1;
    }

    char word[MAX_LENGTH];

    while (fscanf(sourceFile, "%s", word) == 1) {
        if (strstr(word, sequence) != NULL) {
            fprintf(destinationFile, "%s\n", word);
        }
    }

    fclose(sourceFile);
    fclose(destinationFile);

    return 0;
}

//Задание 5: преобразовать файл, оставив в каждой строке только самое длинное слово
int task_5(const char* sourceFilename, const char* destinationFilename) {
    FILE *sourceFile, *destinationFile;

    sourceFile = fopen(sourceFilename, "r");
    if (sourceFile == NULL) {
        printf("Ошибка открытия исходного файла\n");
        return 1;
    }

    destinationFile = fopen(destinationFilename, "w");
    if (destinationFile == NULL) {
        printf("Ошибка открытия файла назначения\n");
        fclose(sourceFile);
        return 1;
    }

    char line[MAX_LENGTH];
    char longestWord[MAX_LENGTH];
    int maxLength = 0;

    while (fgets(line, sizeof(line), sourceFile)) {
        char* word = strtok(line, " ");
        char* lastWord = NULL;
        while (word != NULL) {
            int length = strlen(word);
            if (length > maxLength) {
                maxLength = length;
                strcpy(longestWord, word);
            }

            lastWord = word;
            word = strtok(NULL, " ");
        }

        fprintf(destinationFile, "%s\n", longestWord);

        maxLength = 0;
    }

    fclose(sourceFile);
    fclose(destinationFile);

    return 0;
}

typedef struct {
    int power;
    int coefficient;
} Polynomial;

//возводит число в степень
int pow_(int base, int exp) {
    int result = 1;
    while (exp > 0) {
        result *= base;
        exp--;
    }

    return result;
}

//Задание 6: удалить многочлены с корнем x из бинарного файла
void task_6(const char *filename, int x) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Ошибка открытия исходного файла\n");
        exit(-3);
    }

    FILE *temp_file = fopen("C:/Users/Pasha/CLionProjects/OP/Lab.Basic.of.Programming/libs/files/txt/task_6(2).txt", "wb");

    if (!temp_file) {
        printf("Ошибка открытия файла назначения\n");
        fclose(file);
        exit(-3);
    }

    Polynomial poly;

    while (fread(&poly, sizeof(Polynomial), 1, file)) {
        if ((poly.coefficient * pow_(x, poly.power)) != (x * x)) {
            fwrite(&poly, sizeof(Polynomial), 1, temp_file);
        }
    }

    fclose(file);
    fclose(temp_file);
}

//Задание 7: записать в файле сначала положительные, а затем отрицательные
//числа, сохраняя порядок их следования
void task_7(const char *filename) {
    FILE *file = fopen(filename, "rb");

    if (file == NULL) {
        printf("Ошибка открытия исходного файла\n");
        exit(-3);
    }

    FILE *result_file = fopen("C:/Users/Pasha/CLionProjects/OP/Lab.Basic.of.Programming/libs/files/txt/task_7(2).txt", "wb");

    if (result_file == NULL) {
        printf("Ошибка открытия файла назначения\n");
        fclose(file);
        exit(-3);
    }

    int positive_number;

    while (fread(&positive_number, sizeof(positive_number), 1, file)) {
        if (positive_number > 0) {
            fwrite(&positive_number, sizeof(positive_number), 1, result_file);
        }
    }

    fclose(file);

    file = fopen(filename, "rb");

    int negative_number;

    while (fread(&negative_number, sizeof(negative_number), 1, file)) {
        if (negative_number < 0) {
            fwrite(&negative_number, sizeof(negative_number), 1, result_file);
        }
    }

    fclose(file);
    fclose(result_file);
}

//Задание 8: преобразовать файл, заменив в нём каждую матрицу, не являющуюся симметричной, транспонированной
void task_8(const char *filename) {
    FILE *file = fopen(filename, "rb");

    if (file == NULL) {
        printf("Ошибка открытия исходного файла\n");
        exit(-3);
    }

    FILE *result_file = fopen" C:/Users/Pasha/CLionProjects/OP/Lab.Basic.of.Programming/libs/files/txt/task_8(2).txt", "wb");

    if (result_file == NULL) {
        printf("Ошибка открытия файла назначения\n");
        fclose(file);
        exit(-3);
    }

    matrix m;

    while (fread(&m, sizeof(matrix), 1, file)) {
        if (!isSymmetricMatrix(&m)) {
            transposeMatrix(&m);
            fwrite(&m, sizeof(matrix), 1, result_file);
        } else {
            fwrite(&m, sizeof(matrix), 1, result_file);
        }
    }

    fclose(file);
    fclose(result_file);
}

typedef struct {
    char *initials;
    int score;
} Sportsman;


//добавляет нового спортсмена в массив
void appendS(Sportsman *a, size_t *const size, Sportsman value) {
    a[*size] = (Sportsman) value;
    (*size)++;
}

//Задание 9: В бинарном файле структур хранится информация о спортсменах: Ф.И.О., наилучший результат.
//Требуется сформировать команду из n лучших спортсменов.
//Преобразовать файл, сохранив в нем информацию только о членах команды.
void task_9(const char *filename, int n) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Ошибка открытия исходного файла\n");
        exit(-3);
    }

    FILE *result_file = fopen("C:/Users/Pasha/CLionProjects/OP/Lab.Basic.of.Programming/libs/files/txt/task_9(2).txt", "wb");
    if (result_file == NULL) {
        printf("Ошибка открытия файла назначения\n");
        fclose(file);
        exit(-3);
    }

    size_t size = 0;
    Sportsman persons[MAX_LENGTH];
    Sportsman person;

    while (fread(&person, sizeof(Sportsman), 1, file)) {
        appendS(persons, &size, person);
    }

    for (int i = 0; i < n; ++i) {
        Sportsman temp_player = {NULL, -999};
        int idx = 0;

        for (int j = 0; j < size; ++j) {
            if (persons[j].score > temp_player.score) {
                temp_player.score = persons[j].score;
                temp_player.initials = persons[j].initials;
                idx = j;
            }
        }

        persons[idx].score = -999;
        fwrite(&temp_player, sizeof(Sportsman), 1, result_file);
    }

    fclose(file);
    fclose(result_file);
}


