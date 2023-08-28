#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 255
#define TEST_CASE 5

// tree node element.
typedef struct node {
    int candy;
    struct node *left, *right;
} node;

// helper function for creating house nodes.
node *new_house(int candy) {
    node *house = malloc(sizeof(node));
    if(house == NULL) {
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
    if(nonhouse == NULL) {
        fprintf(stderr, "malloc error\n");
        exit(1);
    }

    nonhouse->left = left;
    nonhouse->right = right;

    return nonhouse;
}

// compute the total amount of candy using recursion.
int tree_candy(node *tree) {
    if(!tree->left && !tree->right) { // base case - house node.
        return tree->candy;
    }

    return tree_candy(tree->left) + tree_candy(tree->right);
}

// compute the number of streets getting back to the root.
int tree_streets(node *tree) {
    if (!tree->left && !tree->right) { // base case - house node.
        return 0;
    }
    // +4 is add to compute the runaround for each child branch.
    return tree_streets(tree->left) + tree_streets(tree->right) + 4;
}

// compute the height of the tree.
int max(int v1, int v2) {
    if(v1 > v2) {
        return v1;
    } else {
        return v2;
    }
}

// compute tree's height.
int tree_height(node *tree) {
    if(!tree->left && !tree->right) { // base case - house node.
        return 0;
    }

    return 1 + max(tree_height(tree->left), tree_height(tree->right));
}

// compute the amount of streets and candy of a given tree.
void tree_solve(node *tree) {
    int candy = tree_candy(tree);
    int height = tree_height(tree);
    int num_streets = tree_streets(tree) - height;

    printf("%d %d\n", num_streets, candy);
}


// build tree based on inputs.
node *read_tree_helper(char *line, int *pos){
    node *tree;

    tree = malloc(sizeof(node));
    if(tree == NULL) {
        fprintf(stderr, "malloc error\n");
        exit(1);
    }

    if(line[*pos] == '(') { // non-house node
        (*pos)++;
        tree->left = read_tree_helper(line, pos);
        (*pos)++;
        tree->right = read_tree_helper(line, pos);
        (*pos)++;
        return tree;

    } else { // house node.
        tree->left = NULL;
        tree->right = NULL;
        tree->candy = line[*pos] - '0';

        (*pos)++;

        // check for closing parenthesis, linespace or endline.
        if(line[*pos] != ')' && line[*pos] != ' ' && line[*pos] != '\0') {
            // multiply last digit by 10 and add current digit.
            tree->candy = tree->candy * 10 + line[*pos] - '0';
            (*pos)++;
        }

        return tree; 
    }
}

// call helper to build tree for a read line.
node *read_tree(char *line) {
    int pos = 0;
    return read_tree_helper(line, &pos);
}

int main(void) {
    int i;
    char line[SIZE + 1];
    node *tree;

    for(i = 0; i < TEST_CASE; i++) {
        gets(line);

        tree = read_tree(line);

        tree_solve(tree);
    }

    return 0;
}