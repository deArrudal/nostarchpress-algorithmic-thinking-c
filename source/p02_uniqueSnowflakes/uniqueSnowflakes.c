#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int identical_right(int snow1[], int snow2[], int start) {
    int offset;

    for(offset = 0; offset < 6; offset++) {
        // (start + offset) % 6 returns values between 0 and 5.
        if(snow1[offset] != snow2[(start + offset) % 6]) {
            return 0; // false.
        }
    }

    return 1; // true.
}

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

void identify_identical(int values[], int n) {
    int i, j;

    for(i = 0; i < n; i++) {
        for(j = i + 1; j < n; j++) {
            if(values[i] == values[j]) {
                printf("Twin integers found.\n");
                return;
            }
        }
    }

    printf("No two integers are alike.\n");
}

int main(void) {
    int a[5] = {1, 2, 3, 1, 5};
    
    identify_identical(a, 5);
    
    return 0;
}