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

int findKeyInChild(char * name, Node root) {
    if( root == NULL)
        return 0;

    Node temp = root->child;

    while(temp) {
        if( strcmp(temp->key, name) == 0) {
            return 1;
        }
        else {
            temp = temp->sibling;
        }
    }
    return 0;
}


void traverseTree(Node root) {
    if(root == NULL) {
        printf("Tree is empty\n");
        return;
    }

    Node temp = root;
    while(temp) {
        if( temp->key)
            printf("%s\n", temp->key);
        if(temp->child)
            traverseTree(temp->child);
        // printf("\n");
        temp = temp->sibling;
    }
}

Node newNode(char *key) {
    Node n = (Node) malloc( sizeof( struct node));
    n->child = NULL;
    n->sibling = NULL;
    n->key = (char*) malloc( sizeof(char)* strlen(key));
    strcpy(n->key, key);
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
            // printf("%d\n", i);
            i--;
            j++;
        }
        str[j] = '\0';
        i--;
        j=0;
        strrev(str);

        int check = findKeyInChild(str, temp);
        // printf("%s %s %d\n", str, domain, strlen(domain));

        if( check != 0) {
            // printf("%s %s not null\n", str, temp->key);
            temp = temp->child;
            while( temp) {
                if(strcmp(temp->key, str) == 0) {
                    break;
                }
                else
                    temp = temp->sibling;
            }
        }
        else {
            // printf("%s %s null\n", str, temp->key);
            newN = newNode(str);
            if( temp->child == NULL) {
                // printf("%s->child == NULL\n", temp->key);
                temp->child = newN;
                temp = newN;
                // printf("%s\n", temp->key);
                // continue;
            }
            else {
                temp = temp->child;
                while(temp->sibling) {
                    temp = temp->sibling;
                }

                temp->sibling = newN;
                temp = newN;
                // continue;
            }
        }

        if( i<0) {
            break;
        }
    }

    newN = newNode(ip);
    if(temp->child == NULL) {
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

void lookup(char * name, Node root) {

    int i, j=0;
    char str[50];
    i = strlen(name) - 1;
    Node temp = root;
    
    while(1) {

        while( (name[i] != '.') && i>=0) {
            str[j] = name[i];
            // printf("%d\n", i);
            i--;
            j++;
        }
        str[j] = '\0';
        i--;
        j=0;
        strrev(str);

        int check = findKeyInChild(str, temp);
        
        if( !check) {
            printf("%s does not exist\n", name);
            return;
        }
        
        else {
            temp = temp->child;

            while( temp) {
                if( !strcmp(temp->key, str)) {
                    break;
                }
                else {
                    temp = temp->sibling;
                }
            }
        }

        if( i<0) {
            break;
        }
    }

    printf("%s exists. IP: \n", name);
    traverseTree(temp->child);
}
