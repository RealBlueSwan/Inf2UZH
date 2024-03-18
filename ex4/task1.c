#include <stdio.h>
#include <stdlib.h>

int BinarySearch(int A[], int t, int high, int low) {
    if (low > high) {
        return -1;  // target is not found
    }
    int mid = low + (high - low) / 2;
    if (A[mid] == t) {  
        return A[mid];  // return the number itself
    } else if (A[mid] < t) {  
        return BinarySearch(A, t, high, mid + 1);  
    } else {  // A[mid] > t
        return BinarySearch(A, t, mid - 1, low);  
    }
}
int BinarySearchCloserNumber(int A[], int t, int high, int low, int closest) {
    if (low > high) {
        return closest;
    }
    int mid = low + (high - low) / 2;
    if (abs(t - closest) > abs(t - A[mid])) {
        closest = A[mid];
    }
    if (A[mid] < t) {
        return BinarySearchCloserNumber(A, t, high, mid + 1, closest);
    } else {
        return BinarySearchCloserNumber(A, t, mid - 1, low, closest);
    }
}

int main() {
    int A[10];
    for(int i = 0; i < 10; i++) A[i] = i + 1;
    int t = 3;
    int high = 9;
    int low = 0;
    printf("%d\n", BinarySearch(A, t, high, low));
    printf("%d\n", BinarySearchCloserNumber(A, t, high, low, A[0]));
    return 0;
}