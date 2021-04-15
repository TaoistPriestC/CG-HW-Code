#include <time.h>
#include <conio.h>			// 引用控制台IO头文件
#include <graphics.h>			// 引用图形绘制库头文件

int x0 = 320;				// 窗口宽度的一半
int y0 = 240;				// 窗口高度的一半
int r0 = 50;				// 圆形的半径
int R0 = 15;				// 循环的圈数 Round
int t = 0;				// 黑白颜色开关 turn

int main(){
	initgraph(640, 480);		// 创建绘图窗口，大小为 640x480像素
	for (int i = 0; i < R0; i+=1, t = (i == R0 ? 1 - t : t), i %= R0) {
		setlinecolor(t ? WHITE : BLACK);
		Sleep(100);
		circle(x0, y0, r0 + i * 10);
		if (_kbhit())break;	// 按任意键返回一个非零值触发break
	}
	closegraph();			// 关闭绘图窗口
	return 0;
}
