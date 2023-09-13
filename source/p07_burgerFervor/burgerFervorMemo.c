#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10000

// return max between two integers.
int max(int v1, int v2) {
    if (v1 > v2) {
        return v1;
    } else {
        return v2;
    }
}

// solve problem for t.
int solve_t(int m, int n, int t, int memo[]) {
    int first, second;

    if(memo[t] != -2) { // known solution.
        return memo[t];
    }

    if(t == 0) { // base case.
        memo[t] = 0;
        return memo[0];
    }

    if(t >= m) { // solve for m burger.
        first = solve_t(m, n, t - m, memo);
    } else {
        first = -1;
    }

    if(t >= n) { // solve for n burger.
        second = solve_t(m, n, t - n, memo);
    } else {
        second = -1;
    }

    if(first == -1 && second == -1) { // no solution found to t.
        memo[t] = -1;
        return memo[t];
    } else {
        memo[t] = max(first, second) + 1; // compute burger.
        return memo[t];
    }
}

// try solve for t, or for its subproblems.
void solve(int m, int n, int t) {
    int result, i;
    int memo[SIZE];

    for(int i = 0; i <= t; i++) { // initialize the memo.
        memo[i] = -2;
    }

    result = solve_t(m, n, t, memo);

    if(result >= 0) { // display solution if found.
        printf("%d\n", result);
    } else { // try solve subproblem.
        i = t - 1;
        
        result = solve_t(m, n, i, memo);

        while(result == -1) { // loop until soution is found.
            i--;
            result = solve_t(m, n, i, memo);
        }

        printf("%d %d\n", result, t - i); // display burgers and beer.
    }
}

int main(void) {
    int m, n, t;

    while(scanf("%d%d%d", &m, &n, &t) != -1) {
        solve(m, n, t);
    }
    
    return 0;
}