#ifndef VALUESH
#define VALUESH

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL.h>



const int WINDOWWIDTH = 800;
const int WINDOWHEIGHT = 800;

int black[] = { 0, 0, 0, 255 };
int white[] = { 255, 255, 255, 255 };

#define length 800
#define randomSeed 5 //time(NULL)

//Linked list part
struct node_t
{
	int values[length];
	struct node_t* next;
};
typedef struct node_t Node;

Node* createNode(int values[])
{
	Node* tempNode = (Node*)malloc(sizeof(Node));
	for (int i = 0; i < length; i++)
	{
		tempNode->values[i] = values[i];
	}
	tempNode->next = NULL;
	return tempNode;
}

void addNode(Node** head, int values[])
{
	Node* tempNode = createNode(values);
	tempNode->next = *head;
	*head = tempNode;
}

void pushNode(Node* head, int values[])
{
	Node* tempHead = head;
	while (tempHead->next != NULL)
	{
		tempHead->next;
	}
	tempHead->next = createNode(values);
}

void printArray(int values[])
{
	for (int i = 0; i < length; i++)
	{
		printf("%d, ", values[i]);
	}
	printf("\n");
}

void printList(Node* head)
{
	while (head != NULL)
	{
		printf("Values : ");
		printArray(head->values);
		head = head->next;
	}
}




//Fundamental Swaping Function, used in most of the, to come, sorting algorithms
void swap(int values[], int indexOne, int indexTwo)
{
	if (indexOne == indexTwo) return;
	values[indexOne] ^= values[indexTwo];
	values[indexTwo] ^= values[indexOne];
	values[indexOne] ^= values[indexTwo];
}



//Color Functions
void setColor(SDL_Renderer *renderer, int color[])
{
	SDL_SetRenderDrawColor(renderer, color[0], color[1], color[2], color[3]);
}

void randColor(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, rand() % 256, rand() % 256, rand() % 256, 255);
}






#endif