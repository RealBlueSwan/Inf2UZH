#include <stdio.h>

void rleCompression(char string[], int length) {
    int counter = 1;
    for (int i = 1; i < length; i++) { // Increment i at each iteration
        if(string[i] == string[i - 1]) {
            counter++;
        } else {
            printf("%d%c", counter, string[i - 1]); // Print counter and the previous character
            counter = 1;
        }
    }
    printf("%d%c", counter, string[length - 1]); // Print the count and the last character
}

int main() {
    char string[] = "AAABBAAAA";
    int length = (sizeof(string) / sizeof(string[0])) - 1;
    rleCompression(string, length);
    return 0;
}