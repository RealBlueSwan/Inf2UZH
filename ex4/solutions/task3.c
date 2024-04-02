#include <stdio.h>
#include <stdlib.h>

/* Divide and conquer approach, majority element is something 
that appears more than or same than half times in an array.  */


int majorityelement(int* A, int l, int r, int h){
    if (l == r) { return A[l]; }
    //make a counter for the variables... 
    int m = (l + h)/2;
    printf("%d %d %d\n", l, r, h);

    //the most used element on the left side and if combined with the right part
    //is bigger than n/2 +1 then its a majority element...
    return majorityelement(A, l, m, h), majorityelement(A, m + 1, r, h);
}
int counter(int* A){
    //oh well, how should I implement this shit...
    return;
}


int main() {
    int A[] = {-2, -3, 4, -1, -2, -2, -2};
    int h = sizeof(A)/sizeof(A[0]);
    int r = h;
    majorityelement(A, r, 0, h);
    return 0;
}