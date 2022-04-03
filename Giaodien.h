#pragma once

#include "CTDL.h"
#include "Linhtinh.h"
#include "Dinh.h"
#include "Canh.h"
#include "Matran.h"
#include "Giaithuat.h"

//===========Prototype=============
void Button(Toado a, int color);
void Button_Enter(Toado a);
void draw_menu();
void menuedit();
void LogDinh();
void LogCanh();
void LogCanhS();
void LogDichuyen();
void LogDoiten();
void ClearLog();
void PreProcess(int selection);
void Process(int selection);
void ProcessAlg(int selection);
void Clearmouse();
bool MouseClik(Toado a);
void MouseChek(Toado a, int x, int y, int selection);
void MouseChekPre(Toado a, int x, int y, int selection);
void MouseChekAlg(Toado a, int x, int y, int selection);
void GetMousePre(Toado menu[]);
void GetMouse(Toado menu[]);
void GetMouseAlg(Toado menu[]);

bool IsVoHuong();
void DeleteDothi();
void ReDraw();
void DrawLineFile();
void DrawLineAlg();
void LogDinh();
void XulyDinh(int mode);
void ClearLog();
void SaveDothi();
void LoadDothi();
void XuatKq(int kq[],int &sl,int &yy);
void DFS_stack2(int u);
void swapint(int &a,int &b);
//======================================
int Vohuong(void)
{
	for(int i=0;i<n;i++)
	{
		for(int j=i;i<n;i++)
		{
			if(matrix[i][j]!=matrix[j][i])
			{
				return FALSE;
			}
		}
	}
	return TRUE;
}
//============Xu li giao dien===========
void Button(Toado a, int color)
{
	setfillstyle(1,color);
	bar(a.x+2,a.y+2,a.x+200-2,a.y+60-2);
	setbkcolor(color);
	setcolor(MENUTEXTCOLOR);
	settextstyle(1,0,2);
	settextjustify(0,2);
	outtextxy(a.x+20,a.y+20,a.name);
}

void Button_Enter(Toado a)//Doi mau Button
{
	setfillstyle(1,MENUBKCOLOR);
	bar(a.x+2,a.y+2,a.x+200-2,a.y+60-2);
	setbkcolor(MENUBKCOLOR);
	setcolor(MENUTEXTCOLOR);
	settextstyle(1,0,2);
	settextjustify(0,2);
	outtextxy(a.x+20,a.y+20,a.name);
}

void draw_menu()
{
	setcolor(MENUCOLOR);
	setlinestyle(1,0,2);
	rectangle(10,10,getmaxx()-10,getmaxy()-10);
	line(850,10,850,getmaxy()-10);
	line(850,getmaxy()/2+50,getmaxx()-10,getmaxy()/2+50);
	line(10,90,getmaxx()-10,90);
	
	setcolor(MENUTEXTCOLOR);
	settextstyle(1,0,2);
	outtextxy(980,20,"MATRIX");
	outtextxy(880,getmaxy()/(2)+70,"Log:");
	setcolor(MENUCOLOR);
	
	for(int i=0;i<630;i+=200)
	{
		rectangle(30+i,20,230+i,80);
	}
	//Khai main menu
	for(int i=0;i<16;i++)
	{
		if(i>=0 && i<4)
		{
			menu[i].name=new char[10];
			menu[i].x=30+200*i;
			menu[i].y=20;
		}
		if(i>=4 && i<8)
		{
			menu[i].name=new char[10];
			menu[i].x=30;
			menu[i].y=80+60*(i-4);
		}
		if(i>=8 && i<12)
		{
			menu[i].name=new char[10];
			menu[i].x=230;
			menu[i].y=80+60*(i-8);
		}
		if(i>=12 && i<16)
		{
			menu[i].name=new char[10];
			menu[i].x=430;
			menu[i].y=110+60*(i-12);
		}
	}

	menu[0].name="File";
	menu[1].name="Algorithms";
	menu[2].name="Info";
	menu[3].name="Exit";
	
	menu[4].name="New";
	menu[5].name="Edit";
	menu[6].name="Save";
	menu[7].name="Load";
	
	menu[8].name="DFS";
	menu[9].name="BFS";
	menu[10].name="TPLT";
	menu[11].name="Elements";
	menu[12].name="Dijkstra";
	menu[13].name="Hamilton";
	menu[14].name="Euler";
	menu[15].name="Topo Sort";
	//GetMouse(menu);
	
}

void menuedit()
{
	setcolor(MENUCOLOR);
	setbkcolor(BKCOLOR);
	setlinestyle(1,0,2);
	rectangle(780,90,850,370);
	line(780,160,850,160);
	line(780,230,850,230);
	line(780,300,850,300);
	//Ve button them xoa dinh
	setlinestyle(0,0,1);
	circle(815,125,30);
	line(790,125,840,125);
	line(815,100,815,150);
	
	//Ve button them xoa canh
	line(790,170,840,220);
	int a[]={790,170,797,170,790,177,790,170};
	setfillstyle(1,MENUCOLOR);
	fillpoly(4,a);
	
	//Ve button di chuyen dinh
	setlinestyle(1,0,3);
	line(790,265,840,265);
	line(815,240,815,290);
	int b[]={790,265,797,258,797,272,790,265};
	fillpoly(4,b);
	int c[]={840,265,833,258,833,272,840,265};
	fillpoly(4,c);
	int e[]={815,240,808,247,822,247,815,240};
	fillpoly(4,e);
	int f[]={815,290,808,283,822,283,815,290};
	fillpoly(4,f);
	setlinestyle(0,0,1);
	
	//Ve button doi ten dinh
	line(790,360,800,360);
	line(800,360,840,320);
	line(840,320,830,310);
	line(830,310,790,350);
	line(790,350,790,360);
	line(790,350,800,360);
	line(835,325,825,315);
}

