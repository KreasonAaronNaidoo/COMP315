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


/* Initialize OpenGL Graphics */
void initGL()
{
    // Set "clearing" or background color
    glClearColor(0, 0, 0, 1); // White and opaque
    
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    
    GLfloat lightpos[] = {0, 0, -70, 0};
    glLightfv(GL_LIGHT0, GL_POSITION, lightpos);
    
    glEnable(GL_DEPTH_TEST); // turns on hidden surface removal so that objects behind other objects do not get displayed
}


void render()
{
    
    // GL_DEPTH_BUFFER_BIT - resets the depth test values for hidden surface removal
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    // Reset transformations
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    // Draw ground
    glColor3ub(0,64,0); // green
    
    glBegin(GL_QUADS);
    glVertex3f(-100.0f, -2.0f, -100.0f);
    glVertex3f(-100.0f, -2.0f, 100.0f);
    glVertex3f(100.0f, -2.0f, 100.0f);
    glVertex3f(100.0f, -2.0f, -100.0f);
    
    glEnd();

    
    gluLookAt(0, 0, -50, // camera position
              0, 0, 0, // look at position, line of sight
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
      
        case 27:
            exit(1);
            break;
            
        default:
            break;
    }
    
    glutPostRedisplay();
    
    
}


void arrowKey(int key, int xx, int y){
    
    
    switch (key) {
        case GLUT_KEY_RIGHT :
            
            break;
            
        case GLUT_KEY_LEFT :
            
            break;
            
        case GLUT_KEY_DOWN :
            
            break;
            
        case GLUT_KEY_UP :
            
            break;
    }
    glutPostRedisplay();
}




int main(int argc, char * argv[]) {
    
    glutInit(&argc, argv);          // Initialize GLUT
    
    glutInitWindowSize(640, 500);   // Set the window's initial width & height - non-square
    glutInitWindowPosition(200, 100); // Position the window's initial top-left corner
    glutCreateWindow("Astro Crisis");  // Create window with the given title
    
    glutDisplayFunc(display);       // Register callback handler for window re-paint event
    glutReshapeFunc(reshape);
    glutKeyboardFunc(key);
    glutSpecialFunc(arrowKey);
    
    initGL();                       // Our own OpenGL initialization
    
    glutMainLoop();                 // Enter the infinite event-processing loop
    return 0;

}
