#include <string.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct vectorVoid {
    void *data; // указатель на нулевой элемент вектора
    size_t size; // размер вектора
    size_t capacity; // вместимость вектора
    size_t baseTypeSize; // размер базового типа:

} vectorVoid;

//возвращает структуру-дескриптор вектор из n значений.
vectorVoid createVectorV(size_t n, size_t baseTypeSize){
    vectorVoid v = {(int *) malloc(sizeof(int) * n), 0, n, baseTypeSize};

    if (v.data == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }

    return v;
}

//изменяет количество памяти, выделенное под хранение элементов вектора.
void reserveV(vectorVoid *v, const size_t newCapacity){
    if (newCapacity == 0) {
        v->data = NULL;
    } else {
        v->data = (int *) realloc(v->data, v->baseTypeSize * newCapacity);
    }

    if (v->data == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }

    if (v->size > newCapacity) {
        v->size = newCapacity;
    }

    v->capacity = newCapacity;
}

//освобождает память, выделенную под неиспользуемые элементы.
void shrinkToFitV(vectorVoid *v){
    int* newData = (int*)realloc(v->data, v->size * sizeof(int));
    if (newData != NULL) {
        v->data = newData;
        v->capacity = v->size;
    }
}

//удаляет элементы из контейнера, но не освобождает выделенную память.
void clearV(vectorVoid *v){
    v->size = 0;
}

//освобождает память, выделенную вектору.
void deleteVectorV(vectorVoid *v){
    free(v->data);
}

