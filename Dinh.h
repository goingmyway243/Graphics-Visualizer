#pragma once

#include "CTDL.h"
#include "Linhtinh.h"
#include "Matran.h"
#include "Giaodien.h"
#include "Canh.h"

//============Prototype=========
void Dinhcolor(Toado a, int color);
bool IsDinhDraw(int x,int y);
bool IsDinh(int x,int y);
bool IsDinhSS(int x, int y, Toado a);
int PickDinh(int x, int y);
char* TenDinh(int vt);
void XulyDinh(int mode);
void DrawDinh(Toado a);
void DeleteDinh();


float Khoangcach(int x1, int y1, int x2, int y2);
string Delete_char(string s);
void ReDrawDinh();
void ReDrawCanh();
//============Dinh==============
void Dinhcolor(Toado a, int color)//doi mau dinh
{
	setfillstyle(1,color);
	setcolor(color);
	arc(a.x,a.y,0,360,BK);
	pieslice(a.x,a.y,0,360,BK);
	setcolor(TEXTDINH);
	setbkcolor(color);
	settextjustify(1,1);
	settextstyle(1,0,1);
	outtextxy(a.x,a.y+5,a.name);		
}

bool IsDinhDraw(int x,int y)//Check xem toa do x,y co trung voi dinh da ve hay khong
{
	for(int i=0;i<n;i++)
	{
		if (Khoangcach(x,y,dothi[i].x,dothi[i].y)<=2*BK)
		{
			return true;
		}
	}
	return false;
}

bool IsDinh(int x,int y)//Check xem toa do x,y co trung voi dinh da ve hay khong
{
	for(int i=0;i<n;i++)
	{
		if (Khoangcach(x,y,dothi[i].x,dothi[i].y)<=BK)
		{
			return true;
		}
	}
	return false;
}

bool IsDinhSS(int x, int y, Toado a)
{
	for(int i=0;i<n;i++)
	{
		if (Khoangcach(x,y,a.x,a.y)<=BK)
		{
			return true;
		}
	}
	return false;
}

int PickDinh(int x, int y)
{
	for(int i=0;i<n;i++)
	{
		if(IsDinhSS(x,y,dothi[i]))
		{
			return i;
		}
	}
}

char* TenDinh(int vt)
{
	char* name=new char[2];
	string s;
	char c;
	int i=0;
	setfillstyle(1,CIRCLECOLOR);
	setcolor(CIRCLECOLOR);
	pieslice(dothi[vt].x,dothi[vt].y,0,360,BK);
	setcolor(TEXTDINH);
	setbkcolor(CIRCLECOLOR);
	settextstyle(1,0,1);
	settextjustify(1,1);
	outtextxy(dothi[vt].x,dothi[vt].y+5,"|");
	
	TextLog(VARCOLOR);
	outtextxy(1120,getmaxy()/2+100,"|");
	
	ad:
	do{
		while(!kbhit());
		fflush(stdin);
		c=getch();
		if(i<2 && ((c>=48 && c<=57) || (c>=65 && c<=90) || (c>=97 && c<=122)))
		{
			i++;
			s+=c;
		}
		else if(c==8 && i>0)
		{
			i--;
			s= Delete_char(s);
			//To de len chu khong biet xoa dung nghia ~
			setfillstyle(1,CIRCLECOLOR);
			setcolor(CIRCLECOLOR);
			pieslice(dothi[vt].x,dothi[vt].y,0,360,BK);
			setcolor(TEXTDINH);
			if(i==0)
			{
				setbkcolor(CIRCLECOLOR);
				settextstyle(1,0,1);
				settextjustify(1,1);
				outtextxy(dothi[vt].x,dothi[vt].y+5,"|");
			}
		}
		strcpy(name,&s[0]);
		setcolor(TEXTDINH);
		setbkcolor(CIRCLECOLOR);
		settextstyle(1,0,1);
		settextjustify(1,1);
		outtextxy(dothi[vt].x,dothi[vt].y+5,&s[0]);
		
		TextLog(VARCOLOR);
		setfillstyle(1,BKCOLOR);
		bar(1120,getmaxy()/2+100,1150,getmaxy()/2+130);
		outtextxy(1120,getmaxy()/2+100,&s[0]);
	}while(c!=13 || i==0);
	
	for(int i=0;i<n;i++)//check trung ten
	{
		if(i==vt)
		{
			continue;
		}
		if(dothi[i].name==s)
		{
			ClearLog();
			TextLog(TEXTCOLOR2);
			outtextxy(XLOG,getmaxy()/(2)+100,"Ten dinh bi trung, vui long nhap ten khac");
			getch();
			ClearLog();
			TextLog(TEXTCOLOR);
			outtextxy(XLOG,getmaxy()/(2)+100,"Nhap ten dinh (toi da 2 ki tu): ");
			setcolor(VARCOLOR);
			outtextxy(1120,getmaxy()/2+100,&s[0]);
			goto ad;
		}
	}
	return name;
}

