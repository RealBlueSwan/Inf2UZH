#include <stdio.h>
#include <stdlib.h>

#define N 10

int h1(int k) { return k % N; }

int h2(int k) { return (int)(.1 * k) % N; }

void printT(int *T) {
    for (int i = 0; i < N; ++i) {
        printf("%d,", T[i]);
    }
    printf("\n");
}

int cuckooInsert(int *T1, int *T2, int k) {
    int y;
    int max_loop = 50;
    while (max_loop-- != 0) {
        /* try inserting on table 1 */
        printf("T1: Inserted %d at 1.%d", k, h1(k));
        if (T1[h1(k)] == -1) { /* still empty slot */
            T1[h1(k)] = k;
            printf("\n");
            return 0;
        }
        /* collision on table 1 */
        /* swap */
        y = T1[h1(k)];
        T1[h1(k)] = k;
        printf(" pushed %d out\n", y);
        /* try inserting on table 2 */
        printf("T2: Inserted %d at 2.%d", y, h2(y));
        if (T2[h2(y)] == -1) { /* if slot for y on T2 is free */
            T2[h2(y)] = y;
            printf("\n");
            return 0;
        }
        /* collision on table 2 */
        k = T2[h2(y)]; /* reuse k for pushed out of table 2 */
        T2[h2(y)] = y;
        printf(" pushed %d out\n", k);
        /* next interation */
    }
    printf("Infinite loop\n");
    /* error */
    return -1;
}

void cukooSearch(int *T1, int *T2, int k) {
    if (T1[h1(k)] == k) {
        printf("Found %d in table 1 at position %d\n", k, h1(k));
    } else if (T2[h2(k)] == k) {
        printf("Found %d in table 2 at position %d\n", k, h2(k));
    } else {
        printf("Did not find %d\n", k);
    }
}

int main(int argc, char *argv[]) {
    int T1[N];
    int T2[N];

    /* init tables */
    for (int i = 0; i < N; ++i) {
        T1[i] = -1;
        T2[i] = -1;
    }

    int n = 3;
    /* int vals[] = {44, 236, 36, 136}; /\* other example infinite loop *\/ */
    int vals[] = {12, 112, 1112};

    printf("T1: ");
    printT(T1);
    printf("T2: ");
    printT(T2);

    printf("inserting...\n");

    for (int i = 0; i < n; ++i) {
        cuckooInsert(T1, T2, vals[i]);
    }

    printf("T1: ");
    printT(T1);
    printf("T2: ");
    printT(T2);

    cukooSearch(T1, T2, 236);

    return 0;
}
