#include "includes/set.h"
#include "includes/array.h"

void test_intersectionTwoArray_oneArrayIsEmpty() {
    // Arrange
    int a[0] = {};
    int b[5] = {1, 2, 3, 4, 5};
    size_t sizeC = 0;
    int c[10];

    // Act
    intersectionTwoArray(a, 0, b, 5, c, &sizeC);

    // Assert
    assert(sizeC == 0);
}

void test_intersectionTwoArray_twoArrayIsEmpty() {
    // Arrange
    int a[0] = {};
    int b[5] = {};
    size_t sizeC = 0;
    int c[10];

    // Act
    intersectionTwoArray(a, 0, b, 0, c, &sizeC);

    // Assert
    assert(sizeC == 0);
}

void test_intersectionTwoArray_equalArrays() {
    // Arrange
    int a[5] = {1, 2, 3, 4, 5};
    int b[5] = {1, 2, 3, 4, 5};
    size_t sizeC = 0;
    int c[10];

    // Act
    intersectionTwoArray(a, 5, b, 5, c, &sizeC);

    // Assert
    assert(sizeC == 5);
    assert(c[0] == 1);
    assert(c[1] == 2);
    assert(c[2] == 3);
    assert(c[3] == 4);
    assert(c[4] == 5);
}

void test_intersectionTwoArray_equalElemsAtBorders() {
    // Arrange
    int a[5] = {1, 22, 9, 7, 5};
    int b[5] = {1, 23, 34, 45, 5};
    size_t sizeC = 0;
    int c[10];

    // Act
    intersectionTwoArray(a, 5, b, 5, c, &sizeC);

    // Assert
    assert(sizeC == 8);
    assert(c[0] == 1);
    assert(c[1] == 22);
    assert(c[2] == 9);
    assert(c[3] == 7);
    assert(c[4] == 5);
    assert(c[5] == 23);
    assert(c[6] == 34);
    assert(c[7] == 45);
}

void test_intersectionTwoArray_oneEqualElemsAtBorder() {
    // Arrange
    int a[5] = {1, 2, 3, 4, 5};
    int b[5] = {5, 6, 7, 8, 9};
    size_t sizeC = 0;
    int c[10];

    // Act
    intersectionTwoArray(a, 5, b, 5, c, &sizeC);

    // Assert
    assert(sizeC == 9);
    assert(c[0] == 1);
    assert(c[1] == 2);
    assert(c[2] == 3);
    assert(c[3] == 4);
    assert(c[4] == 5);
    assert(c[5] == 6);
    assert(c[6] == 7);
    assert(c[7] == 8);
    assert(c[8] == 9);
}

void test_intersectionTwoArray_randomPositionEqualElems() {
    // Arrange
    int a[5] = {1, 21, 33, 44, 56};
    int b[5] = {33, 44, 3, 45, 57};
    size_t sizeC = 0;
    int c[10];

    // Act
    intersectionTwoArray(a, 5, b, 5, c, &sizeC);

    // Assert
    assert(sizeC == 8);
    assert(c[0] == 1);
    assert(c[1] == 21);
    assert(c[2] == 33);
    assert(c[3] == 44);
    assert(c[4] == 56);
    assert(c[5] == 3);
    assert(c[6] == 45);
    assert(c[7] == 57);
}

void test_intersectionTwoArray() {
    test_intersectionTwoArray_oneArrayIsEmpty();
    test_intersectionTwoArray_twoArrayIsEmpty();
    test_intersectionTwoArray_equalArrays();
    test_intersectionTwoArray_equalElemsAtBorders();
    test_intersectionTwoArray_oneEqualElemsAtBorder();
    test_intersectionTwoArray_randomPositionEqualElems();
}

void test_unionTwoArray_oneEmpty() {
    // Arrange
    int a[0] = {};
    int b[5] = {1, 2, 3, 4, 5};
    size_t sizeC = 0;
    int c[10];

    // Act
    unionTwoArray(a, 0, b, 5, c, &sizeC);

    // Assert
    assert(sizeC == 5);
    assert(isEqualTwoArrays(c, sizeC, b, sizeC));
}

void test_unionTwoArray_twoEmpty() {
    // Arrange
    int a[0] = {};
    int b[5] = {};
    size_t sizeC = 0;
    int c[10];

    // Act
    unionTwoArray(a, 0, b, 0, c, &sizeC);

    // Assert
    assert(sizeC == 0);
}

void test_unionTwoArray_equalAtBorders() {
    // Arrange
    int a[5] = {1, 22, 33, 44, 5};
    int b[5] = {1, 2, 3, 4, 5};
    size_t sizeC = 0;
    int c[10];

    // Act
    unionTwoArray(a, 5, b, 5, c, &sizeC);

    // Assert
    assert(sizeC == 8);
    assert(isEqualTwoArrays(c, sizeC, (int[]) {1, 22, 33, 44, 5, 2, 3, 4}, sizeC));
}

void test_unionTwoArray_allIsEqual() {
    // Arrange
    int a[5] = {1, 2, 3, 4, 5};
    int b[5] = {1, 2, 3, 4, 5};
    size_t sizeC = 0;
    int c[10];

    // Act
    unionTwoArray(a, 5, b, 5, c, &sizeC);

    // Assert
    assert(sizeC == 5);
    assert(isEqualTwoArrays(c, sizeC, a, sizeC));
}

