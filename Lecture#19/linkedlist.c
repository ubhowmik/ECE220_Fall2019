#include <stdio.h>
#include <stdlib.h>

typedef struct studentStruct Record;
struct studentStruct
{
	char Name[100];
	int UIN;
	float GPA;
	Record *next;
};

Record *find_node(Record *head, int UIN)
{
	Record *current = head;

	//keep traversing the list while 1)not at the end of the list AND 
	//				 2)current record's UIN < UIN we are looking for
	while((current != NULL) && (current->UIN <= UIN))
	{
		if(current->UIN == UIN)
		{
			printf("Student Found, UIN: %d.\n", current->UIN);
			return current;
		}
		current = current->next; //go to the next node
	}
	printf("Student Not Found.\n");
	return NULL;
}


void add_node(Record **list, int new_UIN)
{
	Record *current = *list;
	Record *prev = *list;
	Record *temp = (Record *)malloc(sizeof(Record)); //allocate memory for the new node
	temp->UIN = new_UIN; //initialize UIN for the new node

	//keep traversing the list until we reach the end
	while(current != NULL)
	{
		//the first instance when new_UIN is smaller than current record's UIN
		//we want to insert new node in front of the current node
		if(new_UIN < current->UIN) 
		{
			temp->next = current;
			if(current == *list) //if the current node is the head, update head pointer
			  {	*list = temp;}
			else //for everything else, update previous node's next pointer
			  {prev->next = temp;}
			return; //exit function
		}

		//we've reached the last note and its UIN is still smaller than new node's UIN
		//new node will have to be inserted at the tail
		if(current->next == NULL) 
		{
			current->next = temp;
			temp->next = NULL;
		}

		prev = current;
		current = current ->next;
	}

}


void remove_node(Record **list, int old_UIN)
{
	Record *prev;
	Record *current = *list;

	while(current != NULL) //find the record with matching UIN
	{
		if(current->UIN == old_UIN)
			break;
		prev = current;
		current = current->next;
	}

	if(current == NULL) //if record is not found, return out
		return;
	
	if(current == *list) //if record is the first node, update head pointer
	{
		*list = current->next;
	}
	else //record found is in the middle of the list
	{
		prev->next = current->next;
	}

	free(current);
}




int main()
{
	Record *head = (Record *)malloc(sizeof(Record));

	head->UIN = 12345;

	int i;
	Record *current = head;
	
	for(i=1;i<5;i++)
	{
		current->next = (Record *)malloc(sizeof(Record));
		current->next->UIN = i*2+12345;
		current = current->next;
	}
	current->next = NULL;

	current = head;
	for(i=0;i<5;i++)
	{
		printf("Node %d: UIN: %d\n", i, current->UIN);
		current = current->next;
	}

	find_node(head, 12349);

	int new_UIN = 12350;
	add_node(&head, new_UIN);
 	printf("Insert record with UIN: %d.\n", new_UIN);
        current = head;
        for(i=0;i<6;i++)
        {
                printf("Node %d: UIN: %d\n", i, current->UIN);
                current = current->next;
        }

	int old_UIN = 12350;
	remove_node(&head, old_UIN);
	printf("Delete record with UIN: %d.\n", old_UIN);
	current = head;
	for(i=0;i<6 && (current != NULL);i++)
        {
                printf("Node %d: UIN: %d\n", i, current->UIN);
                current = current->next;
        }

	return 0;
}
