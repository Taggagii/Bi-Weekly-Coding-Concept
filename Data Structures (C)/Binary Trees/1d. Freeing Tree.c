#include "1a. Tree Basics.h"

//dropping into the tree and deleting when we reach a leaf
void freeTree(Node *root)
{
    if (root == NULL) return;
    freeTree(root->right);
    freeTree(root->left);
    free(root);
}


int main()
{
    //showing the creating and deletion of tree
    Node *root = makeTree(5);
    printTree(root);
    freeTree(root);
    printf("%d\n", root->value); //output shows the memory is no longer allocated
    /*
        Printing the entire tree would not work, as C doesn't recognize when the value has been free and simply believes it a pointer — when
        printed, the tree appears the print the entirety of lined up memory
    */
    return 0;
}
