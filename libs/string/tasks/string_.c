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

//возвращает указатель на первый справа символ, отличный от пробельных,
//расположенный на ленте памяти, начиная с rbegin
char* findNonSpaceReverse(char *rbegin, const char *rend) {
    while ((rbegin != rend) && (*rbegin == ' ' || *rbegin == '\t' || *rbegin == '\r' || *rbegin == '\n' || *rbegin == '\0')) {
        rbegin--;
    }

    return rbegin;
}

//возвращает указатель на первый пробельный символ справа, расположенный
//на ленте памяти, начиная с rbegin и заканчивая rend.
char* findSpaceReverse(char *rbegin, const char *rend){
    while ((rbegin != rend) && (*rbegin != ' ') && (*rbegin != '\t') && (*rbegin != '\r') && (*rbegin != '\n') || *rbegin == '\0'){
        rbegin--;
    }

    return rbegin;
}

//проверка строк на равенство
int strcmp(const char *lhs, const char *rhs){
    while(*lhs != '\0' && *rhs != '\0' && *lhs == *rhs) {
        *lhs++;
        *rhs++;
    }

    return (*lhs > *rhs) - (*lhs < *rhs);
}

//записывает по адресу beginDestination фрагмент памяти, начиная с адреса beginSource до endSource.
//возвращает указатель на следующий свободный фрагмент памяти в destination
char* copy(const char *beginSource, const char *endSource, char *beginDestination) {
    char *current = beginDestination;

    while (beginSource != endSource) {
        *current = *beginSource;
        current++;
        beginSource++;
    }

    return current;
}

//записывает по адресу beginDestination элементы из фрагмента памяти начиная с beginSource
//заканчивая endSource, удовлетворяющие функции-предикату f
char* copyIf(char *beginSource, const char *endSource, char *beginDestination, int (*f)(int)) {
    while (beginSource != endSource) {
        if (f(*beginSource)) {
            *beginDestination = *beginSource;
            beginDestination++;
        }

        beginSource++;
    }

    *beginDestination = '\0';

    return beginDestination;
}

//записывает по адресу beginDestination элементы из фрагмента памяти начиная с rbeginSource
//заканчивая rendSource, удовлетворяющие функции-предикату f
char* copyIfReverse(char *rbeginSource, const char *rendSource, char *beginDestination, int (*f)(int)) {
    char *current = beginDestination;

    while (rbeginSource != rendSource) {
        if (f(*rbeginSource)) {
            *current = *rbeginSource;
            current++;
        }

        rbeginSource--;
    }

    return beginDestination;
}






