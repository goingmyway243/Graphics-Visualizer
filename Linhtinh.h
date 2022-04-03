#pragma once

#include "CTDL.h"
#include "Dinh.h"
#include "Canh.h"
#include "Giaodien.h"
#include "Matran.h"

//=========Prototype===========
void InitMatrix(int n);
void ReInit(void);
void TextLog(int color);
void swap(Toado &a1, Toado &a2);
void swapint(int &a,int &b);
float Khoangcach(int x1, int y1, int x2, int y2);
string Delete_char(string s);
void DeleteDothi();
void ReDrawDinh();
void ReDrawCanh();
void ReDrawMenu();
void ReDraw();
void DrawError();
void DrawLineFile();
void DrawLineAlg();
char* TenFile();
void SaveDothi();
void LoadDothi();
//===========================
void XuatKq(int kq[],int  &sl,int &yy)
{
	int xx=XLOG;
	if(sl!=0)
	{
	for(int i=0;i<sl;i++)
	{
		outtextxy(xx,yy,dothi[kq[i]].name);
		xx+=20;
	}
	}
}

/*void InitMatrix(int n)
{
	matrix=new int*[n];
	for(int i=0;i<n;i++)
	{
		matrix[i]=new int[n];
	}
}*/

void ReInit(void)
{
	for(int i=0;i<n;i++)
	{
		chuaxet[i]=TRUE;
	}
}

void TextLog(int color)
{
	setcolor(color);
	setbkcolor(BKCOLOR);
	settextjustify(0,2);
	settextstyle(3,0,2);
}

void swapint(int &a,int &b)
{
	int tmp;
	tmp=a;
	a=b;
	b=tmp;
}

string Delete_char(string s)//Xoa bang cach xuat ra cac ki tu truoc ki tu cuoi
{
	string a = "";
	for (int i = 0; i < s.length() - 1; i++)
	{
		a += s[i];
	}	
	return a;
}

float Khoangcach(int x1, int y1, int x2, int y2)
{
	float distance = sqrt(pow((x2-x1),2)+pow((y2-y1),2));
	return distance;
}

void DeleteDothi()
{
	for(int i=0;i<=n;i++)
	{
		delete[] dothi[i].name;
		for(int j=0;j<n;j++)
		{
			matrix[i][j]=0;
		}
	}
	n=0;
}

void DrawLineFile()
{
	setcolor(MENUCOLOR);
	setfillstyle(1,BKCOLOR);
	bar(29,81,231,321);
	setlinestyle(1,0,2);
	line(10,90,getmaxx()-10,90);
	setlinestyle(0,0,1);
}
void DrawLineAlg()
{
	setcolor(MENUCOLOR);
	setfillstyle(1,BKCOLOR);
	bar(229,81,631,351);
	setlinestyle(1,0,2);
	line(10,90,getmaxx()-10,90);
	setlinestyle(0,0,1);
}

void ReDrawDinh()
{
	for(int i=0;i<n;i++)
	{
		Dinhcolor(dothi[i],CIRCLECOLOR);		
	}
}

void ReDrawCanh()
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(matrix[i][j]!=0)
			{
				if(matrix[j][i]==0)
				{
					DrawArrow(dothi[i].x,dothi[i].y,dothi[j].x,dothi[j].y,RED);
					nguocchieu[i][j]=false;
					setcolor(MENUTEXTCOLOR);
					setbkcolor(BKCOLOR);
					int dx=(dothi[i].x+dothi[j].x)/2;
					int dy=(dothi[i].y+dothi[j].y)/2;
					settextstyle(8,0,1);
					settextjustify(1,1);
					stringstream ss;
					ss<<matrix[i][j];
					string str=ss.str();
					outtextxy(dx,dy,&str[0]);
				}
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			if(matrix[i][j]!=0 && matrix[j][i]!=0)
			{
				int dx=(dothi[i].x+dothi[j].x)/2;
				int dy=(dothi[i].y+dothi[j].y)/2;
				if(matrix[i][j]==matrix[j][i] && IsVohuong())
				{
					setcolor(RED);
					setlinestyle(1,0,2);
					line(dothi[i].x,dothi[i].y,dothi[j].x,dothi[j].y);
					setcolor(MENUTEXTCOLOR);
					setbkcolor(BKCOLOR);
					settextstyle(8,0,1);
					settextjustify(1,1);
					stringstream ss;
					ss<<matrix[i][j];
					string str=ss.str();
					outtextxy(dx,dy,&str[0]);
					continue;
				}
				DrawArrow(dothi[i].x,dothi[i].y,dothi[j].x,dothi[j].y,RED);
				nguocchieu[j][i]=false;
				setcolor(MENUTEXTCOLOR);
				setbkcolor(BKCOLOR);
				settextstyle(8,0,1);
				settextjustify(1,1);
				stringstream ss;
				ss<<matrix[i][j];
				string str=ss.str();
				outtextxy(dx,dy,&str[0]);
					
				DrawCurvedLine(dothi[j].x,dothi[j].y,dothi[i].x,dothi[i].y,LIGHTRED);
				nguocchieu[j][i]=true;
				int x1=dothi[j].x, y1=dothi[j].y, x2=dothi[i].x, y2=dothi[i].y;
				float xO = (x1 + x2) / 2 + (y1 - y2) / -M_SQRT2;
				float yO = (y1 + y2) / 2 + (x2 - x1) / -M_SQRT2; 
				float r = sqrt(pow(xO - x1, 2) + pow(yO - y1, 2));
				float theta = atan2((y1 + y2) / 2 - yO, (x1 + x2) / 2 - xO);
				float xT = xO + r * cos(theta);
				float yT = yO + r * sin(theta);
				
				settextstyle(8,0,1);
				settextjustify(1,1);
				setcolor(MENUTEXTCOLOR);
				setbkcolor(BKCOLOR);
				stringstream ss1;
				ss1<<matrix[j][i];
				string str1=ss1.str();
				outtextxy(xT,yT,&str1[0]);
			}
		}
	}
}

