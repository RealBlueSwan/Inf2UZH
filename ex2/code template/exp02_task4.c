#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Find the position of the operator with the lowest 
 * priority between index h and index t
*/
int findOperator(char *expr, int h, int t) {
    // use count to make sure the current operator are not inside of a pair of '()'
    // because the ops inside '()' have higher priority
    int count = 0;
    for (int i = h; i <= t; i++){
        if (expr[i] == '('){
            count++;
        }
        else if ((expr[i] == ')')){
            count--;
        }
        else if (count == 0 && (expr[i] == '+') || (expr[i] == '-')) {
            return i;
        }
    }
    for (int i = h; i <= t; i++){
        if (expr[i] == '('){
            count++;
        }
        else if ((expr[i] == ')')){
            count--;
        }
        else if (count == 0 && (expr[i] == '*') || (expr[i] == '/')) {
            return i;
        }
    }
    // -1 means no operator
    return -1;
}
char* removeOuterParentheses(char* expr) {
    int h = 0;
    int t = strlen(expr)-1;
    if (expr[0] == '(' && expr[t] == ')') {
        int count = 0;
        for (int n = h + 1; n < t; n++){
            if (expr[n] == '(') {
                count++;
            }
            else if (expr[n] == ')'){
                if (count == 0){
                    //parenteses are not paired...
                    return expr;
                }
                count--;
            }
            
        }
        // parentheses are paired
        expr[t] = '\0';
        return expr + 1;
    }
    // The first and last chatacters are not parentheses
    return expr;
}

/**
 * Calculate the result of the expression between index h and index t
*/
float calculator(char *expr, int h, int t) {

    // check if both sides have a pair of ()
    // remove them because they don't make any sense
    // !!!! Attension! You must check if the '(' and ')' are paired
    

    int opIndex = findOperator(expr, h, t);
    // printf("op idx %d", opIndex);

    
    if (...) {
        // no operator or the given expr is a negative number (-xxx)
        // Hint: use atoi() to convert numerical string to number
    }
    else {
        // do the math
    }
}

int main() {
    char expr[100];
    printf("Enter an expression: ");
    fgets(expr, sizeof(expr), stdin);
    
    // Remove trailing newline character
    if (expr[strlen(expr) - 1] == '\n') {
        expr[strlen(expr) - 1] = '\0';
    }

    float result = calculator(expr, 0, strlen(expr) - 1);
    printf("\nAns = %f\n", result);

    return 0;
}