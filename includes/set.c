//
// Created by yaxbi on 05.02.2022.
//

#include "set.h"

// Вариант 1
/// Пересечение двух массивов, не содержащих одниковых элементов
/// \param a - адрес ячейки памяти массива
/// \param sizeA - размер массива
/// \param b - адрес ячейки памяти массива
/// \param sizeB - размер массива
/// \param c - адрес ячейки памяти массива в который будет записываться результат
/// \param sizeC - изначальный размер результирующего массива
void intersectionTwoArray(const int *a, const size_t sizeA, const int *b, const size_t sizeB, int *c, size_t *sizeC) {
    for (register size_t i = 0; i < sizeA; ++i) {
        c[*sizeC] = a[i];
        (*sizeC)++;
    }

    bool elemInArray = false;
    for (register size_t i = 0; i < sizeA; ++i) {
        for (register size_t j = 0; j < sizeB && !elemInArray; ++j)
            if (a[i] == b[j])
                elemInArray = true;

        if (!elemInArray) {
            c[*sizeC] = b[i];
            (*sizeC)++;
            elemInArray = false;
        }
    }
}

// Вариант 2
/// Пересечение двух массивов
/// \param a - адрес ячейки памяти массива
/// \param sizeA - размер массива
/// \param b - адрес ячейки памяти массива
/// \param sizeB - размер массива
/// \param c - адрес ячейки памяти массива в который будет записываться результат
/// \param sizeC - изначальный размер результирующего массива
void unionTwoArray(const int *a, const size_t sizeA, const int *b, const size_t sizeB, int *c, size_t *sizeC) {
    for (register size_t i = 0; i < sizeA; ++i) {
        for (register size_t j = 0; j < sizeB; ++j)
            if (a[i] == b[j]) {
                c[*sizeC] = a[i];
                (*sizeC)++;
            }
    }
}

// Вариант 3
/// Разность двух массивов, не содержащих одниковых элементов
/// \param a - адрес ячейки памяти массива
/// \param sizeA - размер массива
/// \param b - адрес ячейки памяти массива
/// \param sizeB - размер массива
/// \param c - адрес ячейки памяти массива в который будет записываться результат
/// \param sizeC - изначальный размер результирующего массива
void differenceTwoArray(const int *a, const size_t sizeA, const int *b, const size_t sizeB, int *c, size_t *sizeC) {
    bool elemAInArrayB = false;
    for (register size_t i = 0; i < sizeA; ++i) {
        for (register size_t j = 0; j < sizeB && !elemAInArrayB; ++j)
            if (a[i] == b[j])
                elemAInArrayB = true;

        if (!elemAInArrayB) {
            c[*sizeC] = a[i];
            (*sizeC)++;
            elemAInArrayB = false;
        }
    }
}

// Вариант 4
/// Симетрическая разность двух массивов, не содержащих одниковых элементов
/// \param a - адрес ячейки памяти массива
/// \param sizeA - размер массива
/// \param b - адрес ячейки памяти массива
/// \param sizeB - размер массива
/// \param c - адрес ячейки памяти массива в который будет записываться результат
/// \param sizeC - изначальный размер результирующего массива
void
symmetricDifferenceTwoArray(const int *a, const size_t sizeA, const int *b, const size_t sizeB, int *c, size_t *sizeC) {
    bool elemAInArrayB = false;
    for (register size_t i = 0; i < sizeA; ++i) {
        for (register size_t j = 0; j < sizeB && !elemAInArrayB; ++j)
            if (a[i] == b[j])
                elemAInArrayB = true;

        if (!elemAInArrayB) {
            c[*sizeC] = a[i];
            (*sizeC)++;
            elemAInArrayB = false;
        }
    }

    bool elemBInArrayA = false;
    for (register size_t i = 0; i < sizeB; ++i) {
        for (register size_t j = 0; j < sizeA && !elemBInArrayA; ++j)
            if (a[i] == b[j])
                elemBInArrayA = true;

        if (!elemBInArrayA) {
            c[*sizeC] = b[i];
            (*sizeC)++;
            elemBInArrayA = false;
        }
    }
}


