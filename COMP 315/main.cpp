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
#include "CoreFoundation/CoreFoundation.h"
#else
#include <GL/glut.h>
#endif
#include <windows.h>
#include <mmsystem.h>
#include <stdarg.h>
#include <string>
#include <sstream>


using namespace std;

float *curx = new float(0);
float *cury = new float(0);
int *H = new int();
int *W = new int();




physics_engine *engine = new physics_engine();
cam *kam = new cam(0.0, 0.57, -1.5, 0, -2.0, 10);


/* Initialize OpenGL Graphics */

void initGL(){



    srand((int)time(NULL));


    glCullFace (GL_BACK);
    glEnable (GL_CULL_FACE);

    // Set "clearing" or background color
    glClearColor(0, 0, 0, 1); // Black and opaque


    glEnable(GL_LIGHTING);
    //this light simulates the sun. Directional with no attenuation
    glEnable(GL_LIGHT0);
    //glEnable(GL_LIGHT1);
    glEnable(GL_LIGHT2);

    glEnable(GL_NORMALIZE);
    //glEnable(GL_COLOR_MATERIAL); //this ruins everything. yes everything.

    GLfloat light_ambient0[] = { 5.0, 5.0, -3.0, 0.0};//position
    //GLfloat light_ambient1[] = { 0.0, 0.0, 6.0, 0.0 };//w=0.0 defines a directional light

    glLightfv(GL_LIGHT0, GL_POSITION, light_ambient0);
    //glLightfv(GL_LIGHT1, GL_POSITION, light_ambient1);

    //global ambient lighting
    GLfloat lmodel_ambient[] = {1,1,1,0.5};
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);

    glEnable(GL_DEPTH_TEST); // turns on hidden surface removal so that objects behind other objects do not get displayed

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);



}

void orthogonalEnd () {

    //Switch back to our projection mode
    glMatrixMode(GL_PROJECTION);
    //Finish our calls above
    glPopMatrix();
    //Switch back to our model matrix to continue with out 3D scene
    glMatrixMode(GL_MODELVIEW);

}

void orthogonalStart () {

    //First of all, we need to switch to our projection matrix
    glMatrixMode(GL_PROJECTION);
    //Start our projection modifications
    glPushMatrix();
    //Then we need to clear it of all previous information
    glLoadIdentity();
    //Now I am calling: gluOrtho2D instead of the previous gluPerspective
    //which was in our reshape function. This takes our parameters which
    //set the view space from 0,0 in the window, to the width and height of the
    //window which we collect in our reshape function
    gluOrtho2D(0, *W, 0, *H);
    //Now we need to flip our scene upside down
    glScalef(1, -1, 1);
    //And translate it to display our scene correctly
    glTranslatef(0, -(*H), 0);
    //Now we switch back to our model matrix so we can draw our 2D shapes
    glMatrixMode(GL_MODELVIEW);
}

void renderHUD(){

    int *healthcent = new int(3*(engine->home->health));
    int *Min = new int(5);

    if(*healthcent == 0){
        *Min = 0;
    }

    engine->getLevel();
    engine->home->health;

            //sets light of material
        GLfloat ambient[] = {2.0, 0.0, 0.0, 1.0};
        glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, ambient);
        //sets specular properties of the material
        GLfloat mat_specular[] = {0.0, 1.0, 0.0, 1.0};
        glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
        // sets the shininess of the material
        GLfloat mat_shininess[] = { 70.0 };
        glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

    glBegin(GL_LINES);

    glVertex2f(1, 1);
    glVertex2f(1, 76);

    glVertex2f(1, 76);
    glVertex2f(306, 76);

    glVertex2f(306, 76);
    glVertex2f(306, 1);

    glVertex2f(306, 1);
    glVertex2f(1, 1);


    glEnd();

