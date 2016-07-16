#include<stdio.h>
#include<conio.h>
#include <graphics.h>
#include <stdlib.h>

void main()
{
	int gdriver = DETECT, gmode;
	int x1,x2,y1,y2,x,y;

	clrscr();
	initgraph(&gdriver,&gmode,"c:\\tc\\bgi") ;
	printf("\n\n\t\tenter the value of x1,y1:");
	scanf("%d%d",&x1,&y1);
	printf("\n\n\t\tenter the value for x2,y2:");
	scanf("%d%d",&x2,&y2);

	rectangle(x1,y1,x2,y2);

	//printf("\n\n\t\tenter the value for x,y:");
	//scanf("%d %d",&x,&y);

	flood_fill(x1+1,y1+1,BLACK,RED);

getch();
closegraph();
}

flood_fill(int x,int y,int old_colour,int new_colour)
{
	if (getpixel (x,y) == BLACK)
	{
		delay(1);
		putpixel(x,y,RED);
		flood_fill(x+1,y,BLACK,RED);
		flood_fill(x-1,y,BLACK,RED);
		flood_fill(x,y+1,BLACK,RED);
		flood_fill(x,y-1,BLACK,RED);
		flood_fill(x+1,y+1,BLACK,RED);
		flood_fill(x-1,y-1,BLACK,RED);
		flood_fill(x+1,y-1,BLACK,RED);
		flood_fill(x-1,y+1,BLACK,RED);
	}
}