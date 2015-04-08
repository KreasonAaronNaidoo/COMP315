#include "player.h"
#include <GLUT/glut.h>
#include <iostream>
#include<math.h>




player::player(){

}

player::player(float x, float y, float z){
    this->x = x;
    this->y = y;
    this->z = z;
}

void player::shoot(){
    mag.push_back(new bullet(x,y,z,0,0,500.0)); // change to mouse position
}

void player::render(){

    glPushMatrix();
    glTranslatef(x, y, z); // move to this position
    drawPlayer();
    glPopMatrix();
}

/*void player::drawBullet(){
    

}*/

void player::drawPlayer(){
    glScalef(0.1f,0.1f,0.1f);
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
