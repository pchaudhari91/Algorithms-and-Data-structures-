#include<stdio.h>
#include<conio.h>
#define max 20

void create(int [],int);
void bub_sort(int [],int);
void sel_sort(int [],int);
void ins_sort(int [],int);

void main()
{
	int no[max],n,ch;

	do
	{
	printf("\n\n\t\tCASE 1:CREATE");
	printf("\n\t\tCASE 2:BUBBLE SORT");
	printf("\n\t\tCASE 3:INSERTION SORT");
	printf("\n\t\tCASE 4:SELECTION SORT");
	printf("\n\t\tCASE 5:EXIT");

	printf("\n\n\t\tenter your choice:");
	scanf("%d",&ch);

	switch(ch)
	{
		case 1:
			{
				printf("\n\n\t\tenter how many nos:");
				scanf("%d",&n);
				if (n > max)
					printf("\n\n\t\tarray full..");
				else
					create(no,n);
				break;
			}
		case 2:
			bub_sort (no,n);
			break;
		case 3:
			ins_sort(no,n);
			break;
		case 4:
			sel_sort(no,n);
			break;
		case 5:
			exit(0);
			break;
		default :
			printf("\n\n\t\tno such option exist..");
	}
}while(1);

//getch();
}

void create(int no[], int n)
{
	int i;

	printf("\n\n\t\tenter the array elements:");
	for (i=0; i<n; i++)
	scanf("%d",&no[i]);
}

void bub_sort (int no[],int n)
{
	int last,i,j,temp,exch,totexch=0,totcomp=0;

	last=n-1;
	for (i=0; i<n; i++)
	{
		exch=0;
		for (j=0; j<last; j++)
		{
			if (no[j] > no[j+1])
			{
				temp = no[j];
				no[j] = no[j+1];
				no[j+1] = temp;
				exch++;
			}
		}
		printf("\n\n\t\tpass %d\texchanges:%d\tcomparions:%d",i,exch,last);
		printf("\n\n");
		for (j=0; j<n; j++)
		printf("\t%d",no[j]);
		totexch=totexch+exch;
		totcomp=totcomp+last;
		if (exch==0)
			break;
		else
			last=last-1;
	}
	printf("\n\n\t\ttotal exchanges:%d\ttotal comparisions:%d",totexch,totcomp);
}

void ins_sort(int no[], int n)
{
	int i,j,temp,last,totcmp=0,totexc=0,exc;
	exc=0;
	last=n-1;

	for (i=0; i<n; i++)
	{
		exc=0;
		for (j=0; j<last; j++)
		{
			if (no[j] > no[j+1])
			{
				temp = no[j];
				no[j]=no[j+1];
				no[j+1]=temp;
				exc++;;
			}
		}

	printf("\n\t\tpass:%d\texchanges:%d\tcomparisions:%d",i,exc,last);
	printf("\n");
	for (j=0; j<=i;j++)
	printf("\t%d",no[j]);
	totexc=totexc+exc;
	totcmp=totcmp+last;
	if (exc == 0)
		break;
	else
		last= last-1;

}
	printf("\n\t\ttotal exchanges:%d\tcomparisions:%d",totexc,totcmp);
}

void sel_sort(int no[],int n)
{
	int i,last,j,temp,totexc=0,totcmp=0,exc;
	last = n-1;

	for (i=0; i<n; i++)
	{
		exc=0;
		for (j=i+1; j<last+1; j++)
		{
			     if(no[i] > no[j])
			     {
				temp=no[i];
				no[i]=no[j];
				no[j]=temp;
				exc++;
			     }
		}
		printf("\n\n\t\tpass:%d\texchanges:%d\tcomparisions:%d",i,totexc,totcmp);
		printf("\n\n");
		for (j=0; j<n; j++)
		printf("\t%d", no[j]);
		totexc=totexc+exc;
		totcmp=totcmp+last;
		if(exc=0)
			break;
		else
			last=last-1;

	}
	printf("\n\t\ttotal exchanges:%d\tcomparisions:%d",totexc,totcmp);
}