void ReDrawMenu()
{
	setfillstyle(1,BKCOLOR);
	bar(0,91,779,getmaxy());
	bar(0,371,849,getmaxy());
	setcolor(MENUCOLOR);
	setlinestyle(1,0,2);
	rectangle(10,10,getmaxx()-10,getmaxy()-10);
	line(850,10,850,getmaxy()-10);
}

void ReDraw()
{
	ReDrawMenu();
	ReDrawCanh();
	ReDrawDinh();
}

void DrawError()
{
	setlinestyle(1,0,3);
	setcolor(RED);
	setfillstyle(1,BKCOLOR);
	
	arc(420,400,0,360,250);
	//line(200,200,640,600);
	//line(640,200,200,600);
	setcolor(LIGHTRED);
	arc(420,550,0,180,70);
	//line(350,500,490,550);
	circle(550,300,BK);
	circle(290,300,BK);
	line(250,275,320,250);
	line(590,275,520,250);
}

char* TenFile()
{
	char* name=new char[30];
	string s;
	char c;
	int i=0;
	setcolor(VARCOLOR);
	setbkcolor(BKCOLOR);
	settextjustify(0,2);
	settextstyle(3,0,1);
	outtextxy(900,getmaxy()/(2)+130,"|");
	
	do{
		while(!kbhit());
		fflush(stdin);
		c=getch();
		if(i<30 && ((c>=46 && c<=57) || (c>=65 && c<=90) || (c>=97 && c<=122)))
		{
			i++;
			s+=c;
		}
		else if(c==8 && i>0)
		{
			i--;
			s= Delete_char(s);
			//To de len chu khong biet xoa dung nghia ~
			setfillstyle(1,BKCOLOR);
			bar(XLOG,getmaxy()/(2)+130,getmaxx()-11,getmaxy()/(2)+160);
			setcolor(VARCOLOR);
			if(i==0)
			{
				outtextxy(900,getmaxy()/(2)+130,"|");
			}
		}
		else if(c==27)
		{
			return "!";
		}
		strcpy(name,&s[0]);
		outtextxy(900,getmaxy()/(2)+130,&s[0]);
	}while(c!=13 || i==0);
	return name;
}

void SaveDothi()
{
	if(n==0)
	{
		TextLog(TEXTCOLOR2);
		settextstyle(3,0,3);
		outtextxy(XLOG,getmaxy()/(2)+100,"Khong co du lieu de save!");
		outtextxy(XLOG,getmaxy()/(2)+160,"...Nhan phim bat ki de tiep tuc...");
		DrawError();
		getch();
		ClearLog();
		ReDrawMenu();
		return;
	}
	else
	{
		char* filename;
		fstream File;
		
		setcolor(TEXTCOLOR);
		setbkcolor(BKCOLOR);
		settextjustify(0,2);
		settextstyle(3,0,1);
		outtextxy(XLOG,getmaxy()/(2)+100,"Nhap ten File de save:");
		filename=TenFile();
		
		if(filename=="!")
		{
			ClearLog();
			return;
		}
		File.open(filename,ios::out);
		
		File<<n<<"\n";
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				File<<matrix[i][j]<<" ";
			}
			File<<"\n";
		}
		for(int i=0;i<n;i++)
		{
			File<<dothi[i].name<<"\n";
			File<<dothi[i].x<<" ";
			File<<dothi[i].y<<"\n";
		}
		setcolor(TEXTCOLOR);
		outtextxy(XLOG,getmaxy()/(2)+160,"Da save xong!");
		File.close();
	}
}

void LoadDothi()
{
	char* filename;
	fstream File;
	
	setcolor(TEXTCOLOR);
	setbkcolor(BKCOLOR);
	settextjustify(0,2);
	settextstyle(3,0,1);
	outtextxy(XLOG,getmaxy()/(2)+100,"Nhap ten File de load:");
	filename=TenFile();
	
	if(filename=="!")
	{
		ClearLog();
		return;
	}
	File.open(filename,ios::in);
	
	if(File.fail())
	{
		setcolor(TEXTCOLOR2);
		outtextxy(XLOG,getmaxy()/(2)+160,"Khong tim thay File de load!");
		outtextxy(XLOG,getmaxy()/(2)+190,"...Nhan phim bat ki de tiep tuc...");
		DrawError();
		getch();
		ClearLog();
		ReDrawMenu();
		return;
	}
	File>>n;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			File>>matrix[i][j];
		}
	}
	for(int i=0;i<n;i++)
	{
		dothi[i].name=new char[2];
		File>>dothi[i].name;
		File>>dothi[i].x;
		File>>dothi[i].y;
	}
	setcolor(TEXTCOLOR);
	outtextxy(XLOG,getmaxy()/(2)+160,"Da load xong!");
	ReDraw();
	DrawMatrix();
	File.close();
}
