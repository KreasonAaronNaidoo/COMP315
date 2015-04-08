#include "player.h"
#include <windows.h>
#include <GL/glut.h>
#include <iostream>
#include<math.h>




player::player(){

}

player::player(float x, float y, float z){
    this->x = x;
    this->y = y;
    this->z = z;
}


void player::render(){

    glPushMatrix();
    glTranslatef(x, y, z); // move to this position
    drawplayer();
    glPopMatrix();
}

void player::drawplayer(){
    glScalef(0.1f,0.1f,0.1f);
	glTranslatef(0.0f,1.0f,0.0f);
    glBegin(GL_TRIANGLES);
        glColor3d(255,0,255);
		glVertex3f( 0.0f, 1.0f, 0.0f);
		glVertex3f(-1.0f,-1.0f, 1.0f);
		glVertex3f( 1.0f,-1.0f, 1.0f);
		glColor3d(0,255,0);
		glVertex3f( 0.0f, 1.0f, 0.0f);
		glVertex3f( 1.0f,-1.0f, 1.0f);
		glVertex3f( 1.0f,-1.0f, -1.0f);
		glColor3d(255,255,0);
		glVertex3f( 0.0f, 1.0f, 0.0f);
		glVertex3f( 1.0f,-1.0f, -1.0f);
		glVertex3f(-1.0f,-1.0f, -1.0f);
		glColor3d(0,0,255);
		glVertex3f( 0.0f, 1.0f, 0.0f);
		glVertex3f(-1.0f,-1.0f,-1.0f);
		glVertex3f(-1.0f,-1.0f, 1.0f);
	glEnd();
}
