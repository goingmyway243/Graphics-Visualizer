#include "CTDL.h"
#include "Linhtinh.h"
#include "Dinh.h"
#include "Matran.h"
#include "Giaodien.h"
#include "Canh.h"
using namespace std ;

//============ main ============
int main()
{
	//srand(time(NULL));
    initwindow(1280,700);
    draw_menu();
    //InitMatrix(MAX);
    while(check==true)
    {
    	delay(DELAY);
    	if(ismouseclick(WM_MOUSEMOVE))
    	{
    		GetMouse(menu);
		}
		if(kbhit())
		{
			char c=getch();
			if(c==27)
			{
				break;
			}
		}
	}
    closegraph();
    return 0;
}
