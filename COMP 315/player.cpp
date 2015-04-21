#include "player.h"
#include <GLUT/glut.h>
#include <iostream>
#include<math.h>
#include "npc.h"
#include "point.h"

using namespace std;



player::player(){

}

player::player(float x, float y, float z, cam *P){
    this->x = x;
    this->y = y;
    this->z = z;
    q = P;
    
}

void player::shoot(){
    //mag.push_back(new bullet(x,y,z,0,0,500.0)); // change to mouse position
    //mag.push_back(new bullet(x,y,z,0,10,5));//player position to mouse position
   
    
    
    mag.push_back(new bullet(x,y,z,1,1,1000));
    //cout<<"true";
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
    for(int i=0 ; i<mag.size() ; i++){
        mag[i].render();
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

vector<bullet>* player::getBulletVector(){
    return &mag;
}
