

#ifndef LAB_BASIC_OF_PROGRAMMING_VECTORVOID_H
#define LAB_BASIC_OF_PROGRAMMING_VECTORVOID_H

typedef struct vectorVoid {
    void *data; // указатель на нулевой элемент вектора
    size_t size; // размер вектора
    size_t capacity; // вместимость вектора
    size_t baseTypeSize; // размер базового типа:

} vectorVoid;

//возвращает структуру-дескриптор вектор из n значений.
vectorVoid createVectorV(size_t n, size_t baseTypeSize);

//изменяет количество памяти, выделенное под хранение элементов вектора.
void reserveV(vectorVoid *v, const size_t newCapacity);

//освобождает память, выделенную под неиспользуемые элементы.
void shrinkToFitV(vectorVoid *v);

//удаляет элементы из контейнера, но не освобождает выделенную память.
void clearV(vectorVoid *v);

//освобождает память, выделенную вектору.
void deleteVectorV(vectorVoid *v);


#endif //LAB_BASIC_OF_PROGRAMMING_VECTORVOID_H
