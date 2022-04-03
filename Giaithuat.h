#pragma once

#include "CTDL.h"
#include "Dinh.h"
#include "Canh.h"
#include "Matran.h"
#include "Linhtinh.h"

//=============prototype===========
void BFS(int kq[],int &sl);
void DFS(int kq[],int &sl);
int Dijkstra(int kq[],int &sl);
void PickTopo();
int Topo_Sort(stack &kq);
void Dinhcolor(Toado a, int color);
void ClearLog();
void ReInit();
void Tarjan();
void DFS_Tar();
int min(int a,int b);
PTR AddTail(PTR head,int value);
PTR CreateList(int value);

int test_lienthong();
void DFS_stack2(int u);
void EulerCycle(int u,int &dCE,int CE[]);
void GhiNhan(int X[],int &dem, int &xx, int &yy);
void Hamilton(int u,int X[],int &dem,int &xx, int &yy);
bool ktralt(int a, int b);
void tmpdel(int A[],int B[], int k);
void readd(int A[],int B[], int k);


void TextLog(int color);
int PickDinh(int x, int y);
//===========Giai thuat Tuan Anh==========

void Chondinh(int &u)
{
	u=-1;
	TextLog(TEXTCOLOR);
	outtextxy(XLOG,getmaxy()/2+100,"Nhan (LMB) de Chon dinh bat dau...");
	while(u==-1)
	{
		delay(.001);
		if(ismouseclick(WM_LBUTTONDOWN))//check bam chuot trai
		{
			int x,y;
			getmouseclick(WM_LBUTTONDOWN,x,y);//lay toa do chuot trai
			if(IsDinh(x,y))//Neu dung vi tri dinh
			{
				for(int i=0;i<n;i++)
				{
					if(IsDinhSS(x,y,dothi[i]))
					{
						Dinhcolor(dothi[i],VARCOLOR);//highlight
						u=i;//lay ra dinh u
						break;
					}
				}
			}
		}
	}
}
void Chondinh2(int &u)
{
	u=-1;
	TextLog(TEXTCOLOR);
	outtextxy(XLOG,getmaxy()/2+100,"Nhan (LMB) de Chon dinh ket thuc...");
	while(u==-1)
	{
		delay(.001);
		if(ismouseclick(WM_LBUTTONDOWN))//check bam chuot trai
		{
			int x,y;
			getmouseclick(WM_LBUTTONDOWN,x,y);//lay toa do chuot trai
			if(IsDinh(x,y))//Neu dung vi tri dinh
			{
				for(int i=0;i<n;i++)
				{
					if(IsDinhSS(x,y,dothi[i]))
					{
						Dinhcolor(dothi[i],WHITE);//highlight
						u=i;//lay ra dinh u
						break;
					}
				}
			}
		}
	}
}
void BFS(int kq[],int &sl)
{
	int u;
	Chondinh(u);
	ClearLog();
	ReInit();
	sl=0;
	int v;
	Insert_q(q,u); // Push u de queue khong bi rong~ va vong lap se duoc khoi dong, vi DK cua vong lap la khac rong~
	//cout<<"Duong di: ";
	chuaxet[u] = FALSE;
	while(empty(q) == FALSE)
	{
		Delete_q(q,u); // Day gia tri vao u de duyet
		//cout<<u+1<<" ";
		kq[sl]=u;
		sl++;
		for(v=0;v<n;v++) //Day toan bo Ke cua u vao queue
		{
			if(matrix[u][v] != 0 && chuaxet[v]==TRUE)
			{
				Insert_q(q,v);
				chuaxet[v]=FALSE;
			}
		}
	}
}
//================DFS Stack=================
void DFS(int kq[],int &sl) // diem bat dau u
{
	int u;
	Chondinh(u);
	ClearLog();
	//Khoi tao
	sl=0;
	ReInit();
	int s,t,dau; // t là Ke cua s, Dinh hien tai dang xet la s 
	push(st1,u);
	chuaxet[u] = FALSE;
	kq[sl]=u;
	sl++;
	//cout<<" Duong di: "<< (char)(u+'A'-1)<<" "; // Duyet dinh dau 
	// Duyet duong di con` lai 
	// Vong lap
	while(Empty(st1) == FALSE)
	{
		pop(st1,s);
		for(t = 0; t <n; t++)
		{
			if(chuaxet[t] == TRUE && matrix[s][t] !=0) // Tim diem ke` nho nhat cua s de day vao stack
			{
				//cout<<(char)(t+'A'-1)<<" ";
				kq[sl]=t;
				sl++;
				chuaxet[t] = FALSE;
				push(st1,s); 
				push(st1,t);
				break; // Day xong quay tro lai vong while de pop s;
			}
		}
	}
	
}
//==================Dijkstra==================

