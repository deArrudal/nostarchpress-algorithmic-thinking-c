#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define hashsize(n) ((unsigned long)1 << (n))
#define hashmask(n) (hashsize(n) - 1)

#define NUM_BITS 17

// create a hash code based on entries.
unsigned long oaat(char *key, unsigned long len, unsigned long bits) {
    unsigned long hash, i;

    // add elements of key to hash.  
    for(hash = 0, i = 0; i < len; i++) {
        hash += key[i];
        hash += (hash << 10); // hash*(2^10)
        hash ^= (hash >> 6); // hash/(2^6)
    }

    hash += (hash << 3);
    hash ^= (hash << 11);
    hash += (hash << 15);

    return hash & hashmask(bits);
}

/* based on https://stackoverflow.com/questions/16870485 */
char *read_line(int size) {
    char *str;
    int ch;
    int len = 0;
    
    str = malloc(size);
    if(str == NULL) {
        fprintf(stderr, "malloc error\n");
        exit(1);
    }

    // loop til end of file or breakline.
    while((ch = getchar()) != EOF && (ch != '\n')) {
        str[len++] = ch;
        
        if(len == size) { // resize if necessary.
            size *= 2;

            str = realloc(str, size);
            if(str == NULL) {
                fprintf(stderr, "malloc error\n");
                exit(1);
            }
        }
    }

    str[len] = '\0'; // add null character.

    return str;
}

typedef struct word_node {
    char **word;
    struct word_node *next;
} word_node;

// takes a hash table and a word to find in the hash table.
int in_hash_table(word_node *hash_table[], char *find, unsigned find_len) {
    unsigned word_code;
    word_node *wordptr;

    word_code = oaat(find, find_len, NUM_BITS);

    wordptr = hash_table[word_code];

    while(wordptr) {
        if((strlen(*(wordptr->word)) == find_len) &&
         (strncmp(*(wordptr->word), find, find_len) == 0)) {
            return 1;
        }

        wordptr = wordptr->next;
    }

    return 0;
}