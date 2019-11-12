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

/* queue access subroutines */
item* dequeue(item **head);
int enqueue(item **head, char *name, int q, float cost);

int main(int argc, char *argv[])
{
    item *inventory = NULL;

    PrintList(inventory);

    /* queue */
    enqueue(&inventory, "part3", 10, 1.0f);
    enqueue(&inventory, "part2", 5, 1.0f);
    enqueue(&inventory, "part1", 5, 1.0f);
    PrintList(inventory);
    dequeue(&inventory);
    PrintList(inventory);

    FreeList(&inventory);

    return 0;
}
/* recursive enqueue */
int enqueue(item **head, char *name, int q, float cost)
{
    item *new_item;
	
    if (*head == NULL)
    {
		if ((new_item = (item *)malloc(sizeof(item))) == NULL)
			return 0;
		
		new_item->quantity = q;
		new_item->cost = cost;
		strcpy(new_item->name, name);
		new_item->nextItem = *head;
		*head = new_item;
		
		return 1;
    }
	
    return enqueue(&(*head)->nextItem, name, q, cost);
}

item* dequeue(item **head)
{
    item *removed;
	
    if (*head == NULL)
		return NULL;
	
	removed = *head;
	*head = (*head)->nextItem;
	
	return removed;
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