void test_unionTwoArray_oneElemIsEqual() {
    // Arrange
    int a[5] = {1, 2, 3, 4, 5};
    int b[5] = {5, 222, 333, 444, 55};
    size_t sizeC = 0;
    int c[10];

    // Act
    unionTwoArray(a, 5, b, 5, c, &sizeC);

    // Assert
    assert(sizeC == 9);
    assert(isEqualTwoArrays(c, sizeC, (int[]) {1, 2, 3, 4, 5, 222, 333, 444, 55}, sizeC));
}

void test_unionTwoArray_randomPositionEqualElems() {
    // Arrange
    int a[5] = {23, 2, 3, 4, 5};
    int b[5] = {12, 23, 3, 2, 1};
    size_t sizeC = 0;
    int c[10];

    // Act
    unionTwoArray(a, 5, b, 5, c, &sizeC);

    // Assert
    assert(sizeC == 7);
    assert(isEqualTwoArrays(c, sizeC, (int[]) {23, 2, 3, 4, 5, 12, 1}, sizeC));
}

void test_unionTwoArray() {
    test_unionTwoArray_oneEmpty();
    test_unionTwoArray_twoEmpty();
    test_unionTwoArray_equalAtBorders();
    test_unionTwoArray_allIsEqual();
    test_unionTwoArray_oneElemIsEqual();
    test_unionTwoArray_randomPositionEqualElems();
}

void test_differenceTwoArray_Equal() {
    // Arrange
    int a[5] = {1, 2, 3, 4, 5};
    int b[5] = {1, 2, 3, 4, 5};
    size_t sizeC = 0;
    int c[10];

    // Act
    differenceTwoArray(a, 5, b, 5, c, &sizeC);

    // Assert
    assert(sizeC == 0);
}

void test_differenceTwoArray_rightIsEmpty() {
    // Arrange
    int a[5] = {1, 2, 3, 4, 5};
    int b[0] = {};
    size_t sizeC = 0;
    int c[10];

    // Act
    differenceTwoArray(a, 5, b, 0, c, &sizeC);

    // Assert
    assert(sizeC == 5);
    assert(isEqualTwoArrays(c, sizeC, a, sizeC));
}

void test_differenceTwoArray_leftIsEmpty() {
    // Arrange
    int a[0] = {};
    int b[5] = {1, 2, 3, 4, 5};
    size_t sizeC = 0;
    int c[10];

    // Act
    differenceTwoArray(a, 0, b, 5, c, &sizeC);

    // Assert
    assert(sizeC == 0);
}

void test_differenceTwoArray_equalElemsAtBorders() {
    // Arrange
    int a[5] = {1, 2, 3, 4, 5};
    int b[5] = {1, 22, 33, 44, 5};
    size_t sizeC = 0;
    int c[10];

    // Act
    differenceTwoArray(a, 5, b, 5, c, &sizeC);

    // Assert
    assert(sizeC == 3);
    assert(isEqualTwoArrays(c, sizeC, (int[]) {2, 3, 4}, sizeC));
}

void test_differenceTwoArray_oneEqualAtBorder() {
    // Arrange
    int a[5] = {5, 2, 3, 4, 1};
    int b[5] = {1, 22, 33, 44, 55};
    size_t sizeC = 0;
    int c[10];

    // Act
    differenceTwoArray(a, 5, b, 5, c, &sizeC);

    // Assert
    assert(sizeC == 4);
    assert(isEqualTwoArrays(c, sizeC, (int[]) {5, 2, 3, 4}, sizeC));
}

void test_differenceTwoArray_uniqueOneElem() {
    // Arrange
    int a[5] = {1, 2, 6, 4, 5};
    int b[5] = {1, 2, 3, 4, 5};
    size_t sizeC = 0;
    int c[10];

    // Act
    differenceTwoArray(a, 5, b, 5, c, &sizeC);

    // Assert
    assert(sizeC == 1);
    assert(isEqualTwoArrays(c, sizeC, (int[]) {6}, sizeC));
}

void test_differenceTwoArray() {
    test_differenceTwoArray_Equal();
    test_differenceTwoArray_rightIsEmpty();
    test_differenceTwoArray_leftIsEmpty();
    test_differenceTwoArray_equalElemsAtBorders();
    test_differenceTwoArray_equalElemsAtBorders();
    test_differenceTwoArray_oneEqualAtBorder();
    test_differenceTwoArray_uniqueOneElem();
}

void test_symmetricDifferenceTwoArray_equalArrays() {
    // Arrange
    int a[5] = {1, 2, 3, 4, 5};
    size_t sizeC = 0;
    int c[10];

    // Act
    symmetricDifferenceTwoArray(a, 5, a, 5, c, &sizeC);

    // Assert
    assert(sizeC == 0);
}

void test_symmetricDifferenceTwoArray_oneIsEmpty() {
    // Arrange
    int a[5] = {1, 2, 3, 4, 5};
    int b[0] = {};
    size_t sizeC = 0;
    int c[10];

    // Act
    symmetricDifferenceTwoArray(a, 5, b, 0, c, &sizeC);

    // Assert
    assert(sizeC == 5);
    assert(isEqualTwoArrays(c, sizeC, a, sizeC));
}

void test_symmetricDifferenceTwoArray_equalAtMiddle() {
    // Arrange
    int a[5] = {1, 2, 3, 4, 5};
    int b[5] = {3, 4, 5, 6, 7};
    size_t sizeC = 0;
    int c[10];

    // Act
    symmetricDifferenceTwoArray(a, 5, b, 5, c, &sizeC);

    // Assert
    assert(sizeC == 4);
    assert(isEqualTwoArrays(c, sizeC, (int[]) {1, 2, 6, 7}, sizeC));
}

