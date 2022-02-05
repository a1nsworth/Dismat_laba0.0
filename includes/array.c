//
// Created by yaxbi on 05.02.2022.
//

#include "array.h"

void inputArray(int *a, const size_t n) {
    for (register size_t i = 0; i < n; ++i)
        scanf("%d", &a[i]);
}

void outputArray(const int *a, const size_t n) {
    for (register size_t i = 0; i < n; ++i)
        printf("%d", a[i]);
}
