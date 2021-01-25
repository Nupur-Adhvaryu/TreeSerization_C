#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "serializeDeserialize.h"

/* Driver program to test serialize/deserialize functions*/
/*                      20
*                     /    \
                     8      22
                   /  \
                  4   12
                     /  \
                    10  14
*/
int main()
{
    // Let us construct a tree shown in the above figure
    Node *root        = newNode(20);
    root->left = newNode(8);
    root->right              = newNode(22);
    root->left->left         = newNode(4);
    root->left->right        = newNode(12);
    root->left->right->left  = newNode(10);
    root->left->right->right = newNode(14);

    // Let us open a file and serialize the tree into the file
    FILE *fp = fopen("tree.txt", "w");
    if (fp == NULL)
    {
        puts("Could not open file");
        return 0;
    }
    serialize(root, fp);
    fclose(fp);

    // Let us deserialize the stored tree into root1
    Node *root1 = NULL;
    fp = fopen("tree.txt", "r");
    deSerialize(root1, fp);

    printf("Inorder Traversal of the tree constructed from file:\n");
    inorder(root1);

    return 0;
}
