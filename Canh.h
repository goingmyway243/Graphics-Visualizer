#pragma once

#include "CTDL.h"
#include "Dinh.h"
#include "Matran.h"
#include "Linhtinh.h"

//=============Prototype==========
void DrawCanh(int x, int y, int a, int b);
void DrawTriangle(int x1, int y1, int x2, int y2, int color);
void DrawArrow(int x1, int y1, int x2, int y2, int color);
void DrawCurvedLine(int x1, int y1, int x2, int y2, int color);
int Trongso(int x, int y);

bool IsDinh(int x,int y);
bool IsDinhSS(int x, int y, Toado a);
string Delete_char(string s);
void ReDraw();
void Dinhcolor(Toado a, int color);
void TextLog(int color);
//============Canh==============
void DrawCanh(int x, int y, int a, int b)
{
	int tmp1,tmp2;
	for(int i=0;i<n;i++)
	{
		if(IsDinhSS(x,y,dothi[i]))
		{
			tmp1=i;
		}
		else if(IsDinhSS(a,b,dothi[i]))
		{
			tmp2=i;
		}
	}
	Dinhcolor(dothi[tmp2],VARCOLOR);
	if(matrix[tmp2][tmp1]==0 || matrix[tmp1][tmp2]!=0)//neu chua co cung nao giua 2 canh hoac ve lai cung thi xu ly
	{
		if(matrix[tmp2][tmp1]==0 || nguocchieu[tmp1][tmp2]==false)
		{
			DrawArrow(dothi[tmp1].x,dothi[tmp1].y,dothi[tmp2].x,dothi[tmp2].y,RED);
			matrix[tmp1][tmp2]=Trongso((dothi[tmp1].x+dothi[tmp2].x)/2,(dothi[tmp1].y+dothi[tmp2].y)/2);
		}
		else
		{
			goto am;
		}
	}
	else
	{
		am:	
		int x1=dothi[tmp1].x, y1=dothi[tmp1].y, x2=dothi[tmp2].x, y2=dothi[tmp2].y;
		float xO = (x1 + x2) / 2 + (y1 - y2) / -M_SQRT2;
		float yO = (y1 + y2) / 2 + (x2 - x1) / -M_SQRT2; 
		float r = sqrt(pow(xO - x1, 2) + pow(yO - y1, 2));
		float theta = atan2((y1 + y2) / 2 - yO, (x1 + x2) / 2 - xO);
		float xT = xO + r * cos(theta);
		float yT = yO + r * sin(theta);
	
		DrawCurvedLine(dothi[tmp1].x,dothi[tmp1].y,dothi[tmp2].x,dothi[tmp2].y,LIGHTRED);
		matrix[tmp1][tmp2]=Trongso(xT,yT);
		nguocchieu[tmp1][tmp2]=true;
				//ReDraw();
	}
			
	if(matrix[tmp1][tmp2]==0 || matrix[tmp1][tmp2]==matrix[tmp2][tmp1])
	{
		ReDraw();
	}
	//clearmouseclick(WM_LBUTTONUP);
			
	for(int i=0;i<n;i++)
	{
		if(IsDinhSS(x,y,dothi[i]) || IsDinhSS(a,b,dothi[i]))
		{
			Dinhcolor(dothi[i],CIRCLECOLOR);
		}
	}
	DrawMatrix();
}

