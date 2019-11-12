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

/* add item to the head of the list */
int AddItem(item **head, char *name, int q, float cost);

/* print list */
void PrintList(item *head);

/* delete list */
void FreeList(item **head);

/* compute total cost of the inventory */
float CalculateInventoryCost(item *head);

int main(int argc, char *argv[])
{
    item *inventory = NULL;
    float totalCost = 0.0f;

    PrintList(inventory);

    AddItem(&inventory, "part3", 10, 1.0f);
    AddItem(&inventory, "part1", 1, 2.50f);
    AddItem(&inventory, "part2", 5, 1.50f);
    PrintList(inventory);

    totalCost = CalculateInventoryCost(inventory);
    printf("Inventory cost %f\n\n", totalCost);

    FreeList(&inventory);
    PrintList(inventory);

    return 0;
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

int AddItem(item **head, char *name, int q, float cost)
{
    item *new_item;

    /* allocate new item */
    new_item = (item *)malloc(sizeof(item));
    if (new_item == NULL)
        return 0;

    /* copy data */
    strcpy(new_item->name, name);
    new_item->cost = cost;
    new_item->quantity = q;
    //new_item->nextItem = NULL;

    /* attach it n front of the head */
    new_item->nextItem = *head;
    *head = new_item;

    return 1;
}

/* compute inventory */
float CalculateInventoryCost(item *head)
{
    item *current_item = head;
    float totalCost = 0.0f;

    while (current_item != NULL)
    {
        totalCost += current_item->quantity * current_item->cost;
        current_item = current_item->nextItem;
    }

    return totalCost;
}
