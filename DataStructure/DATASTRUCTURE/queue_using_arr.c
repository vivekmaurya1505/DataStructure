#include<stdio.h>

#define SIZE 5

void add_ele(int,int [],int *,int *);
int delete(int [],int *,int *);
void display(int [],int *,int *);
int main()
{
	int f=-1;
	int r=-1;
	int n,x,a;
	
	int arr[SIZE];

	while(1)
	{
	printf("\n1.add data\n2.delete data\nchoose option:");
	scanf("%d",&n);

	switch(n)
	{
		case 1: printf("enter data:");
			scanf("%d",&x);
                        add_ele(x,arr,&f,&r);
			break;

		case 2: a=delete(arr,&f,&r);
			break;
	}

	}

}

void add_ele(int x,int a[SIZE],int *f,int *r)
{
	if(*r <(SIZE-1))
	{
		if(*f==-1 && *r==-1)
		{
			++*f;
			++*r;
			a[(*r)]= x;
                        display(a,f,r);

		}
		else
		{
			++*r;
			a[(*r)] = x;
                        display(a,f,r);
		}

	}
	else
		printf("\nqueue is full\n");

}

int delete(int a[SIZE],int *f,int *r)
{
	int temp; 
	if(*f==-1 && *r==-1)
	{
		printf("\nqueue is empty\n");
	}
	else if(*f == *r)
	{
		temp=a[(*f)];
		a[(*f)]=0;
		*f=-1;
		*r=-1;
		printf("\nnow queue is empty\n");
		return temp;
	}
	else
	{
		temp=a[(*f)];
		a[(*f)]=0;
		++*f;
                 display(a,f,r);
		return temp;
	}
}

void display(int a[SIZE],int *q,int *r)
{
	int i;
	printf("\nqueue is:\n");
	for(i=(*q);i<=(*r);i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}
