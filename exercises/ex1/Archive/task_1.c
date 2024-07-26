#include "stdio.h"
//c works in a 4 byte or 32bit system so the maximum value for an integer is 2147483647, to fix this you can use long long int a = 2147483648;
void snippet1() {
    int a = 2147483647;
    int b = 2147483648;
    int c = 2147483649;
    printf("%d, %d, %d", a, b, c);
}
//The array is not initialized/pre-defined so it will contain garbage values. A correct way to initialize would be §int myArray[20] = {0};
void snippet2() {
    int myArray[20];
    for (int i = 0; i < 20; i++) {
        printf("%d \n", myArray[i]);
    }
}
//The array is defined with a size of 1, but it is being accessed with an index of 1, 2 and 3. This will cause a buffer overflow and will result in undefined behavior.
//If I try to access the fourth value of the array it will just give me junk values.
void snippet3() {
    int myArray[1];
    myArray[0] = 0;
    myArray[1] = 1;
    myArray[2] = 2;
    printf("%d, %d, %d, %d", myArray[0], myArray[1], myArray[2], myArray[3]);
}
//decodes the array of integers into a string with %c and prints the string. First line prints all integers in the array, second line prints the string.
//Problem arrises because you cant decode whether it was a number with 3 or 2 digits just from watching the array of integers.
void snippet4() {
    int myArray[] = {72, 101, 108, 108, 111, 32,
                     87, 111, 114, 108, 100, 33};
    for (int i = 0; i < 12; i++) {
        printf("%d", myArray[i]);
    }
    printf("\n");
    for (int i = 0; i < 12; i++) {
        printf("%c", myArray[i]);
    }
}
//int are defined as 4 bytes, so if you request the first elements c returns 4 bytes, since there are 5 elements in the array, 4 * 5 = 20 for the entire array.
void snippet5() {
    int myArray[5];
    int size1 = sizeof(myArray);
    int size2 = sizeof(myArray[0]);
    int size3 = size1 / size2;
    printf("%d, %d, %d", size1, size2, size3);
}
//the C compiler automatically adds a null character to the end of the string, making the actual size of myString 6 bytes. 
//You're also printing the null character at the end of the string. 
//The null character doesn't have a printable representation, so it appears as x00 in your output.
void snippet6() {
    char myString[] = "hello";
    int stringSize = sizeof(myString) / sizeof(myString[0]);
    printf("%d, ", stringSize);
    for (int i = 0; i < stringSize; i++) {
        printf("%c", myString[i]);
    }
}

int main() {
    //The desired snippet can be called by modifying the next line
    snippet6();
    return 0;
}
