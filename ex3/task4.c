#include <stdio.h>

int A[1000];

int algo1(int A[], int n, int k) {
    int sum = 0;
    for (int i = 0; i < k; i++){
        int maxi = i;
        for (int j = i; j < n; j++) {
            if (A[j]>A[maxi])   {   maxi = j;   }   }
        //maintenance
        sum = sum + A[maxi];
        int swp = A[i];
        A[i] = A[maxi];
        A[maxi] = swp;
    } 
    //termination 
    return sum;
}

//initialisation
int main(){
    int n = 10;
    int k = 20;
    for(int i = 0; i < 999; i++) A[i] = i + 1;
    int result = algo1(A, n, k);
    printf("%d", result);
    return 0;

}