void test_symmetricDifferenceTwoArray_equalAtBorders() {
    // Arrange
    int a[5] = {1, 22, 33, 44, 5};
    int b[5] = {1, 45, 55, 66, 5};
    size_t sizeC = 0;
    int c[10];

    // Act
    symmetricDifferenceTwoArray(a, 5, b, 5, c, &sizeC);

    // Assert
    assert(sizeC == 6);
    assert(isEqualTwoArrays(c, sizeC, (int[]) {22, 33, 44, 45, 55, 66}, sizeC));
}

void test_symmetricDifferenceTwoArray_oneEqualAtBorder() {
    // Arrange
    int a[5] = {1, 2, 3, 4, 5};
    int b[5] = {9, 8, 7, 6, 1};
    size_t sizeC = 0;
    int c[10];

    // Act
    symmetricDifferenceTwoArray(a, 5, b, 5, c, &sizeC);

    // Assert
    assert(sizeC == 8);
    assert(isEqualTwoArrays(c, sizeC, (int[]) {2, 3, 4, 5, 9, 8, 7, 6}, sizeC));
}

void test_symmetricDifferenceTwoArray() {
    test_symmetricDifferenceTwoArray_equalArrays();
    test_symmetricDifferenceTwoArray_oneIsEmpty();
    test_symmetricDifferenceTwoArray_equalAtMiddle();
    test_symmetricDifferenceTwoArray_equalAtBorders();
    test_symmetricDifferenceTwoArray_oneEqualAtBorder();
}

void test_allElementsFromAInB_oneArrayIsEmpty() {
    // Arrange
    int a[0] = {};
    int b[3] = {1, 2, 3};

    // Act and Assert
    assert(allElementsFromAInB(b, 3, a, 0));
}

void test_allElementsFromAInB_twoArraysIsEmpty() {
    // Arrange
    int a[0] = {};
    int b[0] = {};

    // Act and Assert
    assert(isEqualArrays(b, 0, a, 0));
}

void test_allElementsFromAInB_arrayALargeArrayB() {
    // Arrange
    int a[5] = {1, 2, 3, 4, 5};
    int b[4] = {1, 2, 3, 4};

    // Act and Assert
    assert(!isEqualArrays(b, 4, a, 5));
}

void test_allElementsFromAInB_twoArraysIsEqual() {
    // Arrange
    int a[4] = {1, 2, 3, 4};
    int b[4] = {1, 2, 3, 4};

    // Act and Assert
    assert(allElementsFromAInB(b, 4, a, 4));
}

void test_allElementsFromAInB_BlargeA() {
    // Arrange
    int a[4] = {1, 2, 3, 4};
    int b[5] = {1, 2, 3, 4, 5};

    // Act and Assert
    assert(allElementsFromAInB(b, 5, a, 4));
}

void test_allElementsFromAInB_equalElemsAtBorders() {
    // Arrange
    int a[2] = {1, 9};
    int b[5] = {1, 5, 8, 6, 9};

    // Act and Assert
    assert(allElementsFromAInB(b, 5, a, 2));
}

void test_allElementsFromAInB() {
    test_allElementsFromAInB_oneArrayIsEmpty();
    test_allElementsFromAInB_twoArraysIsEmpty();
    test_allElementsFromAInB_arrayALargeArrayB();
    test_allElementsFromAInB_twoArraysIsEqual();
    test_allElementsFromAInB_BlargeA();
    test_allElementsFromAInB_equalElemsAtBorders();
}

void test_isEqualArrays_twoArraysIsEmpty() {
    // Arrange
    int a[0] = {};
    int b[0] = {};

    // Act and Assert
    assert(isEqualArrays(b, 0, a, 0));
}

void test_isEqualArrays_oneArrayIsEmpty() {
    // Arrange
    int a[0] = {};
    int b[5] = {1, 2, 3, 4, 5};

    // Act and Assert
    assert(!isEqualArrays(b, 5, a, 0));
}

void test_isEqualArrays_two_equalArrays() {
    // Arrange
    int a[5] = {1, 2, 3, 4, 5};
    int b[5] = {1, 2, 3, 4, 5};

    // Act and Assert
    assert(isEqualArrays(b, 5, a, 5));
}

void test_isEqualArrays_two_noEqualElemsAtRightBorder() {
    // Arrange
    int a[5] = {1, 2, 3, 4, 6};
    int b[5] = {1, 2, 3, 4, 5};

    // Act and Assert
    assert(!isEqualArrays(b, 5, a, 5));
}

void test_isEqualArrays_two_noEqualElemsAtLestBorder() {
    // Arrange
    int a[5] = {9, 2, 3, 4, 5};
    int b[5] = {1, 2, 3, 4, 5};

    // Act and Assert
    assert(!isEqualArrays(b, 5, a, 5));
}

void test_isEqualArrays() {
    test_isEqualArrays_twoArraysIsEmpty();
    test_isEqualArrays_oneArrayIsEmpty();
    test_isEqualArrays_two_equalArrays();
    test_isEqualArrays_two_noEqualElemsAtRightBorder();
    test_isEqualArrays_two_noEqualElemsAtLestBorder();
}

void test_twoArrayDontHaveEqualElements_twoArraysIsEmpty() {
    // Arrange
    int a[0] = {};
    int b[0] = {};

    // Act and Assert
    assert(twoArrayDontHaveEqualElements(a, 0, b, 0));
}

void test_twoArrayDontHaveEqualElements_oneArrayIsEmpty() {
    // Arrange
    int a[0] = {};
    int b[3] = {1, 2, 3};

    // Act and Assert
    assert(twoArrayDontHaveEqualElements(a, 0, b, 3));
}

