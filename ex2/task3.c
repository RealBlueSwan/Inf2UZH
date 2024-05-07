#include <stdio.h>
#include <stdlib.h>

int moveCount = 0;

void hanoi(int n, char src, char aux, char dest) {
    if (n==1){
        printf("Move disk 1 from rod %c to rod %c\n", src, dest);
        moveCount++;
        return;
    }
    hanoi(n-1, src, dest, aux);

    printf("Move disk %d from rod %c to rod %c\n", n, src, dest);
    moveCount++;

    hanoi(n-1, aux, src, dest);
}

int main(){
    int n = 6;
    if (n <= 0){    
        printf("number of plates must be positive\n");    
    } else {
        hanoi(n, 'A', 'B', 'C');
        printf("Total number of moves: %d\n", moveCount);
    }

    return 0;
}