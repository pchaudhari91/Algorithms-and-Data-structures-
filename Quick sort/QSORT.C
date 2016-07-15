#include<conio.h>
#include<stdio.h>
#define max 20

int partition(int low, int high);
void qsort(int low, int high);
void swap(int x, int y);

int no[max],n;

void main()
{

	int i;
	clrscr();

	printf("\n\n\t\tenter hoe many nos:");
	scanf("%d", &n);

	printf("\n\n\t\tenter the array elements:");
	for (i=0; i<n; i++)
	scanf("%d", &no[i]);

	qsort(0,n-1);

	printf("\n\n\t\tsorted order is:\n");
	for (i=0; i<n; i++)
	printf("\t%d",no[i]);

	getch();
}

void swap(int x, int y)
{
	int temp;

	temp =no[x];
	no[x]= no[y];
	no[y]= temp;
}

void qsort(int low, int high)
{
	int pivotloc;

	if (high > low)
	{
		pivotloc = partition(low, high);
		qsort (low, pivotloc-1);
		qsort (pivotloc+1, high);
	}
}

int partition(int low, int high)
{
	int i,j,pivot;
	i=low;
	j=high;
	pivot=no[low];

	while(j>=i)
	{
		while(no[i] <= pivot)
			i++;

		while(no[j] > pivot)
			j--;

		if (j > i)
			swap(i,j);
	}
	swap(j,low);
	return(j);
}

