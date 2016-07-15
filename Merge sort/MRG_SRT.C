#include<stdio.h>
#include<conio.h>
#define max 20

void merge_sort(int [], int , int);
void merge(int [], int , int, int);

void main()
{
	int a[max],n,i;
	clrscr();

	printf("\n\n\t\tenter how many nos. to be entered:");
	scanf("%d", &n);

	printf("\n\n\t\tenter the elements of the array:");
	for (i=0; i<n; i++)
	scanf("%d", &a[i]);

	merge_sort(a,0, n-1);

	printf("\n\n\t\tthe sorted elements are:\n\t");
	for (i=0; i<n; i++)
	printf("\t%d", a[i]);

	getch();
}

void merge_sort(int a[], int i,int j)
{
	int k;

	if(i<j)
	{
		k=(i+j)/2;
		merge_sort(a,i,k);
		merge_sort(a,k+1,j);
		merge(a,i,k,j);
	}
}

void merge(int a[], int l,int m, int u)
{
	int c[max];
	int i,j,k;

	i=l;
	j=m+1;
	k=0;

	while(i<=m && j<=u)
	{
		if (a[i] < a[j])
		{
			c[k]=a[i];
			i++;
			k++;
		}
		else
		{
			c[k]=a[j];
			k++;
			j++;
		}
	}
	while(i<=m)
	{
	c[k]=a[i];
	i++;
	k++;
	}

	while(j<=u)
	{
	 c[k]=a[j];
	 k++;
	 j++;
	}

	for(i=l,j=0; i<=u; i++,j++)
		a[i] = c[j];

}



