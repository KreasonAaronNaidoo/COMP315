#include "player.h"
#include <GLUT/glut.h>
#include <iostream>
#include<math.h>
#include "npc.h"
#include "point.h"

player::player(){

}

player::player(float x, float y, float z){
    this->x = x;
    this->y = y;
    this->z = z;
}

void player::shoot(){
    //cout<<"click"<<endl;
    v_bullet.push_back(*new bullet(this->x,this->y,this->z,x,y,0));//player position to mouse position

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
