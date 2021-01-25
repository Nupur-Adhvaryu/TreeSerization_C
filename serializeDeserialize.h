#ifndef SERIALIZEDESERIALIZE_H_INCLUDED
#define SERIALIZEDESERIALIZE_H_INCLUDED
// A C++ program to demonstrate serialization and de-serialization of
// Binary Tree
#include <stdio.h>
#include <string.h>
#define MARKER '@'

/* A binary tree Node has key, pointer to left and right children */
typedef struct node
{
    int key;
    struct node* left, *right;
}Node;

/* Helper function that allocates a new Node with the
   given key and NULL left and right pointers. */
Node* newNode(int key)
{
    Node* temp = malloc(sizeof(Node));
    temp->key = key;
    temp->left = temp->right = NULL;
    return (temp);
}

// This function stores a tree in a file pointed by fp
void serialize(Node *root, FILE *fp)
{
    // If current node is NULL, store marker
    if (root == NULL)
    {
        fprintf(fp, "%c ", MARKER);
        return;
    }

    // Else, store current node and recur for its children
    fprintf(fp, "%d ", root->key);
    serialize(root->left, fp);
    serialize(root->right, fp);
}

// This function constructs a tree from a file pointed by 'fp'
void deSerialize(Node *root, FILE *fp)
{
    // Read next item from file. If there are no more items or next
    // item is marker, then return
    int val;
    char str[120];
    if (!fscanf(fp, "%s", str) || strcmp(str, "@"))
       return;
    val = atoi(str);
    // Else create node with this item and recur for children
    root = newNode(val);
    deSerialize(root->left, fp);
    deSerialize(root->right, fp);
}

// A simple inorder traversal used for testing the constructed tree
void inorder(Node *root)
{
    if (root)
    {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}
#endif // SERIALIZEDESERIALIZE_H_INCLUDED

/* Sample code demonstrating the use of serialize function
FILE *fp = fopen("MyBSTtree.txt", "w");
    if (fp == NULL)
    {
        puts("Could not open file");
        return 0;
    }
    serialize(bst.root, fp);
    fclose(fp);
*/
