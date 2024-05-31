#include "stdio.h"
#include "string_.h"

//возвращает количество символов в строке, не считая ноль-символ
size_t strlen_(const char *begin) {
    char *end = begin;

    while (*end != '\0') {
        end++;
    }

    return end - begin;
}

// возвращает указатель на первый элемент с кодом ch, расположенным на ленте памяти между
//адресами begin и end не включая end
char* find(char *begin, char *end, int ch) {
    while (begin != end && *begin != ch) {
        begin++;
    }

    return begin;
}

//возвращает указатель на первый символ, отличный от пробельных, расположенный на ленте памяти,
//начиная с begin и заканчивая ноль-символом
char* findNonSpace(char *begin){
    while ((*begin != '\0') && (*begin == ' ' || *begin == '\t' || *begin == '\r' || *begin == '\n')) {
        begin++;
    }

    return begin;
}