void test_twoArrayDontHaveEqualElements_twoArraysIsEqual() {
    // Arrange
    int a[3] = {1, 2, 3};
    int b[3] = {1, 2, 3};

    // Act and Assert
    assert(!twoArrayDontHaveEqualElements(a, 3, b, 3));
}

void test_twoArrayDontHaveEqualElements_oneEqualElemsAtBorder() {
    // Arrange
    int a[5] = {6, 2, 3, 4, 1};
    int b[5] = {1, 22, 33, 44, 55};

    // Act and Assert
    assert(!twoArrayDontHaveEqualElements(a, 5, b, 5));
}

void test_twoArrayDontHaveEqualElements_equalElemsAtBorders() {
    // Arrange
    int a[5] = {55, 2, 3, 4, 1};
    int b[5] = {1, 22, 33, 44, 55};

    // Act and Assert
    assert(!twoArrayDontHaveEqualElements(a, 5, b, 5));
}

void test_twoArrayDontHaveEqualElements_equalElemsInCenter() {
    // Arrange
    int a[5] = {6, 22, 33, 4, 9};
    int b[5] = {1, 22, 33, 44, 55};

    // Act and Assert
    assert(!twoArrayDontHaveEqualElements(a, 3, b, 3));
}

void test_twoArrayDontHaveEqualElements() {
    test_twoArrayDontHaveEqualElements_twoArraysIsEmpty();
    test_twoArrayDontHaveEqualElements_oneArrayIsEmpty();
    test_twoArrayDontHaveEqualElements_twoArraysIsEqual();
    test_twoArrayDontHaveEqualElements_oneEqualElemsAtBorder();
    test_twoArrayDontHaveEqualElements_equalElemsAtBorders();
    test_twoArrayDontHaveEqualElements_equalElemsInCenter();
}

void test_mergeOrderArrayByIncreasing_oneIsEmptyArray() {
    // Arrange
    int a[0] = {};
    int b[] = {1, 2, 3, 4, 5};
    size_t sizeC = 0;
    int c[10];

    // Act
    mergeToOrderByIncreasingArrays(a, 0, b, 5, c, &sizeC);

    // Assert
    assert(sizeC == 5);
    assert(isEqualTwoArrays(c, sizeC, b, sizeC));
}

void test_mergeOrderArrayByIncreasing_twoIsEmptyArrays() {
    // Arrange
    int a[0] = {};
    int b[0] = {};
    size_t sizeC = 0;
    int c[10];

    // Act
    mergeToOrderByIncreasingArrays(a, 0, b, 0, c, &sizeC);

    // Assert
    assert(sizeC == 0);
}

void test_mergeOrderArrayByIncreasing_twoArraysIsEqual() {
    // Arrange
    int a[] = {1, 2, 3, 4, 5};
    int b[] = {1, 2, 3, 4, 5};
    size_t sizeC = 0;
    int c[10];

    // Act
    mergeToOrderByIncreasingArrays(a, 5, b, 5, c, &sizeC);

    // Assert
    assert(sizeC == 5);
    assert(isEqualTwoArrays(c, sizeC, (int[]) {1, 2, 3, 4, 5}, sizeC));
}

void test_mergeOrderArrayByIncreasing_equalElemsAtBorders() {
    // Arrange
    int a[] = {1, 10, 11, 12, 13};
    int b[] = {1, 3, 4, 5, 13};
    size_t sizeC = 0;
    int c[10];

    // Act
    mergeToOrderByIncreasingArrays(a, 5, b, 5, c, &sizeC);

    // Assert
    assert(sizeC == 8);
    assert(isEqualTwoArrays(c, sizeC, (int[]) {1, 3, 4, 5, 10, 11, 12, 13}, sizeC));
}

void test_mergeOrderArrayByIncreasing_oneEqualElemAtBorder() {
    // Arrange
    int a[] = {9, 10, 11, 12, 13};
    int b[] = {1, 3, 4, 5, 13};
    size_t sizeC = 0;
    int c[10];

    // Act
    mergeToOrderByIncreasingArrays(a, 5, b, 5, c, &sizeC);

    // Assert
    assert(sizeC == 9);
    assert(isEqualTwoArrays(c, sizeC, (int[]) {1, 3, 4, 5, 9, 10, 11, 12,  13}, sizeC));
}

void test_mergeOrderArrayByIncreasing_elemsArrayALowElemsArrayB() {
    // Arrange
    int a[] = {20, 21, 22, 23, 24};
    int b[] = {1, 2, 3, 4, 5};
    size_t sizeC = 0;
    int c[10];

    // Act
    mergeToOrderByIncreasingArrays(a, 5, b, 5, c, &sizeC);

    // Assert
    assert(sizeC == 10);
    assert(isEqualTwoArrays(c, sizeC, (int[]) {1, 2, 3, 4, 5, 20, 21, 22, 23, 24}, sizeC));
}

void test_mergeOrderArrayByIncreasing_elemsArrayBLowElemsArrayA() {
    // Arrange
    int b[] = {20, 21, 22, 23, 24};
    int a[] = {1, 2, 3, 4, 5};
    size_t sizeC = 0;
    int c[10];

    // Act
    mergeToOrderByIncreasingArrays(a, 5, b, 5, c, &sizeC);

    // Assert
    assert(sizeC == 10);
    assert(isEqualTwoArrays(c, sizeC, (int[]) {1, 2, 3, 4, 5, 20, 21, 22, 23, 24}, sizeC));
}

