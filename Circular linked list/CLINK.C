#include<conio.h>
#include<stdio.h>
typedef struct node
{
	int data;
	struct node *next;
}node;

node * ccreate(int n);
node * cinsert(node *head, int pos, int x);
node * cdel(node *head, int pos);
void cdisp(node *head);

node * ccreate(int n)
{

node *head, *newnode, *temp;
int i,x;
head = NULL;
for(i=1; i<=n; i++)
{
	printf("\nenter data");
	scanf("%d",&x);

	newnode = (node *)malloc(sizeof(node));
	newnode->data = x;
	newnode->next = NULL;

	if(head== NULL)
	{
		head = newnode;
		newnode->next = head;
	}
	else
	{
		temp= head;
		while(temp->next != head)
			temp = temp->next;

		temp->next = newnode;
		newnode->next = head;
	}
}
return(head);
}

node *cinsert(node *head, int pos, int x)
{
	int i;
	node *newnode,*temp;

	newnode = (node *)malloc(sizeof(node));
	newnode->data = x;
	newnode->next = NULL;

	if(pos ==1)
	{
		temp= head;
		while(temp->next != head)
			temp = temp->next;

		newnode->next = head;
		head = newnode;
		temp->next = head; // temp->next = newnode;
		return(head);
	}

	temp = head;

	/*for(i=1; i<pos-1 && temp->next!=head; i++)
		temp = temp->next;*/

	i=1;
	do
	{
	temp = temp->next;
	i=i+1;
	}while(i<pos-1 && temp != head);

	if (temp == head)
	{
		printf("underflow");
		return(head);

	}

	newnode->next = temp->next;
	temp->next = newnode;
	return(head);
}

node * cdel(node *head, int pos)
{
int i;
node *temp, *q;

if(pos ==1)
{
temp = head;
q= head;
do{
	q=q->next;
}while(q->next !=head);

head = head->next;
q->next = head;
temp->next = NULL;
free(temp);
return(head);
}

q = head;

for(i=1; i<pos-1 && q->next != head; i++)
     q = q->next;

if(q->next == head)
{
	printf("under flow");
	return(head);
}

temp = q->next;
q->next = temp->next;
temp->next = NULL;
free(temp);
return(head);
}

void cdisp(node *head)
{
node *q;
if (head ==NULL)
	printf("list is empty");
else
{       printf("\n\tList : ");
	q=head;
	do

	{
		printf("%d ",q->data);
		q=q->next;
	}while(q!=head);
}
}


void main()
{
int ch,x,pos,n;
node *head;
head = NULL;
clrscr();

do
{
printf("\n\t1. create 2. add  3. Delete  4. Display  5. Exit");
printf("\nEnter your choice");
scanf("%d", &ch);
switch(ch)
{
case 1: printf("enter how manuy no ");
	scanf("%d",&n);
	head = ccreate(n);
	break;
case 2: printf("\n\tenter number to be added ");
	scanf("%d", &x);
	printf("\nenter position");
	scanf("%d",&pos);
	head = cinsert(head,pos,x);
//	add(x);
	break;
case 3: printf("\n\tenter position ");
	scanf("%d",&pos);
	head = cdel(head,pos);
	break;
case 4 : cdisp(head);break;
}
}while(ch !=5);
}


