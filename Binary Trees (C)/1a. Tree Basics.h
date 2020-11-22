#include <stdio.h>
#include <stdlib.h>

//general stucture for the nodes of the tree
struct node_S
{
    int value;
    struct node_S *left;
    struct node_S *right;
};
typedef struct node_S Node;

//generates a new node holding the value as input
Node *newNode(int value)
{
    Node *node = (Node*) malloc(sizeof(Node));

    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

//prints the tree recursively (starting right and moving back)
void printTreeFunctional(Node *root, int depth)
{   
    //leave when end is reached
    if (root == NULL) return;
    //recursively move all the way to the far right
    printTreeFunctional(root->right, depth + 1);
    //after the far right / left is reached, print out the value of this leaf
    for (int i = 0; i < depth; i++)
        printf("\t");
    printf("%d\n", root->value);
    //recursively move to the far left (from the current level)
    printTreeFunctional(root->left, depth + 1);
}

//allows the user to have an easy input function
void printTree(Node *root)
{
    printTreeFunctional(root, 0);
}

//generates a tree of indexes (to be updated). Starts left and moves right using rule 1 from "General Rules of Binary Trees"
void makeTreeFunctional(Node *root, int level, int maxLevel)
{
    if (level == maxLevel) return;
    makeTreeFunctional(root->left = newNode(2 * root->value + 1), level + 1, maxLevel);
    makeTreeFunctional(root->right = newNode(2 * root->value + 2), level + 1, maxLevel);
}

//allows the user to have an easy input function
Node *makeTree(int levels)
{
    //generating a root to branch from
    Node *root = newNode(0);
    //recusively building the tree
    makeTreeFunctional(root, 0, levels - 1);
    return root;
}
