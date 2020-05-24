/*
 ============================================================================
 Name        : LinkedList.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

typedef enum {EXIT,ADDFIRST,ADDLAST,ADDATPOS,DELFIRST,DELLAST,DELFROMPOS,TRAVERSE}MENUOPERATIONS;
typedef struct node
{
	int data;
	struct node *next;
}NODE;

NODE *head=NULL; //head is a pointer which always maintains address of first node


MENUOPERATIONS menu_choice()
{
	MENUOPERATIONS mchoice;
	printf("\n 0. Exit");
	printf("\n 1. Add Element at First");
	printf("\n 2. Add Element at Last");
	printf("\n 3. Add Element at given position");
	printf("\n 4. Delete Element from First");
	printf("\n 5. Delete Element from Last");
	printf("\n 6. Delete Element from given  position");
	printf("\n 7. Traverse List");
	scanf("%d",&mchoice);
	return mchoice;
}

NODE * create_node()
{
	NODE *temp;
	temp=(NODE *)malloc(sizeof(NODE));
	temp->next=NULL;
	return temp;
}//request memory for node at runtime

void add_element_at_first(int data)
{
	NODE *newnode;
	//1. request memory at runtime
	newnode = create_node();
	//2. assign data into runtime memory
	newnode->data=data;
	//3. attach new node in collection
	if(head ==NULL)//3.1 list is empty
	{
		head=newnode;
	}
	else //3.2 list is ready
	{
		newnode->next=head;
		head=newnode;
	}
}

void traverse_list_in_forward()
{
	NODE *trav;
	trav=head;
	if(head==NULL)
	{
		printf("\n list is empty");
		return ;
	}

	while(trav!=NULL)
	{
		printf("%d-->",trav->data);
		trav=trav->next;
	}
}
void accept_data(int *data)
{
	printf("\n Specify data for new node");
	scanf("%d",data);
}
void traverse_list_in_backward(NODE *trav)
{
	if(trav==NULL)
		return;
	traverse_list_in_backward(trav->next);
	printf("%d-->",trav->data);
}
int main(void) {
	MENUOPERATIONS mchoice;
	int data;
	while((mchoice = menu_choice())!=EXIT)
	{
		switch(mchoice)
		{
			case ADDFIRST:
						accept_data(&data);
						add_element_at_first(data);
						break;
			case TRAVERSE:
						printf("\n Traverse in forward direction \n");
						traverse_list_in_forward();
						printf("\n Traverse in Backward direction \n");
						traverse_list_in_backward(head);
						break;
		}
	}
	return EXIT_SUCCESS;
}





