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

//сравнивает два слова
bool areWordsEqual(WordDescriptor w1, WordDescriptor w2) {
    int len1 = w1.end - w1.begin;
    int len2 = w2.end - w2.begin;

    if (len1 != len2) {
        return 0;
    }

    for (int i = 0; i < len1; i++) {
        if (w1.begin[i] != w2.begin[i]) {
            return 0;
        }
    }

    return 1;
}

//ищет первое вхождение любого символа из строки delim в строке str и возвращает указатель на этот символ
char* strpbrk_(const char* str, const char* delim) {
    const char* ptr = str;

    while (*ptr != '\0') {
        const char* d = delim;

        while (*d != '\0') {
            if (*ptr == *d) {
                return (char*)ptr;
            }

            d++;
        }

        ptr++;
    }

    return NULL;
}

//делит строку str на токены с использованием строки delim в качестве разделителя
char* strtok_(char* str, const char* delim) {
    static char* savedToken = NULL;

    if (str != NULL) {
        savedToken = str;
    }

    if (savedToken == NULL) {
        return NULL;
    }

    char* tokenStart = savedToken;
    char* tokenEnd = strpbrk_(savedToken, delim);

    if (tokenEnd != NULL) {
        *tokenEnd = '\0';

        savedToken = tokenEnd + 1;
    } else {
        savedToken = NULL;
    }

    return tokenStart;
}

//определяет, упорядочены ли лексикографически слова данного предложения
bool areWordsOrdered(char *s) {
    int len = strlen_(s);
    int words = 1;

    for (int i = 0; i < len; i++) {
        if (s[i] == ' ') {
            words++;
        }
    }

    char *word1, *word2;

    word1 = strtok_(s, " ");

    for (int i = 1; i < words; i++) {
        word2 = strtok_(NULL, " ");

        if (strcmp(word1, word2) > 0) {
            return 0;
        }
        word1 = word2;
    }

    return 1;
}

//получает позиции начала и конца каждого слова строки
void getBagOfWords(BagOfWords *bag, char *s) {
    char *token = strtok_(s, " ");
    int wordCount = 0;

    while (token != NULL) {
        int wordLen = strlen_(token);

        bag->words[wordCount].begin = token;
        bag->words[wordCount].end = token + wordLen;

        wordCount++;
        token = strtok_(NULL, " ");
    }

    bag->size = wordCount;
}

//выводит слова данной строки в обратном порядке по одному в строке экрана
void reverseWordsBag(char *s) {
    getBagOfWords(&_bag, s);

    for (int i = _bag.size - 1; i >= 0; i--) {
        for (char *ptr = _bag.words[i].end - 1; ptr >= _bag.words[i].begin; ptr--) {
            printf("%c", *ptr);
        }

        printf(" ");
    }
}

//проверяет, является ли заданное слово палиндромом
bool isWordPalindrome(char *begin, char *end) {
    end--;

    while (end - begin > 0) {
        if (*begin != *end) {
            return 0;
        }

        begin++;
        end--;
    }

    return 1;
}

//считает количество палиндромов в строке, разделенной запятыми
int howManyWordsPalindromes(char *s) {
    char *endS = getEndOfString(s);
    char *beginSearch = findNonSpace(s);

    int countPalindromes = 0;

    char *commaPos = find(beginSearch, endS, ',');

    bool lastComma = *commaPos == '\0' && endS - beginSearch != 0;

    while (*commaPos != '\0' || lastComma) {
        beginSearch = findNonSpace(beginSearch);
        countPalindromes += isWordPalindrome(beginSearch, commaPos);
        beginSearch = commaPos + 1;

        if (lastComma) {
            break;
        }

        commaPos = find(beginSearch, endS, ',');
        lastComma = *commaPos == '\0';
    }

    return countPalindromes;
}

//копирует строку
void strcpy_(char *dest, const char *src) {
    while (*src) {
        *dest = *src;

        dest++;
        src++;
    }

    *dest = '\0';
}

//находит последнее вхождение символа в строку
char *strchr_(const char *str, int c) {
    char *last = NULL;
    while (*str != '\0') {
        if (*str == c) {
            last = (char *)str;
        }

        str++;
    }

    return last;
}

