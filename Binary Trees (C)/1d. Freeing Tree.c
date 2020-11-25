#include "1a. Tree Basics.h"

void freeTree(Node *root)
{
    if (root == NULL) return;
    freeTree(root->right);
    freeTree(root->left);
    free(root);
}


int main()
{
    Node *root = makeTree(5);
    printTree(root);
    freeTree(root);
    printf("%d\n", root->value); //output shows the memory is no longer allocated
    return 0;
}