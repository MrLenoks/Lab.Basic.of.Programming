
#ifndef LAB_BASIC_OF_PROGRAMMING_STRING_18__H
#define LAB_BASIC_OF_PROGRAMMING_STRING_18__H

#include "string_.h"
#include <stdbool.h>

#define MAX_STRING_SIZE 100
#define MAX_N_WORDS_IN_STRING 100
#define MAX_WORD_SIZE 20
#define MAX_WORDS 100

typedef struct WordDescriptor {
    char *begin; // позиция начала слова
    char *end; // позиция первого символа, после последнего символа слова
} WordDescriptor;

typedef struct BagOfWords {
    WordDescriptor words[MAX_N_WORDS_IN_STRING];
    size_t size;
} BagOfWords;

typedef enum WordBeforeFirstWordWithAReturnCode {
    FIRST_WORD_WITH_A,
    NOT_FOUND_A_WORD_WITH_A,
    WORD_FOUND,
    EMPTY_STRING
} WordBeforeFirstWordWithAReturnCode;

//находит конечный элемент строки
char* getEndOfString(char *s);


#endif //LAB_BASIC_OF_PROGRAMMING_STRING_18__H