//разбивает строки на токены (слова) с использованием разделителей
char* my_strtok_r(char* str, const char* delim, char** saveptr) {
    char* token;

    if (str == NULL) {
        str = *saveptr;
    }

    int len = 0;

    while (str[len] != '\0' && strchr_(delim, str[len]) != NULL) {
        len++;
    }

    str += len;

    if (*str == '\0') {
        *saveptr = str;

        return NULL;
    }

    token = str;
    str = strpbrk_(token, delim);

    if (str == NULL) {
        *saveptr = token + strlen_(token);
    } else {
        *str = '\0';
        *saveptr = str + 1;
    }

    return token;
}

//получает строку, в которой чередуются слова первой и второй строки
void mergeStrings(char *str1, char *str2, char *result) {
    char *token1, *token2;
    char *saveptr1, *saveptr2;

    token1 = my_strtok_r(str1, " ", &saveptr1);
    token2 = my_strtok_r(str2, " ", &saveptr2);

    while (token1 != NULL || token2 != NULL) {
        if (token1 != NULL) {
            strcpy_(result, token1);

            result += strlen_(token1);
            *result = ' ';

            result++;

            token1 = my_strtok_r(NULL, " ", &saveptr1);
        }

        if (token2 != NULL) {
            strcpy_(result, token2);

            result += strlen_(token2);
            *result = ' ';

            result++;

            token2 = my_strtok_r(NULL, " ", &saveptr2);
        }
    }

    *(result - 1) = '\0';
}

//обращает порядок символов в строке между двумя указателями
void reverse(char *begin, char *end) {
    char temp;
    while (begin < end) {
        temp = *begin;
        *begin++ = *end;
        *end-- = temp;
    }
}

//обращает порядок слов в строке
void reverseWords(char *str) {
    char *word_begin = str;
    char *temp = str;

    while (*temp) {
        temp++;

        if (*temp == '\0') {
            reverse(word_begin, temp - 1);
        } else if (*temp == ' ') {
            reverse(word_begin, temp - 1);

            word_begin = temp + 1;
        }
    }

    reverse(str, temp - 1);
}

//выводит слово данной строки, предшествующее первому из слов, содержащих букву "а"
void printWordBeforeFirstWordWithA(char *s) {
    char *word = NULL;
    char *token = strtok_(s, " ");

    while (token != NULL) {
        int foundA = 0;
        for (int i = 0; token[i] != '\0'; i++) {
            if (tolower(token[i]) == 'a') {
                foundA = 1;
                break;
            }
        }

        if (foundA) {
            if (word != NULL) {
                printf("%s\n", word);
                return;
            }
        } else {
            word = token;
        }

        token = strtok_(NULL, " ");
    }
}

//находит слово данной строки, предшествующее первому из слов, содержащих букву "а"
WordBeforeFirstWordWithAReturnCode getWordBeforeFirstWordWithA(char *s, WordDescriptor *w) {
    if (s == NULL || strlen_(s) == 0) {
        return EMPTY_STRING;
    }

    char *wordBegin = NULL;
    char *wordEnd = NULL;
    char *token = strtok_(s, " ");

    while (token != NULL) {
        int foundA = 0;
        for (int i = 0; token[i] != '\0'; i++) {
            if (tolower(token[i]) == 'a') {
                foundA = 1;
                break;
            }
        }

        if (foundA) {
            if (wordBegin != NULL) {
                w->begin = wordBegin;
                w->end = wordEnd;
                return WORD_FOUND;
            } else {
                return FIRST_WORD_WITH_A;
            }
        } else {
            wordBegin = token;
            wordEnd = token + strlen_(token);
        }

        token = strtok_(NULL, " ");
    }

    return NOT_FOUND_A_WORD_WITH_A;
}

//сравнивает строки с ограничением количества сравниваемых символов
int strncmp_(const char *s1, const char *s2, int n) {
    while (n--) {

        if (*s1 != *s2) {
            return (unsigned char) *s1 - (unsigned char) *s2;
        }

        if (*s1 == '\0') {
            return 0;
        }

        s1++;
        s2++;
    }

    return 0;
}

//копирует строки c ограничением длины
char *strncpy_(char *destination, const char *source, int num) {
    char *start = destination;

    while (num && (*destination++ = *source++)) {
        num--;
    }

    if (num) {
        while (--num) {
            *destination++ = '\0';
        }
    }

    return start;
}

//вычисляет длину слова, копирует его из предложения в строку
void wordDescriptorToString(WordDescriptor word, char *destination) {
    int length = word.end - word.begin;
    strncpy_(destination, word.begin, length);
    destination[length] = '\0';
}

