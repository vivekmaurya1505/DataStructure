/*
 ============================================================================
 Name        : FunctionPointer_3.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void display_array_elements(int *ptr);
int compare(const void *v1,const void *v2);
int main(void) {
	int arr[5]={45,67,23,12,5};
	printf("\n Array before Sorting\n");
	display_array_elements(arr);
	qsort(arr,5,sizeof(int),compare);
	printf("\n Array After Sorting\n");
	display_array_elements(arr);
	return EXIT_SUCCESS;
}

int compare(const void *v1,const void *v2)
{
	int n1 = *(int *)v1;//v1 address considered here as integer address so typecast
	int n2 = *(int *)v2;
	return n1 >n2;
}


void display_array_elements(int *ptr)
{
	int i;
	for(i=0;i<5;i++)
	{
		printf("%4d",ptr[i]);
	}
}













