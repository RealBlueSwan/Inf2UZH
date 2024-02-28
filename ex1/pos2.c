#include <stdio.h>
#include <limits.h>

int a[] = {10, 2, 3, 4, 5, 6, 7, 8, 9, 8};
int listlength = sizeof(a) / sizeof(a[0]);

int pos2() {
  if (listlength < 2) {
    printf("Invalid input. Array should have at least two elements.\n");
    return INT_MIN;
  }

  int first = INT_MIN;
  int second = INT_MIN;

  for (int i = 0; i < listlength; i++) {
    if (a[i] > first) {
      second = first;
      first = a[i];
    } else if (a[i] > second && a[i] != first) {
      second = a[i];
    }
  }

  if (second == INT_MIN) {
    printf("No second largest element exists.\n");
    return INT_MIN;
  }

  return second;
}

int main() {
  int secondLargest = pos2();
  if (secondLargest != INT_MIN) {
    printf("The second largest number is %d\n", secondLargest);
  }
  return 0;
}

/*
Original code:

int j, q, r, i, k, l;
int a[] = {10, 2, 3, 4, 5, 6, 7, 8, 9, 8};
int listlength = sizeof(a) / sizeof(a[0]);

int pos2() {
  q = 0;
  r = 0;
  for (j = 0; j < listlength; j++) {
    if (q < a[j]) {
      r = q;
      q = a[j];
    }
  }
  return r;
}

int main() {
  int secondLargest = pos2();
  printf("The second largest number is %d\n", secondLargest);
  return 0;
}
*/