//разбивает строку на слова
BagOfWords createBagOfWordsFromString(char *s) {
    BagOfWords bag;
    bag.size = 0;

    char *wordBegin = s;
    for (; *s; ++s) {
        if (isspace(*s)) {
            if (s > wordBegin) {
                bag.words[bag.size].begin = wordBegin;
                bag.words[bag.size].end = s;

                ++bag.size;
            }

            wordBegin = s + 1;
        }
    }

    if (s > wordBegin) {
        bag.words[bag.size].begin = wordBegin;
        bag.words[bag.size].end = s;

        ++bag.size;
    }

    return bag;
}

//проверяет если ли в массиве слов нужное слово
int isWordInBagOfWords(WordDescriptor word, BagOfWords bag) {
    for (int i = 0; i < bag.size; ++i) {
        if (strncmp_(word.begin, bag.words[i].begin, word.end - word.begin) == 0) {
            return 1;
        }
    }
    return 0;
}

//определяет последнее из слов первой строки, которое есть во второй строке
WordDescriptor lastWordInFirstStringInSecondString(char *s1, char *s2) {
    BagOfWords bag = createBagOfWordsFromString(s2);
    WordDescriptor lastWord = {NULL, NULL};

    BagOfWords wordsInS1 = createBagOfWordsFromString(s1);
    for (int i = 0; i < wordsInS1.size; ++i) {
        if (isWordInBagOfWords(wordsInS1.words[i], bag)) {
            lastWord = wordsInS1.words[i];
        }
    }

    return lastWord;
}

//проверяет есть ли в строке повторяющиеся слова
bool hasDuplicateWords(char* sentence) {
    char* words[100];
    int wordCount = 0;

    char* word = strtok_(sentence, " ");
    while (word != NULL) {
        words[wordCount] = word;

        wordCount++;

        word = strtok_(NULL, " ");
    }

    for (int i = 0; i < wordCount; i++) {
        for (int j = i + 1; j < wordCount; j++) {
            if (strcmp(words[i], words[j]) == 0) {
                return 1;
            }
        }
    }

    return 0;
}

//возвращает новую строку, содержащую отсортированные по алфавиту символы из исходной строки
char* sortWord(char *word) {
    int length = strlen_(word);
    char *sortedWord = (char*)malloc((length + 1) * sizeof(char));

    strcpy_(sortedWord, word);

    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length - 1; j++) {
            if (tolower(sortedWord[j]) > tolower(sortedWord[j + 1])) {
                char temp = sortedWord[j];
                sortedWord[j] = sortedWord[j + 1];
                sortedWord[j + 1] = temp;
            }
        }
    }

    return sortedWord;
}

//выделяет память под новую строку, копирует содержимое строки в новую строку
char *my_strdup(const char *str) {
    if (str == NULL) {
        return NULL;
    }

    size_t len = strlen_(str) + 1;
    char *new_str = (char *)malloc(len);

    if (new_str == NULL) {
        return NULL;
    }

    strcpy_(new_str, str);

    return new_str;
}

//определяет, есть ли в данной строке пара слов, составленных из одинакового набора букв
int findPairWithSameLetters(char *str) {
    char *buffer = my_strdup(str);
    char *token, *saveptr;
    char *words[MAX_WORDS];
    int numWords = 0;

    token = my_strtok_r(buffer, " ", &saveptr);

    while (token != NULL) {
        words[numWords++] = my_strdup(token);
        token = my_strtok_r(NULL, " ", &saveptr);
    }

    for (int i = 0; i < numWords; i++) {
        char *sortedWord1 = sortWord(words[i]);
        for (int j = i + 1; j < numWords; j++) {
            char *sortedWord2 = sortWord(words[j]);
            if (strcmp(sortedWord1, sortedWord2) == 0) {
                free(sortedWord1);
                free(sortedWord2);

                return 1;
            }

            free(sortedWord2);
        }

        free(sortedWord1);
    }

    return 0;
}

//объединяет строки
char *strcat_(char *dest, const char *src) {
    char *ptr = dest;

    while (*ptr != '\0') {
        ptr++;
    }

    while (*src != '\0') {
        *ptr = *src;

        ptr++;
        src++;
    }

    *ptr = '\0';

    return dest;
}

//функция удаляет пробел в конце строки
void removeLastSpace(char *str) {
    int len = strlen_(str);

    if (str[len - 1] == ' ') {
        str[len - 1] = '\0';
    }
}

