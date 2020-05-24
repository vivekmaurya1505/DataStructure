/*
 ============================================================================
 Name        : FunctionPointer_2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int add(int x,int y)
{
	return x + y;
}

int sub(int x,int y)
{
	return x - y;
}
int mul(int x,int y)
{
	return x * y;
}
int main(void) {
	int (*fnptr)(int,int);	//int *ptr;
	//fnptr is a pointer to such a function which returns integer
	//and it takes first argument as int and second argument as integer

	int a=5,b=3,ans;

	ans=add(a,b);		//call to function original way
	printf("\n ans = %d",ans);
	fnptr=add;
	ans=(*fnptr)(a,b);//call to function via fnptr
	printf("\n ans = %d",ans);

	ans=sub(a,b);		//call to function original way
	printf("\n ans = %d",ans);
	fnptr=sub;
	ans=(*fnptr)(a,b);//call to function via fnptr
	printf("\n ans = %d",ans);


	ans=mul(a,b);		//call to function original way
	printf("\n ans = %d",ans);
	fnptr=mul;
	ans=(*fnptr)(a,b);		//call to function via fnptr
	printf("\n ans = %d",ans);

	return EXIT_SUCCESS;
}









