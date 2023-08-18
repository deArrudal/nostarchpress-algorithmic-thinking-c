#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100000

// linked-list structure that stores a snowflake_node containing both a 
// snowflake element and a pointer to the next one.
typedef struct snowflake_node {
    int snowflake[6];
    struct snowflake_node *next;
} snowflake_node;

// compute the snowflake's sum code. 
int code(int snowflakes[]) {
    return (snowflakes[0] + snowflakes[1] + snowflakes[2]
        + snowflakes[3] + snowflakes[4] + snowflakes[5]) % SIZE;
}

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
void identify_identical(snowflake_node *snowflakes[]) {
    snowflake_node *node1, *node2;
    int i;

    for(i = 0; i < SIZE; i++) {
        node1 = snowflakes[i];

        while(node1 != NULL) {
            node2 = node1->next;

            while(node2 != NULL) {
                if(are_identical(node1->snowflake, node2->snowflake)) {
                    printf("Twin snowflakes found.\n");
                    return;
                }

                node2 = node2->next;
            }

            node1 = node1->next;
        }
    }

    printf("No two snowflakes are alike.\n");
}

int main(void) {
    // snowflakes array is an array of buckets, where each bucket 
    // contains a linked list.
    static snowflake_node *snowflakes[SIZE] = {NULL};
    snowflake_node *snow; // snowflake.
    int n, i, j, snowflake_code;

    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        snow = malloc(sizeof(snowflake_node));
        if(snow == NULL) {
            fprintf(stderr, "malloc error\n");
            exit(1);
        }

        for(j = 0; j < 6; j++) {
            scanf("%d", &snow->snowflake[j]);
        }

        snowflake_code = code(snow->snowflake);
    
        snow->next = snowflakes[snowflake_code];

        snowflakes[snowflake_code] = snow; // put snowflake into bucket.
    }

    identify_identical(snowflakes);

    free(snow);

    return 0;
}