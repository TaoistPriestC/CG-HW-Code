#include <time.h>
#include <conio.h>						// 引用控制台IO头文件
#include <graphics.h>						// 引用图形绘制库头文件

int step = 50;
int maxRC = 8;
int left, top, right, bottom, tx, ty, cnt;
wchar_t s[3];

int main(){
	//initgraph(640, 480);
	initgraph(500, 500);

	setbkcolor(WHITE);
	cleardevice();

	setbkmode(TRANSPARENT);
	settextstyle(15, 0, _T("Arial"));
	for (int i = 1; i <= maxRC; i++) {
		for (int j = 1; j <= maxRC; j++) {
			setfillcolor(((i + j) & 1) ? BLACK : WHITE);
			settextcolor(((i + j) & 1) ? WHITE : BLACK);

			left = i * step,   right = (i + 1) * step;
			top  = j * step,  bottom = (j + 1) * step;
			solidrectangle(left, top, right, bottom);     	// 绘图是自左向右的按列的绘制的
			
			tx = left + (right - left) / 3;
			ty = top + (bottom - top)  / 3;
			cnt = (j - 1) * maxRC + i;                      // 计数

			_itow_s(cnt, s, 10);                            // 内置的函数，能够进行数字到字符串的转化，进制：10
			if (cnt < 10) {
				s[2] = s[1], s[1] = s[0], s[0] = '0';   // 对于不足两位数的进行零填充
			}
			outtextxy(tx, ty, s);
		}
	}

	setlinecolor(BLACK);                                // 设置线条的颜色
	setlinestyle(PS_SOLID, 3);                          // 设置线条的粗细
	rectangle(step, step, 500 - step, 500 - step);      

	_getch();
	closegraph();						
	return 0;
}

