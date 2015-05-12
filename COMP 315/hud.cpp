#include "hud.h"
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>

using namespace std;


HUD::HUD()
{
    this -> health = 100;
    this -> level = 1;
}

HUD::~HUD()
{
    //dtor
}


void HUD::update(int l, int h){

    this -> health = h;
    this -> level = l;
    this -> render();

}



void HUD::render(){

    glDisable( GL_LIGHTING );
    glDisable(GL_DEPTH_TEST);
    glDepthMask(GL_FALSE);

    glMatrixMode(GL_PROJECTION);					// Select Projection
	glPushMatrix();							// Push The Matrix
	glLoadIdentity();						// Reset The Matrix
	//glOrtho( 0, glutGet(GLUT_WINDOW_WIDTH) , glutGet(GLUT_WINDOW_HEIGHT) , 0, -1, 1 );				// Select Ortho Mode
	glOrtho( -100.0f, 100.0f, -100.0f, 100.0f, -100.0f, 100.0f );
	glMatrixMode(GL_MODELVIEW);					// Select Modelview Matrix
	glPushMatrix();							// Push The Matrix
	glLoadIdentity();



    //sets colour of material
    GLfloat ambient[] = { 1.0, 0.0, 0.0, 1.0};
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, ambient);
    //sets specular properties of the material
    GLfloat mat_specular[] = { 1.0, 0.5, 0.5, 1.0 };
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    // sets the shininess of the material
    GLfloat mat_shininess[] = { 10.0 };
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

        glTranslated(0,5,4);
        glBegin(GL_TRIANGLES);
            glVertex2d(0,10);
            glVertex2d(10,0);
            glVertex2d(0,0);
        glEnd();
        //try putting this code in render npc

    glEnable( GL_LIGHTING );
    glEnable(GL_DEPTH_TEST);
    glDepthMask(GL_TRUE);

    glMatrixMode( GL_PROJECTION );					// Select Projection
	glPopMatrix();							// Pop The Matrix
	glMatrixMode( GL_MODELVIEW );					// Select Modelview
	glPopMatrix();
}
