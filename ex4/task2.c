#include <stdio.h>
#include <stdlib.h>
/* If the array has only one element, return that element.
Find the middle of the array.
Recursively find the maximum subarray sum in the left half, right half, and crossing the middle.
The maximum subarray sum is the maximum of the three sums found in step 3. */

int max(int a, int b) {return (a > b)? a : b;}
int max3(int a, int b, int c){ return max(max(a, b), c);}
int maxSubArraySum(int* A, int l, int r){
    if (l == r) {
        return A[l];
    }

    int m = (l + r)/2;

    return max(maxSubArraySum(A, l, m), maxSubArraySum(A, m+1, r));
}

int main() {
    int A[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(A)/sizeof(A[0]);
    int max_sum = maxSubArraySum(A, 0, n-1);
    printf("Maximum contiguous sum is %d\n", max_sum);
    return 0;
}