void D_Init()
{
	for(int i=0; i<n; i++)
{
	for(int j=0; j<n; j++)
{
    if(matrix[i][j] == 0)
    {
		matrix[i][j] = VOCUNG;	
    }
}
}
}

void R_Init()
{
for(int i=0; i<n; i++)
{
for(int j=0; j<n; j++)
{
    if(matrix[i][j] == VOCUNG)
    {
		matrix[i][j] = 0;	
    }
}
}
}

int Dijkstra(int kq[],int &sl, int &r){
//KHOI TAO
int s,t;
sl=0;
r=0;
Chondinh(s);
Chondinh2(t);
while(s==t)
{
	ClearLog();
	TextLog(TEXTCOLOR2);
	outtextxy(XLOG,getmaxy()/(2)+100,"Xin hay chon dinh dau va cuoi khac nhau!");
	delay(1000);
	ClearLog();
	Dinhcolor(dothi[s],CIRCLECOLOR);
	//Dinhcolor(dothi[t],CIRCLECOLOR);
	Chondinh(s);
	Chondinh2(t);
}
ClearLog();
D_Init();
int u, minp=VOCUNG;
for (int v = 0; v < n; v++)
{
	d[v] = matrix[s][v];
  	truoc[v] = s;
  	chuaxet[v] = TRUE;
}
	truoc[s] = -1;
	d[s] = -1;
	chuaxet[s] = FALSE;
//VONG LAP
while (chuaxet[t]==TRUE) 
{
	minp=VOCUNG;
  	for (int v = 0; v < n; v++)
	{
   		if ((chuaxet[v]==TRUE) && (minp > d[v]))
		{
    		u = v;
    		minp = d[v];
   		}	
	}
	if(minp==VOCUNG)
	{
		delay(700);
		Dinhcolor(dothi[s],CIRCLECOLOR);
		Dinhcolor(dothi[t],CIRCLECOLOR);
		R_Init();
		return 0;
	}
  	chuaxet[u] = FALSE;
  	if (chuaxet[t]==TRUE)
	{
   		for (int v = 0; v < n; v++)
		{
	    	if ((chuaxet[v]==TRUE) && (d[u] + matrix[u][v] < d[v]))
			{
	     		d[v] = d[u] + matrix[u][v];
	     		truoc[v] = u;
	    	}
	   	}
  	}
}
kq[sl]=t;
sl++;
int i=truoc[t];
while(i!=s)
{
	kq[sl]=i;
	sl++;
	i = truoc[i];
}
kq[sl]=s;
sl++;
r=d[t];
R_Init();
return 1;
}
//==================Topo Sort==========================
void PickTopo()
{
	re:
		
	sl1=0;
	int yy=getmaxy()/(2)+100;
	ClearLog();
	TextLog(TEXTCOLOR);
	outtextxy(XLOG,yy,"Nhan (LMB) de Chon cac mon da dat! ");
	yy+=30;
	outtextxy(XLOG,yy,"Nhan Enter de Tiep tuc =>");
	while(1)
	{
		re1:
			
		delay(DELAY);
		if(ismouseclick(WM_LBUTTONDOWN))
		{
			int x,y;
			getmouseclick(WM_LBUTTONDOWN,x,y);
			if(IsDinh(x,y))
			{
				int tmp=PickDinh(x,y);
				for(int i=0;i<sl1;i++)
				{
					if (tmp == kq1[i])
					{
						Dinhcolor(dothi[tmp],CIRCLECOLOR);
						for(int j=tmp+1;j<sl1;i++)
						{
							swap(dothi[tmp],dothi[j]);
						}
						sl1--;
						goto re1;
					}
				}
				kq1[sl1]=PickDinh(x,y);//Lay so dinh dua theo x,y (chua kiem tra trung dinh)
				sl1++;
				Dinhcolor(dothi[kq1[sl1-1]],CYAN);
			}
		}
		if(kbhit())
		{
			char c=getch();
			if(c==13)//Enter
			{
				break;//Khi chua bam enter thi van cho chon dinh
			}
		}
	}
	if(sl1==n)
	{
		ReDraw();
		goto re;
	}
}

