#include <stdio.h>
#include <stdlib.h>

//need to implement a recursive function that iterates over itself and find even closer numbers

int closestnumber(int* A, int t, int a, int b)   {

    //basecase
    if (a > b)  {   return A[b];   }
    
    //test if distance to a or b is bigger, increase or decrease
    if (abs(A[a] - t) < abs(A[b] - t))  {   return closestnumber(A, t, a, b-1); }
    else    {   return closestnumber(A, t, a+1, b); }
}


int main(){
    int A[] = {1, 3, 6, 7, 14, 20, 30};
    int t = 5;
    int n = sizeof(A) / sizeof(A[0]);  // Get the number of elements in A
    int result = closestnumber(A, t, 0, n - 1);  // Pass n - 1 as the last index
    printf("%d", result);
    return 0;
}