void test_mergeOrderArrayByIncreasing_randomPosition() {
    // Arrange
    int a[] = {1, 5, 9, 13, 17};
    int b[] = {2, 3, 10, 11, 20};
    size_t sizeC = 0;
    int c[10];

    // Act
    mergeToOrderByIncreasingArrays(a, 5, b, 5, c, &sizeC);

    // Assert
    assert(sizeC == 10);
    assert(isEqualTwoArrays(c, sizeC, (int[]) {1, 2, 3, 5, 9, 10, 11, 13, 17, 20}, sizeC));
}

void test_mergeOrderArrayByIncreasing_aLargeB() {
    // Arrange
    int a[] = {10, 12, 14, 16, 18, 20, 22};
    int b[] = {9, 23};
    size_t sizeC = 0;
    int c[10];

    // Act
    mergeToOrderByIncreasingArrays(a, 7, b, 2, c, &sizeC);

    // Assert
    assert(sizeC == 9);
    assert(isEqualTwoArrays(c, sizeC, (int[]) {9, 10, 12, 14, 16, 18, 20, 22, 23}, sizeC));
}

void test_mergeOrderArrayByIncreasing_bLargeA() {
    // Arrange
    int b[] = {10, 12, 14, 16, 18, 20, 22};
    int a[] = {9, 23};
    size_t sizeC = 0;
    int c[10];

    // Act
    mergeToOrderByIncreasingArrays(a, 2, b, 7, c, &sizeC);

    // Assert
    assert(sizeC == 9);
    assert(isEqualTwoArrays(c, sizeC, (int[]) {9, 10, 12, 14, 16, 18, 20, 22, 23}, sizeC));
}

void test_mergeOrderArrayByIncreasing_aLargeBAndEqualElemsAtBorders() {
    // Arrange
    int a[] = {10, 12, 14, 16, 18, 20, 22};
    int b[] = {10, 22};
    size_t sizeC = 0;
    int c[10];

    // Act
    mergeToOrderByIncreasingArrays(a, 7, b, 2, c, &sizeC);

    // Assert
    assert(sizeC == 7);
    assert(isEqualTwoArrays(c, sizeC, (int[]) { 10, 12, 14, 16, 18, 20, 22}, sizeC));
}

void test_mergeOrderArrayByIncreasing_bLargeAAndEqualElemsAtBorders() {
    // Arrange
    int a[] = {10, 22};
    int b[] = {10, 12, 14, 16, 18, 20, 22};
    size_t sizeC = 0;
    int c[10];

    // Act
    mergeToOrderByIncreasingArrays(a, 2, b, 7, c, &sizeC);

    // Assert
    assert(sizeC == 7);
    assert(isEqualTwoArrays(c, sizeC, (int[]) { 10, 12, 14, 16, 18, 20,  22}, sizeC));
}

void test_mergeOrderArrayByIncreasing() {
    test_mergeOrderArrayByIncreasing_oneIsEmptyArray();
    test_mergeOrderArrayByIncreasing_twoIsEmptyArrays();
    test_mergeOrderArrayByIncreasing_twoArraysIsEqual();
    test_mergeOrderArrayByIncreasing_equalElemsAtBorders();
    test_mergeOrderArrayByIncreasing_oneEqualElemAtBorder();
    test_mergeOrderArrayByIncreasing_elemsArrayALowElemsArrayB();
    test_mergeOrderArrayByIncreasing_elemsArrayBLowElemsArrayA();
    test_mergeOrderArrayByIncreasing_randomPosition();
    test_mergeOrderArrayByIncreasing_aLargeB();
    test_mergeOrderArrayByIncreasing_bLargeA();
    test_mergeOrderArrayByIncreasing_aLargeBAndEqualElemsAtBorders();
    test_mergeOrderArrayByIncreasing_bLargeAAndEqualElemsAtBorders();
}

void test_createOrderArrayByIncreasingByIntersection_aIsEmpty() {
    // Arrange
    int a[0] = {};
    int b[5] = {2, 3, 10, 11, 20};
    size_t sizeC = 0;
    int c[10];

    // Act
    createOrderArrayByIncreasingByIntersection(a, 0, b, 5, c, &sizeC);

    // Assert
    assert(sizeC == 0);
}

void test_createOrderArrayByIncreasingByIntersection_bIsEmpty() {
    // Arrange
    int a[5] = {2, 3, 10, 11, 20};
    int b[0] = {};
    size_t sizeC = 0;
    int c[10];

    // Act
    createOrderArrayByIncreasingByIntersection(a, 5, b, 0, c, &sizeC);

    // Assert
    assert(sizeC == 0);
}

void test_createOrderArrayByIncreasingByIntersection_twoArraysAreEqual() {
    // Arrange
    int a[5] = {1, 2, 3, 4, 5};
    int b[5] = {1, 2, 3, 4, 5};
    size_t sizeC = 0;
    int c[10];

    // Act
    createOrderArrayByIncreasingByIntersection(a, 5, b, 5, c, &sizeC);

    // Assert
    assert(sizeC == 5);
    assert(isEqualArrays(c, sizeC, a, sizeC));

}

void test_createOrderArrayByIncreasingByIntersection_notEqualElemsAtBorders() {
    // Arrange
    int a[5] = {0, 2, 3, 4, 9};
    int b[5] = {1, 2, 3, 4, 5};
    size_t sizeC = 0;
    int c[10];

    // Act
    createOrderArrayByIncreasingByIntersection(a, 5, b, 5, c, &sizeC);

    // Assert
    assert(sizeC == 3);
    assert(isEqualArrays(c, sizeC, (int[]) {2, 3, 4}, sizeC));

}

