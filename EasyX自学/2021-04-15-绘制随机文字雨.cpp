#include <time.h>
#include <conio.h>						 // 引用控制台IO头文件
#include <graphics.h>				        	 // 引用图形绘制库头文件

char c;
int  x, y;

int main() {
	srand((unsigned)time(NULL));		    		// 初始化随机函数种子
	initgraph(640, 480);				        // 初始化图形模式
	settextstyle(16, 8, _T("Courier"));			// 设置字体
	settextcolor(GREEN);				        // 设置文本颜色
	setlinecolor(BLACK);				        // 设置线条颜色

	for (int i = 0; i < 480; i = (i + 1) % 480) {
		for (int j = 0; j < 3; j++) {	    		// 在随机位置显示三个随机字母
			x = (rand() % (80 + 1)) * 8;		// 文本坐标x [0,640]
			y = (rand() % (20 + 1)) * 24;		// 文本坐标y [0,480]
			c = (rand() % 26) + 65;
			outtextxy(x, y, c);             	// 输出文本
		}	
		line(0, i, 640, i);				// 画线擦掉一个像素行
		Sleep(15);					// 设置延时出现
		if (_kbhit())	break;		      	  	// 按任意键退出
	}
	closegraph();						// 关闭图形模式
	return 0;
}
