#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int x;
	struct node *next;
}node_t;

node_t *head = NULL;

node_t *create_node(int);
int count_node(void);
void display_linklist(void);

void add_node_at_1st(int);
void add_node_at_end(int);
void add_node_at_position(int ,int);

void delete_node_at_1st(void);
void delete_node_at_end(void);
void delete_node_at_position(int);

int main()
{
	int x,pos;
	int n;
	while(1){
printf("\n1,add_node_at_1st\n2.add_node_at_end\n3.add_node_at_position\n4.delete_node_at_1st\n5.delete node_at_end\n6.delete_node_at_position\nchoose option:");
scanf("%d",&n);

switch(n)
{
	

	case 1: printf("enter data:");
		scanf("%d",&x);
		add_node_at_1st( x);
                display_linklist();
		break;
	 
	case 2: printf("enter data:");
		scanf("%d",&x);
	        add_node_at_end(x);
                display_linklist();
		break;
	 
	case 3: printf("enter data and position:");
		scanf("%d%d",&x,&pos);
	        add_node_at_position(x,pos);
                display_linklist();
		break;
 
	case 4: delete_node_at_1st();
                display_linklist();
		break;
	 
	case 5: delete_node_at_end();
                display_linklist();
		break;
	 
	case 6:printf("enter position:");
		scanf("%d",&pos);
	       	delete_node_at_position(pos);
                display_linklist();
		break;
}
}

}

node_t *create_node(int x)
{
	node_t *temp = (node_t *)malloc(sizeof(node_t));
	temp->x = x;
	temp->next = NULL;

	return temp;
}

int count_node()
{
	int cnt = 0;
	node_t *trv = head;
	while(trv != NULL)
	{
		cnt++;
		trv = trv->next;
	}
	return cnt;
}

void display_linklist(void)
	{
	if(head != NULL)
           {
		node_t *trv = head;
		printf("head ->");
		while(trv != NULL)
		{
			printf("%d ->",trv->x);
			trv = trv->next;
		}
		printf("NULL\n");
	   }
	else
		printf("linklist is empty");

	}

void add_node_at_1st(int x)
{
	node_t *new = create_node(x);

	if(head == NULL)
		head = new;
	else
	{
		new->next = head;
		head = new;
	}
}

void add_node_at_end(int x)
{
	node_t *new = create_node(x);
	
	node_t *trv = head;

	if(head == NULL)
		head = new;
	else
	{
		while(trv->next != NULL)
		{
			trv = trv->next;
		}
	trv->next = new;
	}
}

void add_node_at_position(int x,int pos)
{
	int i=0;
	node_t *new = create_node(x);
	node_t *trv = head;

	if(pos == 1)
		 add_node_at_end(x);
	else if(pos == (count_node()+1))
		add_node_at_end(x);
	else
           {
		while(i < pos-2)
		{
			i++;
			trv = trv->next;
		}	
		new->next =trv->next;
		trv->next = new;
	}
}

void delete_node_at_1st()
{
	node_t *temp = head;

	if(head != NULL)
	{
		if((head->next) == NULL)
		{
			free(temp);
			head = NULL;
		}
		else
		{
			head = head->next;
			free(temp);
		}
	}
	else
		printf("list is empty\n");
}
void delete_node_at_end()
{
	node_t *trv;
	node_t *temp = head;

	if(head != NULL)
	{
		if((head->next) == NULL)
		{
			free(temp);
			head = NULL;
		}
		else
		{
			while((temp->next->next) != NULL)
			{
				temp = temp->next;
			}
			trv = temp->next;
			free(trv);
			temp->next = NULL;
		}
	}
	else
		printf("list is empty\n");
}

void delete_node_at_position( pos )
{
	int i=0;

	node_t *trv = head;
	node_t *temp ;

	if(head != NULL)
	{
	if(pos == 1)
		 delete_node_at_1st();
	else if(pos == count_node())
		delete_node_at_end();
	else 
           {
		while(i < pos-2)
		{
			i++;
			trv = trv->next;
		}	
		temp = trv->next;
		trv->next = trv->next->next;
		free(temp);
	}
	}
	else
		printf("list is empty");
}