void PickTopo2(int kq[], int &sl)
{
	sl=0;
	ClearLog();
	TextLog(TEXTCOLOR);
	int yy=getmaxy()/(2)+100;
	outtextxy(XLOG,yy,"Nhan (LMB) de Chon cac mon muon hoc! ");
	yy+=30;
	outtextxy(XLOG,yy,"Nhan Enter de Tiep tuc =>");
	while(1)
	{
		delay(DELAY);
		if(ismouseclick(WM_LBUTTONDOWN))
		{
			int x,y;
			getmouseclick(WM_LBUTTONDOWN,x,y);
			if(IsDinh(x,y))
			{
				kq[sl]=PickDinh(x,y);//Lay so dinh dua theo x,y (chua kiem tra trung dinh)
				if(sl1==0)
				{
					Dinhcolor(dothi[kq[sl]],BLUE);
					sl++;
				}
				else{
				for(int i=0;i<sl1;i++)
				{
					kq[sl]=PickDinh(x,y);//Lay so dinh dua theo x,y (chua kiem tra trung dinh)
					if(kq[sl]==kq1[i])
					{
						ClearLog();
						TextLog(TEXTCOLOR2);
						yy=getmaxy()/(2)+100;
						outtextxy(XLOG,yy,"Lam on khong chon mon da dat!");
						delay(1000);
						ClearLog();
						TextLog(TEXTCOLOR);
						outtextxy(XLOG,yy,"Nhan (LMB) de Chon cac mon muon hoc! ");
						yy+=30;
						outtextxy(XLOG,yy,"Nhan Enter de Tiep tuc =>");
						break;
					}
					if(i==sl1-1)
					{
						Dinhcolor(dothi[kq[sl]],BLUE);
						sl++;
					}
				}
			}
				
			}
		}
		if(kbhit())
		{
			char c=getch();
			if(c==13)//Enter
			{
				if(sl==0)
				{
					ClearLog();
					TextLog(TEXTCOLOR2);
					outtextxy(XLOG,yy,"Lam on chon it nhat 1 mon muon hoc!");
					delay(1000);
					ClearLog();
					TextLog(TEXTCOLOR);
					yy=getmaxy()/(2)+100;
					outtextxy(XLOG,yy,"Nhan (LMB) de Chon cac mon muon hoc! ");
					yy+=30;
					outtextxy(XLOG,yy,"Nhan Enter de Tiep tuc =>");
				}
				else
				break;//Khi chua bam enter thi van cho chon dinh
			}
		}
	}
}

int DFS_T(int u,stack &kq) // diem bat dau u
{
	int s,t,dau; // t là Ke cua s, Dinh hien tai dang xet la s 
	push(st1,u);
	chuaxet[u] = FALSE;
	//cout<<" Duong di: "<< (char)(u+'A'-1)<<" "; // Duyet dinh dau 
	// Duyet duong di con` lai 
	while(Empty(st1) == FALSE)
	{
		pop(st1,s);
		for(t = 0; t <n; t++)
		{
			if(matrix[s][t]!=0 && t==u)
			{
				//cout<<"Khong phai do thi DAG!";
				while(Empty(kq)==FALSE)
				{
					pop(kq,dau);
				}
				return 0;
			}
			if(chuaxet[t] == TRUE && matrix[s][t] !=0) // Tim diem ke` nho nhat cua s de day vao stack
			{
				//cout<<(char)(t+'A'-1)<<" ";
				chuaxet[t] = FALSE;
				push(st1,s); 
				push(st1,t);
				break; // Day xong quay tro lai vong while de pop s;
			}
			if(t==(n-1))
			{
				push(kq,s);
			}
		}
		
	}
return 1;	
}
int Topo_Sort(stack &kq)
{
	ReInit();
	int check,x;
	for(int i=0; i<n; i++)
	{
		if(chuaxet[i]==TRUE)
		{
			check = DFS_T(i,kq);
			if (check ==0)
			return 0;
		}
	}
	//cout<<"Topo sort: ";
return 1;
}
void FindRoot(int kq[], int &sl)
{
	sl=0;
	for(int i=0; i<n; i++)
	{
		for(int k=0;k<n;k++)
		{
			if(matrix[k][i] !=0)
			{
				break;
			}
			else if( k==(n-1))
			{
				kq[sl]=i;
				sl++;
			}
		}
	
	}
}
//================TPLT manh aka Tarjan===============