void XulyDinh(int mode)
{
	while(dk==true)
	{
		delay(DELAY);
		switch(mode)
		{
			case 1://dinh
				{
					Clearmouse();
					setfillstyle(1,BKCOLOR);
					bar(780,90,850,370);
					setfillstyle(1,MENUBKCOLOR);
					bar(782,92,848,158);
					menuedit();
					LogDinh();
					while(1)
					{
						delay(DELAY);
						if(ismouseclick(WM_LBUTTONDOWN))
						{
							int x,y;
							getmouseclick(WM_LBUTTONDOWN,x,y);
							if(!IsDinhDraw(x,y) && ((x>11+BK&&x<780-BK && y>90+BK&&y<getmaxy()-10-BK)||(x>11+BK&&x<850-BK && y>370+BK&&y<getmaxy()-10-BK)) && n<11)
							{
								clearmouseclick(WM_RBUTTONUP);
								setfillstyle(1,CIRCLECOLOR);
								setcolor(CIRCLECOLOR);
								pieslice(x,y,0,360,BK);
								dothi[n].x=x;
								dothi[n].y=y;
								dothi[n].name=new char[2];
								ClearLog();
								TextLog(TEXTCOLOR);
								settextstyle(3,0,2);
								outtextxy(XLOG,getmaxy()/(2)+100,"Nhap ten dinh (toi da 2 ki tu): ");
								dothi[n].name=TenDinh(n);
								ClearLog();
								LogDinh();
								for(int i=0;i<=n;i++)
								{
									matrix[i][n]=0;
									matrix[n][i]=0;
								}
								n++;
								DrawMatrix();
								//break;
							}
							if(x>=10&&x<=850 && y>=10&&y<=90)//bam ra ngoai thi thoat vong lap
							{
								dk=false;
								break;
							}
							if(x>=780&&x<=850 && y>=160&&y<=230)
							{
								mode=2;
								break;
							}
							if(x>=780&&x<=850 && y>=230&&y<=300)
							{
								mode=3;
								break;
							}
							if(x>=780&&x<=850 && y>=300&&y<=370)
							{
								mode=4;
								break;
							}
						}
						DeleteDinh();
						if(kbhit())
						{
							char c=getch();
							if(c==27)//ESC
							{
								dk=false;
								break;
							}
						}	
					}
					ClearLog();
					break;
				}
			case 2://canh keo tha
				{
					Clearmouse();
					setfillstyle(1,BKCOLOR);
					bar(780,90,850,370);
					setfillstyle(1,MENUBKCOLOR);
					bar(782,162,848,228);
					menuedit();
					if(n<2)
					{
						TextLog(TEXTCOLOR2);
						outtextxy(XLOG,getmaxy()/(2)+100,"Khong co du dinh de thuc hien chuc nang");
						outtextxy(XLOG,getmaxy()/(2)+130,"...Nhan phim bat ki de tiep tuc...");
						getch();
						ClearLog();
						mode=1;
						break;
					}
					LogCanh();
					int x,y,a,b,tmp1=-1,tmp2=-1;
					while(1)
					{
						delay(DELAY);
						if(ismouseclick(WM_LBUTTONDOWN))
						{
							getmouseclick(WM_LBUTTONDOWN,x,y);
							if(IsDinh(x,y))
							{
								tmp1=PickDinh(x,y);
								Dinhcolor(dothi[tmp1],VARCOLOR);
								
								if(ismouseclick(WM_LBUTTONUP))
								{
									clearmouseclick(WM_LBUTTONUP);
								}
								
								while(!ismouseclick(WM_LBUTTONUP))
								{
									delay(100);
									a=mousex();
									b=mousey();
									setfillstyle(1,BKCOLOR);
									bar(12,92,778,getmaxy()-12);
									bar(12,372,848,getmaxy()-12);
									ReDrawDinh();
									ReDrawCanh();
									Dinhcolor(dothi[tmp1],VARCOLOR);
									DrawArrow(x,y,mousex(),mousey(),WHITE);
									if(IsDinh(mousex(),mousey()))
									{
										tmp2=PickDinh(mousex(),mousey());
										if(tmp2==tmp1)
										{
											tmp2=-1;
										}
									}
								}
								setfillstyle(1,BKCOLOR);
								bar(12,92,778,getmaxy()-12);
								bar(12,372,848,getmaxy()-12);
								ReDraw();
								if(tmp2==-1)
								{
									tmp1=-1;
									continue;
								}
								if(IsDinh(a,b) && tmp2!=tmp1)
								{
									TextLog(TEXTCOLOR);
									outtextxy(XLOG,getmaxy()/(2)+160,"Cung (      -      )");
									TextLog(VARCOLOR);
									settextjustify(1,3);
									outtextxy(935,getmaxy()/(2)+160,dothi[tmp1].name);
									outtextxy(970,getmaxy()/(2)+160,dothi[tmp2].name);
									if(matrix[tmp2][tmp1]==0 || matrix[tmp1][tmp2]!=0)//neu chua co cung nao giua 2 canh hoac ve lai cung thi xu ly
									{
										if(matrix[tmp2][tmp1]==0 || nguocchieu[tmp1][tmp2]==false)
										{
											DrawArrow(dothi[tmp1].x,dothi[tmp1].y,dothi[tmp2].x,dothi[tmp2].y,RED);
											ReDrawDinh();
											ReDrawCanh();
											Dinhcolor(dothi[tmp1],VARCOLOR);
											Dinhcolor(dothi[tmp2],VARCOLOR);
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
										ReDrawDinh();
										ReDrawCanh();
										Dinhcolor(dothi[tmp1],VARCOLOR);
										Dinhcolor(dothi[tmp2],VARCOLOR);
										matrix[tmp1][tmp2]=Trongso(xT,yT);
										nguocchieu[tmp1][tmp2]=true;
									}
											
									if(matrix[tmp2][tmp1]==0)
									{
										ReDraw();
									}
											
									for(int i=0;i<n;i++)
									{
										if(IsDinhSS(x,y,dothi[i]) || IsDinhSS(a,b,dothi[i]))
										{
											Dinhcolor(dothi[i],CIRCLECOLOR);
										}
									}
									tmp1=tmp2=-1;
									ClearLog();
									LogCanh();
									ReDraw();
									DrawMatrix();
								}
							}
							if(!IsDinh(x,y));
							if(x>=10&&x<=850 && y>=10&&y<=90 && tmp1==-1)//bam ra ngoai thi thoat vong lap
							{
								dk=false;
								break;
							}
							if(x>=780&&x<=850 && y>=90&&y<=160)
							{
								mode=1;
								break;
							}
							if(x>=780&&x<=850 && y>=230&&y<=300)
							{
								mode=3;
								break;
							}
							if(x>=780&&x<=850 && y>=300&&y<=370)
							{
								mode=4;
								break;
							}
						}
						if(ismouseclick(WM_RBUTTONDOWN))
						{
							int x,y;
							getmouseclick(WM_RBUTTONDOWN,x,y);
							if(x>=780&&x<=850 && y>=160&&y<=230)
							{
								mode=5;
								break;
							}
						}
						if(kbhit())
						{
							char c=getch();
							if(c==27)//ESC
							{
								dk=false;
								break;
							}
						}	
					}
					ClearLog();
					break;
				}
			case 3://di chuyen
				{
					Clearmouse();
					setfillstyle(1,BKCOLOR);
					bar(780,90,850,370);
					setfillstyle(1,MENUBKCOLOR);
					bar(782,232,848,298);
					menuedit();
					if(n==0)
					{
						setcolor(TEXTCOLOR2);
						outtextxy(XLOG,getmaxy()/(2)+100,"Khong co dinh de thuc hien chuc nang");
						outtextxy(XLOG,getmaxy()/(2)+130,"...Nhan phim bat ki de tiep tuc...");
						getch();
						ClearLog();
						mode=1;
						break;
					}
					LogDichuyen();
					
					int tmp=-1;
					while(1)
					{
						delay(DELAY);
						if(ismouseclick(WM_LBUTTONDOWN))
						{
							int x,y;
							getmouseclick(WM_LBUTTONDOWN,x,y);
							if(IsDinh(x,y))
							{
								if(IsDinhSS(x,y,dothi[tmp]) && tmp!=-1)
								{
									Dinhcolor(dothi[tmp],CIRCLECOLOR);
									ClearLog();
									LogDichuyen();
									tmp=-1;
									continue;
								}
								for(int i=0;i<n;i++)
								{
									if(IsDinhSS(x,y,dothi[i]))
									{
										Dinhcolor(dothi[i],VARCOLOR);
										TextLog(VARCOLOR);
										settextstyle(3,0,2);
										outtextxy(1100,getmaxy()/(2)+130,dothi[i].name);
										setcolor(TEXTCOLOR);
										outtextxy(XLOG,getmaxy()/(2)+160,"...Chon vi tri can di chuyen...");
										tmp=i;
										break;
									}
								}
							}
							if(!IsDinh(x,y) && ((x>11+BK&&x<780-BK && y>90+BK&&y<getmaxy()-10-BK)||(x>11+BK&&x<850-BK && y>370+BK&&y<getmaxy()-10-BK)) && tmp!=-1)
							{
								dothi[tmp].x=x;
								dothi[tmp].y=y;
								ClearLog();
								LogDichuyen();
								ReDraw();
								tmp=-1;
							}
							if(x>=10&&x<=850 && y>=10&&y<=90 && tmp==-1)//bam ra ngoai thi thoat vong lap
							{
								dk=false;
								break;
							}
							if(x>=780&&x<=850 && y>=90&&y<=160 && tmp==-1)
							{
								mode=1;
								break;
							}
							if(x>=780&&x<=850 && y>=160&&y<=230)
							{
								mode=2;
								break;
							}
							if(x>=780&&x<=850 && y>=300&&y<=370 && tmp==-1)
							{
								mode=4;
								break;
							}
						}
						if(ismouseclick(WM_RBUTTONDOWN))
						{
							int x,y;
							getmouseclick(WM_RBUTTONDOWN,x,y);
							if(x>=780&&x<=850 && y>=160&&y<=230)
							{
								mode=5;
								break;
							}
						}
						if(kbhit())
						{
							char c=getch();
							if(c==27)//ESC
							{
								dk=false;
								break;
							}
						}	
					}
					ClearLog();
					break;
				}
			case 4://doi ten
				{
					Clearmouse();
					setfillstyle(1,BKCOLOR);
					bar(780,90,850,370);
					setfillstyle(1,MENUBKCOLOR);
					bar(782,302,848,368);
					menuedit();
					if(n==0)
					{
						setcolor(TEXTCOLOR2);
						outtextxy(XLOG,getmaxy()/(2)+100,"Khong co dinh de thuc hien chuc nang");
						outtextxy(XLOG,getmaxy()/(2)+130,"...Nhan phim bat ki de tiep tuc...");
						getch();
						ClearLog();
						mode=1;
						break;
					}
					LogDoiten();
					while(1)
					{
						delay(DELAY);
						if(ismouseclick(WM_LBUTTONDOWN))
						{
							int x,y;
							getmouseclick(WM_LBUTTONDOWN,x,y);
							if(IsDinh(x,y))
							{
								for(int i=0;i<n;i++)
								{
									if(IsDinhSS(x,y,dothi[i]))
									{
										ClearLog();
										Dinhcolor(dothi[i],VARCOLOR);
										TextLog(TEXTCOLOR);
										settextstyle(3,0,2);
										outtextxy(XLOG,getmaxy()/(2)+100,"Nhap ten dinh (toi da 2 ki tu): ");
										dothi[i].name=TenDinh(i);
										ClearLog();
										LogDoiten();
										DrawMatrix();
										break;
									}
								}
							}
							if(x>=10&&x<=850 && y>=10&&y<=90)//bam ra ngoai thi thoat vong lap
							{
								dk=false;
								break;
							}
							if(x>=780&&x<=850 && y>=90&&y<=160)
							{
								mode=1;
								break;
							}
							if(x>=780&&x<=850 && y>=160&&y<=230)
							{
								mode=2;
								break;
							}
							if(x>=780&&x<=850 && y>=230&&y<=300)
							{
								mode=3;
								break;
							}
						}
						if(ismouseclick(WM_RBUTTONDOWN))
						{
							int x,y;
							getmouseclick(WM_RBUTTONDOWN,x,y);
							if(x>=780&&x<=850 && y>=160&&y<=230)
							{
								mode=5;
								break;
							}
						}
						if(kbhit())
						{
							char c=getch();
							if(c==27)//ESC
							{
								dk=false;
								break;
							}
						}	
					}
					ClearLog();
					break;
				}
			case 5://canh chon
				{
					Clearmouse();
					setfillstyle(1,BKCOLOR);
					bar(780,90,850,370);
					setfillstyle(1,MENUBKCOLOR);
					bar(782,162,848,228);
					menuedit();
					if(n<2)
					{
						TextLog(TEXTCOLOR2);
						outtextxy(XLOG,getmaxy()/(2)+100,"Khong co du dinh de thuc hien chuc nang");
						outtextxy(XLOG,getmaxy()/(2)+130,"...Nhan phim bat ki de tiep tuc...");
						getch();
						ClearLog();
						mode=1;
						break;
					}
					LogCanhS();
					int x,y,tmp=-1;
					while(1)
					{
						delay(DELAY);
						if(ismouseclick(WM_LBUTTONDOWN))
						{
							getmouseclick(WM_LBUTTONDOWN,x,y);
							if(IsDinh(x,y))
							{
								if(tmp==-1)
								{
									tmp=PickDinh(x,y);
									Dinhcolor(dothi[tmp],VARCOLOR);
									TextLog(TEXTCOLOR);
									outtextxy(XLOG,getmaxy()/(2)+160,"Chon dinh cuoi...");
								}
								else
								{
									if(IsDinhSS(x,y,dothi[tmp]))
									{
										Dinhcolor(dothi[tmp],CIRCLECOLOR);
										tmp=-1;
										ClearLog();
										LogCanhS();
									}
									else
									{
										DrawCanh(dothi[tmp].x,dothi[tmp].y,x,y);
										ClearLog();
										LogCanhS();
										tmp=-1;
									}
								}
							}
							if(!IsDinh(x,y) && tmp!=-1)
							{
								Dinhcolor(dothi[tmp],CIRCLECOLOR);
								tmp=-1;
								ClearLog();
								LogCanhS();
							}
							if(x>=10&&x<=850 && y>=10&&y<=90)//bam ra ngoai thi thoat vong lap
							{
								dk=false;
								break;
							}
							if(x>=780&&x<=850 && y>=90&&y<=160)
							{
								mode=1;
								break;
							}
							if(x>=780&&x<=850 && y>=160&&y<=230)
							{
								mode=2;
								break;
							}
							if(x>=780&&x<=850 && y>=230&&y<=300)
							{
								mode=3;
								break;
							}
							if(x>=780&&x<=850 && y>=300&&y<=370)
							{
								mode=4;
								break;
							}
						}
						if(kbhit())
						{
							char c=getch();
							if(c==27)//ESC
							{
								dk=false;
								break;
							}
						}	
					}
					ClearLog();
					break;
				}
		}
	}
}

void DeleteDinh()
{
	if(ismouseclick(WM_RBUTTONDBLCLK))
	{
		int x,y;
		getmouseclick(WM_RBUTTONDBLCLK,x,y);
		if(IsDinh(x,y))
		{
			for(int i=0;i<n;i++)
			{
				if (Khoangcach(x,y,dothi[i].x,dothi[i].y)<=BK)
				{
					setfillstyle(1,BKCOLOR);
					setcolor(BKCOLOR);
					pieslice(dothi[i].x,dothi[i].y,0,360,BK+2);
						
					for(int j=0;j<=n;j++)
					{
						for(int k=i;k<n;k++)
						{
							matrix[k][j]=matrix[k+1][j];
						}
					}
					for(int j=0;j<n;j++)
					{
						for(int k=i;k<n;k++)
						{
							matrix[j][k]=matrix[j][k+1];
						}
					}
					for(int j=i;j<n;j++)
					{
						dothi[j]=dothi[j+1];
					}
					delete dothi[n-1].name;
					n--;
					ReDraw();
					DrawMatrix();
					break;
				}
			}
		}
	}
}

