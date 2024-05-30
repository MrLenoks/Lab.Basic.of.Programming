#include <assert.h>
#include "libs/data_structures/vector/vector.c"

void test_pushBack_emptyVector() {
    vector test_v1 = createVector(0);

    pushBack(&test_v1, 5);

    assert(test_v1.data[0] == 5);
    assert(test_v1.size == 1);
}

void test_pushBack_fullVector() {
    vector test_v1 = createVector(3);

    pushBack(&test_v1, 2);

    assert(test_v1.data[0] == 2);
    assert(test_v1.size == 1);
}

void test_popBack_notEmptyVector() {
    vector v = createVector(0);

    pushBack(&v, 10);

    assert(v.size == 1);

    popBack(&v);

    assert(v.size == 0);
    assert(v.capacity == 1);
}

void test_atVector_notEmptyVector(){
    vector test_v1 = createVector(2);

    pushBack(&test_v1, 4);
    pushBack(&test_v1, 8);

    int first_element = *atVector(&test_v1, 0);
    int second_element = *atVector(&test_v1, 1);

    assert(first_element == 4);
    assert(second_element == 8);
}

void test_atVector_requestToLastElement() {
    vector test_v1 = createVector(2);

    pushBack(&test_v1, 4);
    pushBack(&test_v1, 8);

    int last_element = *atVector(&test_v1, 1);


    assert(last_element == 8);
}

void test_back_oneElementInVector() {
    vector test_v1 = createVector(2);

    pushBack(&test_v1, 4);
    pushBack(&test_v1, 8);

    int last_element = *back(&test_v1);

    assert(last_element == 8);
}

void test_front_oneElementInVector(){
    vector test_v1 = createVector(2);

    pushBack(&test_v1, 4);
    pushBack(&test_v1, 8);

    int first_element = *front(&test_v1);


    assert(first_element == 4);
}

void test(){
    test_pushBack_emptyVector();
    test_pushBack_fullVector();
    test_popBack_notEmptyVector();
    test_atVector_notEmptyVector();
    test_atVector_requestToLastElement();
    test_back_oneElementInVector();
    test_front_oneElementInVector();
}

int main(){
    test();

    return 0;
}

