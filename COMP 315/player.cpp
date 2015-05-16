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
    obj.Load("resources\\models\\spaceship.obj");


}

void player::shoot(int x, int y){
    //cout<<"click"<<endl;


    GLfloat winX, winY, winZ;  // Holds Our X, Y and Z Coordinates

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



    v_bullet.push_back(new bullet((this->x),(this->y)-0.05,(this->z)+0.2,posX,posY,posZ));//player position to mouse position


}

void player::render(){

    glPushMatrix();


     //sets light of material
        GLfloat ambient[] = {0.75294118, 0.75294118, 0.75294118, 1.0};
        glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, ambient);
        //sets specular properties of the material
        GLfloat mat_specular[] = {1.0, 1.0, 1.0, 1.0};
        glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
        // sets the shininess of the material
        GLfloat mat_shininess[] = { 90.0 };
        glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);


    glTranslatef(x, y, z - 0.05); // move to this position
    //drawPlayer();
    glRotated(90,1,0,0);
    glScaled(0.02,0.02,0.02);
    obj.Draw();

    glPopMatrix();

//    collisionCheck();
    drawBullets();

}

void player::drawBullets(){
    for(int i=0 ; i<v_bullet.size() ; i++){
        v_bullet[i]->render();
    }
}

void collisionCheck(){

}

vector<bullet*> player::getBulletVector(){
    return v_bullet;
}
