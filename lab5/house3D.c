#include <stdio.h>
#include <graphics.h>
#include <math.h>
#define PI 3.14

void draw3Dhouse(float xaxis[],float yaxis[],float length)
{
	//12 edges of the cube
	line(xaxis[0],yaxis[0],xaxis[1],yaxis[1]);
	line(xaxis[1],yaxis[1],xaxis[5],yaxis[5]);
	line(xaxis[5],yaxis[5],xaxis[4],yaxis[4]);
	line(xaxis[4],yaxis[4],xaxis[0],yaxis[0]);
	line(xaxis[0],yaxis[0],xaxis[2],yaxis[2]);
	line(xaxis[2],yaxis[2],xaxis[3],yaxis[3]);
	line(xaxis[3],yaxis[3],xaxis[1],yaxis[1]);
	line(xaxis[4],yaxis[4],xaxis[6],yaxis[6]);
	line(xaxis[6],yaxis[6],xaxis[7],yaxis[7]);
	line(xaxis[5],yaxis[5],xaxis[7],yaxis[7]);
	line(xaxis[2],yaxis[2],xaxis[6],yaxis[6]);
	line(xaxis[3],yaxis[3],xaxis[7],yaxis[7]);
	setcolor(4);
	//triangle 1
	line(xaxis[2],yaxis[2],xaxis[2]+(length*cos(PI/3)),yaxis[2]-(length*sin(PI/3)));
	line(xaxis[3],yaxis[3],xaxis[3]-(length*cos(PI/3)),yaxis[2]-(length*sin(PI/3)));
	//triangle 2
	line(xaxis[6],yaxis[6],xaxis[6]+(length*cos(PI/3)),yaxis[6]-(length*sin(PI/3)));
	line(xaxis[7],yaxis[7],xaxis[7]-(length*cos(PI/3)),yaxis[7]-(length*sin(PI/3)));
	//joining line of both the triangles
	line(xaxis[2]+(length*cos(PI/3)),yaxis[2]-(length*sin(PI/3)),xaxis[6]+(length*cos(PI/3)),yaxis[6]-(length*sin(PI/3)));
	setcolor(15);
}

void reflect(float xaxis[],float yaxis[],int dist,int choice)
{
	setcolor(3);
	if(choice==2)
	{
		int i;
		for(i=0;i<10;i++)
		{
			xaxis[i]=2*dist-xaxis[i];
			yaxis[i]=yaxis[i];
		}
		line(xaxis[0],yaxis[0],xaxis[1],yaxis[1]);
		line(xaxis[1],yaxis[1],xaxis[5],yaxis[5]);
		line(xaxis[5],yaxis[5],xaxis[4],yaxis[4]);
		line(xaxis[4],yaxis[4],xaxis[0],yaxis[0]);
		line(xaxis[0],yaxis[0],xaxis[2],yaxis[2]);
		line(xaxis[2],yaxis[2],xaxis[3],yaxis[3]);
		line(xaxis[3],yaxis[3],xaxis[1],yaxis[1]);
		line(xaxis[4],yaxis[4],xaxis[6],yaxis[6]);
		line(xaxis[6],yaxis[6],xaxis[7],yaxis[7]);
		line(xaxis[5],yaxis[5],xaxis[7],yaxis[7]);
		line(xaxis[2],yaxis[2],xaxis[6],yaxis[6]);
		line(xaxis[3],yaxis[3],xaxis[7],yaxis[7]);
		line(xaxis[2],yaxis[2],xaxis[8],yaxis[8]);
		line(xaxis[3],yaxis[3],xaxis[8],yaxis[8]);
		line(xaxis[6],yaxis[6],xaxis[9],yaxis[9]);
		line(xaxis[7],yaxis[7],xaxis[9],yaxis[9]);
		line(xaxis[8],yaxis[8],xaxis[9],yaxis[9]);
	}
	else if(choice==1)
	{
		int i;
		for(i=0;i<10;i++)
		{
			yaxis[i]=2*dist-yaxis[i];
			xaxis[i]=xaxis[i];
		}
		line(xaxis[0],yaxis[0],xaxis[1],yaxis[1]);
		line(xaxis[1],yaxis[1],xaxis[5],yaxis[5]);
		line(xaxis[5],yaxis[5],xaxis[4],yaxis[4]);
		line(xaxis[4],yaxis[4],xaxis[0],yaxis[0]);
		line(xaxis[0],yaxis[0],xaxis[2],yaxis[2]);
		line(xaxis[2],yaxis[2],xaxis[3],yaxis[3]);
		line(xaxis[3],yaxis[3],xaxis[1],yaxis[1]);
		line(xaxis[4],yaxis[4],xaxis[6],yaxis[6]);
		line(xaxis[6],yaxis[6],xaxis[7],yaxis[7]);
		line(xaxis[5],yaxis[5],xaxis[7],yaxis[7]);
		line(xaxis[2],yaxis[2],xaxis[6],yaxis[6]);
		line(xaxis[3],yaxis[3],xaxis[7],yaxis[7]);
		line(xaxis[2],yaxis[2],xaxis[8],yaxis[8]);
		line(xaxis[3],yaxis[3],xaxis[8],yaxis[8]);
		line(xaxis[6],yaxis[6],xaxis[9],yaxis[9]);
		line(xaxis[7],yaxis[7],xaxis[9],yaxis[9]);
		line(xaxis[8],yaxis[8],xaxis[9],yaxis[9]);
	}
	setcolor(15);
}

