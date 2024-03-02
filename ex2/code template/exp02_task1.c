#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Check the symbols in index i and index j
*/
int isPalindrome(char A[], int i, int j) {

    if (A[i] != A[j]){
        return 0;
    }else if (j <= i)
    {
        return 1;
    }else{
        return isPalindrome(A, i+1, j-1);
    }
    

}

int main() {
    char X[] = "1a_b3cD45tgt54Dc3b_a1";
    int len = sizeof(X) / sizeof(X[0]) - 1;

    if (isPalindrome(X, 0, len - 1)) {
        printf("This is a Palindrome.");
    }
    else {
        printf("This is not a Palindrome.");
    }

    return 0;
}