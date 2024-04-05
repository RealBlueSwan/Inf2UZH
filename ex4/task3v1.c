#include <stdio.h>
#include <stdlib.h>

/*recursion to basecase*/

int MajorityElement(int *A, int l, int r) {
    /*Basecase*/
    if (l == r) {   return A[l];    }
    /*define a new mid every time*/
    int m = (l+r)/2;

    /*recursive calls down to basecase*/
    int leftMajority = MajorityElement(A, l, m);
    int rightMajority = MajorityElement(A, m+1, r);

    /*left and right majorityElement then return left majority*/
    if (leftMajority == rightMajority){
        return leftMajority;
    }

    /*count left and right subarray if its not the same*/
    int leftCount = 0; int rightCount = 0;
    for (int i = l; i >= r; i++){
        if (A[i] == leftMajority){
            leftCount += 1;
        }
        else if (A[i] == rightMajority){
            rightCount += 1;
        }
        
    }
    if (leftCount >= rightCount){
        return leftMajority;
    }
    return rightMajority;
}

void printArray(int *A, int n){
    for (int i = 0; i < n-1; i++) {
        printf("%d", A[i]);
    }
    printf("%d", A[n-1]);
}

int main() {
    int A[] = {1, 0, 0, 0, 0, 1, 1, 0, 0}; int n = sizeof(A)/sizeof(A[0]); 
    int Major = MajorityElement(A, 0, n-1);
    printArray(A, n);
    printf("this is the majority element: %d", Major);
    return 0;
}