void LogDinh()
{
	TextLog(BLUE);
	outtextxy(XLOG,getmaxy()/(2)+100,"MODE: Them/Xoa dinh");
	TextLog(TEXTCOLOR);
	outtextxy(XLOG,getmaxy()/(2)+130,"Them dinh: Nhap chuot trai (L)");
	outtextxy(XLOG,getmaxy()/(2)+160,"Xoa dinh: Nhan chuot phai (R) 2 lan");
	outtextxy(XLOG,getmaxy()/(2)+270,"Bam vo File de thoat");
}

void LogCanh()
{
	TextLog(BLUE);
	outtextxy(XLOG,getmaxy()/(2)+100,"MODE: Them/Xoa canh");
	TextLog(TEXTCOLOR);
	outtextxy(XLOG,getmaxy()/(2)+130,"Keo tha chuot tu dinh dau toi dinh cuoi...");
	outtextxy(XLOG,getmaxy()/(2)+270,"Bam vo File de thoat");
}

void LogCanhS()
{
	TextLog(MAGENTA);
	outtextxy(XLOG,getmaxy()/(2)+100,"Secret MODE: Them/Xoa canh");
	TextLog(TEXTCOLOR);
	outtextxy(XLOG,getmaxy()/(2)+130,"Chon dinh dau...");
	outtextxy(XLOG,getmaxy()/(2)+270,"Bam vo File de thoat");
}

void LogDichuyen()
{
	TextLog(BLUE);
	outtextxy(XLOG,getmaxy()/(2)+100,"MODE: Di chuyen");
	TextLog(TEXTCOLOR);
	outtextxy(XLOG,getmaxy()/(2)+130,"Chon dinh can di chuyen: ");
	outtextxy(XLOG,getmaxy()/(2)+270,"Bam vo File de thoat");
}

void LogDoiten()
{
	TextLog(BLUE);
	outtextxy(XLOG,getmaxy()/(2)+100,"MODE: Doi ten");
	TextLog(TEXTCOLOR);
	outtextxy(XLOG,getmaxy()/(2)+130,"Chon dinh can doi ten... ");
	outtextxy(XLOG,getmaxy()/(2)+270,"Bam vo File de thoat");
}

void ClearLog()
{
	setfillstyle(1,BKCOLOR);
	bar(851,getmaxy()/2+100,getmaxx()-11,getmaxy()-11);
}

void PreProcess(int selection)//xu li main menu
{
	switch(selection)
	{
		case 1://File
			{
				setcolor(MENUCOLOR);
				setbkcolor(BKCOLOR);
				setfillstyle(1,BKCOLOR);
				bar(29,81,232,320);
				setlinestyle(1,0,2);
				rectangle(30,80,230,320);
				line(30,140,230,140);
				line(30,200,230,200);
				line(30,260,230,260);
				setlinestyle(0,0,1);
				
				dk=true;
				
				while(dk)
				{
					delay(.001);
			    	if(ismouseclick(WM_MOUSEMOVE))
			    	{
			    		GetMousePre(menu);
			    		//break;
					}
				}
				
				break;
			}
		case 2://Algorithms
			{
				setcolor(MENUCOLOR);
				setbkcolor(BKCOLOR);
				setfillstyle(1,BKCOLOR);
				bar(229,81,432,320);
				setlinestyle(1,0,2);
				rectangle(230,80,430,320);
				rectangle(430,110,630,350);
				line(230,140,430,140);
				line(230,200,430,200);
				line(230,260,430,260);
				line(430,170,630,170);
				line(430,230,630,230);
				line(430,290,630,290);
				setlinestyle(0,0,1);
				dk=true;
				
				while(dk)
				{
					delay(.001);
			    	if(ismouseclick(WM_MOUSEMOVE))
			    	{
			    		GetMouseAlg(menu);
					}
				}
				break;
			}
		case 3://Info
			{
				if(n==0)
				{
					TextLog(BLUE);
					settextstyle(8,0,5);
					outtextxy(50,120,"DEMO CHUONG TRINH DO THI 1.0");
					setcolor(MAGENTA);
					settextstyle(8,0,3);
					outtextxy(50,250,"Duoc thuc hien boi:");
					setcolor(TEXTCOLOR);
					outtextxy(50,290,"Nguyen Hai Dang - N18DCCN040");
					outtextxy(50,330,"Vu Tuan Anh - N18DCCN010");
					outtextxy(50,370,"Dang Le Uy - N18DCCN238");
				}
				else
				{
					ClearLog();
					TextLog(BLUE);
					outtextxy(XLOG,getmaxy()/2+100,"DEMO CHUONG TRINH DO THI 1.0");
					setcolor(MAGENTA);
					outtextxy(XLOG,getmaxy()/2+130,"Duoc thuc hien boi:");
					setcolor(TEXTCOLOR);
					outtextxy(XLOG,getmaxy()/2+160,"Nguyen Hai Dang - N18DCCN040");
					outtextxy(XLOG,getmaxy()/2+190,"Vu Tuan Anh - N18DCCN010");
					outtextxy(XLOG,getmaxy()/2+220,"Dang Le Uy - N18DCCN238");
				}
				break;
			}
		case 4://Exit
			{
				check=false;
				break;
			}
	}
}