//==========================
void DrawTrianle(int x1, int y1, int x2, int y2, int color)
{
	setlinestyle(1, 0, 2);
	setfillstyle(1, color);
	int a[8]={x1+y2-y1, y1+x1-x2, x1-y2+y1, y1-x1+x2, x2, y2, x1+y2-y1, y1+x1-x2};
	setcolor(color);
	fillpoly(4, a);
}
void DrawArrow(int x1, int y1, int x2, int y2, int color)
{
	float corner = atan(float(abs(y1 - y2)) / abs(x1 - x2));
	float Rsin = BK * sin(corner);
	float Rcos = BK * cos(corner);
	int x11 = x1 + Rcos;
	int y11 = y1 + Rsin;
	int x22 = x2 - Rcos;
	int y22 = y2 - Rsin;
	if (x1 > x2)
	{
		x11 = x1 - Rcos;
		x22 = x2 + Rcos;
	}
	if (y1 > y2)
	{
		y11 = y1 - Rsin;
		y22 = y2 + Rsin;
	}
	setlinestyle(1, 1, 2);
	setcolor(color);
	line(x11, y11, x22, y22);
	DrawTrianle(2 * x22 - (x2 + x22) / 2, 2 * y22 -(y22 + y2) / 2, x22, y22, color);
}
void DrawCurvedLine(int x1, int y1, int x2, int y2, int color)
{
	float xO = (x1 + x2) / 2 + (y1 - y2) / -M_SQRT2; //Tam cua cung tron
	float yO = (y1 + y2) / 2 + (x2 - x1) / -M_SQRT2; 
	float r = sqrt(pow(xO - x1, 2) + pow(yO - y1, 2)); // BKcung <=> khoang cach dinh dau-> BK
	//float d = sqrt(pow(x1 - xO, 2) + pow(y1 - yO, 2));
	float a = (pow(r, 2) - pow(BK, 2) + pow(r ,2)) / (2 * r);
	float h = sqrt(r * r - a * a);							//					 
	float tmpx1 = xO + a * (x1 - xO) / r;					//					   xT		  
	float tmpx2 = xO + a * (x2 - xO) / r;					//        *  * x3             x4*  *
	float tmpy1 = yO + a * (y1 - yO) / r;					//     *        *            *        *
	float tmpy2 = yO + a * (y2 - yO) / r;					//    *    x1    *          *     x2   *
	int x3 = tmpx1 + h* (y1 - yO) / r;   // -h				//    *          *          *          *
	int x4 = tmpx2 - h* (y2 - yO) / r;   // +h				//     *        *            *        *
	int y3 = tmpy1 - h * (x1 - xO) / r;  					//        *  *                  *  *
	int y4 = tmpy2 + h * (x2 - xO) / r;  					//				 	   xO          
	float stangle, endangle;								//					 
	float angle1 = float(x1 - xO) / r;
	float angle2 = 1 - float(pow(BK, 2)) / (2 * pow(r, 2));
	if (angle1 < -1 || angle1 > 1) angle1 = int(angle1);
	if (angle2 < -1 || angle2 > 1) angle2 = int(angle2);
	angle1 = acos(angle1) * 180 / M_PI;
	angle2 = acos(angle2) * 180 / M_PI;
	if (y1 >= yO) angle1 = 360 - angle1;
	stangle = angle1 + angle2;
	angle1 = acos(1 - pow(sqrt(pow(x3 - x4, 2) + pow(y3 - y4, 2)), 2) / (2 * pow(r, 2)));
	angle1 = angle1 * 180 / M_PI;
	endangle = stangle + angle1; 
	float theta = atan2((y1 + y2) / 2 - yO, (x1 + x2) / 2 - xO);//??
	float xT = xO + r * cos(theta);//Tam trong so
	float yT = yO + r * sin(theta);
	setcolor(color);
	setlinestyle(1, 1, 2);
	arc(xO, yO, stangle, endangle, r);
	DrawTrianle(2 * x4 - (x2 + x4) / 2, 2 * y4 - (y2 + y4) / 2, x4, y4, color); // FINALY
}
//===============================

int Trongso(int x, int y)
{
	int ts;
	string tmp;
	char c;
	int i=0;
	
	TextLog(TEXTCOLOR);
	outtextxy(XLOG,getmaxy()/(2)+190,"Nhap trong so (0-99): ");

	setfillstyle(1,BKCOLOR);
	bar(x-10,y-15,x+10,y);
	setcolor(MENUTEXTCOLOR);
	setbkcolor(BKCOLOR);
	settextstyle(8,0,1);
	settextjustify(1,1);
	outtextxy(x,y,"|");
	
	do{
		while(!kbhit());
		fflush(stdin);
		c=getch();
		setcolor(MENUTEXTCOLOR);
		setbkcolor(BKCOLOR);
		settextstyle(8,0,1);
		settextjustify(1,1);
		if(i<2 && (c>=48 && c<=57))
		{
			i++;
			tmp+=c;
		}
		else if(c==8 && i>0)
		{
			i--;
			tmp= Delete_char(tmp);
			setfillstyle(1,BKCOLOR);
			bar(x-10,y-15,x+10,y);
			bar(1060,getmaxy()/(2)+190,1080,getmaxy()/(2)+210);
			//To de len chu khong biet xoa dung nghia ~
			if(i==0)
			{
				outtextxy(x,y,"|");
			}
		}
		setfillstyle(1,BKCOLOR);
		bar(x-10,y,x+10,y+5);
		outtextxy(x,y,&tmp[0]);
		TextLog(VARCOLOR);
		settextstyle(3,0,1);
		outtextxy(1060,getmaxy()/(2)+190,&tmp[0]);
	}while(c!=13 || i==0);
	ts=atoi(&tmp[0]);
	return ts;
}
