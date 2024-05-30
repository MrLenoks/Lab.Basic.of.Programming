#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct vector {
    int* data;
    size_t size;
    size_t capacity;
} vector;

//возвращает структуру-дескриптор вектор из n значений.
vector createVector(size_t n){
    vector v = {(int *) malloc(sizeof(int) * n), 0, n};

    if (v.data == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }

    return v;
}

//изменяет количество памяти, выделенное под хранение элементов вектора.
void reserve(vector *v, size_t newCapacity){
    if (newCapacity == 0) {
        v->data = NULL;
    } else {
        v->data = (int *) realloc(v->data, sizeof(int) * newCapacity);
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

//удаляет элементы из контейнера, но не освобождает выделенную память.
void clear(vector* v) {
    v->size = 0;
}

//освобождает память, выделенную поднеиспользуемые элементы.
void shrinkToFit(vector* v) {
    int* newData = (int*)realloc(v->data, v->size * sizeof(int));
    if (newData != NULL) {
        v->data = newData;
        v->capacity = v->size;
    }
}

//освобождает память, выделенную вектору.
void deleteVector(vector* v) {
    free(v->data);
}

