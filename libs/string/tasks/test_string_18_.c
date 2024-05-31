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

void test_digitsToStart_noDigits(){
    char s[] = "And";
    digitsToStart(s);
    ASSERT_STRING("And", s);
}

void test_digitsToStart_withSpaces(){
    char s[] = "And everyone can walk";
    digitsToStart(s);
    ASSERT_STRING("And", s);
}

void test_digitsToStart_digitsPerWord(){
    char s[] = "Walk0123";
    digitsToStart(s);
    ASSERT_STRING("0123Walk", s);
}

void test_digitsToStart_digitsInWord(){
    char s[] = "Wa1lk023";
    digitsToStart(s);
    ASSERT_STRING("1023Walk", s);
}

void test_digitsToStart(){
    test_digitsToStart_noDigits();
    test_digitsToStart_withSpaces();
    test_digitsToStart_digitsPerWord();
    test_digitsToStart_digitsInWord();
}


void test(){
    test_removeNonLetters();
    test_removeExtraSpaces();
    test_digitsToStart();
}

int main(){
    test();
}

