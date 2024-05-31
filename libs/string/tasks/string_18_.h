
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

//удаляет из строки все пробельные символы
void removeNonLetters(char *s);

//функция тестирования, которая даёт информацию о том, где именно произошла ошибка
void assertString(const char *expected, char *got, char const *fileName, char const *funcName, int line);

//сокращает количество пробелов между словами данного предложения до одного
void removeExtraSpaces(char *s);

//возвращает указатель на первый пробельный символ,
//расположенный на ленте памяти начиная с адреса begin
//или на первый ноль-символ
char* findSpace(char *begin);

//возвращает значение 0, если слово не было считано, иначе
//значение 1, в переменную word типа WordDescriptor
//записывает позиции начала слова, и первого символа после конца слова
int getWord(char *beginSearch, WordDescriptor *word);

//преобразовывает слово таким образом, чтобы цифры были перенесены
//в начало слова и изменить порядок следования цифр в слове на обратный
void reversedDigitToStart(WordDescriptor word);

//преобразовывает слово таким образом, чтобы цифры были перенесены в начало слова
void digitToStart(WordDescriptor word);

//преобразовывает строку таким образом, чтобы цифры каждого слова были
//перенесены в начало слова без изменения порядка следования их в слове,
//буквы перенесены в конец слова
void digitsToStart(char *s);

//возвращает значение 0, если слово не было считано, в противном
//случае будет возвращено значение 1 и в переменную word типа WordDescriptor
//будут записаны позиции начала слова, и первого символа конца слова
int getWordReverse(char *rbegin, char *rend, WordDescriptor *word);

//преобразовывает строку, заменяя каждую цифру соответствующим ей числом пробелов
void replacesNumbersWithSpaces(char *input, char *output);

//заменяет все вхождения слова 𝑤1 на слово 𝑤2
void replace(char *source, char *w1, char *w2);

//проверяет слова на равенство
bool areWordsEqual(WordDescriptor w1, WordDescriptor w2);

//ищет первое вхождение любого символа из строки delim в строке str и возвращает указатель на этот символ
char* strpbrk_(const char* str, const char* delim);

//делит строку str на токены с использованием строки delim в качестве разделителя
char* strtok_(char* str, const char* delim);

//определяет, упорядочены ли лексикографически слова данного предложения
bool areWordsOrdered(char *s);

//получает позиции начала и конца каждого слова строки
void getBagOfWords(BagOfWords *bag, char *s);

//выводит слова данной строки в обратном порядке по одному в строке экрана
void reverseWordsBag(char *s);

//проверяет, является ли заданное слово палиндромом
bool isWordPalindrome(char *begin, char *end);

//считает количество палиндромов в строке, разделенной запятыми
int howManyWordsPalindromes(char *s);

//копирует строку
void strcpy_(char *dest, const char *src);

//находит последнее вхождение символа в строку
char *strchr_(const char *str, int c);

//разбивает строки на токены (слова) с использованием разделителей
char* my_strtok_r(char* str, const char* delim, char** saveptr);

//получает строку, в которой чередуются слова первой и второй строки
void mergeStrings(char *str1, char *str2, char *result);

//обращает порядок символов в строке между двумя указателями
void reverse(char *begin, char *end);

//обращает порядок слов в строке
void reverseWords(char *str);

//выводит слово данной строки, предшествующее первому из слов, содержащих букву "а"
void printWordBeforeFirstWordWithA(char *s);

//находит слово данной строки, предшествующее первому из слов, содержащих букву "а"
WordBeforeFirstWordWithAReturnCode getWordBeforeFirstWordWithA(char *s, WordDescriptor *w);

//сравнивает строки с ограничением количества сравниваемых символов
int strncmp_(const char *s1, const char *s2, int n);

//копирует строки c ограничением длины
char *strncpy_(char *destination, const char *source, int num);

//вычисляет длину слова, копирует его из предложения в строку
void wordDescriptorToString(WordDescriptor word, char *destination);

//разбивает строку на слова
BagOfWords createBagOfWordsFromString(char *s);

//проверяет если ли в массиве слов нужное слово
int isWordInBagOfWords(WordDescriptor word, BagOfWords bag);

//определяет последнее из слов первой строки, которое есть во второй строке
WordDescriptor lastWordInFirstStringInSecondString(char *s1, char *s2);

//проверяет есть ли в строке повторяющиеся слова
bool hasDuplicateWords(char* sentence);

//возвращает новую строку, содержащую отсортированные по алфавиту символы из исходной строки
char* sortWord(char *word);

//выделяет память под новую строку, копирует содержимое строки в новую строку
char *my_strdup(const char *str);

//определяет, есть ли в данной строке пара слов, составленных из одинакового набора букв
int findPairWithSameLetters(char *str);

//объединяет строки
char *strcat_(char *dest, const char *src);

//функция удаляет пробел в конце строки
void removeLastSpace(char *str);

//получает строку из слов, которые отличны от последнего слова
char* getWordsDifferentFromLast(char *str);

//ищет подстроку в строке
char* strstr_(char* haystack, char* needle);

//находит слово, предшествующее первому вхождению w (первое слово в
// первой строке, которое есть во второй строке) в первой строке
char* findWordBefore(char *s1, char *s2);

//проверяет, является ли слово палиндромом
int is_palindrome(char *word);

// удаляет слова-палиндромы из строки
void removePalindromes(char *str);

//создает структуру BagOfWords из строки
BagOfWords *create_bag_of_words(char *s);

//дополняет строку, содержащую меньшее количество слов, последними
//словами строки, в которой содержится большее количество слов
void append(char *s1, char *s2);

//определяет, входит ли в данную строку каждая буква данного слова
int checkWordInString(char *word, char *str);


#endif //LAB_BASIC_OF_PROGRAMMING_STRING_18__H
