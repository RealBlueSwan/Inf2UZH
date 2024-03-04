#include <stdio.h>
#include <stdlib.h>

int moveCount = 0;

/**
 * Move disk n from src to dst via aux
 * Hints:
 * 1. move n-1 disks from source to auxiliary via destination
 * 2. move the n-th disk from source to destination in 1 step
 * 3. move n-1 disks from source to destination via auxiliary
*/
void hanoi(int n, char src, char aux, char dst) {
    // Base case (termination condition)
    if(n == 1) {
        printf("\n Move disk 1 from rod %c to rod %c", src, dst);
        moveCount++;
        return;
    }

    // Move n-1 disks from src to aux, so they are out of the way
    hanoi(n-1, src, dst, aux);

    // Move the nth disk from src to dst
    printf("\n Move disk %d from rod %c to rod %c", n, src, dst);
    moveCount++;

    // Move the n-1 disks that we left on aux to dst
    hanoi(n-1, aux, src, dst);
}

int main() {
    int n;

    printf("Enter the number of disks: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Number of disks must be positive.\n");
        return 1;  // return an error code
    }

    printf("\nHanoi Tower Steps:\n");
    hanoi(n, 'A', 'B', 'C');

    printf("\nTotal number of moves: %d\n", moveCount);

    return 0;
}