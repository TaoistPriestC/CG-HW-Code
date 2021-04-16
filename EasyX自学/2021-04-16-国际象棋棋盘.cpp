#include <time.h>
#include <conio.h>						// 引用控制台IO头文件
#include <graphics.h>					// 引用图形绘制库头文件

int step = 50;
int maxRC = 8;
int main(){
	//initgraph(640, 480);
	initgraph(500, 500);
	setbkcolor(WHITE);
	cleardevice();

	for (int i = 1; i <= maxRC; i++) {
		for (int j = 1; j <= maxRC; j++) {
			setfillcolor(((i + j) & 1) ? BLACK : WHITE);                            //按照奇偶性区分方块颜色
			solidrectangle(i * step, j * step, (i + 1) * step, (j + 1) * step);
		}
	}

	setlinecolor(BLACK);
	setlinestyle(PS_SOLID, 3);
	rectangle(step, step, 500 - step, 500 - step);                              //绘制棋盘的边框

	_getch();
	closegraph();						
	return 0;
}