void Process(int selection)//Xu ly menu con/chuc nang chinh
{
	switch(selection)
	{
		case 1://New
			{
				ClearLog();
				DrawLineFile();
				ReDraw();
				if(n!=0)
				{
					TextLog(TEXTCOLOR2);
					outtextxy(XLOG,getmaxy()/(2)+100,"Ban co chac muon TAO MOI do thi?");
					outtextxy(XLOG,getmaxy()/(2)+130,"(Hay dam bao da save truoc khi bam Yes)");
					setfillstyle(1,YELLOW);
					bar(900,getmaxy()/(2)+160,980,getmaxy()/(2)+190);
					bar(1050,getmaxy()/(2)+160,1130,getmaxy()/(2)+190);
					setbkcolor(YELLOW);
					outtextxy(910,getmaxy()/(2)+165,"YES");
					outtextxy(1060,getmaxy()/(2)+165,"NO");
					setlinestyle(1,0,2);
					rectangle(900,getmaxy()/(2)+160,980,getmaxy()/(2)+190);
					rectangle(1050,getmaxy()/(2)+160,1130,getmaxy()/(2)+190);
					setlinestyle(0,0,1);
		
					while(1)
					{
						delay(DELAY);
						if(ismouseclick(WM_LBUTTONDOWN))
						{
							int x,y;
							getmouseclick(WM_LBUTTONDOWN,x,y);
							if(x>=900&&x<=980 && y>=getmaxy()/(2)+160&&y<=getmaxy()/(2)+190)//YES
							{
								ClearLog();
								break;
							}
							if(x>=1050&&x<=1130 && y>=getmaxy()/(2)+160&&y<=getmaxy()/(2)+190)//NO
							{
								DrawLineFile();
								ReDraw();
								ClearLog();
								dk=false;
								return;
							}
						}
					}
				}
				DeleteDothi();//xoa bo nho do thi hien tai
				setfillstyle(1,BKCOLOR);
				bar(11,81,849,getmaxy()-10);
				bar(849,91,getmaxx()-11,getmaxy()/2+49);
				setcolor(MENUCOLOR);
				setlinestyle(1,0,2);
				line(850,10,850,getmaxy()-10);
				line(getmaxx()-10,10,getmaxx()-10,getmaxy()-10);
				setlinestyle(0,0,1);
			}
		case 2://Edit
			{
				ClearLog();
				DrawLineFile();
				ReDraw();
				XulyDinh(1);
				ClearLog();
				break;
			}
		case 3://Save
			{
				DrawLineFile();
				ClearLog();
				ReDraw();
				SaveDothi();
				dk=false;
				break;
			}
		case 4://Load
			{
				DrawLineFile();
				ClearLog();
				ReDraw();
				DeleteDothi();
				LoadDothi();
				dk=false;
				break;
			}
	}
}

