#include "tree.h"

Node findkey(char * name, Node root) {
    if( root == NULL)
        return NULL;

    if(root->key == name) {
        return root;
    }

    findkey(name, root->child);
    findkey(name, root->sibling);
}

Node findKeyInChild(char * name, Node root) {
    if( root == NULL)
        return NULL;

    Node temp = root->child;

    while(temp) {
        if( temp->key = name) {
            return temp;
        }
        else {
            temp = temp->sibling;
        }
    }
    return NULL;
}


void traverseTree(Node root) {
    if(root == NULL)
        return;

    Node temp = root;

    while(temp) {
        printf("%s\n", temp->key);
        if(temp->child)
            traverseTree(temp->child);
        temp = temp->sibling;
    }
}

Node newNode(char *key) {
    Node n = (Node) malloc( sizeof( struct node));
    n->child = NULL;
    n->sibling = NULL;
    n->key = (char*) malloc( sizeof(char)* strlen(key));
    n->key = key;
    return n;
}



void insertDomain(char * domain, char * ip, Node root) {

    int i,j=0;

    Node temp = root, newN;

    char str[50];

    i = strlen(domain) - 1;

    while(1) {
        
        while( (domain[i] != '.') && i>=0) {
            str[j] = domain[i];
            i--;
            j++;
        }
        str[j] = '\0';
        i--;
        j=0;
        if( i<0) {
            break;
        }
        strrev(str);

        Node temp2 = findKeyInChild(str, temp);

        if( temp2 != NULL) {
            printf("%s %s not null\n", str, temp2->key);
            temp = temp2;
            continue;
        }
        else {
            printf("%s %s null\n", str, temp->key);
            newN = newNode(str);
            if( temp->child == NULL) {
                temp->child = newN;
            }
            else {
                temp = temp->child;
                while(temp->sibling) {
                    temp = temp->sibling;
                }

                temp->sibling = newN;
                temp = newN;
                continue;
            }
        }
    }

    newN = newNode(ip);
    if(temp == NULL) {
        temp->child = newN;
    }
    else {
        temp = temp->child;
        while(temp->sibling) {
            temp = temp->sibling;
        }

        temp->sibling = newN;
    }
}

char *strrev(char *str)
{
    char *p1, *p2;

    if (! str || ! *str)
        return str;
        for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
            {
                *p1 ^= *p2;
                *p2 ^= *p1;
                *p1 ^= *p2;
            }
      return str;
}
