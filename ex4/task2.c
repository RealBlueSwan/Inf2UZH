#include <stdio.h>
#include <stdlib.h>

int findsub(int* A, int l, int r) {
    int max;
    if (l == r) {//basecase same number 
        return A[l];
    }
    else if {
        int m = (l+r) / 2;
        int links = findsub(A, l, m);
        int rechts = findsub(A, m, r);
        return (links < rechts ? r : l);
 
    }
    
    

    //compare the two
    //what do I want to do...
    //what is the basecase?
    //basecase could be... one side is bigger than the other and append next value next to it... 
    //Basecase could be that it found the biggest sum, but how should I know if its the biggest sum... 
    //if all the numbers of a certain snipplet of the Array combined are bigger than the other snipplets
    //make a counter like sum and if its smaller just leave that part away. 

}

int main(void){
    int A[] = {-1, 2, -4, 1, 9, -6, 7, -3, 5};
    int l = 0;
    int r = sizeof(A) / sizeof(A[0]);
    findsub(A, l, r); 

}