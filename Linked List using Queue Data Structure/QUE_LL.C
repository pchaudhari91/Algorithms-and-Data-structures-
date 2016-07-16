#include<conio.h>
#include<stdio.h>

typedef struct node
{
	int data;
	struct node *next;
}node;

node *front,*rear;

void init()
{	rear=front=NULL;	}

void insert_q(int x)
{
	node *p;

	p= (node *) malloc (sizeof(node));
	p->data=x;
	p->next=NULL;

	if (rear == NULL)
	{
		front=rear = p;
		rear =p;
	}
	else
	{
		rear->next=p;
		rear=p;
	}
}

int delete_q()
{
	int x=0;
	node *p;

	if (front == NULL)
		printf("\n\n\t\tqueue EMPTY");
	else
	{
		p=front;
		x=p->data;

		if (rear == front)
			init();
		else
		{
			front = front->next;
			free(p);
		}
	return (x);
	}
}

void print()
{
	node *p;
	p=front;

	while (p != NULL)
	{
		printf("\t%d",p->data);
		p=p->next;
	}
}

void main()
{
	int ch,n;
	clrscr();

	init();

	do
	{
		printf("\n\t\t1:INSERT");
		printf("\n\t\t2:DELETE");
		printf("\n\t\t3:PRINT");
		printf("\n\t\t4:EXIT");

		printf("\n\n\t\tenter your choice:");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1:
				printf("\n\t\tenter no.:");
				scanf("%d",&n);
				insert_q(n);
				break;

			case 2:
				n=delete_q();
				printf("\n\n\t\tDeleted element=%d",n);
				break;

			case 3:
				print();
				break;

			case 4:
				exit(0);
				break;

			default:
				printf("\n\t\tSorry.... wrong option..");
		}
	}while(1);

getch();
}