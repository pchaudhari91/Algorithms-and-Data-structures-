

#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

void main()
{
	int gdriver = DETECT, gmode;
	int r,p,x,y,xc,yc;
	clrscr();
	initgraph(&gdriver, &gmode, "c:\\tc\\bgi") ;

	printf("\n\n\t\tenter the radius;");
	scanf("%d",&r);
	printf("\n\n\t\tenter the x and y co-ordinate:");
	scanf("%d %d", &xc, &yc);

	p= 3- 2 * r;

	x=0;
	y=r;

	do
	{
		putpixel (x+xc ,y+yc ,4);
		putpixel(y+xc ,x+yc ,4);
		putpixel((-y)+xc ,(-x)+yc ,4);
		putpixel(x+xc ,(-y)+yc ,4);
		putpixel((-x)+xc ,y+yc ,4);
		putpixel(y+xc ,(-x)+yc ,4);
		putpixel((-x)+xc ,(-y)+yc ,4);
		putpixel((-y)+xc ,x+yc ,4);

		if (p < 0)
		{
			p=p+ (4 * x) +6;
			x=x+1;
		}


		else
		{
			p=p+ 4*(x-y) +10;
			x=x+1;
			y=y-1;
		}

		}while(x<y);

getch();
closegraph();
}
