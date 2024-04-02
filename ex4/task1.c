#include <stdio.h>
#include <stdlib.h>

int BinarySearchClosestNumber(int A[], int l, int r, int t, int closest){
    /*define new middle variable*/
    int m = l + (r - l)/2;
    /*Breakcondition*/
    if (l > r) {    return closest; }
    /* check if the current m is larger than the last */
    if (abs(t - closest) > abs(t - A[m])) { closest = A[m]; }
    /*start the recusive calls until r < l*/
    if (A[m] > t) {    return BinarySearchClosestNumber(A, l, m - 1, t, closest); }
    else       {    return BinarySearchClosestNumber(A, m + 1, r, t, closest); }
}

int main() {
    int t = 18; int A[] = {1, 3, 5, 7, 8, 10, 11, 22, 25}; int n = sizeof(A) / sizeof(A[0]);
    int closest = BinarySearchClosestNumber(A, 0, n - 1, t, A[0]);  // n - 1 is the last index
    printf("Closest number to %d is %d\n", t, closest);
    return 0;
}