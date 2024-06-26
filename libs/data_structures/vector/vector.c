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


//проверка на то, является ли вектор пустым.
bool isEmpty(vector* v) {
    return v->size == 0;
}

//проверка на то, является ли вектор полным.
bool isFull(vector* v) {
    return v->size == v->capacity;
}

//возвращает i-ый элемент вектора v.
int getVectorValue(vector* v, size_t i) {
    return v->data[i];
}

//добавляет элемент x в конец вектора v.
void pushBack(vector *v, int x){
    if (v->capacity == 0) {
        reserve(v, 1);
    } else if (v->size == v->capacity) {
        reserve(v, v->size * 2);
    }

    v->data[v->size++] = x;
}

//удаляет последний элемент из вектора.
void popBack(vector* v) {
    if (isEmpty(v)) {
        fprintf(stderr, "The vector is empty.");
        exit(1);
    }

    v->size--;
}

//возвращает указатель на index-ый элемент вектора.
int* atVector(vector* v, size_t index) {
    if (index >= v->size) {
        fprintf(stderr, "IndexError: a[index] is not exists");
        exit(1);
    }

    return &v->data[index];
}

//возвращает указатель на последний элемент вектора.
int* back(vector* v) {
    return &(v->data[v->size - 1]);
}

//возвращает указатель на нулевой элемент вектора.
int* front(vector* v) {
    return &(v->data[0]);
}



