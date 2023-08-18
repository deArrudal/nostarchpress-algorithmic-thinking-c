// This code returns “Time-Limit Exceeded” error for big problems.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100000

// return true if the snowflakes are the same by “moving right”.
int identical_right(int snow1[], int snow2[], int start) {
    int offset;

    for(offset = 0; offset < 6; offset++) {
        // (start + offset) % 6 returns values between 0 and 5.
        if(snow1[offset] != snow2[(start + offset) % 6]) {
            return 0;
        }
    }

    return 1;
}

// return true if the snowflakes are the same by “moving left”.
int identical_left(int snow1[], int snow2[], int start) {
    int snow2_index;
    int offset;

    for(offset = 0; offset < 6; offset++) {
        snow2_index = start - offset;

        // returns an offset between 0 and 5.
        if(snow2_index < 0) {
            snow2_index += 6; 
        }

        if(snow1[offset] != snow2[snow2_index]) {
            return 0;
        }
    }

    return 1;
}

// check if two snowflakes are identical.
int are_identical(int snow1[], int snow2[]) {
    int start;

    for(start = 0; start < 6; start++) {
        if(identical_right(snow1, snow2, start)) {
            return 1;
        }

        if(identical_left(snow1, snow2, start)) {
            return 1;
        }
    }

    return 0;
}

// check snowflakes' array for two identical snowflakes. 
void identify_identical(int snowflakes[][6], int n) {
    int i, j;

    for(i = 0; i < n; i++) {
        for(j = i + 1; j < n; j++) {
            if(are_identical(snowflakes[i], snowflakes[j])) {
                printf("Twin integers found.\n");
                return;
            }
        }
    }

    printf("No two integers are alike.\n");
}

int main(void) {
    static int snowflakes[SIZE][6];
    int n, i, j;
    
    scanf("%d", &n);
    
    for(i = 0; i < n; i++) {
        for(j = 0; j < 6; j++) {
            scanf("%d", &snowflakes[i][j]);
        }
    }

    identify_identical(snowflakes, n);

    return 0;
}