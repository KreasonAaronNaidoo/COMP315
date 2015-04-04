
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
    glScalef(0.5f,0.5f,0.5f);
	glTranslatef(0.0f,1.0f,0.0f);
    glBegin(GL_TRIANGLES);
        glVertex3f( 0.5f, 1.0f, -2.0f);
		glVertex3f(-1.0f,-1.0f, 1.0f);
		glVertex3f( 1.0f,-1.0f, 1.0f);
		glVertex3f( 0.50f, 1.0f, -2.0f);
		glVertex3f( 1.0f,-1.0f, 1.0f);
		glVertex3f( 1.0f,-1.0f, -1.0f);
		glVertex3f( 0.5f, 1.0f, -2.0f);
		glVertex3f( 1.0f,-1.0f, -1.0f);
		glVertex3f(-1.0f,-1.0f, -1.0f);
		glVertex3f( 0.5f, 1.0f, -2.0f);
		glVertex3f(-1.0f,-1.0f,-1.0f);
		glVertex3f(-1.0f,-1.0f, 1.0f);
	glEnd();
}
