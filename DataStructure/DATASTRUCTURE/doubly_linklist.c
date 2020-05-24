#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	struct node *prv;
	int x;
	struct node *next;
}node_t;

node_t *head=NULL;

node_t *new(int);
void add_1st_post(int);
void add_specific_post(int,int);
void add_last_post(int);
			
void del_1st_post(void);
void del_specific_post(int);
void del_last_post();

int count();
void display();
void rev_display();

int main()
{
	int x,n,pos;
	
	while(1){
	printf("\n1.add at 1st pos\n2.add at specific pos\n3.add at last position\n4.delete at 1st pos\n5.delete at specific position\n6.delete at last post\n7.reverse display\nselect option:");
	scanf("%d",&n);

	switch(n)
	{
		case 1:printf("enter data:");
		       scanf("%d",&x);
		       add_1st_post(x);
		       display();
		       break;
		
		case 2:printf("enter data and position:");
		       scanf("%d%d",&x,&pos);
		       add_specific_post(x,pos);
		       display();
		       break;

		case 3:printf("enter data:");
		       scanf("%d",&x);
		       add_last_post(x);
		       display();
		       break;
		
		case 4:del_1st_post();
		       display();
		       break;
		
		case 5:printf("enter position:");
		       scanf("%d",&pos);
		       del_specific_post(pos);
		       display();
		       break;
		
		case 6:del_last_post();
		       display();
		       break;
		
		case 7:rev_display();
		       break;

	}
}
}

int count()
{
	int count = 0;
	node_t *trav = head;
	while(trav != NULL)
	{
		count++;
		trav = trav->next;
	}
	return count;
}

void del_1st_post()
{
	node_t *temp=head;
	head=head->next;
	head->prv=NULL;
	free(temp);
}

void del_specific_post(int pos)
{
	int n=0;
	if(pos == 1)
		del_1st_post();
	else if(pos == count())
		del_last_post();
	else
	{
		node_t *trav=head;
		while(n < (pos-2))
		{
			n++;
			trav=trav->next;
		}
		node_t *temp=trav->next;
		temp->next->prv=trav;
		trav->next=trav->next->next;
		free(temp);
	}
}

void del_last_post()
{
	node_t *trav=head;
	node_t *temp;
	while(trav->next->next != NULL)
	{
		trav=trav->next;
	}
	temp=trav->next;
	trav->next=NULL;
	free(temp);
}

void rev_display()
{
	node_t *trav = head;
	while(trav->next != NULL)
	{
		trav=trav->next;
	}
	printf("\nNULL ->");
	while(trav != NULL)
	{
		printf("%d ->",trav->x);
		trav=trav->prv;
	}
	printf("head");
}


void display()
{
	node_t *trav;
	trav=head;
	printf("\nhead ->");
	while(trav != NULL)
	{
		printf("%d ->",trav->x);
		trav=trav->next;
	}
	printf("NULL\n");
}

node_t *new(int x)
{
	node_t *temp;
	temp=(node_t *)malloc(sizeof(node_t));
	temp->prv=NULL;
	temp->x=x;
	temp->next=NULL;

	return temp;
}
void add_1st_post(int x)
{
	if(head != NULL)
	{
		node_t *temp=new(x);
		
		head->prv = temp;
		temp->next=head;
		head=temp;
	}
	else
		head=new(x);
}

void add_specific_post(int x,int pos)
{
	int n=0;
	if(pos==1)
	{
		add_1st_post(x);
	}
	else if(pos == (count()+1))
	{
		add_last_post(x);
	}
	else
	{
		node_t *temp = new(x);
		node_t *trav=head;
		while(n < (pos-2))
		{
			n++;
			trav=trav->next;
		}
		temp->next = trav->next;
		temp->prv = trav;
		trav->next->prv=temp;
		trav->next=temp;
	}

}
void add_last_post(int x)
{
	if(head != NULL)
	{
		node_t *trav;
		trav=head;
		while(trav->next != NULL)
		{
			trav = trav->next;
		}
		trav->next = new(x);
		trav->next->prv = trav;
	}
	else
		add_1st_post(x);
}
 
