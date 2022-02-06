#ifndef DISMAT_LABA0_0_SET_H
#define DISMAT_LABA0_0_SET_H

#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

void intersectionTwoArray(const int *a, size_t sizeA, const int *b, size_t sizeB, int *c, size_t *sizeC);

void unionTwoArray(const int *a, size_t sizeA, const int *b, size_t sizeB, int *c, size_t *sizeC);

void differenceTwoArray(const int *a, size_t sizeA, const int *b, size_t sizeB, int *c, size_t *sizeC);

void symmetricDifferenceTwoArray(const int *a, size_t sizeA, const int *b, size_t sizeB, int *c, size_t *sizeC);

bool allElementsFromAInB(const int *b, size_t sizeB, const int *a, size_t sizeA);

bool isEqualArrays(const int *b, size_t sizeB, const int *a, size_t sizeA);

bool twoArrayDontHaveEqualElements(const int *a, size_t sizeA, const int *b, size_t sizeB);

void mergeToOrderByIncreasingArrays(const int *a, const size_t sizeA, const int *b, const size_t sizeB, int *c,
                                    size_t *sizeC);

void
createOrderArrayByIncreasingByIntersection(const int *a, size_t sizeA, const int *b, size_t sizeB, int *c,
                                           size_t *sizeC);

void
createOrderArrayByIncreasingBySymmetricDifference(const int *a, size_t sizeA, const int *b, size_t sizeB,
                                                  int *c,
                                                  size_t *sizeC);

bool allElemsAOrderInBOrder(const int *b, size_t sizeB, const int *a, size_t sizeA);

#endif //DISMAT_LABA0_0_SET_H
