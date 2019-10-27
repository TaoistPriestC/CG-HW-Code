#include <iostream>
#include <GL/glew.h>
#include <GL/gl.h>  
#include <GL/glu.h>  
#include <GL/glut.h> 
#include <math.h>
#include <time.h>
const GLfloat R = 0.5f;
const GLfloat pi = 3.1415926536f;

void init(void) {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glEnable(GL_POINT_SMOOTH);
	srand((unsigned)time(NULL));
	//this command "GL_POINT_SMOOTH"  change the square pixed to smooth circle
}

void circle(float x, float y, int size) {
	glPointSize(size);
	glBegin(GL_POINTS);
	glVertex3f(x, y, 0.0);
	glEnd();

	//使用多边形模式画圆
	/*
	glBegin(GL_POLYGON);
	for (int i = 0; i < 100; i++)
	{
		glVertex2f(x+0.04* cos(2 * pi / 100 * i), y+0.04* sin(2 * pi / 100 * i));
	}
	glEnd();
	*/
}

void points(float x1, float y1, float x2, float y2, int n) {
	float x = x1, y = y1;
	for (int i = 0; i < n; ++i) {
		float xp = (x2 - x) + 0.4 * (rand() % 2050 - 1000) / 1005;
		float yp = (y2 - y) + 0.4 * (rand() % 2050 - 1000) / 1005;
		float d = sqrt(xp * xp + yp * yp);
		xp = xp / d;
		yp = yp / d;
		int size = rand() % 50;
		x += xp * size / 525;
		y += yp * size / 525;
		circle(x, y, size);
	}
}



void lineSegment(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);
	//左上
	glColor3f(0.8, 0.8, 0.8);
	glVertex3f(-1.0, 1.0, 0.0);
	//右上
	glColor3f(0.08, 0.33, 0.85);
	glVertex3f(1.0, 1.0, 0.0);
	//右下
	glColor3f(0.8, 0.8, 0.8);
	glVertex3f(1.0, -1.0, 0.0);
	//左下
	//glColor3f(0.5, 0.5, 0.8);
	glColor3f(0.54, 0.84, 1.00);
	glVertex3f(-1.0, -1.0, 0.0);
	//设置四个顶点，然后自动形成渐变效果
	glEnd();


	//画太阳部分
	glColor3f(1.0, 1.0, 1.0);
	//circle(-1, 1, 2000);
	//glClear(GL_COLOR_BUFFER_BIT);
	//glClear(GL_COLOR_BUFFER_BIT)函数的作用是清空颜色位的缓存，全部置为零(变黑)
	const GLfloat R = 0.3f;
	const GLfloat pi = 3.1415926536f;
	glBegin(GL_POLYGON);
	for (int i = 0; i < 100; i++){
		glVertex2f(-1+R * cos(2 * pi / 100 * i), 1+R * sin(2 * pi / 100 * i));
	}
	glEnd();
	glFlush();
	//glutDisplayFunc(display);


	//画云部分
	glColor3f(1.0, 1.0, 1.0);
	circle(-0.6, 0.6, 50);
	points(-0.75, 0.6, 1, 0.6, 10);
	glColor3f(0.95, 0.95, 0.95);
	circle(-0.2, 0.7, 50);
	points(-0.35, 0.7, 1, 0.7, 10);
	glColor3f(0.90, 0.90, 1.0);

	circle(0.2, 0.6, 50);
	points(0.05, 0.6, 1, 0.6, 50);

	for (int i = 0; i < 5; ++i) {
		float c = 0.75 + 0.05 * i;
		glColor3f(c, c, c);
		points(0.1 + 0.05 * i, 0.1 + 0.05 * i, 1, 0.1 + 0.05 * i, 24 - 3 * i);
	}

	glFlush();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(700, 600);
	glutCreateWindow("Demo");

	glewInit();

	init();
	glutDisplayFunc(lineSegment);
	glutMainLoop();
}
