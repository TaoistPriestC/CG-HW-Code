#include <windows.h>      
#include <gl/glut.h>      
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define GL_PI  (3.1415f)  
#define oneRad (1.5*GL_PI)


float fMoonRot = 0.0f;
float fAdamRot = 0.0f;
float fEarthRot = 0.0f;
float fMarsRot = 0.0f;
float fMarsatellite1 = 0.0f;
float fMarsatellite2 = 0.0f;
float fHesperRot = 0.0f;
float fJupiterRot = 0.0f;
float fSaturnRot = 0.0f;
float fSaturn1 = 0.0f;
float fUranusRot = 0.0f;
float fNeptuneRot = 0.0f;

GLfloat  whiteLight[] = { 0.2f,0.2f,0.2f,1.0f };
GLfloat  lightPos[] = { 0.0f,0.0f,0.0f,1.0f };

void sun() {
	//draw the sun 
	glColor3ub(255, 50, 0);
	glRotatef(fEarthRot / 25.4, 0.0f, 1.0f, 0.0f);
	glDisable(GL_LIGHTING);   //turn off    
	glutSolidSphere(25.0f, 200.0f, 200.0f);
	glEnable(GL_LIGHTING);    //turn on   
	glLightfv(GL_LIGHT7, GL_POSITION, lightPos);
}

void Adam() {
	glPushMatrix();
	glColor3ub(0, 0, 255);
	glRotatef(fAdamRot, 0.0f, 1.0f, 0.0f);
	glTranslatef(30.0f, 0.0f, 0.0f);
	glutSolidSphere(2.0f, 200.0f, 200.0f);
	fAdamRot += 4.152f;
	if (fAdamRot >= 365.0f)
		fAdamRot = 0.0f;
	glPopMatrix();
}

void Hesper() {
	glPushMatrix();
	glColor3ub(255, 215, 0);
	glRotatef(fHesperRot, 0.0f, 1.0f, 0.0f);
	glTranslatef(40.0f, 0.0f, 0.0f);
	//Hesper's radius is 95% of the earth's, 4.75 
	glutSolidSphere(4.75f, 200.0f, 200.0f);
	//Hesper's period of revolution is 61.56% of the earth's, 1.62
	fHesperRot += 1.62f;
	if (fHesperRot >= 365.0f)
		fHesperRot = 0.0f;
	glPopMatrix();
}

void Earth_Moon() {
	glPushMatrix();
	glColor3ub(0, 0, 255);
	glRotatef(fEarthRot, 0.0f, 1.0f, 0.0f);
	glTranslatef(365.0f, 0.0f, 0.0f);
	glutSolidSphere(5.0f, 20.0f, 20.0f);


	glColor3ub(200, 200, 200);
	glRotatef(fMoonRot, 0.0f, 1.0f, 0.0f);
	glTranslatef(5.0f, 0.0f, 0.0f);
	fMoonRot += 13.3f;
	if (fMoonRot >= 365.0f)
		fMoonRot = 0.0f;
	glutSolidSphere(1.363f, 200.0f, 200.0f);
	glPopMatrix();
	fEarthRot += 1.0f;
	if (fEarthRot >= 365.0f)
		fEarthRot = 0.0f;
}


