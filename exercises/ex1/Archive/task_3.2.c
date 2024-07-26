#include <stdio.h>

void insertionSort(int array[], int length) {
    int i, key, j;
    for (i = 1; i < length; i++) {
        key = array[i];
        j = i - 1;

        /* Move elements of array[0..i-1], that are
        greater than key, to one position ahead
        of their current position */
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
}

int main() {
    int array[] = {0, 1, 3, 4, 2, 8, 9, 5, 6, 7};
    int length = sizeof(array) / sizeof(array[0]);
    insertionSort(array, length);
    for(int i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }
    return 0;
}