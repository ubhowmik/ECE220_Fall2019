#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct nodeTag
{
    int data;
    struct nodeTag* left;
    struct nodeTag* right;
}t_node;

t_node* NewNode(int data);        /* allocate memory for a new node */
void FreeTree(t_node *node);     /* destroy entire tree */
void TraverseTree(t_node *node);  /* traverse and print tree */

int main()
{
    /* manually create a simple tree */
    t_node *tree = NULL;
    tree = NewNode(10);
    tree->left = NewNode(5);
    tree->right = NewNode(-2);
    tree->left->left = NewNode(23);

    TraverseTree(tree);
    FreeTree(tree);
}

t_node* NewNode(int data)
{
           t_node* node;

    if ((node = (t_node *)malloc(sizeof(t_node))) != NULL)
    {
        node->data = data;
        node->left = NULL;
        node->right = NULL;
    }

    return node;
}

void FreeTree(t_node *node)
{

    if (node != NULL)
    {
        FreeTree(node->left);
        FreeTree(node->right);
        free(node);
    }
}

void TraverseTree(t_node *node)
{

    if (node != NULL)
    {

        printf("Node %d (address %p, left %p, right %p)\n",
                node->data, node, node->left, node->right);

        TraverseTree(node->left);
        TraverseTree(node->right);
    }
}

