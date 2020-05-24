#include<stdio.h>

typedef struct element{
	  int x;
}stack_e;

#define SIZE 8

int top = -1;

static stack_e arr[SIZE];

void add_ele(int);
void delete_ele(void);
void display_stack(void);

int main()
{
	int n,x;
//	static stack_e arr[SIZE];
	
	while(1)
	{
	printf("\n1.add data in stack\n2.remove data from stack\nchoose option:");
	scanf("%d",&n);

	switch(n)
	{
		case 1: printf("enter data:");
			scanf("%d",&x);
		       	add_ele(x);
			display_stack();
			break;

		case 2: delete_ele();
			display_stack();
			break;
	}
	}


	return 0;
}

void add_ele(int x)
{
	if(top < (SIZE-1))
	{
	if(top == -1)
	{
		top=0;
		arr[top].x=x;
	}	
	else
	{
		top++;
		arr[top].x=x;
	}
	}
	else
		printf("\nstack is full\n");
}

void delete_ele(void)
{
	if(top >= 0)
	{
		if(top == 0)
			top=-1;
		else
		{
			top--;
       		}
	}
	else
		printf("\nstack is empty\n");
}

void display_stack()
{
	int i;
	printf("\nstack is:\n");
	for(i=top;i>(-1);i--)
	{
		printf("%d\n",arr[i].x);
	}
}