void Mars() {
	glPushMatrix();
	glColor3ub(255, 0, 0);
	glRotatef(fMarsRot, 0.0f, 1.0f, 0.0f);
	glTranslatef(65.0f, 0.0f, 0.0f);
	glutSolidSphere(2.65f, 200.0f, 200.0f);
	glPushMatrix();
	glColor3ub(255, 100, 100);
	glRotatef(fMarsatellite1, 0.0f, 1.0f, 0.0f);
	glTranslatef(2.0f, 0.0f, 2.0f);
	fMarsatellite1 += 13.3f;
	if (fMarsatellite1 >= 365.0f)
		fMarsatellite1 = 0.0f;
	glutSolidSphere(0.963f, 200.0f, 200.0f);
	glPopMatrix();
	glPushMatrix();
	glColor3ub(255, 200, 200);
	glRotatef(fMarsatellite2, 0.0f, 1.0f, 0.0f);
	glTranslatef(-3.0f, 0.0f, -3.0f);
	fMarsatellite2 += 13.3f;
	if (fMarsatellite2 >= 365.0f)
		fMarsatellite2 = 0.0f;
	glutSolidSphere(1.20f, 200.0f, 200.0f);
	glPopMatrix();
	fMarsRot += 0.5f;
	if (fMarsRot >= 365.0f)
		fMarsRot = 0.0f;
	glPopMatrix();
}


void Jupiter() {
	glPushMatrix();
	glColor3ub(200, 100, 0);
	glRotatef(fJupiterRot, 0.0f, 1.0f, 0.0f);
	glTranslatef(100.0f, 0.0f, 0.0f);
	glutSolidSphere(17.0f, 200.0f, 200.0f);      
	glPushMatrix();
	glColor3ub(250, 180, 0);
	glRotatef(70.0f, 1.0f, 0.0f, 0.0f);
	glutSolidTorus(1.42, 20, 10, 100);
	glPopMatrix();

	fJupiterRot += 0.15f;
	if (fJupiterRot >= 365.0f)
		fJupiterRot = 0.0f;
	glPopMatrix();
}


void Saturn() {
	glPushMatrix();
	glColor3ub(73, 60, 32);
	glRotatef(fSaturnRot, 0.0f, 1.0f, 0.0f);
	glTranslatef(148.0f, 0.0f, 0.0f);
	glutSolidSphere(15.0f, 200.0f, 200.0f);
	glPushMatrix();
	glColor3ub(255, 200, 200);
	glRotatef(fSaturn1, 0.0f, 1.0f, 0.0f);
	glTranslatef(-17.0f, 0.0f, -17.0f);
	fSaturn1 += 6.4f;
	if (fSaturn1 >= 365.0f)
		fSaturn1 = 0.0f;
	glutSolidSphere(1.20f, 200.0f, 200.0f);
	glPopMatrix();
	glPushMatrix();
	glColor3ub(200, 200, 100);
	glRotatef(70.0f, 1.0f, 0.0f, 0.0f);
	glutSolidTorus(1.42, 25, 10, 100);
	glPopMatrix();
	fSaturnRot += 0.03f;
	if (fSaturnRot >= 365.0f)
		fSaturnRot = 0.0f;
	glPopMatrix();
}
void UranusRot() {
	glPushMatrix();
	glColor3ub(0, 180, 100);
	glRotatef(fUranusRot, 0.0f, 1.0f, 0.0f);
	glTranslatef(202.0f, 0.0f, 0.0f);
	glutSolidSphere(15.0f, 200.0f, 200.0f);

	glPushMatrix();
	glColor3ub(0, 100, 0);
	glRotatef(150.0f, 1.0f, 0.0f, 0.0f);
	glutSolidTorus(1.0, 20, 10, 100);
	glPopMatrix();

	fUranusRot += 0.03f;
	if (fUranusRot >= 365.0f)
		fUranusRot = 0.0f;
	glPopMatrix();
}


void Neptune() {
	glPushMatrix();
	glColor3ub(0, 0, 215);
	glRotatef(fNeptuneRot, 0.0f, 1.0f, 0.0f);
	glTranslatef(240.0f, 0.0f, 0.0f);
	glutSolidSphere(19.45f, 200.0f, 200.0f);
	fNeptuneRot += 2.17f;
	if (fUranusRot >= 365.0f)
		fNeptuneRot = 0.0f;
	glPopMatrix();
}

void RenderScene(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, -300.0f);

	sun();
	Adam();
	Hesper();
	Earth_Moon();
	Mars();
	Jupiter();
	Saturn();
	UranusRot();
	Neptune();
	glPopMatrix();
	glutSwapBuffers();
}

