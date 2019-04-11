#include "tree.h"

Node newNode(int val) {
    Node newN = (Node) malloc( sizeof( struct node));
    newN->left = NULL;
    newN->right = NULL;
    newN->val = val;
    return newN;
}

Node add(Node root, int val) {

    if(root == NULL) {
        return newNode(val);
    }

    if( val < root->val) {
        root->left = add(root->left, val);
    }
    else if( val >  root->val) {
        root->right = add(root->right, val);
    }

    return root;
}

Node find(Node root, int val) {
    if(root == NULL) {
        printf("Node with %d value not present\n", val);
        return root;
    }

    if( root->val == val) {
        printf("Node with value %d is present\n", val);
        return val;
    }

    if( val <  root->val)
        return find(root->left, val);

    return find(root->right, val);
}

Node deleteNode(Node root, int val) {
    if(root == NULL) {
        return NULL;
    }

    if( val < root->val) {
        root->left = deleteNode(root->left, val);
    }
    else if ( val > root->val) {
        root->right = deleteNode(root->right, val);
    }

    else {
        if( root->left == NULL) {
            Node temp = root->right;
            free(root);
            return temp;
        }
        else if( root->right == NULL) {
            Node temp = root->left;
            free(root);
            return temp;
        }
        Node temp = root->right;
        while(temp->left != NULL) {
            temp = temp->left;
        }
        root->val = temp->val;
        root->right = deleteNode(root->right, temp->val);
    }
    return root;
}


