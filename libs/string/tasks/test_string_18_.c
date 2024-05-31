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

void test_removeExtraSpaces_setOneSymbols(){
    char s[] = " NNN  NNN NNN ";
    removeExtraSpaces(s);
    ASSERT_STRING("NNN NNN NNN", s);
}

void test_removeExtraSpaces_noSpace(){
    char s[] = "{1,2,3}";
    removeExtraSpaces(s);
    ASSERT_STRING("{1,2,3}", s);
}

void test_removeExtraSpaces_noDoubleSpaces(){
    char s[] = "Kindness is when";
    removeExtraSpaces(s);
    ASSERT_STRING("Kindness is when", s);
}

void test_removeExtraSpaces_manySpaces(){
    char s[] = "    Everyone     is     friends     with     each     other    ";
    removeExtraSpaces(s);
    ASSERT_STRING("Everyone is friends with each other", s);
}

void test_removeExtraSpaces(){
    test_removeExtraSpaces_setOneSymbols();
    test_removeExtraSpaces_noSpace();
    test_removeExtraSpaces_noDoubleSpaces();
    test_removeExtraSpaces_manySpaces();
}


void test(){
    test_removeNonLetters();
    test_removeExtraSpaces();
}

int main(){
    test();
}

