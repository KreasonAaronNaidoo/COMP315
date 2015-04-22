#include "player.h"
#include <iostream>
#include<math.h>
#include "npc.h"
#include "point.h"
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

player::player(){

}

player::player(float x, float y, float z){
    this->x = x;
    this->y = y;
    this->z = z;
}

void player::shoot(int x, int y){
    //cout<<"click"<<endl;


    GLfloat winX, winY, winZ;               // Holds Our X, Y and Z Coordinates

    winX = x;                  // Holds The Mouse X Coordinate
    winY = y;

    GLint viewport[4];
    GLdouble modelview[16];
    GLdouble projection[16];
    GLdouble posX, posY, posZ;

    glGetDoublev( GL_MODELVIEW_MATRIX, modelview );
    glGetDoublev( GL_PROJECTION_MATRIX, projection );
    glGetIntegerv( GL_VIEWPORT, viewport );

    winY = (float)viewport[3] - winY;           // Subtract The Current Mouse Y Coordinate From The Screen Height.

    glReadPixels( x, int(winY), 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &winZ );

    gluUnProject( winX, winY, winZ, modelview, projection, viewport, &posX, &posY, &posZ);



    v_bullet.push_back(*new bullet(this->x,this->y,this->z,posX,posY,posZ));//player position to mouse position

    /*POINT pt;
    bool result=GetCursorPos(&pt);
    cout<<pt.x<<endl;
    mag.push_back(new bullet(x,y,z,pt.x-650,pt.y-400,50));*/

}

void player::render(){

    glPushMatrix();
    glTranslatef(x, y, z); // move to this position
    drawPlayer();
    glPopMatrix();

//    collisionCheck();
    drawBullets();

}

void player::drawBullets(){
    for(int i=0 ; i<v_bullet.size() ; i++){
        v_bullet[i].render();
    }
}

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

void collisionCheck(){

}

vector<bullet> player::getBulletVector(){
    return v_bullet;
}
