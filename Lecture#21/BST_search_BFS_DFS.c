#include <stdio.h>
#include <stdlib.h>

typedef struct nodeTag
{
     int data;
     struct nodeTag *left;
     struct nodeTag *right;
} t_node;

typedef struct itemTag item;

struct itemTag
{
    t_node *data; 
    item *nextItem;  /* pointer to the next item in the list */
};


t_node *NewNode(int data);

t_node* dequeue(item **head);
void enqueue(item **head, t_node *data);

void FreeTree(t_node *node);
void preOrderTraversal(t_node *node);
void inOrderTraversal(t_node *node);
void PostOrderTraversal(t_node *node);

t_node *BSTinsert(t_node *node, int val);
t_node *BSTsearch(t_node *node, int val);

t_node *BFS(t_node *node, int val);
t_node* DFS(t_node *node, int data);


int main()
{
    t_node *tree = NULL;
    t_node * found;
    
    tree = BSTinsert(tree, 10);
    tree = BSTinsert(tree, -3);
    tree = BSTinsert(tree, 15);
    tree = BSTinsert(tree, 4);
    tree = BSTinsert(tree, 11);
    
    
    /* trav */
    printf("PreOprder: \n");
    preOrderTraversal(tree);
	
	printf("\n inOrder: \n");
    inOrderTraversal(tree);
	
	printf("\n PostOrder: \n");
    PostOrderTraversal(tree);



    found = BSTsearch(tree, 11);
    if (found) printf("\n found\n"); else printf("\n not found\n");

    found = BFS(tree, 10);
    if (found) printf("\n found\n"); else printf("\n not found\n");

	found = DFS(tree, -3);
    if (found) printf("\n found\n"); else printf("\n not found\n");

    FreeTree(tree);


    return 0;
}

//BST SERACH -DFS
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
// BFS Search
t_node* BFS(t_node *node, int data)
{
    item *queue = NULL;
    t_node *i;

    if (node != NULL)
    {
        enqueue(&queue, node);
    }

    while ((i = dequeue(&queue)) != NULL)
    {
        if (i->data == data) break; /* found it! */

        if (i->left != NULL) enqueue(&queue, i->left);
        if (i->right != NULL) enqueue(&queue, i->right);
    }

    /* free the queue */
    while (dequeue(&queue) != NULL); 

   return i;
} 

/* queue access subroutines */
t_node* dequeue(item **head)
{
    item *removed;
    t_node *data;

    if (*head == NULL) return NULL;

    /* get data */
    data = (*head)->data;

    /* remove node from list */
    removed = *head;
    *head = (*head)->nextItem;
    free(removed);

    return data;
}

void enqueue(item **head, t_node *data)
{
    item *newitem = NULL;

    if (*head == NULL)
    {
        newitem = (item *)malloc(sizeof(item));
        
        /* copy data */
        newitem->data = data;
        newitem->nextItem = *head;

        *head = newitem;

        return;
     }

     enqueue(&(*head)->nextItem, data);
}

//DFS Search

t_node* DFS(t_node *node, int data)
{
    t_node *i;

    if (node == NULL)
        return NULL;

    if (node->data == data) 
        return node;

    if ((i = DFS(node->left,data)) != NULL)
        return i;

    return DFS(node->right,data);
}
