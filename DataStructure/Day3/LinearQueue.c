/*
 ============================================================================
 Name        : LinearQueue_Of_Integers.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define TRUE  1
#define FALSE 0
#define SIZE 5

typedef int ELEMENT;
typedef int BOOL;

typedef enum {EXIT,JOINLEMENT,DELELEMENT,TRAVERSE} MENUOPERATIONS;

typedef struct
{
	ELEMENT eles[SIZE];//queue of integers
	int rear,front;//will retain index of rear and front element
}QUEUE;

void init_queue(QUEUE *queue)
{
	int i;
	for(i=0;i<SIZE;i++)
	{
		queue->eles[i]=-1;
	}
	queue->rear=-1;
	queue->front=-1;
}

MENUOPERATIONS menu_choice()
{
	MENUOPERATIONS mchoice;
	printf("\n 0. Exit");
	printf("\n 1. Add Element on queue");
	printf("\n 2. Delete Element from queue");
	printf("\n 3. Traverse queue");
	scanf("%d",&mchoice);
	return mchoice;
}

void accept_element(ELEMENT *ele)
{
	printf("\n Specify element to push on queue");
	scanf("%d",ele);
}

void display_element(const ELEMENT *ele)
{
	printf("Element : %d",*ele);
}

BOOL is_full(const QUEUE *queue)
{
	return queue->rear==SIZE-1 ? TRUE : FALSE;
}

void join_element(QUEUE  *queue,ELEMENT ele)
{
	//manage rear area for new element
	queue->rear++;
	//add element in queue
	queue->eles[queue->rear]=ele;
	if(queue->front==-1)//if very first element is added set as front
		queue->front=0;
}

BOOL is_empty(const QUEUE *queue)
{
	//1. empty initially rear==-1
	//2. after performing operations on //queue queue->front > queue->rear
	return queue->rear==-1 || queue->front > queue->rear ? TRUE :FALSE;
}
void leave_element(QUEUE *queue)
{
	queue->eles[queue->front]=-1;//assume front most element is deleted
	queue->front++; //decide which will be next front element

	/*line no. 85 replacement
	 *   if(queue->front == queue->rear)
	 *     {
	 *         queue->rear=-1;
	 *         queue->front=-1
	 *     }//only element was exist got deleted
	 *   else
	 *      queue->front++;
	 */
}
ELEMENT peek_element(const QUEUE *queue)
{
	return queue->eles[queue->front];
}

void traverse_queue(const QUEUE *queue)
{
	int i;
	for(i=0;i<SIZE;i++)
	{
		printf("%4d",queue->eles[i]);
	}
	printf("\t rear=%d front=%d",queue->rear,queue->front);
}
int main(void) {
	QUEUE queue;
	ELEMENT ele;
	MENUOPERATIONS mchoice;
	init_queue(&queue);

	while((mchoice=menu_choice())!=EXIT)
	{
		switch(mchoice)
		{
			case JOINLEMENT:	//add element on queue
						if(is_full(&queue))	//1 if queue is full
						{
							printf("\n Queue has reached to overflow state");//1.1 show error as queue is full
						}
						else //2. if queue is not full
						{
							accept_element(&ele);//2.1 accept element to be pushed
							join_element(&queue,ele);//2.2  push element on queue
						}
						break;
			case DELELEMENT:
						//pop element on queue
						if(is_empty(&queue))	//1 if queue is empty
						{
							printf("\n Queue has reached to underflow state");//1.1 show error as queue is full
						}
						else //2. if queue is not empty
						{
							ele = peek_element(&queue);	//retrieve element
							display_element(&ele);
							leave_element(&queue);
						}
						break;
			case TRAVERSE:
						traverse_queue(&queue);
						break;
		}
	}
	return EXIT_SUCCESS;
}

