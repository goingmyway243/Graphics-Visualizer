#pragma once

#include "CTDL.h"

using namespace std;

//=========Prototype==========
void DrawMatrix();
bool IsVohuong();
//==========================
void DrawMatrix()
{
	setfillstyle(1,BKCOLOR);
	bar(851,91,getmaxx()-11,getmaxy()/2+49);
	settextjustify(1,1);
	for(int i=0;i<n;i++)
	{
		settextstyle(1,0,1);
		setbkcolor(BKCOLOR);
		setcolor(TEXTCOLOR);
		outtextxy(870+(BK+10)*(i+1),110,dothi[i].name);
		outtextxy(870,110+BK*(i+1),dothi[i].name);
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			setcolor(MENUTEXTCOLOR);
			stringstream ss;
			ss << matrix[i][j];
			string str = ss.str();
			outtextxy(870+(BK+10)*(j+1),110+BK*(i+1),&str[0]);
		}
	}
	
	settextstyle(1,0,1);
	setcolor(LIGHTGREEN);
	if(IsVohuong())
	{
		
		outtextxy(1050,70,"Do thi vo huong");
	}
	else
	{
		outtextxy(1050,70,"Do thi co huong");
	}
}

bool IsVohuong()
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(matrix[i][j]!=matrix[j][i])
			{
				return false;
			}
		}
	}
	return true;
}
