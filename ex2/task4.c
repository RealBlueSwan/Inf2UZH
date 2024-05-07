#include <stdio.h>
#include <stdlib.h>

/* Find the position of the operator with the lowest
priority between index h and index t */
int findOperator(char *expr, int h, int t) {
    /*galgensatz*/
    if (h == t) {   return expr[t]; }
    /*lets search for () first*/
    int temp_1, temp_2;
    for (int i = h; i = t; i++){
        if (expr[i] == '(') {
            temp_1 = i;
        } else if (expr[i] == ')'){
            temp_2 = i;
            /*delete the parenteses -------------dont know how tho...----------*/
            
            findOperator(expr, temp_1+1, temp_2-1);
        }
        /*add a count for when ( is encountered and set temp_1 to this int*/
        /*then do the same for ) and make a temp for ) location*/
    }
    for (int i = h; i = t; i++){
        if (expr[i] == '+'){
            
            /*calculate save that and go from */
        if (expr[i] == '-'){
            return
        }
        /*find the least relevant expression e.g. plus and minus */
    }
    /* if there is no  "( )"*/
    return 0;
}
/* Calculate the result of the expression between index h and index t*/
float calculator(char *expr, int h, int t) {
    //Put your code here
    return 0;
}

int main() {
    char expr[] = "(3+4)*5/6+7*8*(1+2-3)";
    int size = sizeof(expr)/sizeof(expr[0]);
    findOperator(expr, 0, size);
    return 0;
    //Put your code here
}
