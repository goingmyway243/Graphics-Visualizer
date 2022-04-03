#pragma once

#include <iostream>
#include <graphics.h>
#include <math.h>
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <fstream>
#include <cstring>

using namespace std;

#define DELAY .001
#define MAX 20
#define BK 25 //ban kinh r
#define QUEUESIZE 50
#define STACKSIZE 50
#define VOCUNG 100000
#define TRUE 1
#define FALSE 0

#define MENUCOLOR 2
#define MENUTEXTCOLOR 15
#define MENUBKCOLOR 7
#define VARCOLOR 3
#define CIRCLECOLOR 14
#define BKCOLOR 0
#define TEXTCOLOR 14
#define TEXTCOLOR2 4
#define TEXTDINH 4
#define XLOG 860

struct Toado{
	int x;
	int y;
	char* name;
};

struct stack
{
	int sp= -1;
	int nodes[STACKSIZE];
} st1, st2;

struct queue 
{
	int front= -1, rear=-1;
	int nodes[MAX];
}q;



Toado dothi[MAX];
Toado menu[MAX];
//int **matrix;
int matrix[MAX][MAX];
bool check=true;  //dk de thoat chuong trinh
bool dk=true;  //dk de break menu con
int n=0,TPLT=0,id=0,KT=0;  //Tong so dinh trong do thi
int kq1[MAX],sl1;
int chuaxet[MAX], truoc[MAX], d[MAX],index[MAX],low[MAX],Onstack[MAX];
bool nguocchieu[MAX][MAX]={false};

//==========Tao DSLK===================
struct list{
	int data ;//info
	struct list* next;
};

typedef struct list * PTR;

PTR InitHead(){
    PTR head;
    head = NULL;
    return head;
}

PTR CreateList(int value){
    PTR temp; // declare a node
    temp = new list;
    temp->next = NULL;
    temp->data = value; 
    return temp;
}

PTR AddTail(PTR head, int value){
    PTR temp,p;
    temp = CreateList(value);
    if(head == NULL){
        head = temp;     
    }
    else{
        p  = head;
        while(p->next != NULL){
            p = p->next;
        }
        p->next = temp;
    }
    return head;
}
PTR DelHead(PTR head){
    if(head == NULL){
        printf("\nCha co gi de xoa het!");
    }else{
        head = head->next;
    }
    return head;
}
PTR DelList(PTR head)
{
	if(head != NULL)
	{
		DelHead(head);
	}
}
//===============queue=============
int empty(struct queue q)
{
   return((q.front == -1 || q.rear== -1) ? TRUE : FALSE);
}

void Insert_q(struct queue &q, int x)
{
   if (q.rear - q.front + 1== 0 || q.rear -q.front+1== QUEUESIZE)
   {
      printf("\nHang bi day");
   }
   else
   {
      if(q.front==-1)
      { q.front=0;
	q.rear =-1;
      }
      if (q.rear==QUEUESIZE-1) q.rear=-1;
      ++q.rear;
      q.nodes[q.rear]=x;
   }
}

int Delete_q(struct queue &q, int &x)
{
   if(empty(q))
      return 0;
  x= q.nodes[q.front];
  if(q.front == q.rear)  // Hang chi co 1 phan tu
      {
	 q.front = -1;
	 q.rear  = -1;
      }
      else
      {
	 (q.front)++;
	 if (q.front ==QUEUESIZE)
	   q.front=0;
      }
      return 1;
 }
 
 //=========stack=======
int Empty(struct stack st)
{
   if(st.sp == -1)
      return(TRUE);
   else
      return(FALSE);
}
int Full(struct stack st)
{
	if (st.sp == STACKSIZE - 1)
	return(TRUE);
	else return(FALSE);
}

void push (stack &st, int x)
{
   if(Full(st) == TRUE)  cout<<"STACK DAY";
   st.nodes[++(st.sp)] = x;
}

void pop(stack &st, int &x)
{
   if(st.sp==-1)  cout<<"STACK RONG~";
   x=st.nodes[(st.sp)--];
}
