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

    //go to 2D
    glDepthMask(GL_FALSE);                  // disable writes to Z-Buffer
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_LIGHTING);
    glMatrixMode(GL_PROJECTION);			// Select Projection
	glPushMatrix();							// Push The Matrix
	glLoadIdentity();						// Reset The Matrix
	glOrtho(0, glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT), 0, -1, 100);		    // Select Ortho Mode
	glMatrixMode(GL_MODELVIEW);				// Select Modelview Matrix
	glPushMatrix();							// Push The Matrix
	glLoadIdentity();						// Reset The Matrix


    glPushMatrix();
    glColor3d(1,0,0);
    glBegin(GL_QUADS);      // try drawing a quad
        glVertex2f(0.0, 0.0);
        glVertex2f(5.0, 0.0);
        glVertex2f(5.0, 5.0);
        glVertex2f(0.0, 5.0);
    glEnd();

    glPopMatrix();


    //go back to 3D
    glMatrixMode( GL_PROJECTION );			// Select Projection
	glPopMatrix();							// Pop The Matrix
	glMatrixMode( GL_MODELVIEW );			// Select Modelview
	glPopMatrix();							// Pop The Matrix
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glDepthMask(GL_TRUE);  // disable writes to Z-Buffer





}
