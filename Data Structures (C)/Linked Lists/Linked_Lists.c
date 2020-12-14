#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
Linked List:
- Empty list has size 0
- Insert element into any point
- Remove any element from the lsit
- Count elements in list
- Read / Modify element at a position
- Specify data-type
*/
  
struct node_t
{
    int value;
    struct node_t *next;
};
typedef struct node_t node;

void pushHead(node **head, int number)
{
    node *tempHead = (node*) malloc(sizeof(node));
    tempHead->value = number;
    tempHead->next = *head;
    *head = tempHead;
}

void pushTail(node **head, int number)
{
    if (*head != NULL)
    {
        node *tempHead = *head;
        while (tempHead->next != NULL)
            tempHead = tempHead->next;
        tempHead->next = (node*) malloc(sizeof(node));
        tempHead = tempHead->next;
        tempHead->value = number;
        tempHead->next = NULL;
    }
    else
    {
        pushHead(head, number);
    }
}

void insert(node **head, int index, int number)
{

    if (index > 0 && *head != NULL)
    {
        if ((*head)->next != NULL)
        {
            int counter = 0;
            node *tempHead = *head;
            --index;
            while (counter < index && tempHead->next->next != NULL)
            {
                tempHead = tempHead->next;
                ++counter;
            }
            node *tempValue = (node*) malloc(sizeof(node));
            tempValue->value = number;
            tempValue->next = tempHead->next;
            tempHead->next = tempValue;
        }
        else
        {
            pushTail(head, number);
        }
    }
    else
    {
        pushHead(head, number);
    }
}

void reverseList(node **head)
{
    if (*head != NULL)
    {
        node *previous = NULL, *current = *head, *next;
        while (current != NULL)
        {
            next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }
        *head = previous;
    }
}



void printList(node *head)
{
    if (head != NULL && head->next != NULL)
    {
        node *tempHead = head;
        printf("[");
        while (1)
        {
            printf("%d", tempHead->value);
            tempHead = tempHead->next;
            if (tempHead == NULL)
                break;
            printf(", ");
        }
        printf("]\n");
    } 
    else if (head == NULL)
    {
        printf("[]\n");
    }
    else
    {
        printf("[%d]\n", head->value);
    }
}

void recursionprintinglist(node *head)
{
    printf("%d", head->value);
    if (head->next == NULL)
        return;
    printf(", ");
    recursionprintinglist(head->next);
}

void recusionPrintingListBackwards(node *head, int first)
{
    if (head == NULL)
        return;
    recusionPrintingListBackwards(head->next, 0);
    printf("%d", head->value);
    if (!first)
        printf(", ");
}

void recursionPrintingList(node *head, int backwards)
{
    printf("[");
    if (head != NULL)
    {
        if (backwards)
            recusionPrintingListBackwards(head, 1);
        else
            recursionprintinglist(head);
    }
    printf("]\n");
}


void recursiveReverseList(node **head, node *current)
{
    if (current->next == NULL)
    {
        *head = current;
        return;
    }
    recursiveReverseList(head, current->next);
    node *tempNode = current->next;
    tempNode->next = current;
    current->next = NULL;
}



int main()
{
    node *head = NULL;
    for (int i = 0; i < 100000; i++)
        insert(&head, 4, i);
    
    time_t start = clock();
    recursiveReverseList(&head, head);
    //reverseList(&head);
    time_t end = clock();
    printf("time : %f\n", (double)(end - start)/CLOCKS_PER_SEC);
    return 0;
}


