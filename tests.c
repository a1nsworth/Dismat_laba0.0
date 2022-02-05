#include "includes/set.h"

void test_intersectionTwoArray_oneArrayIsEmpty() {
    int a[0] = {};
    int b[5] = {1, 2, 3, 4, 5};
    size_t sizeC = 0;
    int c[5];
    intersectionTwoArray(a, 0, b, 5, c, &sizeC);

    assert(sizeC == 0);
}

void test_intersectionTwoArray_twoArrayIsEmpty() {
    int a[0] = {};
    int b[5] = {};
    size_t sizeC = 0;
    int c[5];
    intersectionTwoArray(a, 0, b, 0, c, &sizeC);

    assert(sizeC == 0);
}

void test_intersectionTwoArray_equalArrays() {
    int a[5] = {1, 2, 3, 4, 5};
    int b[5] = {1, 2, 3, 4, 5};
    size_t sizeC = 0;
    int c[5];
    intersectionTwoArray(a, 0, b, 0, c, &sizeC);

    assert(sizeC == 5);
    assert(c[0] == 1);
    assert(c[1] == 2);
    assert(c[2] == 3);
    assert(c[3] == 4);
    assert(c[4] == 5);
}

void test_intersectionTwoArray_equalElemsAtBorders() {
    int a[5] = {1, 22, 9, 7, 5};
    int b[5] = {1, 23, 34, 45, 5};
    size_t sizeC = 0;
    int c[5];
    intersectionTwoArray(a, 0, b, 0, c, &sizeC);

    assert(sizeC == 2);
    assert(c[0] == 1);
    assert(c[1] == 5);
}

void test_intersectionTwoArray_oneEqualElemsAtBorder() {
    int a[5] = {7, 33, 393, 733, 5};
    int b[5] = {5, 263, 374, 485, 45};
    size_t sizeC = 0;
    int c[5];
    intersectionTwoArray(a, 0, b, 0, c, &sizeC);

    assert(sizeC == 1);
    assert(c[0] == 5);
}

void test_intersectionTwoArray_randomPositionEqualElems() {
    int a[5] = {1, 21, 33, 44, 56};
    int b[5] = {33, 44, 3, 45, 57};
    size_t sizeC = 0;
    int c[5];
    intersectionTwoArray(a, 0, b, 0, c, &sizeC);

    assert(sizeC == 2);
    assert(c[0] == 33);
    assert(c[1] == 44);
}

void test_intersectionTwoArray() {
    test_intersectionTwoArray_oneArrayIsEmpty();
    test_intersectionTwoArray_twoArrayIsEmpty();
    test_intersectionTwoArray_equalArrays();
    test_intersectionTwoArray_equalElemsAtBorders();
    test_intersectionTwoArray_oneEqualElemsAtBorder();
    test_intersectionTwoArray_randomPositionEqualElems();
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