void ProcessAlg(int selection)
{
	switch(selection)
	{
		case 1://DFS
			{
				DrawLineAlg();
				ReDraw();
				ClearLog();
				int xx=XLOG,yy=getmaxy()/(2)+100;
				if(n==0)
				{
					TextLog(TEXTCOLOR2);
					outtextxy(XLOG,yy,"KHONG TON TAI DO THI!");
					dk=false;
					break;
				}
				int kq[MAX],sl;
				DFS(kq,sl);
				TextLog(TEXTCOLOR);
				outtextxy(XLOG,getmaxy()/(2)+100,"DFS: ");
				yy+=30;
				int c=1;
				for (int k=0; k<sl-1; k++)
				{
					if(k==7&& c==1)
					{
						yy+=30;
						xx=XLOG;
						c=0;
					}
					Dinhcolor(dothi[kq[k]],VARCOLOR);//highlight
					TextLog(VARCOLOR);
					outtextxy(xx,yy,dothi[kq[k]].name);
					xx+=20;
					setcolor(TEXTCOLOR);
					outtextxy(xx,yy,"->");
					xx+=20;
					delay(500);//cho 0.5s
					Dinhcolor(dothi[kq[k]],CIRCLECOLOR);//doi lai mau goc
				}
				TextLog(VARCOLOR);
				outtextxy(xx,yy,dothi[kq[sl-1]].name);
				Dinhcolor(dothi[kq[sl-1]],VARCOLOR);
				delay(500);
				Dinhcolor(dothi[kq[sl-1]],CIRCLECOLOR);
				dk=false;
				break;
			}
		case 2://BFS
			{
				DrawLineAlg();
				ReDraw();
				ClearLog();
				int xx=XLOG,yy=getmaxy()/(2)+100;
				if(n==0)
				{
					TextLog(TEXTCOLOR2);
					outtextxy(XLOG,yy,"KHONG TON TAI DO THI!");
					dk=false;
					break;
				}

				int kq[MAX],sl;
				BFS(kq,sl);
				TextLog(TEXTCOLOR);
				outtextxy(XLOG,yy,"BFS: ");
				yy+=30;
				int c=1;
				for (int k=0; k<sl-1; k++)
				{
					if(k==7 && c==1)
					{
						yy+=30;
						xx=XLOG;
						c=0;
					}
					Dinhcolor(dothi[kq[k]],VARCOLOR);//highlight
					TextLog(VARCOLOR);
					outtextxy(xx,yy,dothi[kq[k]].name);
					xx+=20;
					setcolor(TEXTCOLOR);
					outtextxy(xx,yy,"->");
					xx+=20;
					delay(500);//cho 0.5s
					Dinhcolor(dothi[kq[k]],CIRCLECOLOR);//doi lai mau goc
				}
				TextLog(VARCOLOR);
				outtextxy(xx,yy,dothi[kq[sl-1]].name);
				Dinhcolor(dothi[kq[sl-1]],VARCOLOR);
				delay(500);
				Dinhcolor(dothi[kq[sl-1]],CIRCLECOLOR);
				dk=false;
				break;
			}
		case 3://TPLT
			{
				DrawLineAlg();
				ReDraw();
				ClearLog();
				int xx=XLOG,yy=getmaxy()/(2)+100;
				if(n==0)
				{
					TextLog(TEXTCOLOR2);
					outtextxy(XLOG,yy,"KHONG TON TAI DO THI!");
					dk=false;
					break;
				}
				TextLog(TEXTCOLOR);
				PTR A[MAX];
				{
					for(int i=0;i<n;i++)
					{
						A[i]=InitHead();
					}
				}
				T_Init();
				if(Vohuong()==TRUE)
				{
					LTVH(A);
					outtextxy(xx,yy,"Cac TPLT : ");
					yy+=30;	
				}
				else{
				Tarjan(A);
				outtextxy(xx,yy,"Cac TPLT manh: ");
				yy+=30;
				}
				int c=1;
				for(int i=0;i<TPLT;i++)
				{
					xx=XLOG;
					if(i==6&&c==1)
					{
						xx=XLOG+200;
						yy=yy-180;
						c=0;
					}
					setcolor(TEXTCOLOR);
					outtextxy(xx,yy,"TPLT ");
					stringstream s1;
					s1 << i+1;
					string str = s1.str();
					outtextxy(xx+60,yy,&str[0]);
					outtextxy(xx+80,yy,": ");
					xx+=100;
					while(A[i]!= NULL)
					{
						int k=A[i]->data;
						setcolor(VARCOLOR);
						outtextxy(xx,yy,dothi[k].name);
						xx+=20;
						A[i]=A[i]->next;
					}
					yy+=30;
				}
				dk=false;
				break;
			}
		case 4://Elements
			{
				DrawLineAlg();
				ReDraw();
				ClearLog();
				int xx=XLOG,yy=getmaxy()/(2)+100;
				if(n==0)
				{
					TextLog(TEXTCOLOR2);
					outtextxy(XLOG,yy,"KHONG TON TAI DO THI!");
					dk=false;
					break;
				}
				ReInit();
				int m=0;
				
				int y=0;
				for(int u=0;u<n;u++){
					chuaxet[u]=FALSE;
					int v=u+1; if(v>=n) v=0;
					DFS_stack2(v);
					if (test_lienthong()){
						TextLog(VARCOLOR);
						outtextxy(870,getmaxy()/2+(100+y),dothi[u].name);
						setcolor(TEXTCOLOR);
						outtextxy(890,getmaxy()/(2)+(100+y)," la dinh tru,");
						y=y+30;
						m=u+1;
						if(y==180)
						{
							TextLog(TEXTCOLOR);
							outtextxy(XLOG,getmaxy()/(2)+300,"...Nhan phim bat ki de tiep tuc...");
							getch();
							y=0;
							ClearLog();
						}
					}
				ReInit();
				}
				if (m==0){
					TextLog(TEXTCOLOR2);
					outtextxy(XLOG,getmaxy()/(2)+100,"Do thi khong co dinh tru.");
				}
				TextLog(TEXTCOLOR);
				outtextxy(XLOG,getmaxy()/(2)+300,"...Nhan phim bat ki de tiep tuc...");
				getch();
				ClearLog();
				
				ReInit();
				 m=0;
				 y=0;
				int tmp1, tmp2;
				for(int u=0;u<n-1;u++){
					for(int v=u+1;v<=n-1;v++){
						if(matrix[u][v]!=0){
							tmp1=matrix[u][v];
							tmp2=matrix[v][u];
							matrix[u][v]=0; matrix[v][u]=0;
							DFS_stack2(0);
							if (test_lienthong()){
								TextLog(VARCOLOR);
								outtextxy(870,getmaxy()/2+(100+y),dothi[u].name);
								setcolor(TEXTCOLOR);
								outtextxy(890,getmaxy()/2+(100+y),"-");
								setcolor(VARCOLOR);
								outtextxy(910,getmaxy()/2+(100+y),dothi[v].name);
								setcolor(TEXTCOLOR);
								outtextxy(930,getmaxy()/2+(100+y),"la canh cau");
								m=m+1;
								y=y+30;
								if(y==180)
								{
									TextLog(TEXTCOLOR);
									outtextxy(XLOG,getmaxy()/(2)+300,"...Nhan phim bat ki de tiep tuc...");
									getch();
									y=0;
									ClearLog();
								}
							}
							matrix[u][v]=tmp1;
							matrix[v][u]=tmp2;
							ReInit();	
						}
						
					}
				}
				if (m==0){
					TextLog(TEXTCOLOR2);
					outtextxy(XLOG,getmaxy()/(2)+100,"Do thi khong co canh cau.");
				}
				TextLog(TEXTCOLOR);
				outtextxy(XLOG,getmaxy()/(2)+300,"...Nhan phim bat ki de tiep tuc...");
				getch();
				ClearLog();
					
					
				TextLog(TEXTCOLOR);
				outtextxy(XLOG,getmaxy()/(2)+100,"Ban co muon xet luon DINH THAT khong?");
				setfillstyle(1,BKCOLOR);
				TextLog(TEXTCOLOR2);
				bar(900,getmaxy()/(2)+150,980,getmaxy()/(2)+180);
				bar(1050,getmaxy()/(2)+150,1130,getmaxy()/(2)+180);
				setbkcolor(BKCOLOR);
				outtextxy(910,getmaxy()/(2)+155,"YES");
				outtextxy(1060,getmaxy()/(2)+155,"NO");
				setlinestyle(1,0,2);
				rectangle(900,getmaxy()/(2)+150,980,getmaxy()/(2)+180);
				rectangle(1050,getmaxy()/(2)+150,1130,getmaxy()/(2)+180);
				setlinestyle(0,0,1);
				while(1)
				{
					delay(DELAY);
					if(ismouseclick(WM_LBUTTONDOWN))
					{
						int x,y;
						getmouseclick(WM_LBUTTONDOWN,x,y);
						if(x>=900&&x<=980 && y>=getmaxy()/(2)+150&&y<=getmaxy()/(2)+180)//YES
						{
							//Xu ly dinh that o day
							ClearLog();
							if(n<2)
							{
								if(n==0)
								{
									TextLog(TEXTCOLOR2);
									outtextxy(XLOG,yy,"KHONG TON TAI DO THI!");
									dk=false;
									break;
								}
								else
								{
									TextLog(TEXTCOLOR2);
									outtextxy(XLOG,yy,"KHONG DU DINH DE CHAY THUAT TOAN!");
									dk=false;
									break;
								}
							}
							int a,b,c=0,D[n],C[n];
							Chondinh(a);
							Chondinh2(b);
							while(a==b)
							{
								ClearLog();
								TextLog(TEXTCOLOR2);
								outtextxy(XLOG,getmaxy()/(2)+100,"Xin hay chon dinh dau va cuoi khac nhau!");
								delay(1000);
								ClearLog();
								Dinhcolor(dothi[a],CIRCLECOLOR);
								//Dinhcolor(dothi[b],CIRCLECOLOR);
								Chondinh(a);
								Chondinh2(b);
							}
							ClearLog();
							int xx=XLOG,yy=0;								
							ReInit;
							for(int i=0;i<n;i++){
								if(i!=a && i!=b){
									tmpdel(D,C,i);
									chuaxet[i]=FALSE;
									if(ktralt(a,b)){
										readd(D,C,i);
									}
									else{
										TextLog(VARCOLOR);
										outtextxy(xx,getmaxy()/2+(100+yy),dothi[i].name);
										xx=xx+20;
										setcolor(TEXTCOLOR);
										outtextxy(xx,getmaxy()/(2)+(100+yy),"la dinh that,");
										yy=yy+30;
										xx=XLOG;
										readd(D,C,i);
										c++;
										if(yy==180)
										{
											TextLog(TEXTCOLOR);
											outtextxy(XLOG,getmaxy()/(2)+300,"...Nhan phim bat ki de tiep tuc...");
											getch();
											yy=0;
											ClearLog();
										}
									}
									ReInit();
								}
							}
							cout<<endl;
							if(c==0){
								TextLog(TEXTCOLOR2);
								outtextxy(xx,getmaxy()/2+(100+yy),"Giua ");
								xx=xx+50;
								setcolor(VARCOLOR);
								outtextxy(xx,getmaxy()/2+(100+yy),dothi[a].name);
								xx=xx+20;
								setcolor(TEXTCOLOR2);
								outtextxy(xx,getmaxy()/2+(100+yy),"va ");
								xx=xx+30;
								setcolor(VARCOLOR);
								outtextxy(xx,getmaxy()/2+(100+yy),dothi[b].name);
								xx=xx+20;
								setcolor(TEXTCOLOR2);
								outtextxy(xx,getmaxy()/2+(100+yy),"khong co dinh that.");
							}
							break;
						}
						if(x>=1050&&x<=1130 && y>=getmaxy()/(2)+150&&y<=getmaxy()/(2)+180)//NO
						{
							DrawLineAlg();
							ReDraw();
							ClearLog();
							dk=false;
							return;
						}
					}
				}
				dk=false;
				break;
			}
		case 5: //Dijkstra
			{
				DrawLineAlg();
				ReDraw();
				ClearLog();
				int xx=XLOG,yy=getmaxy()/(2)+100;
				if(n<2)
				{
					if(n==0)
					{
						TextLog(TEXTCOLOR2);
						outtextxy(XLOG,yy,"KHONG TON TAI DO THI!");
						dk=false;
						break;
					}
					else
					{
						TextLog(TEXTCOLOR2);
						outtextxy(XLOG,yy,"KHONG DU DINH DE CHAY THUAT TOAN!");
						dk=false;
						break;
					}
				}
				
				int kq[MAX],sl=0,r;
				int check;
				check = Dijkstra(kq,sl,r);
				if(check==0)
				{
					TextLog(TEXTCOLOR2);
					outtextxy(XLOG,yy,"Khong ton tai duong di!");
					dk=false;
					break;
				}
				TextLog(TEXTCOLOR);
				outtextxy(XLOG,yy,"Dijkstra: ");
				yy+=30;
				for (int k=sl-1; k>0; k--)
				{
					Dinhcolor(dothi[kq[k]],VARCOLOR);//highlight
					TextLog(VARCOLOR);
					outtextxy(xx,yy,dothi[kq[k]].name);
					xx+=20;
					setcolor(TEXTCOLOR);
					outtextxy(xx,yy,"->");
					xx+=20;
					delay(500);//cho 0.5s
					Dinhcolor(dothi[kq[k]],CIRCLECOLOR);//doi lai mau goc
				}
				TextLog(VARCOLOR);
				outtextxy(xx,yy,dothi[kq[0]].name);
				setcolor(TEXTCOLOR);
				outtextxy(XLOG,yy+30,"Chi phi duong di:");
				stringstream ss;
				ss << r;
				string str = ss.str();
				setcolor(VARCOLOR);
				outtextxy(1020,yy+30,&str[0]);
				//Dinhcolor(dothi[kq[sl-1]],VARCOLOR);
				Dinhcolor(dothi[kq[sl-1]],CIRCLECOLOR);
				Dinhcolor(dothi[kq[0]],VARCOLOR);
				delay(500);
				Dinhcolor(dothi[kq[0]],CIRCLECOLOR);
				dk=false;
				break;
			}
		case 6:
			{
				DrawLineAlg();
				ReDraw();
				ClearLog();
				int xx=XLOG,yy=getmaxy()/(2)+100;
				if(n==0)
				{
					TextLog(TEXTCOLOR2);
					outtextxy(XLOG,yy,"KHONG TON TAI DO THI!");
					dk=false;
					break;
				}
				yy=30;
				int X[n], dem=0;
				X[0]=0;
				ReInit();
				chuaxet[0]=0;
				Hamilton(1,X,dem,xx,yy);
				if(dem==0){
					TextLog(TEXTCOLOR2);
					outtextxy(XLOG,getmaxy()/(2)+100,"Khong co chu trinh Hamilton cho do thi.");
				}
				dk=false;
				break;
			}
		case 7:
			{
				DrawLineAlg();
				ReDraw();
				ClearLog();
				int xx=XLOG,yy=getmaxy()/(2)+100;
				if(n==0)
				{
					TextLog(TEXTCOLOR2);
					outtextxy(XLOG,yy,"KHONG TON TAI DO THI!");
					dk=false;
					break;
				}
				yy=0;
				if(IsVohuong()){
					ReInit();
					DFS_stack2(0);
					if(test_lienthong()){
						TextLog(TEXTCOLOR2);
						outtextxy(XLOG,getmaxy()/(2)+100,"Do thi khong lien thong nen khong co chu trinh");
						outtextxy(XLOG,getmaxy()/(2)+130,"Euler.");
					}
					else{
						int x=0, y=0;
						for(int i=0;i<n;i++){
							for(int j=0;j<n;j++){
								y=y+matrix[i][j];
							}
							if(y%2==0)
							x++;
							y=0;
						}
						if(x==n){
							int tmp[n][n];
							for(int i=0;i<n;i++){
								for(int j=0;j<n;j++){
									tmp[i][j]=matrix[i][j]; //luu ma tran ke vao mang tam de khoi phuc sau khi chay EulerCycle
								}
							}
							int CE[100];
							int dCE=-1;
							EulerCycle(0,dCE,CE);
							TextLog(TEXTCOLOR);
							outtextxy(XLOG,getmaxy()/(2)+100,"Chu trinh Euler:");
							yy=yy+30;
							for(int i=dCE;i>=0;i--){
								setcolor(VARCOLOR);
								outtextxy(xx,getmaxy()/(2)+100+yy,dothi[CE[i]].name);
								xx=xx+20;
								if(i!=0){
									if(xx>=1240){
										yy=yy+30;
										xx=XLOG;
									}
									setcolor(TEXTCOLOR);
									outtextxy(xx,getmaxy()/(2)+100+yy,"-");
									xx=xx+20;
								}
							}
							for(int i=0;i<n;i++){
								for(int j=0;j<n;j++){
									matrix[i][j]=tmp[i][j]; //khoi phuc sau khi chay EulerCycle
								}
							}
						}
						else{
							TextLog(TEXTCOLOR2);
							outtextxy(XLOG,getmaxy()/(2)+100,"Do thi lien thong nhung khong co chu trinh");
							outtextxy(XLOG,getmaxy()/(2)+130,"Euler.");
						}
					}
				}
				else{
					ReInit();
					int a=-1;
					for(int i=0;i<n;i++){
						DFS_stack2(i);
						if(test_lienthong()==FALSE){
							a=i;
						}
						ReInit;
					}
					if(a==-1){
						TextLog(TEXTCOLOR2);
						outtextxy(XLOG,getmaxy()/(2)+100,"Do thi khong lien thong nen khong co chu trinh");
						outtextxy(XLOG,getmaxy()/(2)+130,"Euler.");
					}
					else{
						a=0;
						int b=0,c=0;
						for(int i=0;i<n;i++){
							for(int j=0;j<n;j++){
								a=a+matrix[i][j];
								b=b+matrix[j][i];
							}
							if(a-b==0){
								c++;
							}
						}
						if(c!=n){
							TextLog(TEXTCOLOR2);
							outtextxy(XLOG,getmaxy()/(2)+100,"Do thi lien thong yeu nhung khong co chu ");
							outtextxy(XLOG,getmaxy()/(2)+130,"trinh Euler.");
						}
						else{
							int tmp[n][n];
							for(int i=0;i<n;i++){
								for(int j=0;j<n;j++){
									tmp[i][j]=matrix[i][j]; //luu ma tran ke vao mang tam de khoi phuc sau khi chay EulerCycle
								}
							}
							int CE[100];
							int dCE=-1;
							EulerCycle(0,dCE,CE);
							TextLog(TEXTCOLOR);
							outtextxy(XLOG,getmaxy()/(2)+100,"Chu trinh Euler:");
							yy=yy+30;
							for(int i=dCE;i>=0;i--){
								setcolor(VARCOLOR);
								outtextxy(xx,getmaxy()/(2)+100+yy,dothi[CE[i]].name);
								xx=xx+20;
								if(i!=0){
									if(xx>=1240){
										yy=yy+30;
										xx=XLOG;
									}
									setcolor(TEXTCOLOR);
									outtextxy(xx,getmaxy()/(2)+100+yy,"-");
									xx=xx+20;
								}
							}
							for(int i=0;i<n;i++){
								for(int j=0;j<n;j++){
									matrix[i][j]=tmp[i][j]; //khoi phuc sau khi chay EulerCycle
								}
							}
						}
					}
				}
				dk=false;
				break;
			}
		case 8: //Topo Sort
			{
				DrawLineAlg();
				ReDraw();
				ClearLog();
				int xx=XLOG,yy=getmaxy()/(2)+100;
				if(n<2)
				{
					if(n==0)
					{
						TextLog(TEXTCOLOR2);
						outtextxy(XLOG,yy,"KHONG TON TAI DO THI!");
						dk=false;
						break;
					}
					else
					{
						TextLog(TEXTCOLOR2);
						outtextxy(XLOG,yy,"KHONG DU DINH DE CHAY THUAT TOAN!");
						dk=false;
						break;
					}
				}
				stack kqT;
				int check;
				check =Topo_Sort(kqT);
				if(check==0)
				{
					ClearLog();
					TextLog(TEXTCOLOR2);
					outtextxy(XLOG,yy,"Khong phai do thi DAG!");
					dk=false;
					break;
				}
				/*int k;
				TextLog(TEXTCOLOR);
				outtextxy(xx,yy,"Toppo Sort: ");
				yy+=30;
				pop(kqT,k);
				while(Empty(kqT)==FALSE)
				{
					
					outtextxy(xx,yy,dothi[k].name);
					xx+=20;
					outtextxy(xx,yy,"->");
					xx+=20;
					pop(kq,k);
				}
				outtextxy(xx,yy,dothi[k].name);*/
				PickTopo();
				int kq2[MAX],sl2;
				PickTopo2(kq2,sl2);
				int kq3[MAX],sl3;
				FindRoot(kq3,sl3);
				ClearLog();
				TextLog(TEXTCOLOR);
				outtextxy(xx,yy,"Cac mon da dat:");
				yy+=30;
				setcolor(VARCOLOR);
				XuatKq(kq1,sl1,yy);
				if(sl1==0)
				{
					outtextxy(xx,yy,"Ø");
				}
				yy+=30;
				setcolor(TEXTCOLOR);
				outtextxy(xx,yy,"Cac mon muon hoc:");
				yy+=30;
				setcolor(VARCOLOR);
				XuatKq(kq2,sl2,yy);
				yy+=30;
				setcolor(TEXTCOLOR);
				outtextxy(xx,yy,"Nhung mon co the dang ky la:");
				setcolor(VARCOLOR);
				yy+=30;
				xx=XLOG;
				int ck=0;
				for(int i=0;i<sl2;i++)
				{
					for(int j=0;j<sl3;j++)
					{
						if(kq2[i]==kq3[j])
						{
							setcolor(VARCOLOR);
							outtextxy(xx,yy,dothi[kq2[i]].name);
							kq2[i]=-1;
							xx+=20;	
							ck=1;	
						}
					}
				}
				if(sl1!=0)
				{	
					for(int i=0; i<sl1;i++)
					{
						int x=kq1[i];
						for(int j=0; j<n; j++)
						{
							if(matrix[x][j] !=0)
							{
								for(int k=0;k<sl2;k++)
								{
									if(j==kq2[k])
									{
										setcolor(VARCOLOR);
										outtextxy(xx,yy,dothi[j].name);
										kq2[k]=-1;
										xx+=20;
										ck=1;
									}
								}
							}
							
						}
					}
				}
				for(int i=0;i<sl2;i++)
				{
				if(kq2[sl2]!=-1 && ck==0)
				{
					outtextxy(xx,yy,"Ø");
					ck=1;
				}
				}
				TextLog(TEXTCOLOR);
				outtextxy(XLOG,getmaxy()/(2)+300,"...Nhan phim bat ki de tiep tuc...");
				getch();
				ClearLog();
				ReDraw();
				dk=false;
				break;
			}
	}
}
//========Xu li chuot======
void Clearmouse()
{
	clearmouseclick(WM_LBUTTONDOWN);
	clearmouseclick(WM_LBUTTONUP);
	clearmouseclick(WM_LBUTTONDBLCLK);
	clearmouseclick(WM_RBUTTONDBLCLK);
	clearmouseclick(WM_RBUTTONDOWN);
	clearmouseclick(WM_RBUTTONUP);
}

