#include <stdio.h>
#include <time.h> // measuring run time

int n, k;
int A[100000000];


int whatDoesItDo(int A[], int n, int k) {
    int result = -1000;
    for (int i = 0; i < n; i++){
        int current = 0;
        for (int j = i; j < n; j = j + k) {
            current = current + A[j];
        }
        if (current > result) {
            result = current;
        }
    }
    return result;
}


int main(){
    clock_t start, end;
    printf("Enter an integer for n: ");
    scanf("%d", &n); 
    printf("Generate an array with %d distinct integers from 1 to %d.\n", n, n);
    for(int i = 0; i < n; i++) A[i] = i + 1;
    printf("Enter an integer for k: \n");
    scanf("%d", &k); 
    start = clock();
    whatDoesItDo(A, n, k);
    end = clock();
    double run_time = ((double)(end - start))/(CLOCKS_PER_SEC/1000);
    printf("whatDoesItDo takes : %f millseconds\n", run_time); 
}