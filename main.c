#include "includes/array.h"
#include "includes/set.h"

int main() {
    size_t sizeA, sizeB;
    scanf("%zd %zd", &sizeA, &sizeB);
    int a[sizeA];
    inputArray(a, sizeA);
    int b[sizeB];
    inputArray(b, sizeB);

    size_t sizeC = 0;
    int c[sizeA + sizeB];

    size_t numberTusk;
    scanf("%zd", &numberTusk);

    switch (numberTusk) {
        case 1:
            intersectionTwoArray(a, sizeA, b, sizeB, c, &sizeC);
            outputArray(c, sizeC);
            break;
        case 2:
            unionTwoArray(a, sizeA, b, sizeB, c, &sizeC);
            outputArray(c, sizeC);
            break;
        case 3:
            differenceTwoArray(a, sizeA, b, sizeB, c, &sizeC);
            outputArray(c, sizeC);
            break;
        case 4:
            symmetricDifferenceTwoArray(a, sizeA, b, sizeB, c, &sizeC);
            outputArray(c, sizeC);
            break;
        case 5:
            printf("%s", allElementsFromAInB(b, sizeB, a, sizeA) ? "true" : "false");
            break;
        case 6:
            printf("%s", isEqualArrays(b, sizeB, a, sizeA) ? "true" : "false");
            break;
        case 7:
            printf("%s", twoArrayDontHaveEqualElements(a, sizeA, b, sizeB) ? "true" : "false");
            break;
        case 8:
            mergeToOrderByIncreasingArrays(a, sizeA, b, sizeB, c, &sizeC);
            outputArray(c, sizeC);
            break;
        case 9:
            createOrderArrayByIncreasingByIntersection(a, sizeA, b, sizeB, c, &sizeC);
            outputArray(c, sizeC);
            break;
        case 10:
            createOrderArrayByIncreasingByDifference(a, sizeA, b, sizeB, c, &sizeC);
            outputArray(c, sizeC);
            break;
        case 11:
            createOrderArrayByIncreasingBySymmetricDifference(a, sizeA, b, sizeB, c, &sizeC);
            outputArray(c, sizeC);
            break;
        case 12:
            printf("%s", allElemsAOrderInBOrder(b, sizeB, a, sizeA) ? "true" : "false");
            break;
    }


    return 0;
}
