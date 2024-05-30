#include <stdio.h>
#include <assert.h>
#include "libs/data_structures/vector/vectorVoid.c"

void test_isEmpty_emptyVectorVoid() {
    vectorVoid v;
    v.size = 0;
    assert(isEmptyV(&v) == 1);
}

void test_isEmpty_notEmptyVectorVoid() {
    vectorVoid v;
    v.size = 5;
    assert(isEmptyV(&v) == 0);
}

void test_isFull_fullVectorVoid() {
    vectorVoid v;
    v.size = 10;
    v.capacity = 10;
    assert(isFullV(&v) == 1);
}

void test_isFull_notFullVectorVoid() {
    vectorVoid v;
    v.size = 3;
    v.capacity = 10;
    assert(isFullV(&v) == 0);
}

void test_getVectorValueV_zeroElementVectorVoid(){
    vectorVoid v;
    v.baseTypeSize = sizeof(int);
    int data[] = {1, 2, 3, 4, 5};
    v.data = data;

    int value;
    getVectorValueV(&v, 0, &value);
    assert(value == 1);
}

void test_getVectorValueV_lastElementVectorVoid(){
    vectorVoid v;
    v.baseTypeSize = sizeof(int);
    int data[] = {1, 2, 3, 4, 5};
    v.data = data;

    int value;
    getVectorValueV(&v, 4, &value);
    assert(value == 5);
}

void test_getVectorValueV_middleElementVectorVoid(){
    vectorVoid v;
    v.baseTypeSize = sizeof(int);
    int data[] = {1, 2, 3, 4, 5};
    v.data = data;

    int value;
    getVectorValueV(&v, 3, &value);
    assert(value == 4);
}

void test_setVectorValueV_zeroElementVectorVoid(){
    vectorVoid v;
    v.baseTypeSize = sizeof(int);
    int data[5] = {0};
    v.data = data;

    int value = 10;
    setVectorValueV(&v, 0, &value);
    assert(data[0] == 10);
}

void test_setVectorValueV_lastElementVectorVoid(){
    vectorVoid v;
    v.baseTypeSize = sizeof(int);
    int data[5] = {0};
    v.data = data;

    int value = 10;
    setVectorValueV(&v, 4, &value);
    assert(data[4] == 10);
}

void test_setVectorValueV_middleElementVectorVoid(){
    vectorVoid v;
    v.baseTypeSize = sizeof(int);
    int data[5] = {0};
    v.data = data;

    int value = 10;
    setVectorValueV(&v, 2, &value);
    assert(data[2] == 10);
}

void test_popBackV_notEmptyVector() {
    vectorVoid v;
    v.size = 3;

    popBackV(&v);
    assert(v.size == 2);
}

void test_pushBackV_emptyVector() {
    vectorVoid v;
    v.baseTypeSize = sizeof(int);
    v.size = 0;
    int data[5] = {0};
    v.data = data;

    int value = 5;
    pushBackV(&v, &value);

    assert(v.size == 1);
    assert(data[0] == 5);
}

void test_pushBackV_fullVector() {
    vectorVoid v;
    v.baseTypeSize = sizeof(int);
    v.size = 3;
    int data[5] = {1, 2, 3};
    v.data = data;

    int value = 4;
    pushBackV(&v, &value);

    assert(v.size == 4);
    assert(data[3] == 4);
}

void test(){
    test_isEmpty_emptyVectorVoid();
    test_isEmpty_notEmptyVectorVoid();
    test_isFull_fullVectorVoid();
    test_isFull_notFullVectorVoid();
    test_getVectorValueV_zeroElementVectorVoid();
    test_getVectorValueV_lastElementVectorVoid();
    test_getVectorValueV_middleElementVectorVoid();
    test_setVectorValueV_zeroElementVectorVoid();
    test_setVectorValueV_lastElementVectorVoid();
    test_setVectorValueV_middleElementVectorVoid();
    test_popBackV_notEmptyVector();
    test_pushBackV_emptyVector();
    test_pushBackV_fullVector();
}

int main(){
    test();

    return 0;
}
