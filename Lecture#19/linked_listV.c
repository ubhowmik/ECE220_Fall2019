#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct person_node Person;

struct person_node
{
    char name[20];
    Person *next;
};

int AddPerson(Person **ourList, char name[]);
void RemovePerson(Person **ourList);
Person **FindPerson(Person **ourList, char name[]);
void PrintList(Person *ourList);

/* add to the linked list */
int AddPerson(Person **ourList, char name[])
{
    Person *newPerson = NULL;
    
    newPerson = (Person *)malloc(sizeof(Person));
    if (newPerson == NULL)
        return 0;
    
    strcpy(newPerson->name, name);
    newPerson->next = *ourList;
    
    *ourList = newPerson;
    
    return 1;
}

/* remove from the linked list */
void RemovePerson(Person **ourList)
{
    Person *removed = NULL;

    if (*ourList != NULL)
    {
        removed = *ourList;
        *ourList = (*ourList)->next;
        free(removed);
    }
}
/* iterative list traversal */
void PrintList(Person *ourList)
{
    printf("==============\n");
    while (ourList != NULL)
    {
        printf("node @ %p, name %s, next %p\n", 
                ourList, ourList->name, ourList->next);
        ourList = ourList->next;
    }
    printf("==============\n");    
}

/* another example of iterative list traversal */
Person **FindPerson(Person **ourList, char name[])
{
        
    while (*ourList != NULL)
    {
        if (strcmp((*ourList)->name, name) == 0)
            return ourList;
        ourList = &(*ourList)->next;
    }
    
    return NULL;
}

int main()
{
    Person *theList = NULL;
    Person **theOne = NULL;
    
    AddPerson(&theList, "Andrew");
    AddPerson(&theList, "Bill");
    AddPerson(&theList, "Conrad");
    AddPerson(&theList, "Dan");
    AddPerson(&theList, "Edward");
    AddPerson(&theList, "Frank");
    AddPerson(&theList, "George");
    
    PrintList(theList);
    
    theOne = FindPerson(&theList, "Conrad");
    RemovePerson(theOne);

    PrintList(theList);
    
    return 0;
}
