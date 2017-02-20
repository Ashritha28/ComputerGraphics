#include <stdio.h>
#include <graphics.h>
#include <math.h>

float edgeLeft=200,edgeRight=500,edgeBottom=300,edgeTop=100;
float x0clip, y0clip, x1clip, y1clip;

int LiangBarsky (float x0src, float y0src, float x1src, float y1src)
{
	float t0 = 0.0;    
	float t1 = 1.0;
    float xdelta = x1src-x0src;
    float ydelta = y1src-y0src;
    float p,q,r;
    int result=0;
    int edge;
    for(edge=0; edge<4; edge++) {   // Traverse through left, right, bottom, top edges.
        if (edge==0) {  p = -xdelta;    q = -(edgeLeft-x0src);  }
        if (edge==1) {  p = xdelta;     q =  (edgeRight-x0src); }
        if (edge==2) {  p = -ydelta;    q = (edgeBottom-y0src);}
        if (edge==3) {  p = ydelta;     q = - (edgeTop-y0src);   }   
        r = q/p;
        if(p==0 && q<0) return 0;   // Don't draw line at all. (parallel line outside)

        if(p<0) {
            if(r>t1) return 0;         // Don't draw line at all.
            else if(r>t0) t0=r;            // Line is clipped!
        } else if(p>0) {
            if(r<t0) return 0;      // Don't draw line at all.
            else if(r<t1) t1=r;         // Line is clipped!
        }
    }

    x0clip = x0src + t0*xdelta;
    y0clip = y0src + t0*ydelta;
    x1clip = x0src + t1*xdelta;
    y1clip = y0src + t1*ydelta;
    return 1;        // (clipped) line is drawn
}

int main()
{
	float x0,y0,x1,y1;
	printf("Enter the co-ordinates of the line\n");
	scanf("%f",&x0);
	scanf("%f",&y0);
	scanf("%f",&x1);
	scanf("%f",&y1);
	int result;
	int gd=DETECT,gm=0;
	initgraph(&gd,&gm,"");
	result = LiangBarsky(x0,y0,x1,y1);
	rectangle(edgeLeft,edgeTop,edgeRight,edgeBottom);
	line(x0,y0,x1,y1);
	getch();
	if(result==1)
	{
		cleardevice();
		rectangle(edgeLeft,edgeTop,edgeRight,edgeBottom);
		line(x0clip,y0clip,x1clip,y1clip);
	}
	if (result==0)
	{
		cleardevice();
		rectangle(edgeLeft,edgeTop,edgeRight,edgeBottom);
	}

	getch();
	closegraph();

}