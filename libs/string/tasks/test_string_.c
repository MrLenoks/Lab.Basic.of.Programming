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

void test(){
    test_strlen_();
}

int main(){
    test();
}


