#include <stdio.h>
#include <stdlib.h>

int BinarySearchClosestNumber(int* A, int l, int r, int t, int closest){
    /*define new middle variable*/
    int m = l + (l + r)/2;
    /*Breakcondition*/
    if (l > r) {    return closest; }
    /* check if the current m is larger than the last */
    if (abs(t - closest) > abs(t - A[m])) { closest = A[m]; }
    /*start the recusive calls until r < l*/
    if (m > t) {    BinarySearchClosestNumber(A, l, m - 1, t, closest); }
    else       {    BinarySearchClosestNumber(A, m + 1, r, t, closest); }
}

int main() {
    int t = 5; int A[] = {1, 3, 5, 7, 8, 10, 11, 22, 25}; int n = sizeof(A) / sizeof(A[0]);
    BinarySearchClosestNumber(A, 0, n, t, 0);
}