/*
 ============================================================================
 Name        : Stack_Of_Integers.c
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
typedef struct
{

}BOOK;
typedef BOOK ELEMENT;
typedef int BOOL;

typedef enum {EXIT,PUSHELEMENT,POPELEMENT,PEEKELEMENT} MENUOPERATIONS;

typedef struct
{
	ELEMENT eles[SIZE];//stack of integers
	int top;//will retainindex of top most element
}STACK;

void init_stack(STACK *stack)
{
	stack->top=-1;
}

MENUOPERATIONS menu_choice()
{
	MENUOPERATIONS mchoice;
	printf("\n 0. Exit");
	printf("\n 1. Push Element on stack");
	printf("\n 2. Pop Element from stack");
	printf("\n 3. Peek Element from stack");
	scanf("%d",&mchoice);
	return mchoice;
}

void accept_element(ELEMENT *ele)
{
	printf("\n Specify element to push on stack");
	scanf("%d",ele);
}

void display_element(const ELEMENT *ele)
{
	printf("Element : %d",*ele);
}

BOOL is_full(const STACK *stack)
{
	return stack->top==SIZE-1 ? TRUE : FALSE;
}

void push_element(STACK  *stack,ELEMENT ele)
{
	//manage top area for new element
	stack->top++;
	//push element on stack
	stack->eles[stack->top]=ele;
}

BOOL is_empty(const STACK *stack)
{
	//1. empty initially top==-1
	//2. after performing operations on stack
	return stack->top==-1 ? TRUE :FALSE;
}
void pop_element(STACK *stack)
{
	//assume top most element is deleted
	stack->top--; //decide which will be next top element
}
ELEMENT peek_element(const STACK *stack)
{
	return stack->eles[stack->top];
}
int main(void) {
	STACK stack;
	ELEMENT ele;
	MENUOPERATIONS mchoice;
	init_stack(&stack);
	while((mchoice=menu_choice())!=EXIT)
	{
		switch(mchoice)
		{
			case PUSHELEMENT:	//add element on stack
						if(is_full(&stack))	//1 if stack is full
						{
							printf("\n Stack has reached to overflow state");//1.1 show error as stack is full
						}
						else //2. if stack is not full
						{
							accept_element(&ele);//2.1 accept element to be pushed
							push_element(&stack,ele);//2.2  push element on stack
						}
						break;
			case PEEKELEMENT:
						//peek element on stack
						if(is_empty(&stack))	//1 if stack is empty
						{
							printf("\n Stack has reached to underflow state");//1.1 show error as stack is full
						}
						else //2. if stack is not empty
						{
							ele = peek_element(&stack);	//retrieve element
							display_element(&ele);
						}
						break;
			case POPELEMENT:
						//pop element on stack
						if(is_empty(&stack))	//1 if stack is empty
						{
							printf("\n Stack has reached to underflow state");//1.1 show error as stack is full
						}
						else //2. if stack is not empty
						{
							ele = peek_element(&stack);	//retrieve element
							display_element(&ele);
							pop_element(&stack);
						}
						break;
		}
	}
	return EXIT_SUCCESS;
}

