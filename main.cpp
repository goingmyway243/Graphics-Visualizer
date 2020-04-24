#include <iostream>
#include <graphics.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#define Round(a) (int)(a+0.5)   // lam tron so
#define max(a,b) (a>b)?a:b
#define DELAY 10
#include <conio.h>
#include <time.h>
using namespace std ;
int color = YELLOW;
   
void lineDDA(int x1, int y1, int x2, int y2){       // thuat toan DDA
    int Dx=x2-x1, Dy=y2-y1;
    float x_inc, y_inc;
    float step=max(abs(Dx),abs(Dy));
    x_inc=Dx/step;
    y_inc=Dy/step;
    float x=x1, y=y1;
    putpixel(x,y,color);
    
    int k=1;
    while(k<=step)
    {
    	k++;
    	//delay(10);
    	x+=x_inc;
    	y+=y_inc;
    	//cout<<"x= "<<x<<"y= "<<y<<endl;
    	putpixel(x,y,color);
	}
}
int main(){
	srand(time(NULL));
    int gd=DETECT, gm;
    initgraph(&gd,&gm,NULL);
    setcolor(9);
    settextstyle(7,0,5);
    outtextxy(100,20,"Hello World");
    
    setcolor(YELLOW);
    setlinestyle(2,0,1);
    lineDDA(10,10,getmaxx()-10,10);
    setlinestyle(1,0,1);
    line(10,10,10,getmaxy()-10);
    setlinestyle(3,0,1);
    line(10,getmaxy()-10,getmaxx()-10,getmaxy()-10);
    setlinestyle(4,0x1111,1);
    line(getmaxx()-10,getmaxy()-10,getmaxx()-10,10);
    setcolor(WHITE);
    int i=0;
    while(i<=100)
    {
    	putpixel(rand()%(getmaxx()-10-11+1)+11,rand()%(getmaxy()-10-11+1)+11,WHITE);
    	i++;
    	delay(10);
	}
    getch();
    return 0;
}
