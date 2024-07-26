#include <stdio.h>

int longest_seq(int n, int a[]) {
    int dp[n+1], p[n+1];

    for (int i = 1; i<=n; i++) {
        int max_subproblem = 0;
        p[i] = -1; // use -1 for marking empty parent cells

        for (int j = 1; j<i; j++)
            if (a[j] <= a[i] && max_subproblem < dp[j]) {
                max_subproblem = dp[j];
                p[i] = j;
            }
        if (max_subproblem == 0)
            dp[i] = 1;
        else
            dp[i] = max_subproblem + 1;
    }
    
    int final_answer = 0, answer_index;
    for (int i = 1; i<=n; i++)
        if (final_answer < dp[i]) {
            final_answer = dp[i];
            answer_index = i;
        }

    // Use a stack to create the right order of the extracted subsequence.
    int stack[n], top = 0;

    int i = answer_index;
    while (i != -1) {  // while we are not in empty parent cell
        stack[top] = a[i];
        top++;
        i = p[i];
    }

    printf("Longest subsequence has length %d: ", final_answer);
    while (top > 0) {  // empty the stack
        printf("%d ", stack[top-1]);
        top--;
    }

    return final_answer;
}

int main() {
    int a[9] = {0, 5, 10, 7, 4, 8, 9, 2, 10};
    longest_seq(8, a);
    int b[9] = {0, 7, 10, 4, 9, 7, 10, 8, 12};
    longest_seq(8, b);
    return 0;
}