void test_createOrderArrayByIncreasingByIntersection_oneNotEqualElemsAtRightBorder() {
    // Arrange
    int a[5] = {1, 2, 3, 4, 9};
    int b[5] = {1, 2, 3, 4, 5};
    size_t sizeC = 0;
    int c[10];

    // Act
    createOrderArrayByIncreasingByIntersection(a, 5, b, 5, c, &sizeC);

    // Assert
    assert(sizeC == 4);
    assert(isEqualArrays(c, sizeC, (int[]) {1, 2, 3, 4}, sizeC));
}

void test_createOrderArrayByIncreasingByIntersection_randomPosition() {
    // Arrange
    int a[5] = {5, 8, 10, 11, 12};
    int b[5] = {1, 5, 8, 10, 11};
    size_t sizeC = 0;
    int c[10];

    // Act
    createOrderArrayByIncreasingByIntersection(a, 5, b, 5, c, &sizeC);

    // Assert
    assert(sizeC == 4);
    assert(isEqualArrays(c, sizeC, (int[]) {5, 8, 10, 11}, sizeC));
}

void test_createOrderArrayByIncreasingByIntersection_aLargeB() {
    // Arrange
    int a[] = {10, 12, 14, 16, 18, 20, 22};
    int b[] = {9, 22};
    size_t sizeC = 0;
    int c[10];

    // Act
    createOrderArrayByIncreasingByIntersection(a, 7, b, 2, c, &sizeC);

    // Assert
    assert(sizeC == 1);
    assert(isEqualTwoArrays(c, sizeC, (int[]) {22}, sizeC));
}

void test_createOrderArrayByIncreasingByIntersection_bLargeA() {
    // Arrange
    int b[] = {10, 12, 14, 16, 18, 20, 22};
    int a[] = {9, 22};
    size_t sizeC = 0;
    int c[10];

    // Act
    createOrderArrayByIncreasingByIntersection(a, 2, b, 7, c, &sizeC);

    // Assert
    assert(sizeC == 1);
    assert(isEqualTwoArrays(c, sizeC, (int[]) {22}, sizeC));
}

void test_createOrderArrayByIncreasingByIntersection_aLargeBAndEqualElemsAtBorders() {
    // Arrange
    int a[] = {10, 12, 14, 16, 18, 20, 22};
    int b[] = {10, 22};
    size_t sizeC = 0;
    int c[10];

    // Act
    createOrderArrayByIncreasingByIntersection(a, 7, b, 2, c, &sizeC);

    // Assert
    assert(sizeC == 2);
    assert(isEqualTwoArrays(c, sizeC, (int[]) {10, 22}, sizeC));
}

void test_createOrderArrayByIncreasingByIntersection_bLargeAAndEqualElemsAtBorders() {
    // Arrange
    int a[] = {10, 22};
    int b[] = {10, 12, 14, 16, 18, 20, 22};
    size_t sizeC = 0;
    int c[10];

    // Act
    createOrderArrayByIncreasingByIntersection(a, 2, b, 7, c, &sizeC);

    // Assert
    assert(sizeC == 2);
    assert(isEqualTwoArrays(c, sizeC, (int[]) {10, 22}, sizeC));
}

void test_createOrderArrayByIncreasingByIntersection() {
    test_createOrderArrayByIncreasingByIntersection_aIsEmpty();
    test_createOrderArrayByIncreasingByIntersection_bIsEmpty();
    test_createOrderArrayByIncreasingByIntersection_twoArraysAreEqual();
    test_createOrderArrayByIncreasingByIntersection_notEqualElemsAtBorders();
    test_createOrderArrayByIncreasingByIntersection_oneNotEqualElemsAtRightBorder();
    test_createOrderArrayByIncreasingByIntersection_randomPosition();
    test_createOrderArrayByIncreasingByIntersection_aLargeB();
    test_createOrderArrayByIncreasingByIntersection_bLargeA();
    test_createOrderArrayByIncreasingByIntersection_aLargeBAndEqualElemsAtBorders();
    test_createOrderArrayByIncreasingByIntersection_bLargeAAndEqualElemsAtBorders();
}

void test_createOrderArrayByIncreasingBySymmetricDifference_leftIsEmpty() {
    // Arrange
    int a[0] = {};
    int b[5] = {1, 2, 3, 4, 5};
    size_t sizeC = 0;
    int c[10];

    // Act
    createOrderArrayByIncreasingBySymmetricDifference(a, 0, b, 5, c, &sizeC);

    // Assert
    assert(sizeC == 5);
    assert(isEqualArrays(c, sizeC, b, sizeC));
}

void test_createOrderArrayByIncreasingBySymmetricDifference_rightIsEmpty() {
    // Arrange
    int a[5] = {1, 2, 3, 4, 5};
    int b[0] = {};
    size_t sizeC = 0;
    int c[10];

    // Act
    createOrderArrayByIncreasingBySymmetricDifference(a, 5, b, 0, c, &sizeC);

    // Assert
    assert(sizeC == 5);
    assert(isEqualArrays(c, sizeC, b, sizeC));
}

void test_createOrderArrayByIncreasingBySymmetricDifference_twoArraysAreEmpty() {
    // Arrange
    int a[0] = {};
    int b[0] = {};
    size_t sizeC = 0;
    int c[10];

    // Act
    createOrderArrayByIncreasingBySymmetricDifference(a, 0, b, 0, c, &sizeC);

    // Assert
    assert(sizeC == 0);
}

