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

    glPushMatrix();

        glBegin(GL_QUADS);
            glVertex2f(125, 125);
            glVertex2f(125, 375);
            glVertex2f(375, 375);
            glVertex2f(375, 125);
        glEnd();

    glPopMatrix();
    glutSwapBuffers();

}
