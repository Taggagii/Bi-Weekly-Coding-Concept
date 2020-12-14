#include "1a. Tree Basics.h"

//generates a tree of indexes (to be updated). Starts left and moves right using rule 1 from "General Rules of Binary Trees"
void makeTreeFromArrayFunctional(Node *root, int values[], int length, int previousIndex)
{
    int left, right;
    if ((left = 2 * previousIndex + 1) < length) 
        makeTreeFromArrayFunctional(root->left = newNode(values[left]), values, length, left);
    if ((right = 2 * previousIndex + 2) < length)  
        makeTreeFromArrayFunctional(root->right = newNode(values[right]), values, length, right);
}

//allows the user to have an easy input function
Node *makeTreeFromArray(int values[], int length)
{
    //generating a root to branch from
    Node *root = newNode(values[0]);
    //recusively building the tree
    makeTreeFromArrayFunctional(root, values, length, 0);
    return root;
}

int main()
{
    //simple usage of concepts mentioned in "Tree Basics.h"
    int myArray[] = {3, 1, 4, 1, 5, 9, 2, 6, 5};
    int length = sizeof(myArray) / sizeof(myArray[0]);
    printf("length %d\n", length);
    Node *root = makeTreeFromArray(myArray, length);
    printTree(root);
    return 0;
}