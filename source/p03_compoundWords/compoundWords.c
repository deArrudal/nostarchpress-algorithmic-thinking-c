#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define hashsize(n) ((unsigned long)1 << (n))
#define hashmask(n) (hashsize(n) - 1)

#define NUM_BITS 17
#define WORD_LENGTH 16

// create a hash code based on the word.
unsigned long oaat(char *key, unsigned long len, unsigned long bits) {
    unsigned long hash, i;
  
    for(hash = 0, i = 0; i < len; i++) {
        hash += key[i]; // add character to hash.
        hash += (hash << 10); 
        hash ^= (hash >> 6);
    }

    hash += (hash << 3);
    hash ^= (hash << 11);
    hash += (hash << 15);

    return hash & hashmask(bits);
}

/* read input string of unknown length
    https://stackoverflow.com/questions/16870485 */
char *read_line(int size) {
    char *str;
    int ch;
    int len = 0;
    
    str = malloc(size);
    if(str == NULL) {
        fprintf(stderr, "malloc error\n");
        exit(1);
    }

    // loop til end of file (EOF) or breakline ("\n").
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

// define linked list element.
typedef struct word_node {
    char **word;
    struct word_node *next;

} word_node;

// search hash table for a specific word.
int in_hash_table(word_node *hash_table[], char *find, unsigned find_len) {
    unsigned word_code;
    word_node *wordptr;

    word_code = oaat(find, find_len, NUM_BITS); // hash code.

    wordptr = hash_table[word_code];
    while(wordptr) {
        // compare size and characters, return 1 if true.
        if((strlen(*(wordptr->word)) == find_len) &&
         (strncmp(*(wordptr->word), find, find_len) == 0)) {
            return 1;
        }

        wordptr = wordptr->next;
    }

    return 0;
}

// check hash table for parts of the word.
void identify_compound_words(char *words[], word_node *hash_table[], int total_words) {
    int i, j;
    unsigned len;

    for(i = 0; i < total_words; i++) { 
        len = strlen(words[i]);

        for(j = 1; j < len; j++) {
            // split word in combination pairs.
            if((in_hash_table(hash_table, words[i], j)) &&
             (in_hash_table(hash_table, &words[i][j], len - j))) {
                printf("%s\n", words[i]);
                break;
            }
        }
    } 
}

int main(void) {
    static char *words[1 << NUM_BITS] = {NULL};
    static word_node *hash_table[1 << NUM_BITS] = {NULL};
    int total = 0;
    char *word;
    word_node *wordptr;
    unsigned length, word_code;


    word = read_line(WORD_LENGTH);
    
    while(*word) {
        words[total] = word;

        wordptr = malloc(sizeof(word_node));
        if(wordptr == NULL) {
            fprintf(stderr, "malloc erro\n");
            exit(1);
        }

        length = strlen(word);

        word_code = oaat(word, length, NUM_BITS); // hash code.

        // add to linked-list.
        wordptr->word = &words[total];
        wordptr->next = hash_table[word_code];
        hash_table[word_code] = wordptr;

        // read next line.
        word = read_line(WORD_LENGTH);
        total++;
    }

   identify_compound_words(words, hash_table, total);

    return 0; 
}