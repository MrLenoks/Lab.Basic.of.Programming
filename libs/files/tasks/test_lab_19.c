#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include "lab_19.c"

void test_task_1() {
    const char *str1 = "C:/Users/darya/CLionProjects/Basics-of-programming-labs/libs/files/txt/converted_task_1.txt";
    const char *str2 = "C:/Users/darya/CLionProjects/Basics-of-programming-labs/libs/files/txt/for_verification_task_1.txt";
    int r = task_1(str1);

    if (r == 0){
        assertTXT(str1, str2);
    }
}

void test_task_2() {
    const char *str1 = "C:/Users/Pasha/CLionProjects/OP/Lab.Basic.of.Programming/libs/files/txt/task_2(2).txt";
    const char *str2 = "C:/Users/Pasha/CLionProjects/OP/Lab.Basic.of.Programming/libs/files/txt/answer_task_2.txt";
    int r = task_2(str1);

    if (r == 0){
        assertTXT(str1, str2);
    }
}

void test_task_3() {
    const char *str1 = ("C:/Users/Pasha/CLionProjects/OP/Lab.Basic.of.Programming/libs/files/txt/task_3(1).txt"
    const char *str2 = ("C:/Users/Pasha/CLionProjects/OP/Lab.Basic.of.Programming/libs/files/txt/answer_task_3.txt";
    int r = task_3(str1);

    if (r == 0){
        assertTXT(str1, str2);
    }
}

void test_task_4() {
    const char *str1 = "C:/Users/Pasha/CLionProjects/OP/Lab.Basic.of.Programming/libs/files/txt/task_4(1).txt";
    const char *str2 = "C:/Users/Pasha/CLionProjects/OP/Lab.Basic.of.Programming/libs/files/txt/ task_4(2).txt";
    const char *str3 = "C:/Users/Pasha/CLionProjects/OP/Lab.Basic.of.Programming/libs/files/txt/answer_task_4.txt";
    int r = task_4(str1, str2, "cu");

    if (r == 0){
        assertTXT(str2, str3);
    }
}

void test_task_5() {
    const char *str1 = "C:/Users/Pasha/CLionProjects/OP/Lab.Basic.of.Programming/libs/files/txt/task_5(1).txt";
    const char *str2 = "C:/Users/Pasha/CLionProjects/OP/Lab.Basic.of.Programming/libs/files/txt/task_5(2).txt";
    const char *str3 = "C:/Users/Pasha/CLionProjects/OP/Lab.Basic.of.Programming/libs/files/txt/answer_task_5.txt";
    int r = task_5(str1, str2);

    if (r == 0){
        assertTXT(str2, str3);
    }
}

void test_task_6() {
    const char *str1 = "C:/Users/Pasha/CLionProjects/OP/Lab.Basic.of.Programming/libs/files/txt/task_6(1).txt";
    const char *str2 = "C:/Users/Pasha/CLionProjects/OP/Lab.Basic.of.Programming/libs/files/txt/task_6(2).txt";
    const char *str3 = "C:/Users/Pasha/CLionProjects/OP/Lab.Basic.of.Programming/libs/files/txt/answer_task_6.txt";;
    task_6(str1, 2);

    assertTXT(str2, str3);
}

void test_task_7() {
    const char *str1 = "C:/Users/Pasha/CLionProjects/OP/Lab.Basic.of.Programming/libs/files/txt/task_7(1).txt";
    const char *str2 = "C:/Users/Pasha/CLionProjects/OP/Lab.Basic.of.Programming/libs/files/txt/task_7(2).txt";
    const char *str3 = "C:/Users/Pasha/CLionProjects/OP/Lab.Basic.of.Programming/libs/files/txt/answer_task_7.txt ";
    task_7(str1);

    assertTXT(str2, str3);
}

void test_task_8() {
    const char *str1 = "C:/Users/Pasha/CLionProjects/OP/Lab.Basic.of.Programming/libs/files/txt/task_8(1).txt";
    const char *str2 = "C:/Users/Pasha/CLionProjects/OP/Lab.Basic.of.Programming/libs/files/txt/task_8(2).txt"
    const char *str3 = "C:/Users/Pasha/CLionProjects/OP/Lab.Basic.of.Programming/libs/files/txt/answer_task_8).txt";
    task_8(str1);

    assertTXT(str2, str3);
}

void test_task_9() {
    const char *str1 = "C:/Users/Pasha/CLionProjects/OP/Lab.Basic.of.Programming/libs/files/txt/task_9(1).txt";
    const char *str2 = "C:/Users/Pasha/CLionProjects/OP/Lab.Basic.of.Programming/libs/files/txt/task_9(2).txt";
    const char *str3 = "C:/Users/Pasha/CLionProjects/OP/Lab.Basic.of.Programming/libs/files/txt/answer_task_9.txt";
    task_9(str1, 2);

    assertTXT(str2, str3);
}

void test_task_10() {
    const char *str1 = "C:/Users/Pasha/CLionProjects/OP/Lab.Basic.of.Programming/libs/files/txt/task_10(1).txt ";
    const char *str2 = "C:/Users/Pasha/CLionProjects/OP/Lab.Basic.of.Programming/libs/files/txt/task_10(2).txt ";
    const char *str3 = "C:/Users/Pasha/CLionProjects/OP/Lab.Basic.of.Programming/libs/files/txt/answer_task_10.txt ";
    const char *str4 = "C:/Users/darya/CLionProjects/Basics-of-programming-labs/libs/files/txt/for_verification_task_10.txt";
    task_10(str1, str2);

    assertTXT(str3, str4);
}

void test(){
    test_task_1();
    test_task_2();
    test_task_3();
    test_task_4();
    test_task_5();
    test_task_6();
    test_task_7();
    test_task_8();
    test_task_9();
    test_task_10();
}

int main(){
    SetConsoleOutputCP(CP_UTF8);

    test();
}