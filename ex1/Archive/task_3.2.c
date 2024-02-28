//Also write the function insertionSort(int array[], int length) in C which takes an array and its length as input and sorts it using the insertion sort algorithm.
#include <stdio.h>

void insertionSort(int array[], int length) {
    int k = 0;
    for (int  i = 1; i = length; i++) { //how many times to repeat
        for (int n = i; n = length; n++) { //repeat for the whole row
            if (array[n+1] > array[n]) {//wert array[n] grösser als vergleichswert k
                k = array[n+1];
                array[n+1] = array[n];
                array[n] = k;
            }
        }
    }
}

int main() {
    int array[] = {0, 1, 3, 4, 2, 8, 9, 5, 6, 7};
    int length = (sizeof(array) / sizeof(array[0])) - 1;
    insertionSort(array, length);
    printf("%d", array);
    return 0;
}