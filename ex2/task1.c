/*damn libraries, cant wrap my head around them, for the simplest shit I need the library import!*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isPalindrome(char *X, int i, int j) {
    /*we need to make this recursivelly, so there must be a basecase*/
    /*define basecase, this will return false if there is something different in the two strings*/
    if (X[i] != X[j]) { return 0;   }

    /*check ig they crossed paths or are the same*/
    else if (i >= j){ return X[i];    }

    /*now we create the recursion*/
    else {  return isPalindrome(X, ++i, --j);   }
}
int main(){
    char X[] = "1a_b3cD45t54Dc3b_a1";
    int length = sizeof(X)/sizeof(X[0]) -1;
    if (isPalindrome(X, 0, length-1)) {
        printf("is Palindrome");
    }
    else {
        printf("isnt Palindrome");
    }
    return 0;
}