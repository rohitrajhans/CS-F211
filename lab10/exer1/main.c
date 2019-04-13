#include<stdio.h>
#include"tree.h"

int main() {

    Node tree;
    
    tree = newNode(6);
    tree = add(tree, 4, NULL); // NULL is the parent of tree's root
    tree = add(tree, 2, NULL);
    // Poor implementation, in no mood to change
    tree = add(tree, 5, NULL);

    printf("Root: %d, Root->left: %d, Root->right: %d\n", tree->val, tree->left->val, tree->right->val);
    printInorder(tree);    
    tree = deleteNode(tree, 4, NULL);
    printf("Root: %d, Root->left: %d, Root->right: %d\n", tree->val, tree->left->val, tree->right->val);
    printInorder(tree);

    return 0;
}