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
void add_element_at_last(int data)
{
	NODE *newnode,*trav=NULL;
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
		trav=head;
		while(trav->next!=NULL)
		{
			trav=trav->next;
		}//traverse till last node
		trav->next=newnode;
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
int countnodes()
{
	NODE *trav=head;
	int cnt=0;
	while(trav!=NULL)
	{
		cnt++;
		trav=trav->next;
	}
	return cnt;
}

void add_element_at_given_pos(int data,int pos)
{
	NODE *newnode,*trav;
	int p=1;
	if(pos==1)
		add_element_at_first(data);
	else if(pos==(countnodes()+1))
		add_element_at_last(data);
	else
	{
		newnode = create_node();
		newnode->data=data;
		trav=head;
		while(p < pos-1)
		{
			trav=trav->next;
			p++;
		}//traverse till node next to which nn to be attached
		newnode->next=trav->next;
		trav->next=newnode;
	}
}
void del_element_from_first()
{
	NODE *temp;
	temp=head;
	head=head->next;
	free(temp);
	temp=NULL;
}
void free_list()
{
	while(head!=NULL)
	{
		del_element_from_first();
	}
}

void del_element_from_last()
{
	NODE *trav=head,*prev=NULL;
	if(head!=NULL)
	{
		while(trav->next!=NULL)
		{
			prev=trav;
			trav=trav->next;
		}
		if(prev==NULL)
			head=NULL;
		else
			prev->next=NULL;	//present second last node next to be set as NULL when we have multiple nodes


		free(trav);
		trav=NULL;
	}
}
void del_element_from_given_pos(int pos)
{
	int p=1;
	NODE *trav=NULL,*temp=NULL;
	if(pos==1)
		del_element_from_first();
	else if(pos==countnodes())
		del_element_from_last();
	else
	{
		p=1;
		trav=head;
		while(p < pos-1)
		{
			trav=trav->next;
			p++;
		}//traverse till the node next to which node is to be deleted
		temp= trav->next; //take a copy of adrress of a node to be deleted
		trav->next = temp->next;
		free(temp);
		temp=NULL;
	}
}
void reverse_list()
{
	NODE *curr=head,*left=NULL,right=NULL;
	while(curr!=NULL)
	{
		right=curr->next;
		curr->next=left;
		left=curr;
		curr=right;
	}
}
int main(void) {
	MENUOPERATIONS mchoice;
	int data,pos;
	while((mchoice = menu_choice())!=EXIT)
	{
		switch(mchoice)
		{
			case ADDFIRST:
						accept_data(&data);
						add_element_at_first(data);
						break;
			case ADDLAST:
						accept_data(&data);
						add_element_at_last(data);
						break;
			case ADDATPOS:
						printf("\n Specify position for newnode");
						scanf("%d",&pos);
						if(pos<=0 || pos > (countnodes()+1))
							printf("\n Invalid position");
						else
						{
							accept_data(&data);
							add_element_at_given_pos(data,pos);
						}
						break;
			case DELFIRST:
						del_element_from_first();
						break;
			case DELLAST:
						del_element_from_last();
						break;
			case DELFROMPOS:
						printf("\n Specify position for newnode");
						scanf("%d",&pos);
						if(pos<=0 || pos > countnodes())
							printf("\n Invalid position");
						else
						{
							del_element_from_given_pos(pos);
						}
						break;
			case TRAVERSE:
						printf("\n Traverse in forward direction \n");
						traverse_list_in_forward();
						printf("\n Traverse in Backward direction \n");
						traverse_list_in_backward(head);
						break;
		}
	}
	free_list();
	return EXIT_SUCCESS;
}