void shear(float xaxis[],float yaxis[],int choice,float angle)
{
	float tanvalue=tan(angle);
	setcolor(3);
	if(choice==2)
	{
		int i;
		for(i=0;i<10;i++)
		{
			xaxis[i]=xaxis[i];
			yaxis[i]=yaxis[i]-tanvalue*xaxis[i];
		}
		line(xaxis[0],yaxis[0],xaxis[1],yaxis[1]);
		line(xaxis[1],yaxis[1],xaxis[5],yaxis[5]);
		line(xaxis[5],yaxis[5],xaxis[4],yaxis[4]);
		line(xaxis[4],yaxis[4],xaxis[0],yaxis[0]);
		line(xaxis[0],yaxis[0],xaxis[2],yaxis[2]);
		line(xaxis[2],yaxis[2],xaxis[3],yaxis[3]);
		line(xaxis[3],yaxis[3],xaxis[1],yaxis[1]);
		line(xaxis[4],yaxis[4],xaxis[6],yaxis[6]);
		line(xaxis[6],yaxis[6],xaxis[7],yaxis[7]);
		line(xaxis[5],yaxis[5],xaxis[7],yaxis[7]);
		line(xaxis[2],yaxis[2],xaxis[6],yaxis[6]);
		line(xaxis[3],yaxis[3],xaxis[7],yaxis[7]);
		line(xaxis[2],yaxis[2],xaxis[8],yaxis[8]);
		line(xaxis[3],yaxis[3],xaxis[8],yaxis[8]);
		line(xaxis[6],yaxis[6],xaxis[9],yaxis[9]);
		line(xaxis[7],yaxis[7],xaxis[9],yaxis[9]);
		line(xaxis[8],yaxis[8],xaxis[9],yaxis[9]);
	}
	else if(choice==1)
	{
		int i;
		for(i=0;i<10;i++)
		{
			xaxis[i]=+yaxis[i]*tanvalue+xaxis[i];
			yaxis[i]=yaxis[i];
		}
		line(xaxis[0],yaxis[0],xaxis[1],yaxis[1]);
		line(xaxis[1],yaxis[1],xaxis[5],yaxis[5]);
		line(xaxis[5],yaxis[5],xaxis[4],yaxis[4]);
		line(xaxis[4],yaxis[4],xaxis[0],yaxis[0]);
		line(xaxis[0],yaxis[0],xaxis[2],yaxis[2]);
		line(xaxis[2],yaxis[2],xaxis[3],yaxis[3]);
		line(xaxis[3],yaxis[3],xaxis[1],yaxis[1]);
		line(xaxis[4],yaxis[4],xaxis[6],yaxis[6]);
		line(xaxis[6],yaxis[6],xaxis[7],yaxis[7]);
		line(xaxis[5],yaxis[5],xaxis[7],yaxis[7]);
		line(xaxis[2],yaxis[2],xaxis[6],yaxis[6]);
		line(xaxis[3],yaxis[3],xaxis[7],yaxis[7]);
		line(xaxis[2],yaxis[2],xaxis[8],yaxis[8]);
		line(xaxis[3],yaxis[3],xaxis[8],yaxis[8]);
		line(xaxis[6],yaxis[6],xaxis[9],yaxis[9]);
		line(xaxis[7],yaxis[7],xaxis[9],yaxis[9]);
		line(xaxis[8],yaxis[8],xaxis[9],yaxis[9]);
	}
	setcolor(15);
}


