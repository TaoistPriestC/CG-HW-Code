#include "GL\glut.h"

static int year = 0, day = 0;

void display(void){

	glClear(GL_COLOR_BUFFER_BIT);  
	//清空颜色缓冲区
	glColor3f(1, 1, 1);   
	//重置颜色，白色
	glPushMatrix();  
	//压栈
	glutWireSphere(1, 20, 16);   
	//绘制太阳
	glRotatef((GLfloat)year, 0, 1, 0);  
	//沿y轴旋转 
	glTranslatef(3, 0, 0); 
	//将场景中的物体沿x轴正方向移动2个单位长
	glRotatef((GLfloat)day, 0, 1, 0);  
	//沿y轴旋转
	
	//绘制行星
	glutWireSphere(0.2, 10, 8);  
	
	//出栈
	glPopMatrix(); 
	glutSwapBuffers();
	glFlush();   
	//刷新窗口以显示当前绘制图形
}


void init(void)
{
	glClearColor(0, 0, 0, 0);
	glShadeModel(GL_FLAT); 
	//选择平面明暗模式或光滑明暗模式
}

void reshape(int w, int h){
	//设置机口
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);   
	//指定哪一个矩阵是当前矩阵
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity();
	//指定哪一个矩阵是当前矩阵
	gluPerspective(60, (GLfloat)w / (GLfloat)h, 1.0, 20); 
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(0, 5, 5, 0, 0, 0, 0, 1, 0);
}

void keyboard(unsigned char key, int x, int y){
	switch (key)
	{
	case 'd':
		day = (day + 10) % 360;
		glutPostRedisplay();
		break;
	case 'D':
		day = (day - 10) % 360; // 大写情况下是逆向的
		glutPostRedisplay();
		break;
	case 'y':
		year = (year + 5) % 360;
		glutPostRedisplay();
		break;
	case 'Y':
		year = (year - 5) % 360;  // 大写情况下是逆向的
		glutPostRedisplay();
		break;
	default:
		break;
	}
}

int main(int argc, char* argv[]){
	glutInit(&argc, argv); 
  //固定格式
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);   
  //缓存模式
	glutInitWindowSize(600, 600);    
  //显示框的大小
	glutInitWindowPosition(100, 100); 
  //确定显示框左上角的位置
	glutCreateWindow("chenzicong_homework");
	init(); 
	glutDisplayFunc(display); 
  // 执行显示
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMainLoop(); 
  //进人GLUT事件处理循环
	return 0;
}
