//COMP 315 : Advanced Programming 2015


//This project and all assosciated files are the property of the creators:
//Kreason Aaron Naidoo
//Liam Bernard
//Shaherin Dehaloo
//Muhammad Bassa
//and of The University of Kwa-Zulu Natal

#include <iostream>
#include <GLUT/glut.h>  // GLUT, include glu.h and gl.h
#include <stdlib.h>
#include <cmath>
#include <stdio.h>
#include "world.h"

float camx = 0;
float camy = 1.1;
float camz = -50;
float lookx = 0;
float looky = 1.1;
float lookz = 0;
float angle = -M_PI/2;

world *uni = new world();





/* Initialize OpenGL Graphics */
void initGL()
{
    // Set "clearing" or background color
    glClearColor(0, 0, 0, 1); // White and opaque
    

    
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);

    
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = { 50.0 };
    GLfloat light_ambient[] = { 0.0, 0.0, -100.0, 0.0000001 };
    
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glLightfv(GL_LIGHT0, GL_POSITION, light_ambient);
    
    glEnable(GL_DEPTH_TEST); // turns on hidden surface removal so that objects behind other objects do not get displayed
}


void render()
{
    
    // GL_DEPTH_BUFFER_BIT - resets the depth test values for hidden surface removal
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    // Reset transformations
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    glPushMatrix();
        uni -> int_empty_world(); //uses the world class
    glPopMatrix();

    
    gluLookAt(0, 1, 0, // camera position
              0, 1, 0, // look at position, line of sight
              0, 1, 0); // up direction (vector) for camera tilt
    

  
    
  
    
    glFlush();   // ******** DO NOT FORGET THIS **********
    
}

void display()
{
    render();
}

void reshape(int w, int h)
{
    
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


void key (unsigned char key, int xx, int yy){
    
    switch (key) {
            
        case 'r':
            camx = 0;
            camz = -50;
            camy = 1.1;
            lookx = 0;
            lookz = 0.0;
            looky = 1.1;
            angle = -M_PI/2;
            break;
            
        case 'w':
            looky = looky + 0.01;
            break;
            
        case 's':
            looky = looky - 0.01;
            break;
            
        case 27:
            exit(1);
            break;
            
        case 'a':
            camz = camz - sin(-angle + M_PI/2);
            camx = camx - cos(-angle + M_PI/2);
            break;
            
        case 'd':
            camz = camz + sin(-angle + M_PI/2);
            camx = camx + cos(-angle + M_PI/2);
            break;
            
            
        default:
            break;
    }
    lookx = cos(-angle) + camx;
    lookz = sin(-angle) + camz;
    glutPostRedisplay();

    
    
}


void arrowKey(int key, int xx, int y){
    switch (key) {
        case GLUT_KEY_RIGHT :
            
            angle = angle - M_PI/200;
            break;
            
        case GLUT_KEY_LEFT :
            
            angle = angle + M_PI/200;
            break;
            
        case GLUT_KEY_DOWN :
            
            camz = camz - sin(-angle);
            camx = camx - cos(-angle);
            break;
            
        case GLUT_KEY_UP :
            
            camz = camz + sin(-angle);
            camx = camx + cos(-angle);
            break;
    }
    
    
    lookx = cos(-angle) + camx;
    lookz = sin(-angle) + camz;
    
    glutPostRedisplay();
   

}

void idle(){
    glutPostRedisplay();
}




int main(int argc, char * argv[]) {
    
    glutInit(&argc, argv);          // Initialize GLUT
    
    glutInitWindowSize(640, 500);   // Set the window's initial width & height - non-square
    glutInitWindowPosition(200, 100); // Position the window's initial top-left corner
    glutCreateWindow("Astro Crisis");  // Create window with the given title
    glutIdleFunc(idle);
    glutDisplayFunc(display);       // Register callback handler for window re-paint event
    glutReshapeFunc(reshape);
    glutKeyboardFunc(key);
    glutSpecialFunc(arrowKey);
    
    initGL();                       // Our own OpenGL initialization
    
    glutMainLoop();                 // Enter the infinite event-processing loop
    return 0;

}
