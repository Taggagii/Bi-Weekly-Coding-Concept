#include "values.h"

/*
FUNDAMENTAL ISSUE / FUTURE FIX:
-this could be done without a linked list. simply do the sorting algorithm, and then graph each array by passing the renderer. Sure, it would be possibly unstable, and this method can be 
checked over for errors in an easier way. But, I suggest you make both versions
*/



void drawBarFromBottom(SDL_Renderer *renderer, int x, int width, int height, int color[])
{
	setColor(renderer, color);
	//randColor(renderer);
	SDL_Rect rect = { .x = (x) * width, .y = WINDOWHEIGHT, .w = width, .h = -height };
	SDL_RenderFillRect(renderer, &rect);
	//setColor(renderer, black);
	//SDL_RenderDrawRect(renderer, &rect);
}


void graphArray(SDL_Renderer* renderer, int values[], int color[])
{
	int blockWidth = (int)(WINDOWWIDTH / length);
	for (int i = 0; i < length; i++)
	{

		//setColor(renderer, color);
		drawBarFromBottom(renderer, i, blockWidth, values[i], color);
		//setColor(renderer, black);
		//SDL_RenderPresent(renderer);
		//SDL_Delay(7);
	}
}

void graphList(SDL_Renderer* renderer, Node* head, int listLength, int color[])
{
	while (head != NULL)
	{
		setColor(renderer, black);
		SDL_RenderClear(renderer);
		graphArray(renderer, head->values, color);
		SDL_RenderPresent(renderer);
		head = head->next;
		//SDL_Delay(0);
	}
}

void reverseList(Node** head)
{
	Node* previous = NULL, * current = *head, * next = NULL;
	while (current != NULL)
	{
		next = current->next;
		current->next = previous;
		previous = current;
		current = next;
	}
	*head = previous;
}

int lenList(Node* head)
{
	int counter = 0;
	while (head != NULL)
	{
		++counter;
		head = head->next;
	}
	return counter;
}

void randomizeArray(int values[])
{
	for (int i = 0; i < length * 3; i++)
	{
		int one = rand() % length, two;
		do two = rand() % length; while (two == one);
		swap(values, one, two);
	}
}


typedef struct partitionOutput_b
{
	int p;
	int comparisions;
} partitionOutput;

int partition(int values[], int low, int high, Node **head)
{
	int comparisionsCounter = 0;
	int pivot = values[high];
	int i = low;
	for (int j = low; j < high; j++)
	{
		comparisionsCounter++;
		if (values[j] < pivot)
		{
			swap(values, i, j);
			addNode(head, values);
			i++;
		}
	}
	swap(values, i, high);
	addNode(head, values);

	partitionOutput *output = (partitionOutput*)malloc(sizeof(partitionOutput));
	output->p = i;
	output->comparisions = comparisionsCounter;
	return output;
}


int quicksort(int values[], int low, int high, Node **head)
{
	int comparisionsCounter = 0;
	if (low < high)
	{
		partitionOutput *output = partition(values, low, high, head);
		comparisionsCounter += output->comparisions;
		comparisionsCounter += quicksort(values, low, output->p - 1, head);
		comparisionsCounter += quicksort(values, output->p + 1, high, head);
	}
	return comparisionsCounter;
}

int selectionSort(int values[], Node **head)
{
	int comparisionsCounter = 0;
	for (int i = 0; i < length; i++) //every value must be checked for, change the starting point everytime you sort one
	{
		int min = i;
		comparisionsCounter += length - (i + 1);
		for (int ii = i + 1; ii < length; ii++)
		{
			if (values[ii] < values[min])
				min = ii;
		}
		if (min != i)
		{
			swap(values, i, min);
			addNode(head, values);
		}
	}
	return comparisionsCounter;
}

enum sortingAlgorithmTypes { type_QuickSort = 0, type_SelectionSort };

typedef struct OutputValues_b
{
	Node* head;
	int comparisions;
	int swaps;
	int ticks;
} OutputValues;

OutputValues *graphSorting(SDL_Renderer *renderer, enum sortingAlgorithmTypes sortingType)
{
	OutputValues* output = (OutputValues*)malloc(sizeof(OutputValues));

	//Creating Random Array
	srand(randomSeed);

	int values[length];

	//the step size of the "staircase" created from a sorted array
	int step = (int)(WINDOWHEIGHT / length);

	//generating array so it'll end looking even and nice (like a staircase)
	for (int i = 0; i < length; i++)
		values[i] = (i + 1) * step;

	//randomizing array
	randomizeArray(values);

	clock_t starting, ending;

	//setting up output structure
	output->head = createNode(values);

	//preparing output list
	switch (sortingType)
	{
		case type_QuickSort:
			printf("Quicksort\n");
			starting = clock();
			output->comparisions = quicksort(values, 0, length - 1, &output->head);
			ending = clock();
			break;
		case type_SelectionSort:
			printf("SelectionSort\n");
			starting = clock();
			output->comparisions = selectionSort(values, &output->head);
			ending = clock();
			break;
		default:
			printf("Please enter a valid sorting algorithm name.\n");
			output->comparisions = 0;
			output->swaps = 0;
			return output;
	}

	//reversing list so video goes in right direction
	reverseList(&output->head);

	//setting up swap amount for output
	output->swaps = lenList(output->head);

	//getting the ticks of the sort
	output->ticks = ending - starting;

	//outputting general info about the sort
	printf("\tComparisions: %d\n\tSwaps: %d\n\tTicks: %d\n\n", output->comparisions, output->swaps);
	
	//graphing output list
	graphList(renderer, output->head, output->swaps, white);
	

	return output; //returning the output incase the user wants to use it
}


int main()
{

	
	//INITALIZING SDL: Creating a window and a renderer
	//init
	SDL_Init(SDL_INIT_VIDEO);

	//window
	SDL_Window* window = SDL_CreateWindow("A window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOWWIDTH, WINDOWHEIGHT, SDL_WINDOW_OPENGL);
	if (!window)
	{
		printf("Window creation failure: %s\n", SDL_GetError());
		return 1;
	}
	//renderer
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (!renderer)
	{
		SDL_DestroyWindow(window);
		printf("Renderer failed to initalize %s\n", SDL_GetError());
		return 1;
	}
	

	//tesitng
	graphSorting(renderer, type_SelectionSort);
	graphSorting(renderer, type_QuickSort);
	
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;



}