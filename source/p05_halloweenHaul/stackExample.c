#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 255

typedef struct node {
    int candy;
    struct node *left, *right;
} node;

// helper function for creating house nodes.
node *new_house(int candy) {
    node *house = malloc(sizeof(node));
    if (house == NULL) {
        fprintf(stderr, "malloc error\n");
        exit(1);
    }

    house->candy = candy;
    house->left = NULL;
    house->right = NULL;

    return house;
}

// helper function for creating non-house nodes.
node *new_nonhouse(node *left, node *right) {
    node *nonhouse = malloc(sizeof(node));
    if (nonhouse == NULL) {
        fprintf(stderr, "malloc error\n");
        exit(1);
    }

    nonhouse->left = left;
    nonhouse->right = right;

    return nonhouse;
}

typedef struct stack {
    node *values[SIZE];
    int highest_used;
} stack;

// creates a stack.
stack *new_stack(void) {
    stack *s = malloc(sizeof(stack));
    if (s == NULL) {
        fprintf(stderr, "malloc error\n");
        exit(1);
    }

    s->highest_used = -1; // -1 means an empty stack.
    return s;
}

// pushes on a stack.
void push_stack(stack *s, node *value) {
    s->highest_used++;
    s->values[s->highest_used] = value;
}

// pop on a stack.
node *pop_stack(stack *s) {
    node *ret = s->values[s->highest_used];
    s->highest_used--;
    return ret;
}

// check if stack is empty.
int is_empty_stack(stack *s) {
    return s->highest_used == -1;
}

// calculate the amount of candy.
int tree_candy(node *tree) {
    int total = 0;
    stack *s = new_stack();

    while (tree != NULL) {
        if (tree->left && tree->right) {
            push_stack(s, tree->left);
            tree = tree->right;
        } else {
            total = total + tree->candy;
            if (is_empty_stack(s)) {
                tree = NULL;
            } else {
                tree = pop_stack(s);
            }
        }
    }
    return total;
}

// test if stack is working.
int main() {
    stack *s;
    s = new_stack();

    node *n, *n1, *n2, *n3, *a, *b;
    n1 = new_house(20);
    n2 = new_house(30);
    n3 = new_house(10);
    b = new_nonhouse(n2, n3);
    a = new_nonhouse(n1, b);
    
    /* 
    push_stack(s, n1);
    push_stack(s, n2);
    push_stack(s, n3);

    while (!is_empty_stack(s)) {
        n = pop_stack(s);
        printf("%d\n", n->candy);
    }
    */

    printf("%d\n", tree_candy(a));

    return 0;
}
