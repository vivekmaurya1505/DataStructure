#include<stdio.h>

#define SIZE 10

void add_ele(int,int [],int *,int *);
int retrive_ele(int [],int *,int *);
void display_que(int [],int *,int *);

int main()
{
	int arr[SIZE];
	int f,r,n,x,a;
	f=-1;
	r=-1;

	while(1){
	printf("\n1.add element\n2.retrive element\nchoose option:");
	scanf("%d",&n);

	switch(n)
	{
		case 1: printf("enter data:");
		       scanf("%d",&x);	
			add_ele(x,arr,&f,&r);
	                printf("\n");
                         display_que(arr,&f,&r);
	                  printf("\n");
			 break;

		case 2: a=retrive_ele(arr,&f,&r);
	                printf("\n");
                        display_que(arr,&f,&r);
	                 printf("\n");
			break;
	}
	}
}

void add_ele(int x,int a[SIZE],int *f,int *r)
{
	if(((*f == 0) & (*r == (SIZE-1))) | ((*f - *r)==1))
	{	printf("\nqueue is full\n");
		return;}
	else if((*f == -1)&(*r == -1))
	{
		*f=0;
		*r=0;
		a[*r]=x;
		return;
	}
	else if((*f > 0) & (*r == (SIZE-1)))
	{
		*r=0;
		a[*r]=x;
		return;
	}
	else if(*r < (SIZE-1))
	{
		++*r;
		a[*r]=x;
		return;
	}

}

int retrive_ele(int a[SIZE],int *f,int *r)
{
	int temp;
	if((*f == -1)&(*r == -1)) 
	{	printf("\nqueue is empty\n");
	}
	else if(*f == *r)
	{
		temp = a[*f];
		*f=-1;
		*r=-1;
		printf("\nqueue is empty now\n");
		
		return temp;
	}
	else if((*f != *r) & (*f == (SIZE-1)))
	{
		temp = a[*f];
		*f=0;

		return temp;
	}
	else if(*f < (SIZE-1))
	{
		temp = a[*f];
		++*f;
		return temp;
	}

}

void display_que(int a[SIZE],int *f,int *r)
{
	int i;
	if((*f == -1)&(*r == -1)) 
		return;
	else
	{
	printf("queue is:\n");
	if(*f <= *r)
	{
		for(i=*f;i<=*r;i++)
			printf("%d ",a[i]);

	}
	else if(*f > *r)
		{
			for(i=*f;i<SIZE;i++)
			printf("%d ",a[i]);
		
			for(i=0;i<=*r;i++)
			printf("%d ",a[i]);
		}
}
}
