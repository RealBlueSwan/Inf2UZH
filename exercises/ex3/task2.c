#include <stdio.h>

int A[10000];
int n, k, result;
//The code returns a sum of all the int values that j takes when accessing 
//the 12th element after the current one as long as it does not reach the 
//breaking point. But result -1000. It has a O(n^2). 
int whatdoesitdo(int A[], int n, int k) {
    int result = -1000;
    for (int i = 0; i < n; i++) {
        int current = 0;
        for (int j = i; j < n; j = j + k) {
            current = current + A[j];
        }
        if (current >= result) {
            result = current;
        }
    }
    return result;
}

int main() {
    //define n to make an array
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    //create a sorted array with n integers from 0 to n-1
    for(int i = 0; i < n; i++) A[i] = i + 1;

    //define a skipping value
    int k;
    printf("Enter the skipping value: ");
    scanf("%d", &k);

    //just a dummy to print later
    int dummy1 = whatdoesitdo(A, n, k);

    //printing
    printf("this is the result: %d", dummy1);
    return 0;
}