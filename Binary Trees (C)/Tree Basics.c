#include <stdio.h>
#include <stdlib.h>

struct node_S
{
    int value;
    struct node_S *left;
    struct node_S *right;
};
typedef struct node_S Node;

Node *newNode(int data)
{
    Node *node = (Node*) malloc(sizeof(Node));

    node->value = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void printTreeFunctional(Node *root, int depth)
{   
    if (root == NULL) return;
    printTreeFunctional(root->right, depth + 1);
    for (int i = 0; i < depth; i++)
        printf("\t");
    printf("%d\n", root->value);
    printTreeFunctional(root->left, depth + 1);
}

void printTree(Node *root)
{
    printTreeFunctional(root, 0);
}

void makeTreeFunctional(Node *root, int level, int maxLevel)
{
    if (level == maxLevel) return;
    makeTreeFunctional(root->left = newNode(2 * root->value + 1), level + 1, maxLevel);
    makeTreeFunctional(root->right = newNode(2 * root->value + 2), level + 1, maxLevel);
}

Node *makeTree(int levels)
{
    Node *root = newNode(0);
    makeTreeFunctional(root, 0, levels - 1);
    return root;
}

int main()
{
    Node *root = makeTree(4);
    printTree(root);
    return 0;
}