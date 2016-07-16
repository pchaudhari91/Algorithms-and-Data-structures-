#include<conio.h>
#include<stdio.h>
#define max 10

int no[max],n;

void create();
int lsearch();
int bsearch();


void main()
{
	int i,choice,x;

	while(1)
	{      // clrscr();
		printf("\n\n\t\tCASE 1: LINEAR SEARCH");
		printf("\n\t\tCASE 2: BINARY SEARCH");
		printf("\n\t\tCASE 3: EXIT");

		printf("\n\n\t\tenter your choice:");
		scanf("%d", &choice);

		switch(choice)
		{
			case 1: x=lsearch();
				if (x== (-1))
					printf("\n\t\tno. not found..");
				else
					printf("\n\t\tno. found at position %d", x);
				getch();
				break;

			case 2:
				x= bsearch();
				if(x==(-1))
					printf("\n\t\tno. not found..");
				else
					printf("\n\t\tno. found at position %d", x);
				getch();
				break;

			case 3:
				exit(0);

				break;

			default:
				printf("\n\t\tsorry.. no. such option exist..");
		}
	}
	}
getch();


void create()
{
	int i;

	printf("\n\t\tenter how many nos.:");
	scanf("%d",&n);

	printf("\n\t\tenter the elements of the array:");
	for (i=0; i<n; i++)
	scanf("%d",&no[i]);
}


int lsearch()
{
	int i,key;

	create();

	printf("\n\t\tenter the no. you want to search:");
	scanf("%d",&key);

	for (i=0; i<n; i++)
	{
		if (no[i] == key)
			return(i);
	}
	return(-1);

}

int bsearch()
{
	int i,key,low, high,mid;


	create();
	low=0;
	high=n-1;

	printf("\n\t\tenter the no. you want to search:");
	scanf("%d", &key);
	printf("\n\tLow\tmid\thigh ");
	while(low <= high)
	{


		mid = ( low+high )/2;

		printf("\n\t%d\t%d\t%d",low,mid,high);

		if ( no[mid]  == key)
			return(mid);
		else if( no[mid] < key)
			low = mid+1;
		else
			high = mid -1;
	}
		return(-1);
}