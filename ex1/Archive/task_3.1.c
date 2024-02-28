#include <stdio.h>

void bubbleSort(int array[], int length) {
    int k = 0;
    for (int i = length - 1; i >= 1; i--) { //how many times to repeat
        for (int n = 1; n <= i; n++) { //repeat for the whole row
            if (array[n-1] > array[n]) {//wert array[n] grösser als vergleichswert k
                k = array[n-1];
                array[n-1] = array[n];
                array[n] = k;
            }
        }
    }
}

int main() {
    int array[] = {0, 1, 3, 4, 2, 8, 9, 5, 6, 7};
    int length = sizeof(array) / sizeof(array[0]);
    bubbleSort(array, length);
    for (int i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }
    return 0;
}