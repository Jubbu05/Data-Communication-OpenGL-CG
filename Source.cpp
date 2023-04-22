#include<stdlib.h>
#include<Windows.h>
#include<string.h>
#include<stdarg.h>
#include<stdio.h>
#include <GL/glut.h>

static double x = 0.0, x1 = -3.0, x2 = 3.0, y1 = 0.0, y2 = 0, x8 = -4.0, x9 = 4.0, y8 = 1.0, y9 = 1;
static bool pca2pcb = false, pca2rt = false, rt2pca = false, pcb2pca = false, local = false, dubai = false;

void P();
void d();
void* font;
void* currentfont;

void setFont(void* font)
{
	currentfont = font;
}

void drawstring(float x, float y, float z, char* string)
{
	char* c;
	glRasterPos3f(x, y, z);

	for (c = string; *c != '\0'; c++)
	{
		glColor3f(0.0, 1.0, 1.0);
		glutBitmapCharacter(currentfont, *c);
	}
}

void
stroke_output(GLfloat x, GLfloat y, char* format, ...)
{
	va_list args;
	char buffer[200], * p;
	va_start(args, format);
	vsprintf_s(buffer, format, args);
	va_end(args);
	glPushMatrix();
	glTranslatef(-2.5, y, 0);
	glScaled(0.003, 0.005, 0.005);
	for (p = buffer; *p; p++)
		glutStrokeCharacter(GLUT_STROKE_ROMAN, *p);
	glPopMatrix();
}

void building()
{
	glPushMatrix();
	glColor3f(1, 1, 0.5);
	//glTranslatef(0,0,5.2);
	//glRotatef(-85,1,0,0);
	glScaled(0.5, 2, 3);
	glutSolidCube(0.5);

	glPushMatrix();
	glColor3f(0.2, 0.1, 0.2);
	glTranslatef(0.2, 0.1, -0.1);
	glScaled(0.3, 0.2, 0.1);
	glutSolidCube(0.5);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.2, 0.1, 0.2);
	glTranslatef(0.2, -0.1, -0.1);
	glScaled(0.3, 0.2, 0.1);
	glutSolidCube(0.5);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.2, 0.1, 0.2);
	glTranslatef(0.2, 0.1, 0);
	glScaled(0.3, 0.2, 0.1);
	glutSolidCube(0.5);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.2, 0.1, 0.2);
	glTranslatef(0.2, -0.1, 0);
	glScaled(0.3, 0.2, 0.1);
	glutSolidCube(0.5);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.2, 0.1, 0.2);
	glTranslatef(0.2, 0.1, 0.07);
	glScaled(0.3, 0.2, 0.1);
	glutSolidCube(0.5);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.2, 0.1, 0.2);
	glTranslatef(0.2, -0.1, 0.07);
	glScaled(0.3, 0.2, 0.1);
	glutSolidCube(0.5);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.2, 0.1, 0.2);
	glTranslatef(0.2, 0.1, 0.15);
	glScaled(0.3, 0.2, 0.1);
	glutSolidCube(0.5);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.2, 0.1, 0.2);
	glTranslatef(0.2, -0.1, 0.15);
	glScaled(0.3, 0.2, 0.1);
	glutSolidCube(0.5);
	glPopMatrix();

	glPopMatrix();
}

//Router
void router(float x6, float y6)
{
	glLoadIdentity();
	glColor3f(0.2, 0.3, 1);
	glTranslatef(0.0f, 0.0f, -13.0f);
	glPushMatrix();
	glScaled(0.45, 1.5, 0.1);
	glRotatef(91, 1.0f, 0.0f, 0.0f);
	glTranslatef(x6, y6, -2.0);
	glutSolidTorus(0.2, 1.5, 10, 10);
	glPopMatrix();
}

