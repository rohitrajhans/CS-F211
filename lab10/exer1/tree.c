#include "tree.h"

Node newNode(int val) {
    Node newN = (Node) malloc( sizeof( struct node));
    newN->left = NULL;
    newN->right = NULL;
    newN->val = val;
    newN->hb = 0;
    return newN;
}

int findHeight(Node z) {
    
    if( z == NULL) {
        return -1;
    }
    else {
        return 1 + max( findHeight(z->left), findHeight(z->right));
    }

}

Node add(Node root, int val, Node p) {

    if(root == NULL) {
        return newNode(val);
    }

    Node parent = p;

    if( val < root->val) {
        root->left = add(root->left, val, root);
    }
    else if( val >  root->val) {
        root->right = add(root->right, val, root);
    }

    root->hb = findHeight(root->left) - findHeight(root->right);
    if( root->hb > 1 && val < root->left) {
        root = rotate( root, root->left->left, root->left, root, parent);
    }
    else if( root->hb > 1 && val > root->left) {
        root = rotate(root, root->left->right, root->left, root, parent);
    }
    else if( root->hb < -1  && val < root->right) {
        root = rotate(root, root->right->left, root->right, root, parent);
    }
    else if( root->hb < -1 && val > root->right) {
        root = rotate(root, root->right->right, root->right, root, parent);
    }

    return root;
}

Node find(Node root, int val) {
    if(root == NULL) {
        printf("Node with %d value not present\n", val);
        return NULL;
    }

    if( root->val == val) {
        printf("Node with value %d is present\n", val);
        return root;
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
        else {
            Node temp = root->right;
            while(temp->left != NULL) {
                temp = temp->left;
            }
            root->val = temp->val;
            root->right = deleteNode(root->right, temp->val);
        }
    }
    return root;
}

Node rotate(Node root, Node x, Node y, Node z, Node parent) {
    Node t0, t1, t2, t3, a, b, c;
    // x, y, z ordered as a, b, c
    // t0, t1, t2, t3 are children of x, y, z in left-to-right order

    if( !((z->left == y) || (z->right == y)) || !((y->left == x) || (y->right == x)))
        return root;

    if( z->left == y) {
        c = z;
        t3 = z->right;
        if( y->left == x) {
            t0 = x->left;
            t1 = x->right;
            t2 = y->right;
            b = y; // as b replaces z (c)
            a = x; // a becomes right child of c i.e. x becomes right child of z
        }
        else if (y->right == x ) {
            t0 = y->left;
            t1 = x->left;
            t2 = x->right;
            a = y;
            b = x; // x comes at top in this case   
        }
    }
    else if( z->right == y) {
        a = z;
        t0 = z->left;
        if( y->right == x) {
            t1 = y->left;
            t2 = x->left;
            t3 = x->right;
            b = y;
            c = x;
        }
        else if( y->left == x) {
            t1 = x->left;
            t2 = x->right;
            t3 = y->right;
            b = x;
            c = y;
        }
    }

    if( root == z || parent == NULL) {
        // if z is root, make b as new root
        root = b;
    }
    else {
        // if parent of z exists, change child of parent to b
        if( parent->left == z)
            parent->left = b;
        else
            parent->right = b;
    }

    a->left = t0;
    a->right = t1;
    c->left = t2;
    c->right = t3;
    b->left = a;
    b->right = c;

    int h0 = findHeight(t0);
    int h1 = findHeight(t1);
    int h2 = findHeight(t2);
    int h3 = findHeight(t3);

    a->hb = h0 - h1;
    c->hb = h2 - h3;
    b->hb = max(h0, h1) - max(h2, h3);

    return root;
}

int max(int a, int b) {
    if( a<b)
        return b;
    else
        return a;
}