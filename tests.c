#include "includes/set.h"
#include "includes/array.h"

void test_intersectionTwoArray_oneArrayIsEmpty() {
    // Arrange
    int a[0] = {};
    int b[5] = {1, 2, 3, 4, 5};
    size_t sizeC = 0;
    int c[5];

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
    int c[5];

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
    int c[5];

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
    int c[5];

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
    int c[5];

    // Act
    unionTwoArray(a, 5, b, 5, c, &sizeC);

    // Assert
    assert(sizeC == 5);
    assert(isEqualTwoArrays(c, sizeC, (int[]) {1, 5}, sizeC));
}

void test_unionTwoArray_allIsEqual() {
    // Arrange
    int a[5] = {1, 2, 3, 4, 5};
    int b[5] = {1, 2, 3, 4, 5};
    size_t sizeC = 0;
    int c[5];

    // Act
    unionTwoArray(a, 5, b, 5, c, &sizeC);

    // Assert
    assert(sizeC == 0);
}

void test_unionTwoArray_oneElemIsEqual() {
    // Arrange
    int a[5] = {1, 2, 3, 4, 5};
    int b[5] = {5, 222, 333, 444, 55};
    size_t sizeC = 0;
    int c[5];

    // Act
    unionTwoArray(a, 5, b, 5, c, &sizeC);

    // Assert
    assert(sizeC == 0);
    assert(isEqualTwoArrays(c, sizeC, (int[]) {5}, sizeC));
}

void test_unionTwoArray_randomPositionEqualElems() {
    // Arrange
    int a[5] = {23, 2, 3, 4, 5};
    int b[5] = {12, 23, 3, 2, 1};
    size_t sizeC = 0;
    int c[5];

    // Act
    unionTwoArray(a, 5, b, 5, c, &sizeC);

    // Assert
    assert(sizeC == 0);
    assert(isEqualTwoArrays(c, sizeC, (int[]) {23, 2, 3}, sizeC));
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
    assert(isEqualTwoArrays(c, sizeC, (int[]) {2, 3, 4, 1}, sizeC));
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
    int c[5];

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
    int c[5];

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
    int c[5];

    // Act
    symmetricDifferenceTwoArray(a, 5, a, 5, c, &sizeC);

    // Assert
    assert(sizeC == 4);
    assert(isEqualTwoArrays(c, sizeC, (int[]) {1, 2, 6, 7}, sizeC));
}

void test_symmetricDifferenceTwoArray_equalAtBorders() {
    // Arrange
    int a[5] = {1, 22, 33, 44, 5};
    int b[5] = {1, 45, 55, 66, 5};
    size_t sizeC = 0;
    int c[5];

    // Act
    symmetricDifferenceTwoArray(a, 5, a, 5, c, &sizeC);

    // Assert
    assert(sizeC == 6);
    assert(isEqualTwoArrays(c, sizeC, (int[]) {22, 33, 44, 45, 55, 66}, sizeC));
}

void test_symmetricDifferenceTwoArray_oneEqualAtBorder() {
    // Arrange
    int a[5] = {1, 2, 3, 4, 5};
    int b[5] = {9, 8, 7, 6, 1};
    size_t sizeC = 0;
    int c[5];

    // Act
    symmetricDifferenceTwoArray(a, 5, a, 5, c, &sizeC);

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
    assert(isEqualArrays(b, 3, a, 0));
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
    assert(isEqualArrays(b, 4, a, 4));
}

void test_allElementsFromAInB_BlargeA() {
    // Arrange
    int a[4] = {1, 2, 3, 4};
    int b[5] = {1, 2, 3, 4, 5};

    // Act and Assert
    assert(isEqualArrays(b, 5, a, 4));
}

void test_allElementsFromAInB_equalElemsAtBorders() {
    // Arrange
    int a[2] = {1, 9};
    int b[5] = {1, 5, 8, 6, 9};

    // Act and Assert
    assert(isEqualArrays(b, 5, a, 4));
}

void test_allElementsFromAInB() {
    test_allElementsFromAInB_oneArrayIsEmpty();
    test_allElementsFromAInB_twoArraysIsEmpty();
    test_allElementsFromAInB_arrayALargeArrayB();
    test_allElementsFromAInB_twoArraysIsEqual();
    test_allElementsFromAInB_BlargeA();
    test_allElementsFromAInB_equalElemsAtBorders();
}

void test() {
    test_intersectionTwoArray();
    test_unionTwoArray();
    test_differenceTwoArray();
    test_symmetricDifferenceTwoArray();
    test_allElementsFromAInB();
    test_isEqualArrays();
    test_twoArrayDontHaveEqualElements();
    test_createOrderArrayByIncreasingByUnion();
    test_createOrderArrayByIncreasingByIntersection();
    test_createOrderArrayByIncreasingBySymmetricDifference();
    test_allElemsAOrderInBOrder();
}

int main() {
    test();

    return 0;
}