bool MouseClik(Toado a)//Check vi tri click chuot
{
	int x, y;
	getmouseclick(WM_LBUTTONDOWN,x,y);
	if ((x >= a.x && x <= a.x + 200) && (y >= a.y && y <= a.y + 60))
	{
		return true;
	}
	return false;
}

void MouseChek(Toado a, int x, int y, int selection)//Check neu dung toa do cua bat cu Button nao thi xu ly
{
	if ((x >= a.x && x <= a.x + 200) && (y >= a.y && y <= a.y + 60))
	{
		Button(a,MENUBKCOLOR);//Di chuot vo dung toa do Button thi doi mau
		if (MouseClik(a))
		{
			//Button(a);
			PreProcess(selection);
		}
	}
	else
	{
		Button(a,BKCOLOR);
	}
}

void MouseChekPre(Toado a, int x, int y, int selection)
{
	if ((x >= a.x && x <= a.x + 200) && (y >= a.y && y <= a.y + 60))
	{
		Button(a,MENUBKCOLOR);//Di chuot vo dung toa do Button thi doi mau
		if (MouseClik(a))
		{
			//Button(a);
			Process(selection);
		}
	}
	else
	{
		setfillstyle(1,BKCOLOR);
		bar(779,91,849,371);
		if(dk==true)
		{
			Button(a,BKCOLOR);
		}
	}
}

