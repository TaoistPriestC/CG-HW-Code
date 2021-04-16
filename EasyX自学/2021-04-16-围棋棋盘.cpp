#include <time.h>
#include <conio.h>						// 引用控制台IO头文件
#include <graphics.h>					// 引用图形绘制库头文件


int step = 30;
int maxRC = 19;
int main(){
	initgraph(600, 600);
	setbkcolor(YELLOW);
	cleardevice();

	setlinestyle(PS_SOLID, 3);
	setlinecolor(BLACK);

	for (int i = 1; i <= maxRC; i++) {
		line(1 * step, i * step, 19 * step, i * step);		
		line(i * step, 1 * step, i * step, 19 * step);
	}
	_getch();
	closegraph();
	return 0;
}