//PC Computers
void pc(float x7, float y7, float z7)
{
	glLoadIdentity();
	glColor3f(0.1, 0.1, .1);
	glTranslatef(0.0f, 0.0f, -13.0f);

	glPushMatrix();

	glPushMatrix();
	glScaled(.7, .7, 0);
	glRotatef(95, 1.0f, 0.0f, 0.0f);
	glTranslatef(x7, y7, z7);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1, 1, 1);

	//Condition for pcB to change Color
	if (pcb2pca && x7 == 5)
		glColor3f(0, 1, 0);

	// Condition for PCA to change color
	if (pcb2pca && x9 >= -5 && x9 <= -4 && x7 == -5)
		glColor3f(1, 1, 0);
	if (rt2pca && x8 <= -4 && x7 == -5)
		glColor3f(1, 1, 0);

	glScaled(.7, .7, 0);
	glRotatef(95, 1.0f, 0.0f, 0.0f);
	glTranslatef(x7, y7, z7);
	glutSolidCube(.85);
	glPopMatrix();

	glPopMatrix();
}

//CPU
void cpu(float x7, float y7, float z7)
{
	glLoadIdentity();
	glColor3f(0, 0, 0);
	glTranslatef(0.0f, 0.0f, -13.0f);
	glPushMatrix();

	glPushMatrix();
	glScaled(1, .3, 0);
	glRotatef(95, 1.0f, 0.0f, 0.0f);
	glTranslatef(x7, y7, z7);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1, 1, 1);
	glScaled(1, .3, 0);
	glRotatef(95, 1.0f, 0.0f, 0.0f);
	glTranslatef(x7, y7, z7);
	glutSolidCube(.4);
	glPopMatrix();

	glPopMatrix();
}

//Draw LAN/WAN