void test_createOrderArrayByIncreasingBySymmetricDifference_equalElemsAtBorders() {
    // Arrange
    int a[5] = {1, 6, 7, 8, 9};
    int b[5] = {1, 2, 3, 4, 9};
    size_t sizeC = 0;
    int c[10];

    // Act
    createOrderArrayByIncreasingBySymmetricDifference(a, 5, b, 5, c, &sizeC);

    // Assert
    assert(sizeC == 6);
    assert(isEqualArrays(c, sizeC, (int[]) {2, 3, 4, 6, 7, 8}, sizeC));
}

void test_createOrderArrayByIncreasingBySymmetricDifference_oneEqualLeftBorder() {
    // Arrange
    int a[5] = {1, 6, 7, 8, 9};
    int b[5] = {1, 2, 3, 4, 5};
    size_t sizeC = 0;
    int c[10];

    // Act
    createOrderArrayByIncreasingBySymmetricDifference(a, 5, b, 5, c, &sizeC);

    // Assert
    assert(sizeC == 8);
    assert(isEqualArrays(c, sizeC, (int[]) {2, 3, 4, 5, 6, 7, 8, 9}, sizeC));
}

void test_createOrderArrayByIncreasingBySymmetricDifference_oneEqualAtRightBorder() {
    // Arrange
    int a[5] = {5, 6, 7, 8, 9};
    int b[5] = {1, 2, 3, 4, 9};
    size_t sizeC = 0;
    int c[10];

    // Act
    createOrderArrayByIncreasingBySymmetricDifference(a, 5, b, 5, c, &sizeC);

    // Assert
    assert(sizeC == 8);
    assert(isEqualArrays(c, sizeC, (int[]) {1, 2, 3, 4, 5, 6, 7, 8}, sizeC));
}

void test_createOrderArrayByIncreasingBySymmetricDifference_equalElemsInCenter() {
    // Arrange
    int a[5] = {1, 5, 6, 7, 9};
    int b[5] = {2, 5, 6, 7, 10};
    size_t sizeC = 0;
    int c[10];

    // Act
    createOrderArrayByIncreasingBySymmetricDifference(a, 5, b, 5, c, &sizeC);

    // Assert
    assert(sizeC == 4);
    assert(isEqualArrays(c, sizeC, (int[]) {1, 2, 9, 10}, sizeC));
}

void test_createOrderArrayByIncreasingBySymmetricDifference() {
    test_createOrderArrayByIncreasingBySymmetricDifference_leftIsEmpty();
    test_createOrderArrayByIncreasingBySymmetricDifference_rightIsEmpty();
    test_createOrderArrayByIncreasingBySymmetricDifference_twoArraysAreEmpty();
    test_createOrderArrayByIncreasingBySymmetricDifference_equalElemsAtBorders();
    test_createOrderArrayByIncreasingBySymmetricDifference_oneEqualLeftBorder();
    test_createOrderArrayByIncreasingBySymmetricDifference_oneEqualAtRightBorder();
    test_createOrderArrayByIncreasingBySymmetricDifference_equalElemsInCenter();
}

void test_createOrderArrayByIncreasingByDifference_leftIsEmpty() {
    // Arrange
    int a[0] = {};
    int b[5] = {1, 2, 3, 4, 5};
    size_t sizeC = 0;
    int c[10];

    // Act
    createOrderArrayByIncreasingByDifference(a, 0, b, 5, c, &sizeC);

    // Assert
    assert(sizeC == 0);
}

void test_createOrderArrayByIncreasingByDifference_rightIsEmpty() {
    // Arrange
    int a[5] = {1, 2, 3, 4, 5};
    int b[0] = {};
    size_t sizeC = 0;
    int c[10];

    // Act
    createOrderArrayByIncreasingByDifference(a, 5, b, 0, c, &sizeC);

    // Assert
    assert(sizeC == 5);
    assert(isEqualArrays(c, sizeC, b, sizeC));
}

void test_createOrderArrayByIncreasingByDifference_twoArraysAreEmpty() {
    // Arrange
    int a[0] = {};
    int b[0] = {};
    size_t sizeC = 0;
    int c[10];

    // Act
    createOrderArrayByIncreasingByDifference(a, 0, b, 0, c, &sizeC);

    // Assert
    assert(sizeC == 0);
}

void test_createOrderArrayByIncreasingByDifference_equalElemsAtBorders() {
    // Arrange
    int a[5] = {1, 6, 7, 8, 9};
    int b[5] = {1, 2, 3, 4, 9};
    size_t sizeC = 0;
    int c[10];

    // Act
    createOrderArrayByIncreasingByDifference(a, 5, b, 5, c, &sizeC);

    // Assert
    assert(sizeC == 3);
    assert(isEqualArrays(c, sizeC, (int[]) {6, 7, 8}, sizeC));
}

void test_createOrderArrayByIncreasingByDifference_oneEqualLeftBorder() {
    // Arrange
    int a[5] = {1, 6, 7, 8, 9};
    int b[5] = {1, 2, 3, 4, 5};
    size_t sizeC = 0;
    int c[10];

    // Act
    createOrderArrayByIncreasingByDifference(a, 5, b, 5, c, &sizeC);

    // Assert
    assert(sizeC == 4);
    assert(isEqualArrays(c, sizeC, (int[]) {6, 7, 8, 9}, sizeC));
}

