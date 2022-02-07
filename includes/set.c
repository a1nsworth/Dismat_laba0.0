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
    if (sizeA != 0 && sizeB != 0) {
        for (register size_t i = 0; i < sizeA; ++i) {
            c[*sizeC] = a[i];
            (*sizeC)++;
        }

        bool elemInArray = false;
        for (register size_t i = 0; i < sizeB; ++i) {
            for (register size_t j = 0; j < sizeA && !elemInArray; ++j)
                if (b[i] == a[j])
                    elemInArray = true;

            if (!elemInArray) {
                c[*sizeC] = b[i];
                (*sizeC)++;
            }
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
    if (sizeA == 0)
        for (register size_t i = 0; i < sizeB; ++i) {
            c[*sizeC] = b[i];
            (*sizeC)++;
        }
    else if (sizeB == 0) {
        for (register size_t i = 0; i < sizeA; ++i) {
            c[*sizeC] = a[i];
            (*sizeC)++;
        }
    } else {
        for (register size_t i = 0; i < sizeA; ++i) {
            c[*sizeC] = a[i];
            (*sizeC)++;
        }

        bool elemInArray = false;
        for (register size_t i = 0; i < sizeB; ++i) {
            for (register size_t j = 0; j < sizeA && !elemInArray; ++j)
                if (b[i] == a[j])
                    elemInArray = true;

            if (!elemInArray) {
                c[*sizeC] = b[i];
                (*sizeC)++;
            }
            elemInArray = false;
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
        elemAInArrayB = false;
    }
}

// Вариант 4
/// Симметрическая разность двух массивов, не содержащих одниковых элементов
/// \param a - адрес ячейки памяти массива
/// \param sizeA - размер массива
/// \param b - адрес ячейки памяти массива
/// \param sizeB - размер массива
/// \param c - адрес ячейки памяти массива в который будет записываться результат
/// \param sizeC - изначальный размер результирующего массива
void
symmetricDifferenceTwoArray(const int *a, const size_t sizeA, const int *b, const size_t sizeB, int *c,
                            size_t *sizeC) {
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
        elemAInArrayB = false;
    }

    bool elemBInArrayA = false;
    for (register size_t i = 0; i < sizeB; ++i) {
        for (register size_t j = 0; j < sizeA && !elemBInArrayA; ++j)
            if (b[i] == a[j])
                elemBInArrayA = true;

        if (!elemBInArrayA) {
            c[*sizeC] = b[i];
            (*sizeC)++;
            elemBInArrayA = false;
        }
        elemBInArrayA = false;
    }
}

// Вариант 5
/// Проверяет, что все элементы массива A принадлежат массиву B.
/// \param b - адрес нулевой ячейки памяти массива
/// \param sizeB - размер массива
/// \param a - адрес нулевой ячейки памяти массива
/// \param sizeA - размер массива
/// \return Возвращает true, если все элементы массива A принадлежат B, иначе false.
bool allElementsFromAInB(const int *b, const size_t sizeB, const int *a, const size_t sizeA) {
    if (sizeB < sizeA)
        return false;

    bool isEqual = true;
    for (register size_t i = 0; i < sizeA; ++i)
        for (register size_t j = 0; j < sizeB; ++j) {
            if (a[i] != b[j])
                isEqual = false;
            else {
                isEqual = true;
                break;
            }
        }

    return isEqual;
}

// Вариант 6
/// Два массива равны, т.е имеют все равные элементы.
/// \param a - адрес нулевой ячейки памяти массива
/// \param sizeA - размер массива
/// \param b - адрес нулевой ячейки памяти массива
/// \param sizeB - размер массива
/// \return Возвращает true, если массивы равны, иначе false.
bool isEqualArrays(const int *a, const size_t sizeA, const int *b, const size_t sizeB) {
    if (sizeA != sizeB)
        return false;

    for (register size_t i = 0; i < sizeA; ++i)
        if (a[i] != b[i])
            return false;

    return true;
}

// Вариант 7
/// Два массива не имеют общий элементов.
/// \param a - адрес нулевой ячейки памяти массива
/// \param sizeA - размер массива
/// \param b - адрес нулевой ячейки памяти массива
/// \param sizeB - размер массива
/// \return Возвращает true, если нет общих элементов, иначе false.
bool twoArrayDontHaveEqualElements(const int *a, const size_t sizeA, const int *b, const size_t sizeB) {
    for (register size_t i = 0; i < sizeA; ++i)
        for (register size_t j = 0; j < sizeB; ++j)
            if (a[i] == b[j])
                return false;

    return true;
}

// Задание 8
/// Формирует массив C (отсортированный по возрастанию и без повторения элементов) из элементов массива A и элементов массива B (отсортированные по возрастанию).
/// \param a - адрес нулевой ячейки памяти массива (отсортированный по возрастанию)
/// \param sizeA - размер массива
/// \param b - адрес нулевой ячейки памяти массива (отсортированный по возрастанию)
/// \param sizeB - размер массива
/// \param c - адрес нулевой ячейки памяти массива, куда будет записываться результат
/// \param sizeC - размер массива
void mergeToOrderByIncreasingArrays(const int *a, const size_t sizeA, const int *b, const size_t sizeB, int *c,
                                    size_t *sizeC) {
    size_t iReadA = 0;
    size_t iReadB = 0;
    while (iReadA < sizeA || iReadB < sizeB) {
        if (iReadB == sizeB || iReadA < sizeA && a[iReadA] < b[iReadB]) {
            c[iReadA + iReadB] = a[iReadA];
            iReadA++;
        } else {
            c[iReadA + iReadB] = b[iReadB];
            iReadB++;
        }
    }

    (*sizeC) = iReadA + iReadB;
}

// Задание 9
/// Формирует массив C (отсортированный по возрастанию) из элементов которые
/// есть одновременно в массиве A и B (отсортированные по возрастанию).
/// \param a - адрес нулевой ячейки памяти массива (отсортированный по возрастанию)
/// \param sizeA - размер массива
/// \param b - адрес нулевой ячейки памяти массива (отсортированный по возрастанию)
/// \param sizeB - размер массива
/// \param c - адрес нулевой ячейки памяти массива, куда будет записываться результат
/// \param sizeC - размер массива
void
createOrderArrayByIncreasingByIntersection(const int *a, const size_t sizeA, const int *b, const size_t sizeB,
                                           int *c,
                                           size_t *sizeC) {
    size_t iReadA = 0;
    size_t iReadB = 0;
    while (iReadA < sizeA && iReadB < sizeB) {
        if (a[iReadA] == b[iReadB]) {
            c[(*sizeC)++] = a[iReadA];
            iReadA++;
            iReadB++;
        } else if (a[iReadA] < b[iReadB]) {
            iReadA++;
        } else
            iReadB++;
    }
}

// Задание 10
/// Формирует массив C (отсортированный по возрастанию) из элементов которые
/// есть в массиве A, но нет в массиве B (отсортированные по возрастанию).
/// \param a - адрес нулевой ячейки памяти массива (отсортированный по возрастанию)
/// \param sizeA - размер массива
/// \param b - адрес нулевой ячейки памяти массива (отсортированный по возрастанию)
/// \param sizeB - размер массива
/// \param c - адрес нулевой ячейки памяти массива, куда будет записываться результат
/// \param sizeC - размер массива
void
createOrderArrayByIncreasingByDifference(const int *a, const size_t sizeA, const int *b, const size_t sizeB,
                                         int *c,
                                         size_t *sizeC) {
    size_t iReadA = 0;
    size_t iReadB = 0;
    while (iReadA < sizeA && iReadB < sizeB) {
        if (a[iReadA] == b[iReadB]) {
            iReadB++;
            iReadA++;
        } else if (a[iReadA] < b[iReadB]) {
            c[(*sizeC)++] = a[iReadA];
            iReadA++;
        } else {
            iReadB++;
        }
    }

    for (register size_t i = iReadA; i < sizeA; ++i)
        c[(*sizeC)++] = a[i];
}

// Задание 11
/// Формирует массив C (отсортированный по возрастанию) из элементов которые
/// есть в массиве A, но нет в массиве B (отсортированные по возрастанию).
/// \param a - адрес нулевой ячейки памяти массива (отсортированный по возрастанию)
/// \param sizeA - размер массива
/// \param b - адрес нулевой ячейки памяти массива (отсортированный по возрастанию)
/// \param sizeB - размер массива
/// \param c - адрес нулевой ячейки памяти массива, куда будет записываться результат
/// \param sizeC - размер массива
void
createOrderArrayByIncreasingBySymmetricDifference(const int *a, const size_t sizeA, const int *b, const size_t sizeB,
                                                  int *c,
                                                  size_t *sizeC) {
    size_t iReadA = 0;
    size_t iReadB = 0;
    while (iReadA < sizeA || iReadB < sizeB) {
        if (iReadB == sizeB || iReadA < sizeA && a[iReadA] < b[iReadB]) {
            c[(*sizeC)++] = a[iReadA];
            iReadA++;
        } else if (iReadA == sizeA || iReadB < sizeB && a[iReadA] > b[iReadB]) {
            c[(*sizeC)++] = b[iReadB];
            iReadB++;
        } else {
            iReadA++;
            iReadB++;
        }
    }
}

// Вариант 12
/// Проверяет принадлежность всех элементов из A в B
/// \param a - адрес нулевой ячейки памяти массива (отсортированный по возрастанию)
/// \param sizeA - размер массива
/// \param b - адрес нулевой ячейки памяти массива (отсортированный по возрастанию)
/// \param sizeB - размер массива
/// \return Возвращает true, если все элемент из A содержатся в B, иначе false.
bool allElemsAOrderInBOrder(const int *b, const size_t sizeB, const int *a, const size_t sizeA) {
    if (sizeA > sizeB)
        return false;

    size_t iReadA = 0;
    size_t iReadB = 0;
    unsigned counterEquals = 0;
    while (iReadA < sizeA && iReadB < sizeB) {
        if (a[iReadA] < b[iReadB])
            iReadA++;
        else if (a[iReadA] > b[iReadB])
            iReadB++;
        else {
            counterEquals++;
            iReadA++;
            iReadB++;
        }
    }

    return counterEquals == sizeA;
}





