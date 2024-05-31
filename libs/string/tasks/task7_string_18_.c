#include "string_lab18_.c"
#include <stdio.h>

void test_reverseWordsBag_noString(){
    char s[MAX_STRING_SIZE] = "";
    reverseWordsBag(s);
    printf("\n");
}

void test_reverseWordsBag_symbols(){
    char s[MAX_STRING_SIZE] = "h e y";
    reverseWordsBag(s);
    printf("\n");
}

void test_reverseWordsBag_words(){
    char s[MAX_STRING_SIZE] = "Calm down, just calm down!";
    reverseWordsBag(s);
    printf("\n");
}

void test_reverseWordsBag(){
    test_reverseWordsBag_noString();
    test_reverseWordsBag_symbols();
    test_reverseWordsBag_words();
}

int main(){
    test_reverseWordsBag();
}