int min(int a, int b)
{
	KT=0;
	if(b<a)
	{
		KT=1;
		return b;
	}
	else
	return a; 
}
void UpdateK(int s)
{
int check;
	for(int i=0;i<n;i++)
	{
		if(matrix[i][s] != 0)
		{
			low[i] = min(low[i],low[s]);
			if(KT==1)
			{
				UpdateK(i);
			}
		}
	}
}
void T_Init()
{	id=0;
	TPLT=0;
	for(int i=0; i<n; i++)
	{
		chuaxet[i]=TRUE;
		Onstack[i]=FALSE;
	}
}

void DFS_Stack(int u,PTR A[]) // diem bat dau u
{
	//Khoi tao
	int s,t,check; // t là Ke cua s, Dinh hien tai dang xet la s 
	push(st1,u);
	chuaxet[u] = FALSE;
	Onstack[u] = TRUE;
	low[u]=index[u]=id;
	id++; 
	// Duyet duong di con` lai 
	// Vong lap
	while(Empty(st1) == FALSE)
	{
		pop(st1,s);
		for(t = 0; t <n; t++)
		{
			if( matrix[s][t] !=0)
			{ // Tim diem ke` nho nhat cua s de day vao stack
			if(chuaxet[t]==TRUE)
				{
				//cout<<(char)(t+'A'-1)<<" ";
				chuaxet[t] = FALSE;
				push(st1,s); 
				push(st1,t);
				Onstack[t]=TRUE;
				low[t] = index[t]=id;
				id++;
				break; // Day xong quay tro lai vong while de pop s;
				}
			if(Onstack[t]==TRUE)
				{
				low[s]= min(low[s],low[t]);
				if(KT==1)
				{
					UpdateK(s);
				}
				}
			}	
			if(t==(n-1) && low[s]==index[s])
			{
				TPLT++;
				//cout<<TPLT<<": "<<s<<" ";
				A[TPLT-1] = AddTail(A[TPLT-1],s);
				Onstack[s]=FALSE;
				for(int i=0;i<n;i++)
				{
					if(Onstack[i]==TRUE && low[s]==low[i])
					{
						Onstack[i]=FALSE;
						//Cho i vao mang
						//cout<<i<<" ";
						A[TPLT-1] = AddTail(A[TPLT-1],i);
					}	
				}
				//cout<<endl;
			}
		}
	}
	
}
void Tarjan(PTR A[])
{
for(int i=0;i<n;i++)
{
	if(chuaxet[i]==TRUE)
	DFS_Stack(i,A);
}
}
//=====================TPLT Vo huong========================
void BFS_VH(int u,PTR kq[])
{
	int v;
	Insert_q(q,u); 
	//cout<<"Duong di: ";
	chuaxet[u] = FALSE;
	while(empty(q) == FALSE)
	{
		Delete_q(q,u); // Day gia tri vao u de duyet
		//cout<<u<<" ";
		kq[TPLT-1] = AddTail(kq[TPLT-1],u);
		for(v=0;v<n;v++) //Day toan bo Ke cua u vao queue
		{
			if(matrix[u][v] != 0 && chuaxet[v]==TRUE)
			{
				Insert_q(q,v);
				chuaxet[v]=FALSE;
			}
		}
	}
}
void LTVH(PTR kq[])
{
	for (int i=0; i<n; i++)
	{
		if(chuaxet[i]==TRUE) 
		{
			TPLT++;
			//cout<<"BFS("<<TPLT<<"): ";
			BFS_VH(i,kq);
			cout<<endl;
		}
	}
}

