#include <stdio.h>
#include "Line2D.h"
#include "Circle.h"

#define GL_GLEXT_PROTOTYPES
#ifdef __APPLE__
#include<GLUT/glut.h>
#else
#include<GL/glut.h>
#endif

#include <cmath>


GLint gFramesPerSecond = 0;
 
void FPS(void) {
  static GLint Frames = 0;         // frames averaged over 1000mS
  static GLuint Clock;             // [milliSeconds]
  static GLuint PreviousClock = 0; // [milliSeconds]
  static GLuint NextClock = 0;     // [milliSeconds]
 
  ++Frames;
  Clock = glutGet(GLUT_ELAPSED_TIME); //has limited resolution, so average over 1000mS
  if ( Clock < NextClock ) return;
 
  gFramesPerSecond = Frames/1; // store the averaged number of frames per second
 
  PreviousClock = Clock;
  NextClock = Clock+1000; // 1000mS=1S in the future
  Frames=0;
}
 
void idle() {
  #define REGULATE_FPS
  #ifdef REGULATE_FPS
  static GLuint PreviousClock=glutGet(GLUT_ELAPSED_TIME);
  static GLuint Clock=glutGet(GLUT_ELAPSED_TIME);
  static GLfloat deltaT;
 
  Clock = glutGet(GLUT_ELAPSED_TIME);
  deltaT=Clock-PreviousClock;
  if (deltaT < 35) {return;} else {PreviousClock=Clock;}
  #endif
 
  //put your specific idle code here
  //... this code will run at FPS
  
  printf(".");
  //end your specific idle code here
 
  FPS(); //only call once per frame loop 
  glutPostRedisplay();
}


float x1 = 70;
float xy1 = 70;

float x2 = 520;
float y2 = 520;

void Display();
void SpecialKeys(int key,int x,int y);
void reshape (int w, int h) ;
int main(int argc,char ** argv)
{
	glutInit(&argc,argv);

	//  Request double buffered true color window with Z-buffer
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

	glutCreateWindow("My open gl test");

	//enable z-buffering
	glEnable(GL_DEPTH_TEST);
	
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glutDisplayFunc(Display);
	glutIdleFunc(idle);
	glutSpecialFunc(SpecialKeys);
	//glutReshapeFunc (reshape);
	glutMainLoop();

	return 0;
}

void reshape (int w, int h) {
 glViewport (0, 0, (GLsizei)w, (GLsizei)h);
 glMatrixMode (GL_PROJECTION);
 glLoadIdentity ();
 gluPerspective (60, (GLfloat)w / (GLfloat)h, 0.1, 100.0);
 glMatrixMode (GL_MODELVIEW);
}

void DrawCircle(float cx, float cy, float r, int num_segments) 
{ 
	float theta = 2 * 3.1415926 / float(num_segments); 
	float tangetial_factor = tanf(theta);//calculate the tangential factor 

	float radial_factor = cosf(theta);//calculate the radial factor 
	
	float x = r;//we start at angle = 0 

	float y = 0; 
    
	glBegin(GL_LINE_LOOP); 
	for(int ii = 0; ii < num_segments; ii++) 
	{ 
		glVertex2f(x + cx, y + cy);//output vertex 
        
		//calculate the tangential vector 
		//remember, the radial vector is (x, y) 
		//to get the tangential vector we flip those coordinates and negate one of them 

		float tx = -y; 
		float ty = x; 
        
		//add the tangential vector 

		x += tx * tangetial_factor; 
		y += ty * tangetial_factor; 
        
		//correct using the radial factor 

		x *= radial_factor; 
		y *= radial_factor; 
	} 
	glEnd(); 
}

void drawFilledCircle(GLfloat x, GLfloat y, GLfloat radius){
	int i;
	int triangleAmount = 20; //# of triangles used to draw circle
	
	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * 3.14;
	
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) { 
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)), 
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
}

bool IsCollided(int r){
	double dist = Vector2DF::Distance(Vector2DF(x1,xy1),Vector2DF(x2,y2));

	return dist <= r*2;
}

int GetCollideAdjustment(int x1,int xy1,int w,int h,int r,int c){
	double dist1 = Vector2DF::Distance(Vector2DF(x1,xy1),Vector2DF(0,xy1));
	double dist2 = Vector2DF::Distance(Vector2DF(x1,xy1),Vector2DF(x1,0));
	double dist3 = Vector2DF::Distance(Vector2DF(x1,xy1),Vector2DF(w,xy1));
	double dist4 = Vector2DF::Distance(Vector2DF(x1,xy1),Vector2DF(x1,h));

	if(dist1 <= r*2){
		return 10;
	}

	if(dist2 <= r*2){
		return 10;
	}

	if(dist3 <= r*2){
		return -10;
	}

	if(dist4 <= r*2){
		return -10;
	}

	return c;
}

int c1 = 10;
int c2 = -10;

void Display(){
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode (GL_PROJECTION);

	//reset transformation
	glLoadIdentity();
	
	glOrtho (0, 600, 600, 0, 0, 1);

	glMatrixMode (GL_MODELVIEW);

	glDisable(GL_DEPTH_TEST);

	if(IsCollided(50))
		glColor3f(0,1,0);
	else
		glColor3f(1,0,0);

	//drawFilledCircle(100,150,120);
	DrawCircle(x1,xy1,50,50);
	DrawCircle(x2,y2,50,50);

	glFlush();
	glutSwapBuffers();

	c1 = GetCollideAdjustment(x1,xy1,600,600,50,c1);
	c2 = GetCollideAdjustment(x2,y2,600,600,50,c2);

	x1 += c1;
	xy1 += c1;

	x2 += c2;
	y2 += c2;
 return;

	//clear the screen and the z-buffer
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode (GL_PROJECTION);

	//reset transformation
	glLoadIdentity();
	
	glOrtho (0, 640, 460, 0, 0, 1);

	glMatrixMode (GL_MODELVIEW);

	glDisable(GL_DEPTH_TEST);

	Pen px(2.5f,Color::Green);
	//Line2D l(100,100,150,150);

	//l.Draw(px);

	//Circle c(100,100,20);

	//c.Draw(px);
	glTranslatef(-10,0,-30);
	//drawCircle(10,0,0);
		/*	glLineWidth(px.GetWidth());

		glColor3f(px.GetColor().R(), px.GetColor().G(), px.GetColor().B());

		int h = 100;
		int k = 100;
		int r = 20;

		glBegin(GL_LINES);

		for (float i = 0;i < 180;i++){
		
			float x = r * cosf(i) - h;
			float y = r * sin(i) + k;

			glVertex3f(x + k,y - h,0);

			x = r * cos(i + 0.1) - h;
			y = r * sin(i + 0.1) + k;

			glVertex3f(x + k,y - h,0);
		}

		glEnd();
*/
	//glLineWidth(px.GetWidth()); 
	//glColor3f(px.GetColor().R(), px.GetColor().G(), px.GetColor().B());
	//glBegin(GL_LINES);
	//glVertex2f(l.GetX1(),l.GetY1());
	//glVertex2f(l.GetX2(),l.GetY2());
	////glVertex3f(0.0, 0.0, 0.0);
	////glVertex3f(15, 0, 0);
	//glEnd();
 
	//ensure double buffering effects
	glFlush();
	glutSwapBuffers();
}

void SpecialKeys(int key,int x,int y){
	   switch (key) {
      case 27:
         exit(0);
         break;
   }
}