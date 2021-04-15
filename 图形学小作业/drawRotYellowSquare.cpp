
#include <GL/glut.h>
#include <math.h>
#define DEG_TO_RAD 0.017453
GLfloat theta = 0.0;
void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);
	glVertex2f(0.1*sin(DEG_TO_RAD * theta), 0.1 * -cos(DEG_TO_RAD * theta));
	glVertex2f(0.1 * -cos(DEG_TO_RAD * theta), 0.1 * -sin(DEG_TO_RAD * theta));
	glVertex2f(0.1 * -sin(DEG_TO_RAD * theta), 0.1 * cos(DEG_TO_RAD * theta));
	glVertex2f(0.1 * cos(DEG_TO_RAD * theta), 0.1 * sin(DEG_TO_RAD * theta));
	glTranslatef(0.0f, -20.0f, -40.0f);
	glRotatef(-80.0f, 10.0f, 1.0f, 0.0f);
	glEnd();
	//flush GL  buffers
	glFlush();
}
void myidle(){
	theta += 0.2;
	if (theta > 360.0)
		theta -= 360.0;
	glutPostRedisplay();


}
void init(){
	//set color to black
	glClearColor(0.0, 0.0, 0.0, 0.0);
	//set fill color to white
	glColor3f(1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-1.0,1.0,-1.0,1.0);

}
int main(int argc, char* argv[]){
	/* code */
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("chenzicong_homework");
	glutDisplayFunc(display);
	init();
	glutIdleFunc(myidle);
	glutMainLoop();
	return 0;
}
