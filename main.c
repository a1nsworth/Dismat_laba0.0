#include "includes/array.h"

void intersectionTwoArray(const int *a, const size_t sizeA, const int *b, const size_t sizeB, int *c, size_t *sizeC) {
    for (register size_t i = 0; i < sizeA; ++i) {
        c[*sizeC] = a[i];
        (*sizeC)++;
    }

    bool elemInArray = false;
    for (register size_t i = 0; i < sizeB; ++i) {
        for (register size_t j = 0; j < sizeB; ++j)
            if (b[i] == a[j])
                elemInArray = true;

        if (!elemInArray) {
            c[*sizeC] = b[i];
            (*sizeC)++;
            elemInArray = false;
        }
    }
}

int main() {
    printf("Hello, World!\n");
    return 0;
}
