#include <stdio.h>

const int INF = 1000000;

int max(int x, int y) {
    if (x > y)
        return x;
    return y;
}

void write_to_row(int n, int row[], int value) {
    for (int i = 0; i<=n; i++)
        row[i] = value;
}

void copy_row(int n, int source[], int dest[]) {
    for (int i = 0; i<=n; i++)
        dest[i] = source[i];
}

int max_value(int n, int w[], int v[], int W) {
    // w[1...n], v[1...n]
    int curr_row[W+1], prev_row[W+1];
    
    // First, initialize DP with -infinity (in practice a small enough value)
    write_to_row(W, curr_row, -INF);
    write_to_row(W, prev_row, -INF);
    
    // current row is index 1
    prev_row[0] = 0;  // equivalent to dp[0][0] = 0;
    for (int i = 1; i<=n; i++) {
        write_to_row(W, curr_row, -INF);
        for (int j = 0; j<=W; j++) {
            if (j < w[i])
                curr_row[j] = prev_row[j];
            else
                curr_row[j] = max(prev_row[j], prev_row[j-w[i]] + v[i]);
        }
        // Copy curr_row into prev_row to make curr_row available for row i+1
        copy_row(W, curr_row, prev_row);
    }

    int final_answer = 0;
    for (int i = 0; i<=W; i++)
        final_answer = max(final_answer, curr_row[i]);
    
    return final_answer;
}

int main() {
    int n = 5, w[] = {0, 2, 4, 5, 3, 9}, v[] = {0, 3, 5, 8, 4, 10}, W = 20;
    printf("%d", max_value(n, w, v, W));
    return 0;
}