#include <graphics.h>
#include <stdlib.h>
#include<conio.h>
#include<stdio.h>
int mat[3][2];


void main()
{
	int gdriver = DETECT, gmode;
	int i,j,ch;
	initgraph(&gdriver,&gmode,"c:\\tc\\bgi") ;
		  cleardevice();
	clrscr();

	printf("\n\n\t\tenter the matrix:");
	for (i=0; i<3; i++)
		for (j=0; j<2; j++)
		scanf("%d",&mat[i][j]);

	line(mat[0][0], mat[0][1], mat[1][0], mat[1][1]);
	line(mat[1][0], mat[1][1], mat[2][0], mat[2][1]);
	line(mat[2][0], mat[2][1], mat[0][0], mat[0][1]);

	do
	{
		printf("\n\n\t\tCASE 1:TRANSLATION");
		printf("\n\t\tCASE 2:SCALING");
		printf("\n\t\tCASE 3:EXIT");

		printf("\n\n\t\tenter your choice:");
		scanf("%d", ch);

		switch(ch)
		{
			case 1: translation();
				break;

			case 2: scaling();
				break;

			case 3: exit(0);
				break;

			default:
				printf("\n\n\t\tno such option exist....");
		}
	}while(1);

getch();
closegraph();
}

void translation()
{
	int tx,ty;

	printf("\n\n\t\enter the translation points:");
	scanf("%d %d",&tx,&ty);

	mat[0][0]=mat[0][0]+tx;
	mat[0][1]=mat[0][1]+ty;
	mat[1][0]=mat[1][0]+tx;
	mat[1][1]=mat[1][1]+ty;
	mat[2][0]=mat[2][0]+tx;
	mat[2][1]=mat[2][1]+ty;

	line(mat[0][0], mat[0][1], mat[1][0], mat[1][1]);
	line(mat[1][0], mat[1][1], mat[2][0], mat[2][1]);
	line(mat[2][0], mat[2][1], mat[0][0], mat[0][1]);
}

void scaling()
{
	int sx,sy;

	printf("\n\n\t\enter the translation points:");
	scanf("%d %d",&sx,&sy);

	mat[0][0]=mat[0][0]*sx;
	mat[0][1]=mat[0][1]*sy;
	mat[1][0]=mat[1][0]*sx;
	mat[1][1]=mat[1][1]*sy;
	mat[2][0]=mat[2][0]*sx;
	mat[2][1]=mat[2][1]*sy;

	line(mat[0][0], mat[0][1], mat[1][0], mat[1][1]);
	line(mat[1][0], mat[1][1], mat[2][0], mat[2][1]);
	line(mat[2][0], mat[2][1], mat[0][0], mat[0][1]);
}
