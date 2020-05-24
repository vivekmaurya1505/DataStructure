#include<stdio.h>
#include<stdlib.h>

#define SIZE 10

typedef struct element{
	int x;
	struct element *next;
}queue_t;

queue_t *head = NULL;

queue_t *new(int);
int count(void);
void add_ele(int);
void delete_ele(void);
void display_que(void);

int main()
{
	int n,x;
	while(1)
	{
	printf("\n1.add_data\n2.delete data\nchoose option:");
	scanf("%d",&n);
	switch(n)
{
	case 1: printf("\nenter data:");
		scanf("%d",&x);
		add_ele(x);
	        display_que();
		break;

	case 2: delete_ele();
	        display_que();
		break;
}

}
}

int count()
{
	int cnt=0;
	queue_t *trv= head;
	while(trv != NULL)
	{
		cnt++;
		trv = trv->next;
	}

	return cnt;
}

queue_t *new(int x)
{
	queue_t *new;
	new = (queue_t *)malloc(sizeof(queue_t));
	new->x = x;
	new->next = NULL;

	return new;
}

void add_ele(int x)
{
	int n=count();
	if(n<SIZE)
	{
	queue_t *trv = head;
	if(head == NULL)
		head = new(x);
	else
		{
			while(trv -> next != NULL)
			{
				trv = trv->next;
			}
			trv->next = new(x);
		}
	}
	else
		printf("\nqueue is full\n");
}
void delete_ele(void)
{
	queue_t *temp;
	queue_t *trv=head;
	if(head != NULL)
	{
		temp = head;
		head = trv->next;
		free(temp);
	}
	else
		printf("\nqueue is empty\n");
}
void display_que(void)
{
	queue_t *trv = head;
        printf("\nqueue is:\n");
	while(trv != NULL)
	{
		printf("%d ",trv->x);
		trv = trv->next;
	}
}
