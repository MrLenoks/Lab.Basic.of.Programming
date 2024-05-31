#include "stdio.h"
#include "string_.c"
#include <assert.h>

void test_strlen_(){
    char *test_string1 = "Hello";
    int len1 = strlen_(test_string1);
    assert(len1 == 5);

    char *test_string2 = "   "; //три пробела
    int len2 = strlen_(test_string2);
    assert(len2 == 3);

    char *test_string3 = "()!""№;%:\е \0";
    int len3 = strlen_(test_string3);
    assert(len3 == 12);
}

void test_find(){
    char test_string1[] = "Space";
    char *found1 = find(test_string1, test_string1 + 6, 'S');
    assert(*found1 == 83);

    char test_string2[] = "Space";
    char *found2 = find(test_string2, test_string2 + 2, 'c');
    assert(found2 == test_string2 + 2);

    char test_string3[] = "012 784 245";
    char *found3 = find(test_string3, test_string2 + 3, '2');
    assert(found3 != test_string3 + 3 && *found3 == 50);
}

void test_findNonSpace(){
    char test_string1[] = " Love is a book";
    char *found1 = findNonSpace(test_string1);
    assert(found1 != test_string1 && *found1 == 76);

    char test_string2[] = " \t \n And the book is a novel";
    char *found2 = findNonSpace(test_string2);
    assert(found2 != test_string2 && *found2 == 65);
}

void test_findNonSpaceReverse(){
    char test_string1[] = "A novel is a fairy tale  ";
    char *found1 = findNonSpaceReverse(test_string1 + 23, test_string1);
    assert(found1 != test_string1 && *found1 == 101);

    char test_string2[] = " And the fairy tale is a deception \t \n ";
    char *found2 = findNonSpaceReverse(test_string2 + 40, test_string2);
    assert(found2 != test_string2 && *found2 == 110);
}

void test_findSpaceReverse(){
    char test_string1[] = "Deception is a lie";
    char *found1 = findSpaceReverse(test_string1 + 19, test_string1);
    assert(found1 != test_string1 && *found1 == 32);

    char test_string2[] = "And lying is a \t \npain";
    char *found2 = findSpaceReverse(test_string2 + 22, test_string2);
    assert(found2 != test_string2 && *found2 == 10);
}

void test_strcmp(){
    char test_string1[] = "Pain is a feeling";
    char test_string2[] = "Pain is a feeling";
    int result1 = strcmp(test_string1, test_string2);
    assert(result1 == 0);

    char test_string3[] = "And the feeling is love";
    int result2 = strcmp(test_string1, test_string3);
    assert(result2 == 1);
}

void test_copy(){
    char *source1 = "The boy who survived";
    char destination1[30];
    copy(source1, source1 + 20, destination1);
    destination1[20] = '\0';
    assert(strcmp(source1, destination1) == 0);

    char *source2 = "Salamander \t ";
    char destination2[20];
    copy(source2, source2 + 13, destination2);
    destination2[13] = '\0';
    assert(strcmp(source2, destination2) == 0);
}

int isUpperCase(int c) {
    return (c >= 'A' && c <= 'Z');
}

void test_copyIf() {
    char *source = "Professor of Magic";
    char destination[20];
    char *endOfDestination = copyIf(source, source + 19, destination, isUpperCase);
    *endOfDestination = '\0';

    const char *expectedResult = "PM";
    assert(strcmp(destination, expectedResult) == 0);
}


void test(){
    test_strlen_();
    test_find();
    test_findNonSpace();
    findNonSpaceReverse();
    test_findSpaceReverse();
    test_strcmp();
    test_copy();
    test_copyIf();
}

int main(){
    test();
}


