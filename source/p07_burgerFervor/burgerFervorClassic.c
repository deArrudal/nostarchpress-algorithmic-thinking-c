#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// return max between two integers.
int max(int v1, int v2) {
    if (v1 > v2) {
        return v1;
    } else {
        return v2;
    }
}

// solve problem for t.
int solve_t(int m, int n, int t) {
    int first, second;

    if(t == 0) { // base case.
        return 0;
    }

    if(t >= m) { // solve for m burger.
        first = solve_t(m, n, t - m);
    } else {
        first = -1;
    }

    if(t >= n) {// solve for n burger.
        second = solve_t(m, n, t -n);
    } else {
        second = -1;
    }

    if(first == -1 && second == -1) { // no solution found to t.
        return -1;
    } else {
        return max(first, second) + 1; // compute burger.
    }
}

// try solve for t, or for its subproblems.
void solve(int m, int n, int t) {
    int result, i;

    result = solve_t(m, n, t);

    if(result >= 0) { // display solution if found.
        printf("%d\n", result);
    } else { // try solve subproblem.
        i = t - 1;

        result = solve_t(m, n, i);

        while(result == -1) { // loop until soution is found.
            i--;

            result = solve_t(m, n, i);
        }

        printf("%d %d\n", result, t - i); // display burgers and beer.
    }
}

int main(void) {
    int m, n, t;

    while(scanf("%d%d%d", &m, &n, &t) != -1) { // loop through multiple cases.
        solve(m, n, t);
    }

    return 0;
}

