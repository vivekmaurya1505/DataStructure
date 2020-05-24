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
void del_last_post(void);

int count(void);
void display(void);
void rev_display(void);

int main()
{
	int x,n,pos,a;
	
	while(1){
	printf("\n0.count\n1.add at 1st pos\n2.add at specific pos\n3.add at last position\n4.delete at 1st pos\n5.delete at specific position\n6.delete at last post\n7.reverse display\nselect option:");
	scanf("%d",&n);

	switch(n)
	{
		case 0:a=count();
		       printf("count of linklist = %d;",a);
		       break;

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
	if(head != NULL)
	{
	do
	{
		count++;
		trav = trav->next;
	}while(trav != head);
	}
	else
		return 0;

	return count;
}

void del_1st_post()
{
	node_t *temp = head;
	head = head->next;
	head->prv = temp->prv;
	temp->prv->next = head;
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
		node_t *temp = trav->next;
		temp->next->prv = trav;
		trav->next = trav->next->next;
		free(temp);
	}
}

void del_last_post()
{
	node_t *trav=head;
	node_t *temp;
	while(trav->next->next != head)
	{
		trav=trav->next;
	}
	temp = trav->next;

	trav->next = head;
	head->prv = trav;
	free(temp);
}

void rev_display()
{
	node_t *trav = head;
	while(trav->next != head)
	{
		printf("%d ",trav->x);
		trav=trav->next;
		
	}
	printf("\n");
	node_t *temp =trav;
	do
	{
		printf("%d ->",trav->x);
		trav=trav->prv;
	}while(trav->prv != temp);
	printf("head");
}


void display()
{
	node_t *trav;
	trav=head;
	printf("\nhead ->");
	do
	{
		printf("%d ->",trav->x);
		trav=trav->next;
	}while(trav != head);
	printf("\n");
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
	
		temp->next = head;
		temp->prv = head->prv;
		head->prv->next = temp;
		head=temp;
	}
	else
	{
		head=new(x);
		head->prv = head;
		head->next = head;
	}
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
			trav = trav->next;
		}
		temp->next = trav->next;
		temp->prv = trav;
		trav->next->prv = temp;
		trav->next = temp;
	}

}

void add_last_post(int x)
{
	if(head != NULL)
	{
		node_t *trav;
		trav=head;
		while(trav->next != head)
		{
			trav = trav->next;
		}
		trav->next = new(x);
		trav->next->prv = trav;
		trav->next->next = head;
	}
	else{
		add_1st_post(x);
	}
}
 