void lan(double x8, double y8)
{
	glClearColor(0.6, 0.5, .5, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -13.0f);

	router(0, -1);
	//Data Media (connected to Router)
	glPushMatrix();
	glTranslatef(0.0, 1.0, -2.0);
	glScaled(0.1, 5.0, 0.1);
	glColor3f(1, 1, 1);
	glutWireCube(1.5);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, 0.0, -2.0);
	glScaled(5.1, 0.1, 0.1);
	glColor3f(1, 1, 1);
	glutWireCube(1.5);
	glPopMatrix();


	glPushMatrix();

	//glScaled(1.1,2.0,0.1);
	glTranslatef(0.0, 0.0, -2.0);
	setFont(GLUT_BITMAP_TIMES_ROMAN_24);

	glColor3f(0, 0, 0);
	drawstring(1, 3.5, -1.0, (char*)"ROUTER");
	setFont(GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(0, 0, 0);
	drawstring(-4.6, .5, -1.0, (char*)"PC-A");
	setFont(GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(0, 0, 0);
	drawstring(-.5, .5, -1.0, (char*)"SWITCH");
	setFont(GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(0, 0, 0);
	drawstring(4, .5, -1.0, (char*)"PC-B");
	glPopMatrix();

	//Data Transfer

	if (pca2pcb) {

		// data
		glPushMatrix();
		glTranslatef(x8, y8, -2.0);
		glScaled(0.1, 0.1, 0.1);
		glColor3f(0, 1, 0);
		glutSolidCube(1);
		glPopMatrix();
		if (x8 >= 4) {
			pcb2pca = true;
			pca2pcb = false;

		}
	}
	//Ack
	if (pcb2pca) {

		glPushMatrix();
		glTranslatef(x8, y8, -2.0);
		glScaled(0.1, 0.1, 0.1);
		glColor3f(1, 1, 0);
		glutSolidCube(1);
		glPopMatrix();
	}

	if (pca2rt)
	{
		glPushMatrix();
		glTranslatef(x8, y8, -2.0);
		glScaled(0.1, 0.1, 0.1);

		if (rt2pca)
			glColor3f(1, 1, 0);
		else
			glColor3f(1, 0, 0);

		glutSolidCube(1);
		glPopMatrix();
	}

	// move the packet out of LAN
	if (pca2rt && rt2pca == false && y8 >= 6)
	{
		glutIdleFunc(P);
	}

	//switch
	glPushMatrix();
	glColor3f(0.5, 0.5, 1.5);
	glTranslatef(0.0, 0, 1.0);
	glRotatef(15, 1.0f, 0.0f, 0.0f);
	glScaled(1.2, 0.2, 1.0);
	glutSolidCube(1);
	glPopMatrix();

	pc(-5, 1, 0);
	cpu(-3.5, 7, 1.5);

	pc(5, 1, 0);
	cpu(3.5, 7, 1.5);

	pc(0, 20, 2);
	cpu(0, 105, 1.5);

	glFlush();
	glutSwapBuffers();
}

// Draw Network
void network(double ang, double x1, double x2, double y1, double y2)
{
	glClearColor(0.0, 0.0, 0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -19.0f);

	//Packet
	glPushMatrix();
	glTranslatef(0, 0, 5.5);
	glScaled(0.1, 0.15, 0.1);

	// Color for Syn packet
	if (x <= 0 && x >= -180)
		glColor3f(1, 0, 0);
	//change color for ACK packet
	if (x <= -200 && x >= -380)
		glColor3f(1, 1, 0);

	glutSolidCube(1);
	glPopMatrix();

	if (x <= 0 && x >= -180)
		glRotatef(-ang, 0.0f, -1.0f, 0.0f);

	if (x <= -200 && x >= -380)
		glRotatef(ang + 20, 0.0f, -1.0f, 0.0f);

	//Earth
	glPushMatrix();
	glColor3f(0.5, 0.5, 1.5);
	glScaled(5, 5, 5);
	glutSolidSphere(1, 200, 200);
	glPopMatrix();

	// Earth Texture code

	//artic
	glPushMatrix();
	glColor3f(1, 1, 1);
	glTranslatef(0.0, 0.0, 0.0);
	glScaled(5, 5, 5);
	glutSolidSphere(0.99, 200, 200);
	glPopMatrix();

	//antartica
	glPushMatrix();
	glColor3f(1, 1, 1);
	glTranslatef(0.0, -0.08, 0.0);
	glScaled(5, 5, 5);
	glutSolidSphere(0.99, 200, 200);
	glPopMatrix();

	//Africa
	glPushMatrix();
	glColor3f(0, 1, 0);
	glTranslatef(0.04, 0.0, 0.08);
	glScaled(5, 5, 5);
	glutSolidSphere(0.99, 20, 20);
	glPopMatrix();

	//Local Area Network Wires
	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslatef(0.0, 0.0, 3);
	glScaled(5, 5, 5);
	glutWireSphere(0.5, 10, 10);
	glPopMatrix();

	//Unknown Island
	glPushMatrix();
	glColor3f(0, 1, 0);
	glTranslatef(-0.04, 0.0, -0.08);
	glScaled(5, 5, 5);
	glutSolidSphere(0.99, 20, 20);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0, 1, 1);
	glTranslatef(-0.04, 0.0, -0.08);
	glScaled(1, 1, 1);
	glutSolidDodecahedron();
	glPopMatrix();

	//Local Area Network Wires
	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslatef(0.0, 0.0, -3);
	glScaled(5, 5, 5);
	glutWireSphere(0.5, 10, 10);
	glPopMatrix();

	//Building A
	glPushMatrix();
	glColor3f(1, 1, 0.5);
	glTranslatef(0, 0, 5.2);
	building();
	glPopMatrix();

	//Building B
	glPushMatrix();
	glColor3f(1, 1, 0.5);
	glTranslatef(0, 0, -5.2);
	building();
	glPopMatrix();

	//Local Area Network Buildings A
	glPushMatrix();
	glColor3f(1, 1, 0.5);
	glTranslatef(0, 1.7, 4.9);
	glScaled(0.6, 0.4, 0.4);
	glRotated(-10, 0, 0, 1);
	building();
	glPopMatrix();

	glPushMatrix();
	glColor3f(1, 1, 0.5);
	glTranslatef(1.6, 0.5, 4.9);
	glScaled(0.6, 0.4, 0.4);
	glRotated(-10, 0, 0, 1);
	building();
	glPopMatrix();

	glPushMatrix();
	glColor3f(1, 1, 0.5);
	glTranslatef(1, -1.3, 4.9);
	glScaled(0.6, 0.4, 0.4);
	glRotated(-10, 0, 0, 1);
	building();
	glPopMatrix();

	glPushMatrix();
	glColor3f(1, 1, 0.5);
	glTranslatef(-1, -1.3, 4.9);
	glScaled(0.6, 0.4, 0.4);
	glRotated(-10, 0, 0, 1);
	building();
	glPopMatrix();

	glPushMatrix();
	glColor3f(1, 1, 0.5);
	glTranslatef(-1.7, 0.5, 4.9);
	glScaled(0.6, 0.4, 0.4);
	glRotated(-10, 0, 0, 1);
	building();
	glPopMatrix();

	//Local Area Network Buildings B
	glPushMatrix();
	glColor3f(1, 1, 0.5);
	glTranslatef(0, 1.7, -4.9);
	glScaled(0.6, 0.4, 0.4);
	glRotated(-10, 0, 0, 1);
	building();
	glPopMatrix();

	glPushMatrix();
	glColor3f(1, 1, 0.5);
	glTranslatef(1.6, 0.5, -4.9);
	glScaled(0.6, 0.4, 0.4);
	glRotated(-10, 0, 0, 1);
	building();
	glPopMatrix();

	glPushMatrix();
	glColor3f(1, 1, 0.5);
	glTranslatef(1, -1.3, -4.9);
	glScaled(0.6, 0.4, 0.4);
	glRotated(-10, 0, 0, 1);
	building();
	glPopMatrix();

	glPushMatrix();
	glColor3f(1, 1, 0.5);
	glTranslatef(-1, -1.3, -4.9);
	glScaled(0.6, 0.4, 0.4);
	glRotated(-10, 0, 0, 1);
	building();
	glPopMatrix();

	glPushMatrix();
	glColor3f(1, 1, 0.5);
	glTranslatef(-1.7, 0.5, -4.9);
	glScaled(0.6, 0.4, 0.4);
	glRotated(-10, 0, 0, 1);
	building();
	glPopMatrix();

	//Physical Medium
	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	glColor3f(1, 0, 1);
	glutWireTorus(0.1, 5.2, 10, 100);
	glPopMatrix();

	if (ang <= -380) {
		dubai = false;
		local = true;
		rt2pca = true;
		x8 = 0;
		y8 = 6;

		glutIdleFunc(d);
	}
	glFlush();
	glutSwapBuffers();
}

void about()
{
	glClearColor(0.0, 0.85, 1, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -13.0f);

	setFont(GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(0, 0, 0);
	drawstring(-4.2, 2, 0.0, (char*)"About Data Communication");
	setFont(GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(0, 0, 0);

	drawstring(-3.5, 1.5, 0.0, (char*)"1. Data Communications refers to the exchange of data between two devices via some");
	glColor3f(0, 0, 0);
	drawstring(-3.5, 1, 0.0, (char*)"   form of transmission medium such as a wire cable.");
	glColor3f(0, 0, 0);
	drawstring(-3.5, .5, 0.0, (char*)"2. Similarly data and information from one computer system can be transmitted to");
	glColor3f(0, 0, 0);
	drawstring(-3.5, 0.0, 0.0, (char*)"   other systems across geographical areas.");
	glColor3f(0, 0, 0);
	drawstring(-3.5, -0.5, 0.0, (char*)"3. Thus data transmission is the movement of information using some standard methods.");
	glColor3f(0, 0, 0);
	drawstring(-3.5, -1, 0.0, (char*)"4. The effectiveness of a data communications system depends on");
	glColor3f(0, 0, 0);
	drawstring(-3.5, -1.5, 0.0, (char*)"   four fundamental characteristics: delivery, accuracy, timeliness, and jitter.");

	glColor3f(0, 0, 0);
	drawstring(-3.5, -2, 0.0, (char*)"5. A network is two or more devices connected through links.");

	glColor3f(0, 0, 0);
	drawstring(-3.5, -2.5, 0.0, (char*)"6. A link is a communications pathway that transfers data from one device to another.");

	glColor3f(0, 0, 0);
	drawstring(-3.5, -3, 0.0, (char*)"7. Type of Connection : Point-to-Point & Multipoint.");

	glFlush();
	glutSwapBuffers();
}

void s()
{
	lan(-4, 1);
}

void n()
{
	x -= 0.7;

	network(x, 0, 0, 0, 0);
}

void P()
{
	x -= .7;
	network(x, 0, 0, 0, 0);
}

void d()
{
	if (pca2pcb)
	{
		if (x8 >= -4 && x8 <= 4) {

			x8 += 0.01;

		}


		lan(x8, 0);
	}

	if (pcb2pca)
	{


		if (x9 <= 4 && x9 >= -4) {

			x9 -= 0.01;

		}


		lan(x9, 0);
	}



	if (pca2rt && rt2pca == false)
	{

		if (x8 >= -4 && y8 <= 6) {

			if (x8 <= 0)
			{
				x8 += 0.01;
			}
			if (x8 >= 0 && y8 <= 6)
			{
				y8 += 0.01;
			}
		}

		lan(x8, y8);
	}

	if (rt2pca)
	{
		if (x8 <= 0 && y8 <= 6) {

			if (y8 >= 0)
			{
				y8 -= 0.01;
			}
			if (x8 >= -4 && y8 <= 0)
			{
				x8 -= 0.01;
			}
		}
		lan(x8, y8);

	}
}

void doInit()
{
	/* Background and foreground color */
	glClearColor(0.0, 0.0, 0.0, 0);
	glViewport(0, 0, 640, 480);

	/* Select the projection matrix and reset it then
	 setup our view perspective */
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(30.0f, (GLfloat)640 / (GLfloat)480, 0.1f, 200.0f);

	/* Select the modelview matrix, which we alter with rotatef() */
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClearDepth(2.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
}


void display()
{
	glClearColor(0.1, 0.1, 0.5, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -13.0f);

	setFont(GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(3.0, 1.0, 1.0);
	drawstring(-1.25, 3.0, 0.0, (char*)"DEPARTMENT OF COMPUTER SCIENCE");
	setFont(GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(0.0, 1.0, 1.0);
	drawstring(-2, 2.5, 0.0, (char*)"Computer Graphics Project on DATA COMMUNICATION IN NETWORK");
	setFont(GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(0.0, 1.0, 1.0);
	drawstring(-.75, 2, 0, (char*)"Using OPENGL");
	setFont(GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(0.0, 1.0, 1.0);
	drawstring(-0.4, 1.5, 0, (char*)"By");

	setFont(GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(0.0, 1.0, 1.0);
	drawstring(-1, 1, 0, (char*)"Ayush Nagpure (102016100)");

	setFont(GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(0.0, 1.0, 1.0);
	drawstring(-1, .5, 0, (char*)"Harsh Dawar (102016039)");

	setFont(GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(0.0, 1.0, 1.0);
	drawstring(-1, 0, 0, (char*)"Kartikay Mehrotra (102016053)");

	setFont(GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(0.0, 1.0, 1.0);
	drawstring(-1.25, -.5, 0, (char*)"Under the mentorship of - Diksha Arora");

	stroke_output(-1.0, -1.7, (char*)"s --> Start");
	stroke_output(-1.0, -2.45, (char*)"A --> About");
	stroke_output(-1.0, -3.2, (char*)"q --> Quit");

	GLfloat mat_ambient[] = { 0.0f,1.0f,2.0f,1.0f };
	GLfloat mat_diffuse[] = { 0.0f,1.5f,.5f,1.0f };
	GLfloat mat_specular[] = { 5.0f,1.0f,1.0f,1.0f };
	GLfloat mat_shininess[] = { 100.0f };

	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

	GLfloat lightIntensity[] = { 1.7f,1.7f,1.7f,1.0f };
	GLfloat light_position3[] = { -5.0f,4.0f,5.0f,0.0f };

	glLightfv(GL_LIGHT0, GL_POSITION, light_position3);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightIntensity);

	glEnable(GL_COLOR_MATERIAL);

	glFlush();
	glutSwapBuffers();
}

void menu(int id)
{
	switch (id)
	{
	case 1:glutIdleFunc(about);
		break;


	case 6:
		pca2pcb = true;
		x8 = -4;

		//Re-initialze the Variable
		x = 0.0; x1 = -3.0; x2 = 3.0; y1 = 0.0; y2 = 0; x9 = 4.0; y8 = 1.0; y9 = 1;
		pca2rt = false; rt2pca = false; pcb2pca = false; local = false; dubai = false;

		glutIdleFunc(d);
		break;

	case 7:
		local = true;
		dubai = false;
		pca2rt = true;

		//Re-initialze the Variable
		x = 0.0; x1 = -3.0; x2 = 3.0; y1 = 0.0; y2 = 0; x8 = -4.0; x9 = 4.0; y8 = 0.0; y9 = 0;
		pca2pcb = false; rt2pca = false; pcb2pca = false;

		glutIdleFunc(d);
		break;

	case 8:
		//Re-initialze ALL of the Variable
		x = 0.0; x1 = -3.0; x2 = 3.0; y1 = 0.0; y2 = 0; x8 = -4.0; x9 = 4.0; y8 = 1.0; y9 = 1;
		pca2pcb = false; pca2rt = false; rt2pca = false; pcb2pca = false; local = false; dubai = false;


		glutIdleFunc(s);
		break;

	case 9:exit(0);
		break;
	}
	glFlush();
	glutSwapBuffers();
	glutPostRedisplay();
}

void mykey(unsigned char key, int x, int y)
{

	if (key == 's')
	{
		glutIdleFunc(s);
	}

	if (key == '1')
	{
		pca2pcb = true;
		x8 = -4;

		//Re-initialze the Variable
		x = 0.0; x1 = -3.0; x2 = 3.0; y1 = 0.0; y2 = 0; x9 = 4.0; y8 = 1.0; y9 = 1;
		pca2rt = false; rt2pca = false; pcb2pca = false; local = false; dubai = false;

		glutIdleFunc(d);
	}

	if (key == '2')
	{
		local = true;
		dubai = false;
		pca2rt = true;

		//Re-initialze the Variable
		x = 0.0; x1 = -3.0; x2 = 3.0; y1 = 0.0; y2 = 0; x8 = -4.0; x9 = 4.0; y8 = 0.0; y9 = 0;
		pca2pcb = false; rt2pca = false; pcb2pca = false;

		glutIdleFunc(d);

	}

	if (key == 'A' || key == 'a')
	{
		glutIdleFunc(about);
	}


	if (key == 'q' || key == 'Q')
	{
		exit(0);
	}



	if (key == 'R' || key == 'r')
	{
		//Re-initialze ALL of the Variable
		x = 0.0; x1 = -3.0; x2 = 3.0; y1 = 0.0; y2 = 0; x8 = -4.0; x9 = 4.0; y8 = 1.0; y9 = 1;
		pca2pcb = false; pca2rt = false; rt2pca = false; pcb2pca = false; local = false; dubai = false;


		glutIdleFunc(s);


	}
}

void main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(1000, 480);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Data Communication in Network");
	glutDisplayFunc(display);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);

	glutKeyboardFunc(mykey);

	glutCreateMenu(menu);

	glutAddMenuEntry("About Project  'A'", 1);
	glutAddMenuEntry("Transfer data from PC-A to PC-B '1'", 6);
	glutAddMenuEntry("Transfer data from PC-A to Company B -->'2'", 7);
	glutAddMenuEntry("Reset            'r'", 8);
	glutAddMenuEntry("Quit            'q'", 9);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	doInit();

	glutMainLoop();
}