//sets light of material
        GLfloat ambient1[] = {0.0, 2.0, 0.0, 1.0};
        glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, ambient1);
        //sets specular properties of the material
        GLfloat mat_specular1[] = {0.0, 1.0, 0.0, 1.0};
        glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular1);
        // sets the shininess of the material
        GLfloat mat_shininess1[] = { 70.0 };
        glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess1);

    glBegin(GL_QUADS);
    glVertex2f(*Min+1, 6);
    glVertex2f(*Min+1, 71);
    glVertex2f(*healthcent+1, 71);
    glVertex2f(*healthcent+1, 6);
    glEnd();

    int number = engine->getLevel();
    stringstream convert; // stringstream used for the conversion
    convert << number;

    //text
    string level = "Level: "+ convert.str();
    glRasterPos2f(*W - 200, 50);


    int len = level.length();
    for (int i = 0; i < len; i++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, level[i]);
    }

}

void render(){

    glMatrixMode(GL_MODELVIEW);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();

    orthogonalStart();

        renderHUD();

    orthogonalEnd();

    kam -> place();

    engine -> update_with_time();



    //glFlush();
    glutSwapBuffers();   // ******** DO NOT FORGET THIS **********

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

    *W = w;
    *H = h;

    glMatrixMode(GL_MODELVIEW);

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

        case 'r':
                engine -> player1->shoot(*curx,*cury);
            break;

    	default:
            break;
    }

        if (GetKeyState('W') & 0x80){
            (engine->player1->y)+=0.03;
            kam ->y +=0.03;
        }
        else if (GetKeyState('S') & 0x80){
            (engine->player1->y)-=0.03;
            kam ->y -=0.03;
        }
        else if (GetKeyState('A') & 0x80){
            (engine->player1->x)+=0.03;
            kam ->x +=0.03;
        }
        else if (GetKeyState('D') & 0x80){
            (engine->player1->x)-=0.03;
            kam ->x -=0.03;

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

    *curx = (float)x;
    *cury = (float)y;



        kam -> lx = 0.1*(glutGet(GLUT_WINDOW_WIDTH)/2 - x);
              //^this value denotes the speed of the camera rotation in the x-direction
        kam -> ly = 0.1*(glutGet(GLUT_WINDOW_HEIGHT)/2 - y);
              //^this value denotes the speed of the camera rotation in the y-direction


        /*
        if(kam -> lx > 2){
            kam -> lx = 2;
        }

        if(kam -> lx < -2){
            kam -> lx = -2;
        }

        if(kam -> ly > 2.5){
            kam -> ly = 2.5;
        }

        if(kam -> ly < -1.5){
            kam -> ly = -1.5;
        }
        */
        //glutWarpPointer((int)kam -> lx,(int)kam -> ly);

}

void timer(int value){
    glutPostRedisplay();
    glutTimerFunc(30, timer, 0);
}




int main(int argc, char * argv[]) {

    //PlaySound("resources\\catch.wav", NULL, SND_ASYNC);


    glutInit(&argc, argv);          // Initialize GLUT
    //glutInitDisplayMode (GLUT_DOUBLE);
    glutInitWindowSize(900, 600);   // Set the window's initial width & height - non-square
    glutInitWindowPosition(200, 100); // Position the window's initial top-left corner
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB| GLUT_ALPHA | GLUT_DEPTH);
    glutCreateWindow("Astro Crisis, Still a better love story than Twilight");  // Create window with the given title

    glutTimerFunc(0,timer,0);

    glutDisplayFunc(display);       // Register callback handler for window re-paint event
    glutReshapeFunc(reshape);
    //glutFullScreen(); //takes to game into full screen also i got rid of the console
    glutKeyboardFunc(key);
    glutSpecialFunc(arrowKey);
    glutMouseFunc(mouseClick);
    glutPassiveMotionFunc(mouseMove);
    glutSetCursor(GLUT_CURSOR_CROSSHAIR);
    glutWarpPointer(glutGet(GLUT_WINDOW_WIDTH)/2, glutGet(GLUT_WINDOW_HEIGHT)/2 -11);


    initGL();                       // Our own OpenGL initialization
    engine->home->initPlanet();
    engine->uni->initWorld();
    engine->initAsteroid();

    glutMainLoop();                 // Enter the infinite event-processing loop
    return 0;

}
