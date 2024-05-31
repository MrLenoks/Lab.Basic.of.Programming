#define ASSERT_STRING(expected, got) assertString(expected, got, \
__FILE__, __FUNCTION__, __LINE__)

#include "string_lab18_.c"
#include <stdio.h>
#include <assert.h>

void test_removeNonLetters_oneSpace(){
    char s[] = " ";
    removeNonLetters(s);
    ASSERT_STRING("", s);
}

void test_removeNonLetters_emptyLine(){
    char s[] = "";
    removeNonLetters(s);
    ASSERT_STRING("", s);
}

void test_removeNonLetters_noSpace(){
    char s[] = "Moths";
    removeNonLetters(s);
    ASSERT_STRING("Moths", s);
}

void test_removeNonLetters_manySpaces(){
    char s[] = " What is kindness? ";
    removeNonLetters(s);
    ASSERT_STRING("Whatiskindness?", s);
}

void test_removeNonLetters(){
    test_removeNonLetters_oneSpace();
    test_removeNonLetters_emptyLine();
    test_removeNonLetters_noSpace();
    test_removeNonLetters_manySpaces();
}

void test(){
    test_removeNonLetters();
}

int main(){
    test();
}

