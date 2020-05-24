/*
 ============================================================================
 Name        : FunctionPointer.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void print(void)
{
	printf("\n print() is called");
}

void display(void)
{
	printf("\n display() is called");
}
void show(void)
{
	printf("\n show() is called");
}

int main(void)
{
	void (*fnptr)(void);

	printf("\n address of main = %u",main);
	printf("\n address of print = %u",print);
	printf("\n address of show = %u",show);
	printf("\n address of display = %u",display);

	print();	//original way of calling function
	fnptr=print;
	(*fnptr)();	//call to function via fnptr

	show();		//original way of calling function
	fnptr=show;
	(*fnptr)();	//call to function via fnptr

	display();	//original way of calling function
	fnptr=display;
	(*fnptr)();	//call to function via fnptr

	return EXIT_SUCCESS;
}


/* int x=847,y=20;
 * char ch='A'
 * int *ptr;
 * char *cptr;
 * ptr=&x;		*ptr;
 * ptr=&y;		*ptr
 *
 * cptr=&ch;
 * cptr=&x;
 * *cptr
 */








