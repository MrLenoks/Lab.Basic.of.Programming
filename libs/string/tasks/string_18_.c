#include "string_lab18_.h"
#include "string_.c"
#include <stdio.h>
#include <ctype.h>
#include <memory.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stddef.h>

char _stringBuffer[MAX_STRING_SIZE + 1];
BagOfWords _bag;
BagOfWords _bag2;

//находит конечный элемент строки
char* getEndOfString(char *s) {
    char *end = s;

    while (*end != '\0') {
        end++;
    }

    return end;
}

//удаляет из строки все пробельные символы
void removeNonLetters(char *s) {
    char *endSource = getEndOfString(s);
    char *destination = copyIf(s, endSource, s, isgraph);
    *destination = '\0';
}

//функция тестирования, которая даёт информацию о том, где именно произошла ошибка
void assertString(const char *expected, char *got, char const *fileName, char const *funcName, int line){
    if (strcmp(expected, got)){
        fprintf(stderr, "File %s\n", fileName);
        fprintf(stderr, "%s - failed on line %d\n", funcName, line);
        fprintf(stderr, "Expected: \"%s\"\n", expected);
        fprintf(stderr, "Got: \"%s\"\n\n", got);
    } else {
        fprintf(stderr, "%s - OK\n", funcName);
    }
}

//сокращает количество пробелов между словами данного предложения до одного
void removeExtraSpaces(char *s){
    char *begin = s;
    char *destination = begin;
    char last = *begin;

    while (*begin != '\0') {
        if (*begin != last || last != ' ') {
            *destination++ = *begin;
        }

        last = *begin++;
    }

    if (last == ' ') {
        destination--;
    }

    *destination = '\0';
}

//возвращает указатель на первый пробельный символ,
//расположенный на ленте памяти начиная с адреса begin
//или на первый ноль-символ
char* findSpace(char *begin) {
    while (*begin != '\0' && *begin != ' ') {
        begin++;
    }

    return begin;
}

//возвращает значение 0, если слово не было считано, иначе
//значение 1, в переменную word типа WordDescriptor
//записывает позиции начала слова, и первого символа после конца слова
int getWord(char *beginSearch, WordDescriptor *word) {
    word->begin = findNonSpace(beginSearch);

    if (*word->begin == '\0') {
        return 0;
    }

    word->end = findSpace(word->begin);

    return 1;
}

//преобразовывает слово таким образом, чтобы цифры были перенесены
//в начало слова и изменить порядок следования цифр в слове на обратный
void reversedDigitToStart(WordDescriptor word) {
    char *endStringBuffer = copy(word.begin, word.end, _stringBuffer);
    char *recPosition = copyIfReverse(endStringBuffer - 1, _stringBuffer - 1, word.begin, isdigit);

    copyIf(_stringBuffer, endStringBuffer, recPosition, isalpha);
}

//преобразовывает слово таким образом, чтобы цифры были перенесены в начало слова
void digitToStart(WordDescriptor word) {
    char *endStringBuffer = copy(word.begin, word.end,_stringBuffer);
    char *recPosition = copyIf(_stringBuffer,endStringBuffer,word.begin, isdigit);

    copyIf(_stringBuffer, endStringBuffer, recPosition, isalpha);
}

//преобразовывает строку таким образом, чтобы цифры каждого слова были
//перенесены в начало слова без изменения порядка следования их в слове,
//буквы перенесены в конец слова
void digitsToStart(char *s) {
    char *beginSearch = s;

    WordDescriptor word;

    while (getWord(beginSearch, &word)) {
        digitToStart(word);

        beginSearch = word.end;
    }
}

//возвращает значение 0, если слово не было считано, в противном
//случае будет возвращено значение 1 и в переменную word типа WordDescriptor
//будут записаны позиции начала слова, и первого символа конца слова
int getWordReverse(char *rbegin, char *rend, WordDescriptor *word) {
    word->end = findNonSpaceReverse(rbegin, rend);

    if (*word->begin == *rend){
        return 0;
    }

    word->begin = findSpaceReverse(word->end, rend);
    word->begin++;

    return 1;
}

//преобразовывает строку, заменяя каждую цифру соответствующим ей числом пробелов
void replacesNumbersWithSpaces(char *input, char *output) {
    int i = 0, j = 0;

    while (input[i] != '\0') {
        if (isdigit(input[i])) {
            int numSpaces = input[i] - '0';

            for (int k = 0; k < numSpaces && j < MAX_STRING_SIZE-1; k++) {
                output[j++] = ' ';
            }
        } else if (j < MAX_STRING_SIZE-1) {
            output[j++] = input[i];
        }

        i++;
    }

    output[j] = '\0';
}

//заменяет все вхождения слова 𝑤1 на слово 𝑤2
void replace(char *source, char *w1, char *w2){
    size_t w1Size = strlen_(w1);
    size_t w2Size = strlen_(w2);

    WordDescriptor word1 = {w1, w1 + w1Size};
    WordDescriptor word2 = {w2, w2 + w2Size};

    char *readPtr, *recPtr;

    if (w1Size >= w2Size){
        readPtr = source;
        recPtr = source;
    }else{
        copy(source, getEndOfString(source), _stringBuffer);

        readPtr = _stringBuffer;
        recPtr = source;
    }

    while (*readPtr != '\0') {
        if (memcmp(readPtr, w1, w1Size) == 0) {
            for (int i = 0; i < w2Size; ++i) {
                *recPtr = w2[i];

                recPtr++;
            }

            readPtr += w1Size;

        } else {
            *recPtr = *readPtr;

            readPtr++;
            recPtr++;
        }
    }

    *recPtr = '\0';
}


