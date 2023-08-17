#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100

// return the index of the shortest line.
int shortest_line_index(int lines[], int n) {
    int shortest = 0;
    int k;

    for (k = 1; k < n; k++) {
        if (lines[k] < lines[shortest]) {
            shortest = k;
        }
    }

    return shortest;
}

// display the number of people in the shortest line.
void solve(int lines[], int n, int m) {
    int shortest;
    int j;

    for(j = 0; j < m; j++) {
        shortest = shortest_line_index(lines, n);
        printf("%d\n", lines[shortest]);

        lines[shortest]++; // add person to line.
    }
}

int main(void) {
    int lines[MAX_LINES];
    int n, m, i;

    scanf("%d %d", &n, &m); // read lines and persons.

    for(i = 0; i < n; i++) {
        scanf("%d", &lines[i]);
    }

    solve(lines, n, m);

    return 0;
}