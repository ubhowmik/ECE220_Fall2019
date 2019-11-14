#include <stdio.h>
#include <stdlib.h>

typedef struct nodeTag
{
     int data;
     struct nodeTag *left;
     struct nodeTag *right;
} t_node;

t_node *NewNode(int data);
void FreeTree(t_node *node);
void preOrderTraversal(t_node *node);
void inOrderTraversal(t_node *node);
void PostOrderTraversal(t_node *node);

t_node *BSTinsert(t_node *node, int val);
t_node *BSTsearch(t_node *node, int val);


int main()
{
    t_node *tree = NULL;
    t_node * found;
    
    tree = BSTinsert(tree, 8);
    tree = BSTinsert(tree, 3);
    tree = BSTinsert(tree, 10);
    tree = BSTinsert(tree, 9);
    tree = BSTinsert(tree, 6);
	tree = BSTinsert(tree, 4);
	tree = BSTinsert(tree, 7);
	tree = BSTinsert(tree, 1);
    
    
    /* trav */
    printf("PreOrder: \n");
    preOrderTraversal(tree);

	printf("\n inOrder: \n");
    inOrderTraversal(tree);
	
	printf("\n PostOrder: \n");
    PostOrderTraversal(tree);

    found = BSTsearch(tree, 11);
    if (found) printf("\nfound\n"); else printf("\nnot found\n");
	
	 found = BSTsearch(tree, 7);
    if (found) printf("\nfound\n"); else printf("\nnot found\n");

    FreeTree(tree);
    return 0;
}


t_node *BSTsearch(t_node *node, int val)
{
    if (node == NULL) 
        return NULL;
    
    if (node->data == val)
        return node;
        
    if (val < node->data)
        return BSTsearch(node->left, val);
    else
        return BSTsearch(node->right, val);
}


t_node *BSTinsert(t_node *node, int val)
{
    if (node == NULL)
         return NewNode(val);
    
    if (val < node->data)
         node->left = BSTinsert(node->left, val);
    else
         node->right = BSTinsert(node->right, val);

    return node;
}

void preOrderTraversal(t_node *node)
{
    if (node != NULL)
    {
         printf("Node %d (address %p, left %p, right %p)\n",
                 node->data, node, node->left, node->right);
         preOrderTraversal(node->left);  
         preOrderTraversal(node->right); 
    }
}

void inOrderTraversal(t_node *node)
{
    if (node != NULL)
    {
         inOrderTraversal(node->left);  
         printf("Node %d (address %p, left %p, right %p)\n",
                 node->data, node, node->left, node->right);
         inOrderTraversal(node->right); 
    }
}

void PostOrderTraversal(t_node *node)
{
    if (node != NULL)
    {
         PostOrderTraversal(node->left);  
         PostOrderTraversal(node->right); 
		 printf("Node %d (address %p, left %p, right %p)\n",
                 node->data, node, node->left, node->right);
    }
}

t_node *NewNode(int data)
{
    t_node *node;
    
    node = (t_node *)malloc(sizeof(t_node));
    if (node == NULL) return NULL;
    
    node->data = data;
    node->left = node->right = NULL; 
    
    return node;
}


void FreeTree(t_node *node)
{
    if (node == NULL)
        return;
        
    FreeTree(node->left);
    FreeTree(node->right);
    free(node);
}
