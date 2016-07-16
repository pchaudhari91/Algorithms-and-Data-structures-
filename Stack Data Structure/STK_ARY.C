#include<conio.h>
#include<stdio.h>
#define max 3

int top;
int stack[max];
void init()
{
top = -1;
}

int isfull()
{
	if (top == max-1)
		return (1);
	else
		return(0);
}

int isempty()
{
	if (top == -1)
		return (1);
	else
		return(0);
}

void push()
{
	int x;

	if (isfull())
		printf("\n\n\t\tstack full...");
	else
	{
		printf("\n\n\t\tenter the element:");
		scanf("%d",&x);

		top = top +1;

		stack[top] =x;
	}
}

int pop()
{
	int x;

	x= stack[top];
	top = top-1;

	return(x);
}

void print()
{
	int i;

	printf("\n\n\t\tthe nos. are:\n");
	for (i=0; i<=top; i++)
		printf("\t%d",stack[i]);
}

void main()
{
	int ch;
	clrscr();
	init();
	do
	{
		printf("\n\n\t\tCASE 1:PUSH");
		printf("\n\t\tCASE 2:POP");
		printf("\n\t\tCASE 3:PRINT");
		printf("\n\t\tCAES 4:EXIT");

		printf("\n\n\t\tenter your choice:");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1:
				push();
				break;
			case 2:
				if (isempty())
					printf("\n\n\t\tstack empty....");
				else
					printf("\n\n\t\tpop element %d", pop());
				break;
			case 3:
				print();
				break;
			case 4:
				exit(0);
				break;
			default:
				printf("\n\n\t\tsorry... no such option exist");
		}
	}while(1);

//getch();
}