void test_createOrderArrayByIncreasingByDifference_oneEqualAtRightBorder() {
    // Arrange
    int a[5] = {5, 6, 7, 8, 9};
    int b[5] = {1, 2, 3, 4, 9};
    size_t sizeC = 0;
    int c[10];

    // Act
    createOrderArrayByIncreasingByDifference(a, 5, b, 5, c, &sizeC);

    // Assert
    assert(sizeC == 4);
    assert(isEqualArrays(c, sizeC, (int[]) {5, 6, 7, 8}, sizeC));
}

void test_createOrderArrayByIncreasingByDifference_equalElemsInCenter() {
    // Arrange
    int a[5] = {1, 5, 6, 7, 9};
    int b[5] = {2, 5, 6, 7, 10};
    size_t sizeC = 0;
    int c[10];

    // Act
    createOrderArrayByIncreasingByDifference(a, 5, b, 5, c, &sizeC);

    // Assert
    assert(sizeC == 2);
    assert(isEqualArrays(c, sizeC, (int[]) {1, 9}, sizeC));
}

void test_createOrderArrayByIncreasingByDifference() {
    test_createOrderArrayByIncreasingByDifference_leftIsEmpty();
    test_createOrderArrayByIncreasingByDifference_rightIsEmpty();
    test_createOrderArrayByIncreasingByDifference_twoArraysAreEmpty();
    test_createOrderArrayByIncreasingByDifference_equalElemsAtBorders();
    test_createOrderArrayByIncreasingByDifference_oneEqualLeftBorder();
    test_createOrderArrayByIncreasingByDifference_oneEqualAtRightBorder();
    test_createOrderArrayByIncreasingByDifference_equalElemsInCenter();
}

void test_allElemsAOrderInBOrder_aIsEmpty() {
    // Arrange
    int a[0] = {};
    int b[5] = {1, 2, 3, 4, 5};

    // Act and Assert
    assert(allElemsAOrderInBOrder(b, 5, a, 0));
}

void test_allElemsAOrderInBOrder_bIsEmpty() {
    // Arrange
    int a[5] = {1, 2, 3, 4, 5};
    int b[0] = {};

    // Act and Assert
    assert(!allElemsAOrderInBOrder(b, 0, a, 5));
}

void test_allElemsAOrderInBOrder_aAndBIsEmpty() {
    // Arrange
    int a[0] = {};
    int b[0] = {};

    // Act and Assert
    assert(allElemsAOrderInBOrder(b, 0, a, 0));
}

void test_allElemsAOrderInBOrder_arrayALargeB() {
    // Arrange
    int a[5] = {1, 2, 3, 4, 5};
    int b[4] = {1, 2, 3, 4};

    // Act and Assert
    assert(!allElemsAOrderInBOrder(b, 4, a, 5));
}

void test_allElemsAOrderInBOrder_arrayBLargeA() {
    // Arrange
    int b[5] = {1, 2, 3, 4, 5};
    int a[4] = {1, 2, 3, 4};

    // Act and Assert
    assert(allElemsAOrderInBOrder(b, 5, a, 4));
}

void test_allElemsAOrderInBOrder_notEqualEmlemsAtBorders() {
    // Arrange
    int b[5] = {2, 5, 6, 7, 9};
    int a[5] = {1, 5, 6, 7, 8};

    // Act and Assert
    assert(!allElemsAOrderInBOrder(b, 5, a, 5));
}

void test_allElemsAOrderInBOrder_notEqualEmlemsAtLeftBorder() {
    // Arrange
    int b[5] = {2, 5, 6, 7, 8};
    int a[5] = {1, 5, 6, 7, 8};

    // Act and Assert
    assert(!allElemsAOrderInBOrder(b, 5, a, 5));
}

void test_allElemsAOrderInBOrder_notEqualEmlemsAtRightBorder() {
    // Arrange
    int b[5] = {2, 5, 6, 7, 8};
    int a[5] = {2, 5, 6, 7, 9};

    // Act and Assert
    assert(!allElemsAOrderInBOrder(b, 5, a, 5));
}

void test_allElemsAOrderInBOrder_notEqualEmlemsAtCenter() {
    // Arrange
    int b[5] = {1, 5, 6, 7, 8};
    int a[5] = {1, 2, 3, 4, 9};

    // Act and Assert
    assert(!allElemsAOrderInBOrder(b, 5, a, 5));
}

void test_allElemsAOrderInBOrder() {
    test_allElemsAOrderInBOrder_aIsEmpty();
    test_allElemsAOrderInBOrder_bIsEmpty();
    test_allElemsAOrderInBOrder_aAndBIsEmpty();
    test_allElemsAOrderInBOrder_arrayALargeB();
    test_allElemsAOrderInBOrder_arrayBLargeA();
    test_allElemsAOrderInBOrder_notEqualEmlemsAtBorders();
    test_allElemsAOrderInBOrder_notEqualEmlemsAtLeftBorder();
    test_allElemsAOrderInBOrder_notEqualEmlemsAtRightBorder();
    test_allElemsAOrderInBOrder_notEqualEmlemsAtCenter();
}

void test() {
    test_intersectionTwoArray();
    test_unionTwoArray();
    test_differenceTwoArray();
    test_symmetricDifferenceTwoArray();
    test_allElementsFromAInB();
    test_isEqualArrays();
    test_twoArrayDontHaveEqualElements();
    test_mergeOrderArrayByIncreasing();
    test_createOrderArrayByIncreasingByIntersection();
    test_createOrderArrayByIncreasingByDifference();
    test_createOrderArrayByIncreasingBySymmetricDifference();
    test_allElemsAOrderInBOrder();
}

int main() {
    test();

    return 0;
}