//использование функции removeLastSpace в функции getWordsDifferentFromLast
char* getWordsDifferentFromLast(char *str) {
    char *buffer = my_strdup(str);
    char *token, *saveptr;
    char *lastWord;
    char *result = (char*)malloc(strlen_(str) * sizeof(char));

    result[0] = '\0';

    token = my_strtok_r(buffer, " ", &saveptr);

    while (token != NULL) {
        lastWord = token;
        token = my_strtok_r(NULL, " ", &saveptr);
    }

    buffer = my_strdup(str);
    token = strtok_(buffer, " ");

    while (token != NULL) {
        if (strcmp(token, lastWord) != 0) {
            strcat_(result, token);
            strcat_(result, " ");
        }

        token = strtok_(NULL, " ");
    }

    removeLastSpace(result);

    return result;
}

//ищет подстроку в строке
char* strstr_(char* haystack, char* needle) {
    if (*needle == '\0') {
        return haystack;
    }

    char* p1;
    char* p2;
    char* p3;

    while (*haystack) {
        p1 = haystack;
        p2 = needle;

        while (*p1 && *p2 && (*p1 == *p2)) {
            p1++;
            p2++;
        }

        if (*p2 == '\0') {
            return haystack;
        }

        haystack++;
    }

    return NULL;
}

//находит слово, предшествующее первому вхождению w (первое слово в
// первой строке, которое есть во второй строке) в первой строке
char* findWordBefore(char *s1, char *s2) {
    char* word = strtok_(s1, " ");
    char* prevWord = "";

    while (word != NULL) {
        if (strstr_(s2, word)) {
            return prevWord;
        }

        prevWord = word;
        word = strtok_(NULL, " ");
    }

    return NULL;
}

//проверяет, является ли слово палиндромом
int is_palindrome(char *word) {
    int length = strlen_(word);

    for (int i = 0; i < length / 2; i++) {
        if (tolower(word[i]) != tolower(word[length - i - 1])) {
            return 0;
        }
    }

    return 1;
}

// удаляет слова-палиндромы из строки
void removePalindromes(char *str) {
    char *token = strtok_(str, " ");
    char result[1000] = "";

    while (token != NULL) {
        if (!is_palindrome(token)) {
            strcat_(result, token);
            strcat_(result, " ");
        }

        token = strtok_(NULL, " ");
    }

    strcpy_(str, result);

    removeLastSpace(str);
}

//создает структуру BagOfWords из строки
BagOfWords *create_bag_of_words(char *s) {
    BagOfWords *bag = malloc(sizeof(BagOfWords));
    bag->size = 0;

    char *p = s;
    int in_word = 0;

    while (*p != '\0') {
        if (*p == ' ') {
            in_word = 0;
        } else {
            if (!in_word) {
                bag->words[bag->size].begin = p;

                in_word = 1;
            }
        }

        p++;

        if (in_word && (*p == ' ' || *p == '\0')) {
            bag->words[bag->size].end = p;
            bag->size++;
        }
    }

    return bag;
}

//дополняет строку, содержащую меньшее количество слов, последними
//словами строки, в которой содержится большее количество слов
void append(char *s1, char *s2) {
    BagOfWords *bag1 = create_bag_of_words(s1);
    BagOfWords *bag2 = create_bag_of_words(s2);

    if (bag1->size < bag2->size) {
        if (bag1->size == 1) {
            bag1->size++;
        }else{
            bag1->size--;
        }

        if (bag2->size == 2) {
            bag2->size++;
        }

        char *p = bag2->words[bag2->size - bag1->size].begin;
        char *q = s1;

        while (*q != '\0') {
            q++;
        }

        *q = ' ';
        q++;

        while (*p != '\0') {
            *q = *p;
            q++;
            p++;
        }

        *q = '\0';
    } else if (bag1->size > bag2->size){
        if (bag2->size == 1) {
            bag2->size++;
        }else{
            bag2->size--;
        }

        if (bag1->size == 2) {
            bag1->size++;
        }

        char *p = bag1->words[bag1->size - bag2->size].begin;

        char *q = s2;

        while (*q != '\0') {
            q++;
        }

        *q = ' ';
        q++;

        while (*p != '\0') {
            *q = *p;
            q++;
            p++;
        }

        *q = '\0';
    }

    free(bag1);
    free(bag2);
}




