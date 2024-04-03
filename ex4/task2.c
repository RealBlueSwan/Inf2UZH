#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {return (a > b)? a : b;}
int max3(int a, int b, int c) {return max(max(a, b), c);}

int MaxCrossSubArray(int *A, int l, int r, int m) {
    int sum = 0; int sum_left = 0;

    for (int i = m; i >= l; i--) {
        sum = sum + A[i];
        if (sum > sum_left) {
            sum_left = sum;
        }
    }

    sum = 0; int sum_right = 0;

    for (int i = m+1; i <= r; i++) {
        sum = sum + A[i];
        if (sum > sum_right){
            sum_right = sum;
        }
    }
    return sum_left + sum_right;
}


int MaxSumSubArray(int *A, int l, int r){
    if (r == l) {
        return A[l];
    }
    int m = l + (r-l)/2;
    return max3(MaxSumSubArray(A, l, m), MaxSumSubArray(A, m+1, r), MaxCrossSubArray(A, l, r, m));


}


int main(){
    int A[] = {-1, 2, -4, 1, 9, -6, 7, -3, 5}; int n = sizeof(A)/sizeof(A[0]);
    int max_sum = MaxSumSubArray(A, 0, n-1);
    printf("%d", max_sum);
    return 0;
}