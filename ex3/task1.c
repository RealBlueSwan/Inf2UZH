#include <stdio.h>
#include <time.h> // measuring run time

int n, t;
int A[100000000];

int linear_search(int A[], int n, int t) {
    for (int i = 0; i < n; i++){
        if (A[i] == t) {
            return 1;
        }
    }
    return 0; // not found
}

int binary_search(int A[], int n, int t) {
    //go to the middle, check if its bigger or smaller, then repeat
    int l = 0;
    int r = n;
    int m = (l + r)/2;
    //check if this works... 
    printf("%d\n", r);
    while (l <= r & t == A[m]) {
        if 
    }
    
    return 0; // not found
}

int main() {
    clock_t start, end;

    //some random value I did because I cant use the console without it crashing:D
    int n = 20;
    //printf("Enter an integer for n: ");
    //scanf("%d", &n); 

    printf("Generate an array with %d distinct integers from 1 to %d.\n", n, n);
    for(int i = 0; i < n; i++) A[i] = i + 1;
    
    //some random calue for t because I cant use the fking console pls fix.... 
    int t = 7;
    //printf("Enter an integer for t: \n");
    //scanf("%d", &t); 
    start = clock();
    linear_search(A, n, t); // your implementation
    end = clock();
    double run_time = ((double)(end - start))/(CLOCKS_PER_SEC/1000);
    printf("Linear search takes : %f millseconds\n", run_time); 

    start = clock();
    binary_search(A, n, t); // your implementation
    end = clock();
    run_time = ((double)(end - start))/(CLOCKS_PER_SEC/1000);
    printf("Binary search takes : %f millseconds\n", run_time); 
}