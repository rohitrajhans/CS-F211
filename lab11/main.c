#include "driver.h"
#include "tree.h"
#include<stdio.h>

int main() {
    Node root = (Node) malloc(sizeof(struct node));
    root->key = NULL;

    populateData("input.txt", root);
    traverseTree(root);
    return 0;
}