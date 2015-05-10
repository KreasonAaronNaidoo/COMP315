//COMP 315 : Advanced Programming 2015


//This project and all assosciated files are the property of the creators:
//Kreason Aaron Naidoo
//Liam Bernard
//Shaherin Dehaloo
//Muhammad Bassa
//and of The University of Kwa-Zulu Natal
#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <stdio.h>
#include "physics_engine.h"
#include "cam.h"
#include "time.h"
#include "imageloader.h"
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
using namespace std;


cam *kam = new cam(0.0, 1.0, -2.5, 0, 0.1, 10);
physics_engine *engine = new physics_engine();
//player *p = new player(0.0f, 0.01f, 0.0f);

//Makes the image into a texture, and returns the id of the texture
GLuint loadTexture(Image* image) {
	GLuint textureId;
	glGenTextures(1, &textureId); //Make room for our texture
	glBindTexture(GL_TEXTURE_2D, textureId); //Tell OpenGL which texture to edit
	//Map the image to the texture
	glTexImage2D(GL_TEXTURE_2D,                //Always GL_TEXTURE_2D
				 0,                            //0 for now
				 GL_RGB,                       //Format OpenGL uses for image
				 image->width, image->height,  //Width and height
				 0,                            //The border of the image
				 GL_RGB, //GL_RGB, because pixels are stored in RGB format
				 GL_UNSIGNED_BYTE, //GL_UNSIGNED_BYTE, because pixels are stored
				                   //as unsigned numbers
				 image->pixels);               //The actual pixel data
	return textureId; //Returns the id of the texture
}

/* Initialize OpenGL Graphics */
void initGL()
{

    srand((int)time(NULL));


    // Set "clearing" or background color
    glClearColor(0, 0, 0, 1); // Black and opaque

    gluOrtho2D(-10.0,10.0,-10.0,10.0);


    glEnable(GL_LIGHTING);
    //this light simulates the sun. Directional with no attenuation
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);

    glEnable(GL_NORMALIZE);
    //glEnable(GL_COLOR_MATERIAL); //this ruins everything. yes everything.

    GLfloat light_ambient0[] = { 0.0, 0.0, -10.0, 1.0};//position
    //GLfloat light_ambient1[] = { 0.0, 0.0, -6.0, 0.0 };//w=0.0 defines a directional light

    glLightfv(GL_LIGHT0, GL_POSITION, light_ambient0);
    //glLightfv(GL_LIGHT1, GL_POSITION, light_ambient1);


    //global ambient lighting
    GLfloat lmodel_ambient[] = {0.5,0.5,0.5,1.0};
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);

    glEnable(GL_DEPTH_TEST); // turns on hidden surface removal so that objects behind other objects do not get displayed

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

}

void render()
{

    // GL_DEPTH_BUFFER_BIT - resets the depth test values for hidden surface removal
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Reset transformations
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();



    kam -> place();



    engine -> init_world();



    glFlush();   // ******** DO NOT FORGET THIS **********

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
    gluPerspective(45, ratio, 0.00001, 500);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

}

void display(){

    render();
    glutPostRedisplay();

}
void key (unsigned char key, int xx, int yy){

    switch (key) {


        case 27:
            exit(1);
            break;

        case 'q':
            kam -> z = kam -> z + 0.1;
            break;

        case 'e':
            kam -> z = kam -> z - 0.1;
            break;

        case 'l': //OMFG WTH is happening here!!!
            cout << "moving level: "<< (engine -> getLevel()) << endl;
            (engine -> setLevel((engine -> getLevel()) +1));
            engine -> start_new_level();
            glutWarpPointer(glutGet(GLUT_WINDOW_WIDTH)/2, glutGet(GLUT_WINDOW_HEIGHT)/2 -11);
            break;

        /*case 'w': (p->y)+=0.01; break;
		case 's': (p->y)-=0.01; break;
		case 'a': (p->x)+=0.01; break;
		case 'd': (p->x)-=0.01; break;*/

		case 'w': (engine->player1->y)+=0.01;
		           break;
		case 's': (engine->player1->y)-=0.01;
		           break;
		case 'a': (engine->player1->x)+=0.01;
		           break;
		case 'd': (engine->player1->x)-=0.01;
		           break;

        default:
            break;
    }

    glutPostRedisplay();



}


void arrowKey(int key, int xx, int y){


    glutPostRedisplay();


}

void mouseClick(int button, int state, int x, int y){

    if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
        engine -> player1->shoot(x,y);

    glutPostRedisplay();

}

void mouseMove(int x, int y){


    kam -> lx = 0.1*(glutGet(GLUT_WINDOW_WIDTH)/2 - x);
                //^this value denotes the speed of the camera rotation in the x-direction
    kam -> ly = 0.1*(glutGet(GLUT_WINDOW_HEIGHT)/2 - y);
                //^this value denotes the speed of the camera rotation in the y-direction



}



void timer(int value){
    engine->home->update();
    engine -> update_with_time();
    //engine -> init_world();
    glutPostRedisplay();

    glutTimerFunc(30, timer, 0);
}




int main(int argc, char * argv[]) {

    glutInit(&argc, argv);          // Initialize GLUT

    glutInitWindowSize(900, 600);   // Set the window's initial width & height - non-square
    glutInitWindowPosition(200, 100); // Position the window's initial top-left corner
    //glutInitDisplayMode (GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Astro Crisis");  // Create window with the given title

    glutTimerFunc(0,timer,0);

    glutDisplayFunc(display);       // Register callback handler for window re-paint event
    glutReshapeFunc(reshape);

    glutKeyboardFunc(key);
    glutSpecialFunc(arrowKey);
    glutMouseFunc(mouseClick);
    glutPassiveMotionFunc(mouseMove);
    glutSetCursor(GLUT_CURSOR_CROSSHAIR);
    glutWarpPointer(glutGet(GLUT_WINDOW_WIDTH)/2, glutGet(GLUT_WINDOW_HEIGHT)/2 -11);

    initGL();                       // Our own OpenGL initialization
    engine->home->initPlanet();
    //engine->uni->initWorld();

    glutMainLoop();                 // Enter the infinite event-processing loop
    return 0;

}
