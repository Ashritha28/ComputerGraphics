#include<stdio.h>
#include<graphics.h>
#include<math.h>
#define PI 3.14


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

void drawcircle(int xc,int yc,int r)
{
	int x,y,Pk;
		x=0;
        y=r;
        Pk=1-r;
       
        while(x<y)
        {
        	pixel(xc,yc,x,y);
        	if(Pk<0)
                {
                    x=x+1;
                    Pk=Pk+(2*x)+1;
                }
                else
                {
                    x=x+1;
                    y=y-1;
                    Pk=Pk+(2*x)-(2*y)+1;
                }
                
         }
            
}


void main()
{

	float tx,ty,sx,sy;
	tx=200;
	ty=200;
	sx=sy=0.75;
	sy=sx;
	int th=150;
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"..\\BGI\\");
	int j=0,k=0;
	int xc=300,yc=300;
	int r=60;
	int x1=300+r*cos(0*PI/180);
	int y1=300+r*sin(0*PI/180);
	int x2=300+r*cos(72*PI/180);
	int y2=300+r*sin(72*PI/180);
	int x3=300+r*cos(144*PI/180);
	int y3=300+r*sin(144*PI/180);
	int x4=300+r*cos(216*PI/180);
	int y4=300+r*sin(216*PI/180);
	int x5=300+r*cos(288*PI/180);
	int y5=300+r*sin(288*PI/180);
	drawline(x1,y1,x2,y2);
	drawline(x1,y1,x5,y5);
	drawline(x3,y3,x2,y2);
	drawline(x3,y3,x4,y4);
	drawline(x5,y5,x4,y4);
	j=tx,k=ty;
	x1=300+r*cos(0*PI/180+th);
	y1=300+r*sin(0*PI/180+th);
	x2=300+r*cos(72*PI/180+th);
	y2=300+r*sin(72*PI/180+th);
	x3=300+r*cos(144*PI/180+th);
	y3=300+r*sin(144*PI/180+th);
	x4=300+r*cos(216*PI/180+th);
	y4=300+r*sin(216*PI/180+th);
	x5=300+r*cos(288*PI/180+th);
	y5=300+r*sin(288*PI/180+th);
	drawline(x1,y1,x2,y2);
	drawline(x1,y1,x5,y5);
	drawline(x3,y3,x2,y2);
	drawline(x3,y3,x4,y4);
	drawline(x5,y5,x4,y4);
	x1=300+r*cos(0*PI/180+th)+j;
	y1=300+r*sin(0*PI/180+th)+k;
	x2=300+r*cos(72*PI/180+th)+j;
	y2=300+r*sin(72*PI/180+th)+k;
	x3=300+r*cos(144*PI/180+th)+j;
	y3=300+r*sin(144*PI/180+th)+k;
	x4=300+r*cos(216*PI/180+th)+j;
	y4=300+r*sin(216*PI/180+th)+k;
	x5=300+r*cos(288*PI/180+th)+j;
	y5=300+r*sin(288*PI/180+th)+k;
	drawline(x1*sx,y1*sy,x2*sx,y2*sy);
	drawline(x1*sx,y1*sy,x5*sx,y5*sy);
	drawline(x3*sx,y3*sy,x2*sx,y2*sy);
	drawline(x3*sx,y3*sy,x4*sx,y4*sy);
	drawline(x5*sx,y5*sy,x4*sx,y4*sy);
	getch();
	closegraph();
}




