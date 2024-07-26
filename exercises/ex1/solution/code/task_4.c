#include <stdio.h>

int zeroSubarray(int const array[], int length) {
    for (int i = 0; i < length; i++) {
        int sum = 0;
        for (int j = i; j < length; j++) {
            sum += array[j];
            if (sum == 0) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    int array[] = {3, -2, 4, 2, 1, -5};
    int arrayLength = sizeof(array) / sizeof(array[0]);
    printf("Solution: %d", zeroSubarray(array, arrayLength));
    return 0;
}