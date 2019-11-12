#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/* each node contains a value and a next pointer */
typedef struct dll_node_t {
  int val;
  struct dll_node_t *next;
  struct dll_node_t *prev;
} dll_node;

/* to make tail and head insertion fast, keep head and tail pointers */
typedef struct dll_t {
  dll_node *head;
  dll_node *tail;
} dll;

/* to create an empty linked list, create a list with NULL head,tail */
dll *dll_create() {
  dll *list = malloc(sizeof(dll));
  list->head = list->tail = NULL;
  return list;
}

/* delete the first match in doubly linked list */
void dll_delete(dll *list, int v) {
  dll_node *walk = list->head;
  while (walk && walk->val != v)
    walk = walk->next;

  if (!walk) return;
  if (walk->prev) {
    walk->prev->next = walk->next; /* (*(*walk.prev)).next */
  } else {
    list->head = walk->next;
  }

  if (walk->next) {
    walk->next->prev = walk->prev;
  } else {
    list->tail = walk->prev;
  }
  
  free(walk);
}

/* compute the length of a list by traversing it */
unsigned int dll_length(const dll* list) {
  unsigned int count = 0;
  dll_node *elt;
  /* this for loop traverses the list */
  for (elt = list->head; elt; elt = elt->next) {
    printf("%d\n", elt->val); /* added this for debugging */
    if (elt->next) {
      assert(elt->next->prev == elt);
    } else {
      assert(list->tail == elt);
    }
    count++; /* increment the count for each node we see */
  }
  return count;
}

void dll_insert_head(dll *list, int val) {
  dll_node *tmp = malloc(sizeof(dll_node)); /* alloc space */
  
  /* when inserting into an empty list, set tail */
  if (!list->head) list->tail = tmp;

  /* set our value, our next pointer to the current head, update current head */
  tmp->val  = val;
  tmp->next = list->head;
  tmp->prev = NULL;
  if (list->head)
    list->head->prev = tmp;
  list->head  = tmp;
}

void dll_insert_tail(dll *list, int val) {
  dll_node *tmp = malloc(sizeof(dll_node));
  
  /* when inserting into an empty list, set head */
  if (!list->head) list->head = tmp;

  /* we're inserting a new last value so ->next is always NULL */
  tmp->prev = list->tail;
  tmp->next = NULL;
  tmp->val  = val;

  /* splice in tmp from the last element of the current list,
   * taking care to not crash if the list is empty
   */
  if (list->tail)
    list->tail->next = tmp;

  /* update the tail pointer */
  list->tail = tmp;
}  


int main() {
  dll *list = dll_create();
  dll_insert_tail(list, 5);
  printf("Len: %d\n", dll_length(list));
  dll_delete(list, 5);
  printf("Len: %d\n", dll_length(list));
  dll_insert_tail(list, 5);
  printf("Len: %d\n", dll_length(list));
  dll_insert_tail(list, 7);
  printf("Len: %d\n", dll_length(list));
  dll_insert_head(list, 3);
  printf("Len: %d\n", dll_length(list));
  dll_insert_tail(list, 10);
  printf("Len: %d\n", dll_length(list));
  dll_delete(list, 3);
  printf("Len: %d\n", dll_length(list));
  dll_insert_head(list, 3);
  printf("Len: %d\n", dll_length(list));
  dll_delete(list, 7);
  printf("Len: %d\n", dll_length(list));
  dll_delete(list, 10);
  printf("Len: %d\n", dll_length(list));
  dll_delete(list, 11);
  printf("Len: %d\n", dll_length(list));
}