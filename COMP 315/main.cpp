//COMP 315 : Advanced Programming 2015


//This project and all assosciated files are the property of the creators:
//Kreason Aaron Naidoo
//Liam Bernard
//Shaherin Dehaloo
//Muhammad Bassa
//and of The University of Kwa-Zulu Natal

#include <windows.h>
#include <GL/glut.h>
#include <iostream>
#include <math.h>
#include "planet.h"
#include<vector>

using namespace std;

int time=0;
vector<planet> v_planet;

/*float z_dist_at;
float camera[3][3] = {
            {0, 0, -z_dist_at},
            {0, 0, 0},
            {0, 1.0f, 0}
    };
float lx, ly, lz;
float angle;
*/
void initGL(){
   glClearColor(0, 0, 0, 1);
   //lighting
     glShadeModel (GL_SMOOTH);

     glEnable(GL_LIGHTING); // turns on the lighting model in OpenGL

     glEnable(GL_LIGHT0);  // enables light 0

     // set the position and type of light 0 (x,y,z,w) w=1 for a point source and 0 for a directional source
     GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
     glLightfv(GL_LIGHT0, GL_POSITION, light_position);

   glEnable(GL_DEPTH_TEST);

   planet *p=new planet(0,0,-5);
   v_planet.push_back(*p);
}

/*void setCamera(){

		cout << angle << " lx: " << lx << " lz:" << lz << "\n";
    	// Set the camera

		gluLookAt(	camera[0][0], camera[0][1], camera[0][2],
    				camera[1][0], camera[1][1], camera[1][2],
    				camera[2][0], camera[2][1], camera[2][2]  );

}*/

void render(){
   // GL_DEPTH_BUFFER_BIT - resets the depth test values for hidden surface removal
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

   // Reset transformations
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();

  // setCamera();

   v_planet[0].render();

   glutSwapBuffers();
   //glFlush();
}

void update(){
    time = glutGet(GLUT_ELAPSED_TIME); // get the elapsed time in milliseconds since glutInit() was executed
    // do nothing
}

void display(){
    update();
    render();
}

void reshape(int w, int h){
    // Prevent a divide by zero, when window is too short
    // (you cant make a window of zero width).
    if(h == 0)	h = 1;

    GLfloat ratio = 1.0f * (GLfloat)w / (GLfloat)h;

    // Set the viewport to be the entire window
    glViewport(0, 0, w, h);

    // Reset the coordinate system before modifying
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // Set the clipping volume
    gluPerspective(45, ratio, 0.1, 100);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void processNormalKeys(unsigned char key, int x, int y) {

	switch (key) {
		case 27 :  exit(0); break;
	}
    glutPostRedisplay();
}

void inputKey(int key, int ix, int iy) {

    glutPostRedisplay();
}

void idle(){
    glutPostRedisplay(); // called when there is now other event
}

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);

    glutInitWindowSize (500, 500);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Astro Crisis");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutKeyboardFunc(processNormalKeys);
    glutSpecialFunc(inputKey);
    glutIdleFunc(idle);
    //glutIdleFunc(spin);

    //glutTimerFunc(25,update,0);

    initGL();
    glutMainLoop();
    return 0;
}
