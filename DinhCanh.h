#pragma once

#include "CTDL.h"
#include "Linhtinh.h"
#include "Matran.h"
#include "Giaodien.h"

//============Prototype=========
bool IsDinh(int x,int y);
bool IsDinhSS(int x, int y, Toado a);
void LogDinh();
void LogDinh2();
void ClearLog();
char* TenDinh();
void XulyDinh();
void DrawDinh(Toado a);
void DeleteDinh();
void DrawCanh(int x, int y);
void VeMuiTen(Toado dau, Toado cuoi, int color);
void VeMuiTenNguoc(int dau, int cuoi, int color);
int Trongso(Toado dau, Toado cuoi);

float Khoangcach(int x1, int y1, int x2, int y2);
string Delete_char(string s);
//============Dinh==============


bool IsDinh(int x,int y)//Check xem toa do x,y co trung voi dinh da ve hay khong
{
	for(int i=0;i<n;i++)
	{
		if (Khoangcach(x,y,dothi[i].x,dothi[i].y)<=BK+25)
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

void LogDinh()
{
	setcolor(RED);
	setbkcolor(BLACK);
	settextjustify(0,2);
	settextstyle(3,0,1);
	outtextxy(860,getmaxy()/(2)+100,"Nhan chuot trai (L) de tao dinh");
	outtextxy(860,getmaxy()/(2)+130,"Nhan chuot phai (R) 2 lan de xoa dinh");
	outtextxy(860,getmaxy()/(2)+160,"Ten dinh (toi da 2 ki tu), Trong so (0-99)");
	outtextxy(860,getmaxy()/(2)+190,"De ve canh:");
	outtextxy(860+20,getmaxy()/(2)+210,"Chuot phai (R) o dinh dau");
	outtextxy(860+20,getmaxy()/(2)+230,"Chuot trai (L) o dinh cuoi");
	outtextxy(860,getmaxy()/(2)+260,"Dung ve bang cach an vao nut File");
	int a[]={1200,getmaxy()-30,1220,getmaxy()-30,1220,getmaxy()-35,1250,getmaxy()-25,1220,getmaxy()-15,1220,getmaxy()-20,1200,getmaxy()-20,1200,getmaxy()-30};
	setfillstyle(1,RED);
	fillpoly(8,a);
}

void LogDinh2()//trang 2 cua LogDinh
{
	setcolor(RED);
	setbkcolor(BLACK);
	settextjustify(0,2);
	settextstyle(3,0,1);
	outtextxy(860,getmaxy()/(2)+100,"Ve lai canh do neu muon sua trong so");
	outtextxy(860,getmaxy()/(2)+130,"Gan trong so = 0 neu muon xoa canh");
	int a[]={880,getmaxy()-25,910,getmaxy()-35,910,getmaxy()-30,930,getmaxy()-30,930,getmaxy()-20,910,getmaxy()-20,910,getmaxy()-15,880,getmaxy()-25};
	setfillstyle(1,RED);
	fillpoly(8,a);
}
void ClearLog()
{
	setfillstyle(1,BLACK);
	bar(851,getmaxy()/2+100,getmaxx()-11,getmaxy()-11);
}

char* TenDinh()
{
	char* name=new char[2];
	string s;
	char c;
	int i=0;
	setcolor(RED);
	setbkcolor(YELLOW);
	settextstyle(1,0,1);
	settextjustify(1,1);
	outtextxy(dothi[n].x,dothi[n].y+5,"|");
	
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
			setfillstyle(1,YELLOW);
			setcolor(YELLOW);
			pieslice(dothi[n].x,dothi[n].y,0,360,BK);
			setcolor(RED);
			if(i==0)
			{
				outtextxy(dothi[n].x,dothi[n].y+5,"|");
			}
		}
		strcpy(name,&s[0]);
		outtextxy(dothi[n].x,dothi[n].y+5,&s[0]);
	}while(c!=13 || i==0);
	
	for(int i=0;i<n;i++)//check trung ten
	{
		if(dothi[i].name==s)
		{
			ClearLog();
			setcolor(RED);
			setbkcolor(BLACK);
			settextstyle(3,0,1);
			settextjustify(0,2);
			outtextxy(860,getmaxy()/(2)+100,"Ten dinh bi trung, vui long nhap ten khac");
			getch();
			ClearLog();
			LogDinh();
			setcolor(RED);
			setbkcolor(YELLOW);
			settextstyle(1,0,1);
			settextjustify(1,1);
			goto ad;
		}
	}
	
	return name;
}

