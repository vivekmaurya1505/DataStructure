#include<stdio.h>
#include<stdlib.h>

typedef struct stack{
	int x;
	struct stack *next;
}queue_t;

#define SIZE 5

queue_t *head=NULL;

queue_t *new_node(int);

void add_data(int);
int retrive_data(void);
void display_queue();

int count=0;

int main()
{
	int x,n,a;
	while(1){
	printf("\n1.add data\n2.retrive data\nchoose option:");
	scanf("%d",&n);

	switch(n)
	{
		case 1: printf("enter data:");
			scanf("%d",&x);
			add_data(x);
			printf("\n");
			display_queue();
			break;

		case 2: a=retrive_data();
			printf("\n");
			display_queue();
			break;
	}
	}
}

queue_t *new_node(int x)
{
	queue_t *temp;
	temp = (queue_t *)malloc(sizeof(queue_t));
	temp->x=x;
	temp->next=NULL;

	return temp;
}

void add_data(int x)
{
	queue_t *temp;
	temp= new_node(x);

	if(head==NULL)
		 {
			 head=temp;
			 count++;
			 return;
		 }
	else if( SIZE == count)
	{
		printf("\nqueue is full\n");
		return;
	}
	else 
	{ 
		queue_t *trav=head;
		while(trav->next != NULL)
			trav=trav->next;
		trav->next=temp;
		count++;
		return;
	}
}
int retrive_data(void)
{
	queue_t *temp;
	queue_t *trav=head;

	if(head == NULL)
	{
		printf("\nqueue is empty\n");
		return 0;
	}
	else if(head->next == NULL)
	{
		temp=head;
		head=NULL;
		free(temp);
		count=0;
		printf("\nnow queue is empty\n");
		return temp->x;
	}
	else
	{
		temp=head;
		head=head->next;
		free(temp);
		return temp->x;
	}
}

void display_queue()
{
//	int n = count();
	queue_t *trav=head;
	if(head != NULL)
	{
		printf("\nqueue is:\n");
		while(trav != NULL)
		{
			printf("%d ",trav->x);
			trav=trav->next;
		}
		printf("\n");
	}
	else
		return;
}
