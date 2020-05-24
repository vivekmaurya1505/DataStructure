/*
 ============================================================================
 Name        : PostfixEvaluation .c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define TRUE  1
#define FALSE 0
#define SIZE 5
typedef int ELEMENT;
typedef int BOOL;

typedef struct
{
	ELEMENT eles[SIZE];//stack of integers
	int top;//will retainindex of top most element
}STACK;

void init_stack(STACK *stack)
{
	stack->top=-1;
}

BOOL is_full(const STACK *stack)
{
	return stack->top==SIZE-1 ? TRUE : FALSE;
}

void push_element(STACK  *stack,ELEMENT ele)
{
	//manage top area for new element
	stack->top++;
	//push element on stack
	stack->eles[stack->top]=ele;
}

BOOL is_empty(const STACK *stack)
{
	//1. empty initially top==-1
	//2. after performing operations on stack
	return stack->top==-1 ? TRUE :FALSE;
}
void pop_element(STACK *stack)
{
	//assume top most element is deleted
	stack->top--; //decide which will be next top element
}
ELEMENT peek_element(const STACK *stack)
{
	return stack->eles[stack->top];
}
BOOL is_operand(char operand)
{
	return operand>=48 && operand<=57 ? TRUE : FALSE;
}

BOOL is_operator(char oper)
{
	if(oper=='+' || oper =='-' || oper == '*' || oper == '/')
		return TRUE;
	else
		return FALSE;
}

int calculate(int n1,int n2,char opr)
{
	int ans;
	switch(opr)
	{
		case '+':
				ans= n1 + n2;
				break;
		case '-':
				ans= n1 - n2;
				break;
		case '*':
				ans= n1 * n2;
				break;
		case '/':
				ans= n1 / n2;
				break;
	}
return ans;
}
int evaluate_postfix(char postfix[80]) //char *postfix
{
	STACK stack;
	int i,n1,n2;
	ELEMENT result;
	i=0;
	init_stack(&stack);

	while(postfix[i]!=NULL)
	{
		if(is_operand(postfix[i]))//if operand
		{
			if(!is_full(&stack))
				push_element(&stack, postfix[i]-48);//if operand push on stack
		}
		else if(is_operator(postfix[i]))//if operator
		{
			if(!is_empty(&stack))
			{
				n2 = peek_element(&stack);
				pop_element(&stack);
			}//1st pop result to be considered as right operand
			if(!is_empty(&stack))
			{
				n1 = peek_element(&stack);
				pop_element(&stack);
			}//2nd pop result to be considered as left operand
			result = calculate(n1,n2,postfix[i]) ;
			//result as operand push on stack
			if(!is_full(&stack))
			{
				push_element(&stack,result);
			}
		}
		i++;
	}
	if(!is_empty(&stack))
		{
			result = peek_element(&stack);
			pop_element(&stack);
		}
	return result;
}
int main(void)
{
	char postfix[80];
	printf("\n Please specify postfix string");
	gets(postfix);
	int result = evaluate_postfix(postfix);
	printf("\n Result = %d",result);
}

