void ChangeSize(GLsizei w, GLsizei h) {
	GLfloat fAspect;
	if (h == 0) h = 1;
	glViewport(0, 0, w, h);
	fAspect = (GLfloat)w / (GLfloat)h;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0f, fAspect, 1.0, 4000);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}


void SetupRC(void) {
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glEnable(GL_LIGHTING);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, whiteLight);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
	glEnable(GL_LIGHT0);
}


int mSecond = 10;
void TimerFunc(int value) {
	glutPostRedisplay();
	glutTimerFunc(mSecond, TimerFunc, 1);
}


void keyFunc(unsigned char ch, int, int) {
	if ('w' == ch || 'W' == ch) {
		mSecond += 2;
		if (mSecond < 0)mSecond = -mSecond;
		printf("mSecond:%d\n", mSecond);
	}
	if ('s' == ch || 'S' == ch) {
		mSecond -= 2;
		if (mSecond < 0)mSecond = -mSecond;
		printf("mSecond:%d\n", mSecond);
	}
	if ('R' == ch || 'r' == ch) {
		mSecond = 10;
		fMoonRot = 0.0f;
		fAdamRot = 0.0f;
		fEarthRot = 0.0f;
		fMarsRot = 0.0f;
		fMarsatellite1 = 0.0f;
		fMarsatellite2 = 0.0f;
		fHesperRot = 0.0f;
		fJupiterRot = 0.0f;
		fSaturnRot = 0.0f;
		fSaturn1 = 0.0f;
		fUranusRot = 0.0f;
		fNeptuneRot = 0.0f;
		system("cls");
		printf("The mSecond (%d) and all rotation angle has been reset!\n", mSecond);
	}
	if ('a' == ch || 'A' == ch) {
		fMoonRot = fMoonRot + oneRad;
		fAdamRot = fAdamRot + oneRad;
		fEarthRot = fEarthRot + oneRad;
		fMarsRot = fMarsRot + oneRad;
		fMarsatellite1 = fMarsatellite1 + oneRad;
		fMarsatellite2 = fMarsatellite2 + oneRad;
		fHesperRot = fHesperRot + oneRad;
		fJupiterRot = fJupiterRot + oneRad;
		fSaturnRot = fSaturnRot + oneRad;
		fSaturn1 = fSaturn1 + oneRad;
		fUranusRot = fUranusRot + oneRad;
		fNeptuneRot = fNeptuneRot + oneRad;
		//printf("rotation angle - oneRad\n");
	}
	if ('d' == ch || 'D' == ch) {

		fMoonRot = fMoonRot - oneRad;
		fAdamRot = fAdamRot - oneRad;
		fEarthRot = fEarthRot - oneRad;
		fMarsRot = fMarsRot - oneRad;
		fMarsatellite1 = fMarsatellite1 - oneRad;
		fMarsatellite2 = fMarsatellite2 - oneRad;
		fHesperRot = fHesperRot - oneRad;
		fJupiterRot = fJupiterRot - oneRad;
		fSaturnRot = fSaturnRot - oneRad;
		fSaturn1 = fSaturn1 - oneRad;
		fUranusRot = fUranusRot - oneRad;
		fNeptuneRot = fNeptuneRot - oneRad;

		if ('l' == ch || 'L' == ch) {
			for (int i = 0;i < 4;i++) {
				lightPos[i] += 10;
			}
		}
		if ('j' == ch || 'J' == ch) {
			for (int i = 0;i < 4;i++) {
				lightPos[i] -= 10;
			}
		}
	}
}

int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Orthographic Projection");
	glutDisplayFunc(RenderScene);
	glutReshapeFunc(ChangeSize);
	SetupRC();
	glutTimerFunc(250, TimerFunc, 1);

	glutKeyboardFunc(keyFunc);

	glutMainLoop();
	return 0;
}
