#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int sz;
    printf("Enter the size of the array: ");
    scanf("%d", &sz);

    int randArray[sz];
    for (int i = 0; i < sz; ++i)
        randArray[i] = rand() % 100; // Generate numbers between 0 and 99

    printf("\nElements of the array:\n");
    for (int i = 0; i < sz; ++i)
        printf("Element %d: %d\n", i + 1, randArray[i]);

    return 0;
}