int main()
{
float xaxis[10];
float yaxis[10];
float xaxis1[10];
float yaxis1[10];
float length=100;
float x=100;
float y=285;
float root=length/1.414;
float angle;
int choice;
int dist;
int degrees;
printf("Choose axis\n1.X-axis\n2.Y-axis\n");
scanf("%d",&choice);
printf("Enter angle of shear in degrees\n");
scanf("%d",&degrees);
angle=(PI/180)*degrees;
if(choice==1)
{
	length=100;
	y=285;
	dist=310;
}
else
{
	y=400;
	dist=350;
}
int gd=DETECT,gm=0;
initgraph(&gd,&gm,"");
//initwindow(800,800,"",0,0,false,true);
xaxis[0]=x;
yaxis[0]=y;
xaxis[1]=x+length;
yaxis[1]=y;
xaxis[2]=x;
yaxis[2]=y-length;
xaxis[3]=x+length;
yaxis[3]=y-length;
xaxis[4]=x+(root);
yaxis[4]=y-(root);
xaxis[5]=x+root+length;
yaxis[5]=y-root;
xaxis[6]=x+root;
yaxis[6]=y-length-root;
xaxis[7]=x+length+root;
yaxis[7]=y-length-root;
xaxis[8]=xaxis[2]+(length*cos(PI/3));
yaxis[8]=yaxis[2]-(length*sin(PI/3));
xaxis[9]=xaxis[6]+(length*cos(PI/3));
yaxis[9]=yaxis[6]-(length*sin(PI/3));
draw3Dhouse(xaxis,yaxis,length);
reflect(xaxis,yaxis,dist,choice);
getch();
cleardevice();
xaxis1[0]=x;
yaxis1[0]=y;
xaxis1[1]=x+length;
yaxis1[1]=y;
xaxis1[2]=x;
yaxis1[2]=y-length;
xaxis1[3]=x+length;
yaxis1[3]=y-length;
xaxis1[4]=x+(root);
yaxis1[4]=y-(root);
xaxis1[5]=x+root+length;
yaxis1[5]=y-root;
xaxis1[6]=x+root;
yaxis1[6]=y-length-root;
xaxis1[7]=x+length+root;
yaxis1[7]=y-length-root;
xaxis1[8]=xaxis1[2]+(length*cos(PI/3));
yaxis1[8]=yaxis1[2]-(length*sin(PI/3));
xaxis1[9]=xaxis1[6]+(length*cos(PI/3));
yaxis1[9]=yaxis1[6]-(length*sin(PI/3));
draw3Dhouse(xaxis1,yaxis1,length);
shear(xaxis1,yaxis1,choice,angle);
getch();
closegraph();
}