#include<conio.h>
#include<stdio.h>
#define max 5

typedef struct queue
{
	int data[max];
	int front,rear;
}queue;

void init(queue *q)
{
   q->front=q->rear=-1;
}

void insert(queue *q)
{
	int no;

	if (q-> front == ((q->rear+1) %max))
		printf("\n\n\t\tQUEUE FULL...");
	else
	{
		printf("\n\n\t\tenter the no.:");
		scanf("%d",&no);

		if (q->rear == -1)
			q->rear = q->front =0;
		else
			q->rear = q->rear +1;

		q->data[q->rear]=no;

		printf("\n\n\t\tFRONT:%d\tREAR:%d",q->front,q->rear);
	}
}

void del(queue *q)
{
	int no;

	if(q->front == -1)
		printf("\n\n\t\tQUEUE IS EMPTY..");

	else
	{
		no = q->data[q->front];
		printf("\n\n\t\tDELETED ELEMENT:%d", no);

		if (q->front == q->rear)
			q->front = q->rear =-1;
		else
			q->front = (q->front +1) % max;

		printf("\n\n\t\tFRONT:%d\tREAR:%d",q->front,q->rear);
	}
}

void display(queue *q)
{
	int i;

	if (q->front == -1)
		printf("\n\n\t\tQUEUE IS EMPTY..");
	else
	{
		printf("\n\n\t\tQUEUE:");

		for (i=q->front; i<=q->rear; i++)
		printf("\t%d",q->data[i]);

		if (q->front == q->rear)
		{
			for (i=q->front; i<max; i++)
			printf("\t%d",q->data[i]);
			for (i=0; i<q->rear; i++)
			printf("\t%d",q->data[i]);
		}
	}
}

void main()
{
	int ch;
	queue q;
	init(&q);
	clrscr();

	do
	{
	printf("\n\n\t\t1: INSERT");
	printf("\n\t\t2:DELETE");
	printf("\n\t\t3:DISPLAY");
	printf("\n\t\t4:EXIT");

	printf("\n\n\t\tenter your choice:");
	scanf("%d",&ch);

	switch(ch)
	{
		case 1:
			insert(&q);
			break;
		case 2:
			del(&q);
			break;
		case 3:
			display(&q);
			break;
		case 4:
			exit (0);
			break;
		default:
			printf("\n\n\t\tsorry... no such option exist.");
	}
}while(1);

}