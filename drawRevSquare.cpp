#include <gl/glut.h>
#include <math.h>
#include <stdio.h>
#include <windows.h>

const double PI = 3.1415926;

//设置窗口
GLsizei winWidth = 600;
GLsizei winHeight = 600;

//图形的基本参数
int cirR = winWidth	 / 3;   
int posX = winWidth  / 2 + cirR;
int posY = winHeight / 2;		
int move = 0;
int squreSize = 36;

//根据转动的角度确定平移的距离
double angle = 0;	


//画弧
void drawArc(double x0, double y0, double theta0, double thetaED, double radius, int MODE){
	double delta_angle = PI / 180;
	glBegin(MODE);
	for (double i = theta0; i <= thetaED; i = i+delta_angle){
		//圆形参数方程
		double x = x0 + radius * cos(i);
		double y = y0 + radius * sin(i);
		glVertex2d(x, y);
	}
	glEnd();

}

//画圆
void drawCircle(double x, double y, double radius, int MODE){
	drawArc(x, y, 0, 2 * PI, radius, MODE);
}


//画矩形
void glRect(int leftX, int downY, int rightX, int upY, int MODE) {
	//根据左上/下/右下/右上,确定封闭曲线.
	glBegin(MODE);
	glVertex2d(leftX, upY);
	glVertex2d(leftX, downY);
	glVertex2d(rightX, downY);
	glVertex2d(rightX, upY);
	glEnd();
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);	
	glColor3ub(0, 0, 0);	
	drawCircle(winWidth / 2, winHeight / 2, cirR, GL_LINE_LOOP);

	//画连接线,使用直线参数方程
	glBegin(GL_LINE_STRIP);
	glVertex2d(winWidth / 2, winHeight / 2);  
	glVertex2d(posX + cirR * (cos(-angle) - 1), posY + cirR * sin(-angle)); 
	glEnd();

	//利用旋转和平移矩阵实现图形的变化:
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslated(winWidth / 2, winHeight / 2, 0);			
	glRotated(-move / 4, 0.0, 0.0, 1.0);
	glTranslated(-winWidth / 2, -winHeight / 2, 0);			
	glTranslated(posX, posY, 0);
	glTranslated(-posX, -posY, 0);
	
	//小方块的颜色
	glColor3ub(0, 0, 0);
	glRect(posX - squreSize, posY - squreSize, posX + squreSize, posY + squreSize, GL_POLYGON);
	glLoadIdentity(); 
	glFlush();
	Sleep(20);
	angle = angle + (PI/180); 
	move  = move  +  4;
	glutPostRedisplay();
}


void init(void){
	glClearColor(1.0, 1.0, 1.0, 1.0);  
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-600.0, 600.0, -600.0, 600.0);
}

//窗口大小变动
void winReshapeFcn(GLint newWidth, GLint newHeight)  {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, GLdouble(newWidth), 0.0, GLdouble(newHeight));
	winWidth  = newWidth;
	winHeight = newHeight;
	glClear(GL_COLOR_BUFFER_BIT);
	glutPostRedisplay();  
}

void main(int argc, char** argv){
	//-采用双缓冲的显示模式的模板-//
	glutInit(&argc, argv);						
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(winWidth, winHeight);
	glutCreateWindow("myhomework_chenzicong");
	//-采用双缓冲的显示模式的模板-//

	init();
	glutDisplayFunc(display);
	glutReshapeFunc(winReshapeFcn);	

	glutMainLoop();  
}