//===================Giai thuat Uy===================
int test_lienthong(){
	for(int u=0; u<n;u++)
		if(chuaxet[u]==TRUE) return 1;
	return 0;
}

void DFS_stack2(int u) // diem bat dau u
{
	int s,t,dau; // t là Ke cua s, Dinh hien tai dang xet la s 
	push(st1,u);
	chuaxet[u] = FALSE;
	while(Empty(st1) == FALSE)
	{
		pop(st1,s);
		for(t = 0; t <n; t++)
		{
			if(chuaxet[t] == TRUE && matrix[t][s] != 0) // Tim diem ke` nho nhat cua s de day vao stack
			{
				chuaxet[t] = FALSE;
				push(st1,s); 
				push(st1,t);
				break; // Day xong quay tro lai vong while de pop s;
			}
		}
	}
	
}

void EulerCycle(int u,int &dCE,int CE[]){
int v, x, top=0;
  int STACK[100];
  STACK[top]=u;
  do{
    v = STACK[top];
	x=0;
    while (x<n && matrix[v][x]==0){
    	x++;
	}
    if (x>n-1) {
    	dCE++;
		CE[dCE]=v;
		top--;
    }
    else{
    	top++;
		STACK[top]=x;
    	matrix[v][x]=0;
		matrix[x][v]=0;
    }
  } while(top!=-1);
}

void Hamilton(int u,int X[],int &dem,int &xx, int &yy){
	for (int y=0; y<n; y++){
		if (matrix[X[u-1]][y] != 0){
			if( (u==n) && (y==0)){
				GhiNhan(X,dem,xx,yy);
			}
			else if (chuaxet[y] == 1){
				X[u] = y;
				chuaxet[y] = 0;
				Hamilton(u+1,X,dem,xx,yy);
				chuaxet[y] = 1;
            }
        }
    }
}

void GhiNhan(int X[],int &dem, int &xx, int &yy){
	TextLog(TEXTCOLOR);
	if(dem==0){
		outtextxy(xx,getmaxy()/(2)+100,"Cac chu trinh Hamilton:");
	}
	for(int i=0;i<n;i++){
		cout<<dothi[i].name;
		setcolor(VARCOLOR);
		outtextxy(xx,getmaxy()/(2)+100+yy,dothi[X[i]].name);
		xx=xx+20;
		if(i!=n){
			if(xx>=1240){
				yy=yy+30;
				xx=XLOG;
			}
			setcolor(TEXTCOLOR);
			outtextxy(xx,getmaxy()/(2)+100+yy,"-");
			xx=xx+20;
		}
		setcolor(VARCOLOR);
		outtextxy(xx,getmaxy()/(2)+100+yy,dothi[X[0]].name);
	}
	dem++;
	yy=yy+30;
	xx=XLOG;
	
}
bool ktralt(int a, int b){
	int s,t;
	push(st1,a);
	chuaxet[a]=FALSE;
	while(Empty(st1)==FALSE){
		pop(st1,s);
		for(t=0;t<n;t++){
			if(chuaxet[t]==TRUE && matrix[t][s]!=0){
				if(t==a){
					while(Empty(st1)==FALSE){
						pop(st1,s);
					}
					return FALSE;
				}
				else{
					if(t==b){
						while(Empty(st1)==FALSE){
							pop(st1,s);
						}
						return TRUE;
					}
					else{
						chuaxet[t]=FALSE;
						push(st1,s);
						push(st1,t);
						break;
					}
				}
			}
		}
	}
	return FALSE;
}
void tmpdel(int A[],int B[], int k){
	for(int i=0;i<n;i++){
		A[i]=matrix[i][k];
		matrix[i][k]=0;
	}
	for(int i=0;i<n;i++){
			B[i]=matrix[k][i];
			matrix[k][i]=0;
	}
}
void readd(int A[],int B[], int k){
	for(int i=0;i<n;i++){
		matrix[i][k]=A[i];
		A[i]=0;
	}
	for(int i=0;i<n;i++){
			matrix[k][i]=B[i];
			B[i]=0;
	}
}
