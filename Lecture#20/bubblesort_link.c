#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct itemTag item;

/* inventory item record */
struct itemTag
{
    char name[64];   /* item name */
    int quantity;    /* # of items in stock */
    float cost;      /* cost per item */
    item *nextItem;  /* pointer to the next item in the list */
};

/* print list */
void PrintList(item *head);

/* delete list */
void FreeList(item **head);

/* insert item in alphabetical order */
int InsertItem(item **head, char *name, int q, float cost);

/* linked list sort subroutine */
void BubbleSort(item **head);

/* help function used by BubbleSort */
void SwapTwoNodes(item **head);

int main(int argc, char *argv[])
{
    item *inventory = NULL;
    
    /* Insert/Sort example */
    InsertItem(&inventory, "paerC", 1, 1.0f);
    InsertItem(&inventory, "paerA", 1, 1.0f);
    InsertItem(&inventory, "paerD", 1, 1.0f);
    InsertItem(&inventory, "paerQ", 1, 1.0f);
    InsertItem(&inventory, "paerB", 1, 1.0f);
    PrintList(inventory);

    BubbleSort(&inventory);

    PrintList(inventory);

    /* using list for computation */

    FreeList(&inventory);

    return 0;
}
int InsertItem(item **head, char *name, int q, float cost)
{
    item *new_item;

    if ((*head == NULL) || (strcmp((*head)->name, name) > 0))
    {

        new_item = (item *)malloc(sizeof(item));
        if (new_item == NULL)
            return 0;

        /* copy data */
        strcpy(new_item->name, name);        /* found spot to insert */
    
        /* allocate new item */
        new_item->cost = cost;
        new_item->quantity = q;
        new_item->nextItem = NULL;

        /* attach it n front of the head */
        new_item->nextItem = *head;
        *head = new_item;

        return 1;
    }

    return InsertItem(&(*head)->nextItem, name, q, cost); 
}

void SwapTwoNodes(item **head)
{
    item *node1, *node2;
    item *new_head;

    node1 = *head;
    if (node1 == NULL)
        return;

    node2 = node1->nextItem;
    if (node2 == NULL)
        return;

    new_head = node2;
    node1->nextItem = node2->nextItem;
    node2->nextItem = node1;
    *head = new_head;
}

void BubbleSort(item **head)
{
    item **node1 = head;
    int swapped = 1;

    while (swapped) 
    {
        swapped = 0;
        for (node1 = head; (*node1)->nextItem != NULL; node1 = &(*node1)->nextItem)
        {
            if (strcmp((*node1)->name, (*node1)->nextItem->name) < 0)
            {
                /* swap nodes */
                SwapTwoNodes(node1);
                swapped = 1;
            }
        }
    }
}


/* print list (using non-recursive traversal) */
void PrintList(item *head)
{
    item *current_item = head;
    int ic = 0;

    printf("Printing linked list:\n");
    while (current_item != NULL)
    {
        printf("Item #%i @ %p: ", ic, current_item);
        printf("%s %d %f %p\n", current_item->name, current_item->quantity,
                current_item->cost, current_item->nextItem);
      
        current_item = current_item->nextItem; 
        ic++;
    }

    printf("\n");
}

/* delete list (using recursive traversal) */
void FreeList(item **head)
{
    item *removed = NULL;

    if (*head == NULL) /* nothing to delete */
        return;

    removed = *head;
    *head = (*head)->nextItem;
    free(removed);
   
    FreeList(head);
}