#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1000000

// longest common prefix.
int prefix_length(char s1[], char s2[]) {
    int i = 1; // problem requires we index a string from 1.
    
    while(s1[i] == s2[i]) {
        i++;
    }

    return i - 1;
}

// longest common suffix.
int suffix_length(char s1[], char s2[], int len) {
    int i = len;
    
    while((i >= 2) && (s1[i] == s2[i - 1])) {
        i--;
    }

    return len - i;
}

int main(void) {
    // an extra element for the null terminator and start index equals 1.
    static char s1[SIZE + 2], s2[SIZE + 2];
    int len, prefix, suffix, total;

    gets(&s1[1]); // get stores characters at index 1 rather than 0.
    gets(&s2[1]);

    len = strlen(&s1[1]);

    prefix = prefix_length(s1, s2);
    suffix = suffix_length(s1, s2, len);

    total = (prefix + 1) - (len - suffix) + 1; // add 1 to include limit.
    if(total < 0) {
        total = 0;
    }

    printf("%d\n", total);

    for(int i = 0; i < total; i++) {
        printf("%d", i + len - suffix);

        // display correct format.
        if(i < total - 1) {
            printf(" ");
        } else {
            printf("\n");
        }
    }

    return 0;
}