void XulyDinh()
{
	while(1)
	{
		clearmouse();
		delay(.001);
		if(ismouseclick(WM_LBUTTONDOWN))
		{
			int x,y;
			getmouseclick(WM_LBUTTONDOWN,x,y);
			if(!IsDinh(x,y) && x>11+BK&x<850-BK && y>90+BK&&y<getmaxy()-10-BK && n<11)
			{
				setfillstyle(1,YELLOW);
				setcolor(YELLOW);
				pieslice(x,y,0,360,BK);
				dothi[n].x=x;
				dothi[n].y=y;
				dothi[n].name=new char[3];
				dothi[n].name=TenDinh();
				for(int i=0;i<=n;i++)
				{
					matrix[i][n]=0;
					matrix[n][i]=0;
				}
				n++;
				DrawMatrix();
				//break;
			}
			//Dang update ve canh
			if(IsDinh(x,y))
			{
				DrawCanh(x,y);
				DrawMatrix();
			}
			if(x>=30&&x<=230 && y>=20&&y<=80)//bam vo file thi thoat vong lap
			{
				dk=false;
				break;
			}
			if(x>=1200&&x<=1250 && y>=getmaxy()-35&&y<=getmaxy()-15)
			{
				ClearLog();
				LogDinh2();
			}
			if(x>=880&&x<=930 && y>=getmaxy()-35&&y<=getmaxy()-15)
			{
				ClearLog();
				LogDinh();
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
}

void DrawDinh(Toado a)
{
	setfillstyle(1,YELLOW);
	setcolor(YELLOW);
	pieslice(a.x,a.y,0,360,BK);
	setcolor(RED);
	setbkcolor(YELLOW);
	settextstyle(1,0,1);
	settextjustify(1,1);
	outtextxy(a.x,a.y+5,a.name);
}

void DeleteDinh()
{
		if(ismouseclick(WM_RBUTTONDBLCLK))
		{
			int x,y;
			getmouseclick(WM_RBUTTONDBLCLK,x,y);
			if(IsDinh(x,y))
			{
				for(int i=0;i<=n;i++)
				{
					if (Khoangcach(x,y,dothi[i].x,dothi[i].y)<=BK)
					{
						setfillstyle(1,BLACK);
						setcolor(BLACK);
						pieslice(dothi[i].x,dothi[i].y,0,360,BK+2);
						
						for(int j=0;j<=n;j++)
						{
							for(int k=i;k<n;k++)
							{
								matrix[k][j]=matrix[k+1][j];
							}
						}
						for(int j=0;j<=n;j++)
						{
							for(int k=i;k<n;k++)
							{
								matrix[j][k]=matrix[j][k+1];
							}
						}
						for(int j=i;j<n;j++)
						{
							swap(dothi[j],dothi[j+1]);
						}
						n--;
						DrawMatrix();
						ReDraw();
						break;
					}
				}
			}
		}
}
//============Canh==============
void DrawCanh(int x, int y)
{
	if(ismouseclick(WM_RBUTTONUP))
	{
		int a,b;
		getmouseclick(WM_RBUTTONUP,a,b);
		if(IsDinh(a,b) && (a!=x || b!=y))
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
			
			if(matrix[tmp1][tmp2]==0 || matrix[tmp2][tmp1]!=0)//neu chua co cung nao giua 2 canh hoac ve lai cung thi xu ly
			{
				if(matrix[tmp1][tmp2]==0)
				{
					VeMuiTen(dothi[tmp2],dothi[tmp1],RED);
					matrix[tmp2][tmp1]=Trongso(dothi[tmp2],dothi[tmp1]);
				}
				else
				{
					goto am;
				}
			}
			else
			{
				am:	
				Toado t1, t2;
				t1.x=dothi[tmp1].x+15;
				t1.y=dothi[tmp1].y+15;
				t2.x=dothi[tmp2].x+15;
				t2.y=dothi[tmp2].y+15;
				
				VeMuiTen(dothi[tmp1],dothi[tmp2],BLACK);
				int dx=(dothi[tmp1].x+dothi[tmp2].x)/2;
				int dy=(dothi[tmp1].y+dothi[tmp2].y)/2;
				setcolor(RED);
				setbkcolor(WHITE);
				setfillstyle(1,BLACK);
				bar(dx-15,dy-12,dx+20,dy-35);
				
				VeMuiTen(t1,t2,RED);
				dx=(t1.x+t2.x)/2;
				dy=(t1.y+t2.y)/2;
				setfillstyle(1,WHITE);
				bar(dx-10,dy+14,dx+25,dy+37);
				settextstyle(8,0,1);
				settextjustify(1,1);
				stringstream ss;
				ss << matrix[tmp1][tmp2];
				string str = ss.str();
				outtextxy(dx+7,dy+30,&str[0]);
				
				Toado t3, t4;
				t3.x=dothi[tmp2].x-15;
				t3.y=dothi[tmp2].y-15;
				t4.x=dothi[tmp1].x-15;
				t4.y=dothi[tmp1].y-15;
				VeMuiTen(t3,t4,RED);
				matrix[tmp2][tmp1]=Trongso(t3,t4);
			}
			
			if(matrix[tmp2][tmp1]==0)
			{
				/*VeMuiTen(dothi[tmp2],dothi[tmp1],BLACK);
				int dx=(dothi[tmp2].x+dothi[tmp1].x)/2;
				int dy=(dothi[tmp2].y+dothi[tmp1].y)/2;
				setfillstyle(1,BLACK);
				bar(dx-15,dy-12,dx+20,dy-35);*/
				ReDraw();
			}
			clearmouseclick(WM_RBUTTONUP);
			
			for(int i=0;i<n;i++)
			{
				if(IsDinhSS(x,y,dothi[i]) || IsDinhSS(a,b,dothi[i]))
				{
					DrawDinh(dothi[i]);
				}
			}
		}
	}
}

void VeMuiTen(Toado dau, Toado cuoi, int color)
{
	const int R = 12;
	const double PI = 3.14159265;
	Toado d1, d2, d3, d;
	setcolor(color);
	line(dau.x, dau.y, cuoi.x, cuoi.y);
	d.x = (dau.x + cuoi.x) / 2;//Toa do dau mui ten
	d.y = (dau.y + cuoi.y) / 2;
	setcolor(BLACK);
	double result;
	double param = 0;
	struct arccoordstype h;//khai struct arccoordstype lay gia tri cua cung tron da ve
	
	if (cuoi.x > dau.x && cuoi.y < dau.y)//Bottom-Left (nut dau)
	{
		param = 1.0*(dau.y - cuoi.y) / (cuoi.x - dau.x);
		result = atan(param) * 180 / PI;
		
		arc(d.x, d.y, 0, result + 90, R);//Toa do goc trai
		getarccoords(&h);
		d1.x = h.xend;
		d1.y = h.yend;
		arc(d.x, d.y, result + 90, result + 90 + 180, R);//Toa do goc phai
		getarccoords(&h);
		d2.x = h.xend;
		d2.y = h.yend;
		arc(d.x, d.y, 0, result, R);//Toa do dinh mui ten
		getarccoords(&h);
		d3.x = h.xend;
		d3.y = h.yend;
	}
	else if (cuoi.x < dau.x && cuoi.y > dau.y)//Upper-Right
	{
		param = 1.0*(cuoi.y - dau.y) / (dau.x - cuoi.x);
		result = atan(param) * 180 / PI;
		arc(d.x, d.y, 0, result + 90, R);
		getarccoords(&h);
		d1.x = h.xend;
		d1.y = h.yend;
		arc(d.x, d.y, result + 90, result + 90 + 180, R);
		getarccoords(&h);
		d2.x = h.xend;
		d2.y = h.yend;
		arc(d.x, d.y, result, 180 + result, R);//Lo quen khong hieu nho lay paint ra ve cho de :))
		getarccoords(&h);
		d3.x = h.xend;
		d3.y = h.yend;
	}
	else if (cuoi.x < dau.x && cuoi.y < dau.y)//Bottom-Right
	{
		param = 1.0*(cuoi.y - dau.y) / (cuoi.x - dau.x);
		result = atan(param) * 180 / PI;
		arc(d.x, d.y, 0, 90 - result, R);
		getarccoords(&h);
		d1.x = h.xend;
		d1.y = h.yend;
		arc(d.x, d.y, 90 - result, 90 - result + 180, R);
		getarccoords(&h);
		d2.x = h.xend;
		d2.y = h.yend;
		arc(d.x, d.y, 0, 180 - result, R);
		getarccoords(&h);
		d3.x = h.xend;
		d3.y = h.yend;
	}
	else if (cuoi.x > dau.x && cuoi.y > dau.y)//Upper-Left
	{
		param = 1.0*(cuoi.y - dau.y) / (cuoi.x - dau.x);
		result = atan(param) * 180 / PI;
		arc(d.x, d.y, 0, 90 - result, R);
		getarccoords(&h);
		d1.x = h.xend;
		d1.y = h.yend;
		arc(d.x, d.y, 90 - result, 90 - result + 180, R);
		getarccoords(&h);
		d2.x = h.xend;
		d2.y = h.yend;
		arc(d.x, d.y, -result, 0, R);
		getarccoords(&h);
		d3.x = h.xstart;
		d3.y = h.ystart;
	}
	else if (dau.y == cuoi.y)//Ngang hang nhau
	{
		arc(d.x, d.y, 0, 90, R);
		getarccoords(&h);
		d1.x = h.xend;
		d1.y = h.yend;
		arc(d.x, d.y, 90, 90 + 180, R);
		getarccoords(&h);
		d2.x = h.xend;
		d2.y = h.yend;
		if (dau.x < cuoi.x)//Mui ten qua phai
		{
			arc(d.x, d.y, 0, 0, R);
			getarccoords(&h);
			d3.x = h.xstart;
			d3.y = h.ystart;
		}
		else
		{
			arc(d.x, d.y, 0, 180, R);//Mui ten qua trai
			getarccoords(&h);
			d3.x = h.xend;
			d3.y = h.yend;
		}
	}
	else
	{
		arc(d.x, d.y, 0, 180, R);
		getarccoords(&h);
		d1.x = h.xend;
		d1.y = h.yend;
		d2.x = h.xstart;
		d2.y = h.ystart;
		if (cuoi.y > dau.y)//Mui ten di xuong
		{
			arc(d.x, d.y, 0, 270, R);
			getarccoords(&h);
			d3.x = h.xend;
			d3.y = h.yend;
		}
		else
		{
			arc(d.x, d.y, 0, 90, R);//Mui ten di len
			getarccoords(&h);
			d3.x = h.xend;
			d3.y = h.yend;
		}
	}
	setcolor(color);
	setfillstyle(1, color);
	int a[] = { d3.x, d3.y, d1.x, d1.y, d2.x, d2.y, d3.x, d3.y };
	fillpoly(4, a);
}

void VeMuiTenNguoc(int dau, int cuoi, int color)
{
	Toado t1, t2;
	Toado t3, t4;
	
	t1.x=dothi[cuoi].x+15;
	t1.y=dothi[cuoi].y+15;
	t2.x=dothi[dau].x+15;
	t2.y=dothi[dau].y+15;
		
	t3.x=dothi[dau].x-15;
	t3.y=dothi[dau].y-15;
	t4.x=dothi[cuoi].x-15;
	t4.y=dothi[cuoi].y-15;
	
					
	VeMuiTen(t1,t2,color);
	
	int dx=(t1.x+t2.x)/2;
	int dy=(t1.y+t2.y)/2;
	setcolor(color);
	setbkcolor(WHITE);
	setfillstyle(1,WHITE);
	bar(dx-10,dy+14,dx+25,dy+37);
	settextstyle(8,0,1);
	settextjustify(1,1);
	stringstream ss;
	ss << matrix[cuoi][dau];
	string str = ss.str();
	outtextxy(dx+7,dy+30,&str[0]);
				
	
	VeMuiTen(t3,t4,color);
	dx=(t3.x+t4.x)/2;
	dy=(t3.y+t4.y)/2;
	setcolor(color);
	setbkcolor(WHITE);
	setfillstyle(1,WHITE);
	bar(dx-15,dy-12,dx+20,dy-35);
	settextstyle(8,0,1);
	settextjustify(1,1);
	stringstream ss1;
	ss1 << matrix[dau][cuoi];
	str = ss1.str();
	outtextxy(dx+3,dy-17,&str[0]);
	
	//matrix[dau][cuoi]=Trongso(t3,t4);
}

int Trongso(Toado dau, Toado cuoi)
{
	int ts;
	string tmp;
	char c;
	int i=0;
	int dx=(dau.x+cuoi.x)/2;
	int dy=(dau.y+cuoi.y)/2;
	setcolor(RED);
	setbkcolor(WHITE);
	setfillstyle(1,WHITE);
	bar(dx-15,dy-12,dx+20,dy-35);
	settextstyle(8,0,1);
	settextjustify(1,1);
	outtextxy(dx+3,dy-17,"|");
	
	do{
		while(!kbhit());
		fflush(stdin);
		c=getch();
		if(i<2 && (c>=48 && c<=57))
		{
			i++;
			tmp+=c;
		}
		else if(c==8 && i>0)
		{
			i--;
			tmp= Delete_char(tmp);
			//To de len chu khong biet xoa dung nghia ~
			setfillstyle(1,WHITE);
			bar(dx-15,dy-12,dx+20,dy-35);
			setcolor(RED);
			if(i==0)
			{
				outtextxy(dx+3,dy-17,"|");
			}
		}
		//strcpy(name,&tmp[0]);
		outtextxy(dx+3,dy-17,&tmp[0]);
	}while(c!=13 || i==0);
	ts=atoi(&tmp[0]);
	return ts;
}