void MouseChekAlg(Toado a, int x, int y, int selection)
{
	if ((x >= a.x && x <= a.x + 200) && (y >= a.y && y <= a.y + 60))
	{
		Button(a,MENUBKCOLOR);//Di chuot vo dung toa do Button thi doi mau
		if (MouseClik(a))
		{
			//Button(a);
			ProcessAlg(selection);
		}
	}
	else
	{
		if(dk==true)
		{
			Button(a,BKCOLOR);
		}
	}
}

void GetMousePre(Toado menu[])
{
	int x,y;
	getmouseclick(WM_MOUSEMOVE, x, y);
	for(int i=0;i<8;i++)
	{
		if(i==0)
		{
			if ((x >= menu[0].x && x <= menu[0].x+ 200) && (y >= menu[0].y && y <= menu[0].y + 60))
			{
				if (MouseClik(menu[0]))
				{
					DrawLineFile();
					ReDraw();
					dk=false;
					break;
				}
			}
		}
		else if(i>=1 && i<4)
		{
			continue;
		}
		Button(menu[0],MENUBKCOLOR);
		MouseChekPre(menu[i],x,y,i-3);
	}
}

void GetMouse(Toado menu[])//Dua toa do x,y khi click chuot cho ham MouseChek
{
	int x,y;
	getmouseclick(WM_MOUSEMOVE, x, y);
	for(int i=0;i<4;i++)
	{
		MouseChek(menu[i],x,y,i+1);
	}
}

void GetMouseAlg(Toado menu[])
{
	int x,y;
	getmouseclick(WM_MOUSEMOVE, x, y);
	for(int i=1;i<16;i++)
	{
		if(i==1)
		{
			if ((x >= menu[i].x && x <= menu[i].x+ 200) && (y >= menu[i].y && y <= menu[i].y + 60))
			{
				if (MouseClik(menu[i]))
				{
					DrawLineAlg();
					ReDraw();
					dk=false;
					break;
				}
			}
		}
		else if(i>=2 && i<8)
		{
			continue;
		}
		Button(menu[1],MENUBKCOLOR);
		MouseChekAlg(menu[i],x,y,i-7);
	}
}
