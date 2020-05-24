#include<stdio.h>
#include<stdlib.h>

typedef struct stack{
	int x;
	struct stack *next;
}stack_t;

#define SIZE 5

stack_t *head=NULL;

stack_t *new_node(int);
int count(void);
void push_data(int);
void pop_data(void);
void display_stack();
int main()
{
	int x,n;
	while(1){
	printf("\n1.push data\n2.retrive data\nchoose option:");
	scanf("%d",&n);

	switch(n)
	{
		case 1: printf("enter data:");
			scanf("%d",&x);
			push_data(x);
			display_stack();
			break;

		case 2: pop_data();
			display_stack();
			break;
	}
	}
}

stack_t *new_node(int x)
{
	stack_t *temp;
	temp = (stack_t *)malloc(sizeof(stack_t));
	temp->x=x;
	temp->next=NULL;

	return temp;
}

int count()
{
	stack_t *trav=head;
	int cnt=0;
	while(trav!=NULL)
	{
		cnt++;
		trav=trav->next;
	}
	return cnt;
}

void push_data(int x)
{
	
	stack_t *temp;
	temp= new_node(x);

	if(head==NULL)
		 {
			 head=temp;
			 return;
		 }
	else if( SIZE == (count()) )
	{
		printf("\nstack is full\n");
		return;
	}
	else 
	{ 
		stack_t *trav=head;
		while(trav->next != NULL)
			trav=trav->next;
		trav->next=temp;
		return;
	}
}
void pop_data(void)
{
	stack_t *temp;
	stack_t *trav=head;

	if(head == NULL)
	{
		printf("\nstack is empty\n");
		return;
	}
	else if(head->next == NULL)
	{
		temp=head;
		head=NULL;
		free(temp);
		printf("\nnow stack is empty\n");
		return;
	}
	else
	{
		while(trav->next->next != NULL)
			trav=trav->next;
		temp=trav->next;
		trav->next=NULL;
		free(temp);
		return;
	}
}

void display_stack()
{
	int n = count();
	stack_t *trav=head;
	if(head != NULL)
	{
		printf("\nstack is:\n");
		while(n!=0)
		{
			printf("%d\n",trav->x);
			trav=trav->next;
			--n;
		}
		printf("\n");
	}
	else
		return;
}
