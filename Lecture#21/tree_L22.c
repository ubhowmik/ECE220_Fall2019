#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct nodeTag t_node;
struct nodeTag
{
    int data;
    t_node *left;
    t_node *right;
};

t_node* NewNode(int data);
void FreeTree(t_node *node);

void preorder(t_node *node);
void inorder(t_node *node);
void postorder(t_node *node);

void padding(char ch, int n);
void printTree(t_node *node, int level);

t_node* InsertNode(t_node *node, int data);
t_node* BSTSearch(t_node *node, int key);

t_node* FindMin(t_node *node);
t_node* FindMax(t_node *node);

int getHeight(t_node *node);

void FreeTree(t_node *node);

int main()
{
    t_node *root = NULL;
/*
    //construct a tree
    root = NewNode(1);
    root->left = NewNode(2);
    root->right= NewNode(3);
    root->left->left = NewNode(4);
    root->left->right= NewNode(5);
    root->right->left= NewNode(6);
    root->left->right->right= NewNode(7);
*/
    root = InsertNode(root, 8);
    root = InsertNode(root, 3);
    root = InsertNode(root, 10);
    root = InsertNode(root, 1);
    root = InsertNode(root, 6);
    root = InsertNode(root, 9);
    root = InsertNode(root, 7);
    root = InsertNode(root, 2);

    printTree(root, 0);

    printf("Preorder DFS\n");
    preorder(root);
    printf("\n\nInorder DFS\n");
    inorder(root);
    printf("\n\nPostorder DFS\n");
    postorder(root);

    printf("\n\n");
    if( BSTSearch(root, -1) ==NULL)
        printf(" Not found the key\n");

    t_node* temp;
    temp = FindMin(root);
    printf("\nmin value is %d\n", temp->data);
    temp = FindMax(root);
    printf("\nmax value is %d\n", temp->data);

    printf("\nHeight of tree is %d\n", getHeight(root));

    FreeTree(root);
}


t_node* InsertNode(t_node *node, int data)
{
    printf("Call InserNode-- node addree:%p, data:%d\n", node, data);
    //base case : Found a right place to insert the node.
    if(node ==NULL){
        node = NewNode(data);
        return node;
    }
    // recursive case: Traverse either to the left (new data is smaller) or the right (new data is larger) 
    else{
        if(data < node->data)
            node->left = InsertNode(node->left , data);
        else
            node->right = InsertNode(node->right , data);
        return node;
    }
}

t_node* BSTSearch(t_node *node, int key)
{
    // base case
    // 1. no match
    if(node == NULL) 
        return NULL;
    // 2. yes match
    if(node->data == key){
        printf("Found the key %d\n", key);
        return node;
    }
    // recursive case: otherwise, traverse either to the left or the right
    if(key < node->data)
        return BSTSearch(node->left, key);
    else 
        return BSTSearch(node->right, key);
}

void preorder(t_node *node)
{
    // Base case
    if(node ==NULL)
        return;
    // Recursive case
    else{
        printf("%d ", node->data);
        preorder(node->left);
        preorder(node->right);
    }
}
void inorder(t_node *node)
{
    // Base case
    if(node ==NULL)
        return;
    // Recursive case
    else{
        inorder(node->left);
        printf("%d ", node->data);
        inorder(node->right);
    }
}

void postorder(t_node *node)
{
    // Base case
    if(node ==NULL)
        return;
    // Recursive case
    else{
        postorder(node->left);
        postorder(node->right);
        printf("%d ", node->data);
    }
}
t_node* NewNode(int data)
{
    t_node *node = (t_node*) malloc(sizeof(t_node));
    if(node != NULL){
        node->data = data;
        node->left = NULL;
        node->right = NULL;
    }
    return node;
}

void padding(char ch, int n)
{
    int i;
    for(i=0;i<n;i++)
        putchar(ch);
}
void printTree(t_node *node, int level)
{
    if(node == NULL){
        padding('\t',level);
        printf("*\n");

    }
    else{
        printTree(node->right,level+1);
        padding('\t', level);
        printf("%d\n", node->data);
        printTree(node->left, level+1);
    }
}
t_node* FindMin(t_node *node)
{
    //base case
    if(node->left == NULL)
        return node;
    //recursive case
    else
        return FindMin(node->left);
}

t_node* FindMax(t_node *node)
{
    //base case
    if(node->right == NULL)
        return node;
    //recursive case
    else
        return FindMax(node->right);
}


int getHeight(t_node *node)
{
    int lh, rh;
    //base
    if(node == NULL)
        return -1;
    //recursive
    else{
        lh = getHeight(node->left);
        rh = getHeight(node->right);
        if(lh>rh)
            return lh + 1;
        else
            return rh + 1;
    }

}

void FreeTree(t_node *node)
{
    // Base case
    if(node ==NULL)
        return;
    // Recursive case
    else{
        FreeTree(node->left);
        FreeTree(node->right);
        printf("Free node of %d\n ", node->data);
        free(node);

    }
}







