#include <stdio.h>

int max(int x, int y) {
    if (x > y)
        return x;
    return y;
}

int longest_seq(int n, int a[]) {
    int dp[n+1];

    for (int i = 1; i<=n; i++) {
        int max_subproblem = 0;
        for (int j = 1; j<i; j++)
            if (a[j] <= a[i])
                max_subproblem = max(max_subproblem, dp[j]);
        if (max_subproblem == 0)
            dp[i] = 1;
        else
            dp[i] = max_subproblem + 1;
    }
    
    int final_answer = 0;
    for (int i = 1; i<=n; i++)
        final_answer = max(final_answer, dp[i]);
    return final_answer;
}

int main() {
    int a[9] = {0, 5, 10, 7, 4, 8, 9, 2, 10};
    printf("%d\n", longest_seq(8, a));
    int b[9] = {0, 7, 10, 4, 9, 7, 10, 8, 12};
    printf("%d\n", longest_seq(8, b));
    return 0;
}