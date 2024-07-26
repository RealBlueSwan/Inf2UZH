#include <stdio.h>
#include <time.h> // measuring run time

int n, t;
int A[1000000];

int linear_search(int A[], int n, int t) {  //asymptotic complexity is linear n times
    for (int i = 0; i < n; i++){
        if (A[i] == t) {
            return 1;
        }
    }
    return 0; // not found
}

int binary_search(int A[], int n, int t) {  //asymptotic complexity is log(n)
    //go to the middle, check if its bigger or smaller, then repeat
    int l = 0;
    int r = n;
    int m = (l + r)/2;
    while (l <= r && t != A[m])  {
        if (A[m] > t) { r = m - 1;  }
        else {  l = m + 1;  }
        m = (l + r)/2;
    }
    if (l <= r) {   return 1;   }
    return 0; // not found
}

int main() {
    clock_t start, end;
    printf("Enter an integer for n: ");
    scanf("%d", &n); 
    printf("Generate an array with %d distinct integers from 1 to %d.\n", n, n);
    for(int i = 0; i < n; i++) A[i] = i + 1;
    printf("Enter an integer for t: \n");
    scanf("%d", &t); 
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

