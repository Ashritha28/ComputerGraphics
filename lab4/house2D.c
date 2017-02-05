#include<stdio.h>
#include<graphics.h>
#include<math.h>
#define pi 3.14


int sign(x)
{
	if(x>0)
		return 1;
	else if(x<0)
	 	return -1;
	else
	 	return 0;
}


void drawline(int x1,int y1, int x2, int y2)
{
	int x,y,dx,dy,swap,temp,s1,s2,p,i;
	x=x1;
	y=y1;
	dx=abs(x2-x1);
	dy=abs(y2-y1);
	s1=sign(x2-x1);
	s2=sign(y2-y1);
	swap=0;
	putpixel(x1,y1,WHITE);
	if(dy>dx)
	{
		temp=dx;
		dx=dy;
		dy=temp;
		swap=1;
	}
	p=2*dy-dx;
	for(i=0;i<dx;i++)
	{
		
		if(p>=0)
	  	{
	  		p=p-2*dx;
	  		if(swap)
	   			x+=s1;
	  		else
	   			y+=s2;
	  	}
	  	p=p+2*dy;
	 	if(swap)
	  		y+=s2;
	 	else
	  		x+=s1;
	  putpixel(x,y,WHITE);
 	}
	putpixel(x2,y2,WHITE);
}

void pixel(int xc,int yc,int x,int y)
{
            putpixel(xc+x,yc+y,7);
            putpixel(xc+y,yc+x,7);
            putpixel(xc-y,yc+x,7);
            putpixel(xc-x,yc+y,7);
            putpixel(xc-x,yc-y,7);
            putpixel(xc-y,yc-x,7);
            putpixel(xc+y,yc-x,7);
            putpixel(xc+x,yc-y,7);
}

void drawhouse(int x,int y)
{
	line(x,y,x+150,y);
	line(x+150,y,x+150,y-150);
	line(x+150,y-150,x,y-150);
	line(x,y-150,x,y);
	line(x,y-150,x+70,y-250);
	line(x+150,y-150,x+70,y-250);
	line(x+50,y,x+50,y-80);
	line(x+100,y,x+100,y-80);
	line(x+100,y-80,x+50,y-80);
	line(x+20,y-100,x+40,y-100);
	line(x+40,y-100,x+40,y-120);
	line(x+40,y-120,x+20,y-120);
	line(x+20,y-120,x+20,y-100);
	line(x+110,y-100,x+130,y-100);
	line(x+130,y-100,x+130,y-120);
	line(x+130,y-120,x+110,y-120);
	line(x+110,y-120,x+110,y-100);
}

void reflect(int choice,int x,int y)
{
	if(choice==2)
	{
	int d=250;
	line(x+200,0,x+200,400);
	line(x+d,y,x+150+d,y);
	line(x+d+150,y,x+d+150,y-150);
	line(x+d+150,y-150,x+d,y-150);
	line(x+d,y-150,x+d,y);
	line(x+d,y-150,x+d+70,y-250);
	line(x+d+150,y-150,x+d+70,y-250);
	line(x+d+50,y,x+d+50,y-80);
	line(x+d+100,y,x+d+100,y-80);
	line(x+d+100,y-80,x+d+50,y-80);
	line(x+d+20,y-100,x+d+40,y-100);
	line(x+d+40,y-100,x+d+40,y-120);
	line(x+d+40,y-120,x+d+20,y-120);
	line(x+d+20,y-120,x+d+20,y-100);
	line(x+d+110,y-100,x+d+130,y-100);
	line(x+d+130,y-100,x+d+130,y-120);
	line(x+d+130,y-120,x+d+110,y-120);
	line(x+d+110,y-120,x+d+110,y-100);
	}
	if(choice==1)
	{
	int dist=20;
	line(0,y+10,400,y+10);
	line(x,y+dist,x+150,y+dist);
	line(x+150,y+dist,x+150,y+150+dist);
	line(x+150,y+150+dist,x,y+150+dist);
	line(x,y+150+dist,x,y+dist);
	line(x,y+150+dist,x+70,y+250+dist);
	line(x+150,y+150+dist,x+70,y+250+dist);
	line(x+50,y+dist,x+50,y+80+dist);
	line(x+100,y+dist,x+100,y+80+dist);
	line(x+100,y+80+dist,x+50,y+80+dist);
	line(x+20,y+100+dist,x+40,y+100+dist);
	line(x+40,y+100+dist,x+40,y+120+dist);
	line(x+40,y+120+dist,x+20,y+120+dist);
	line(x+20,y+120+dist,x+20,y+100+dist);
	line(x+110,y+100+dist,x+130,y+100+dist);
	line(x+130,y+100+dist,x+130,y+120+dist);
	line(x+130,y+120+dist,x+110,y+120+dist);
	line(x+110,y+120+dist,x+110,y+100+dist);
	}
	
}

void shear(int choice,int x1,int y1,int x2,int y2)
{
	if(choice==1)
	{
	line(x1+tan(pi/6)*y1,y1,x2+tan(pi/6)*y2,y2);
	}	
	if(choice==2)
	{
	line(x1,y1-tan(pi/6)*x1,x2,y2-tan(pi/6)*x2);
	}
}

int main()
{
int choice;
printf("Choose the axis:\n1.X-axis\n2.Y-axis\n");
scanf("%d",&choice);
int gd=DETECT,gm;
initgraph(&gd,&gm,"");
int x=100;
int y=300;
drawhouse(x,y);
reflect(choice,x,y);
shear(choice,x,y,x+150,y);
shear(choice,x+150,y,x+150,y-150);
shear(choice,x+150,y-150,x,y-150);
shear(choice,x,y-150,x,y);
shear(choice,x,y-150,x+70,y-250);
shear(choice,x+150,y-150,x+70,y-250);
shear(choice,x+50,y,x+50,y-80);
shear(choice,x+100,y,x+100,y-80);
shear(choice,x+100,y-80,x+50,y-80);
shear(choice,x+20,y-100,x+40,y-100);
shear(choice,x+40,y-100,x+40,y-120);
shear(choice,x+40,y-120,x+20,y-120);
shear(choice,x+20,y-120,x+20,y-100);
shear(choice,x+110,y-100,x+130,y-100);
shear(choice,x+130,y-100,x+130,y-120);
shear(choice,x+130,y-120,x+110,y-120);
shear(choice,x+110,y-120,x+110,y-100);
getch();
closegraph();
}