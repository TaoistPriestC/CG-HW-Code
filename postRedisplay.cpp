#include <GL/glut.h>
#include <stdlib.h>

static GLdouble axix = 0.0, axiy = 0.0, z = 0.0;
void init(void){
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
}

void display(void){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glLoadIdentity();             /* clear the matrix */
			/* viewing transformation  */
	gluLookAt(axix, axiy, z, 0.0, 0.0, 0.0, 1.0, 1.0, 0.0);
	glScalef(1.0, 2.0, 1.0);      /* modeling transformation */
	glutWireCube(1.0);
	glFlush();
}

void reshape(int w, int h){
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	// glFrustum (-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
	gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 1.5, 20.0);
	glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case 'd':
		axix += 1.0;
		glutPostRedisplay();
		break;
	case 'a':
		axix -= 1.0;
		glutPostRedisplay();
		break;
	case 'w':
		z -= 1.0;
		glutPostRedisplay();
		break;
	case 's':
		z += 1.0;
		glutPostRedisplay();
		break;
	case 27:
		exit(0);
		break;
	}
}

int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}
