//
//  bullet.cpp
//  COMP 315
//
//  Created by Kreason Aaron Naidoo on 2015/04/09.
//  Copyright (c) 2015 Kreason Aaron Naidoo. All rights reserved.
//

#include "bullet.h"
#include <GL/glut.h>
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <cstdlib>
#include "point.h"

using namespace std;

bullet::bullet(float sx,float sy,float sz,float fx ,float fy,float fz){

    this -> sx = sx;
    this -> sy = sy;
    this -> sz = sz;
    this -> fx = fx;
    this -> fy = fy;
    this -> fz = fz;
//cout<<fx<<endl;
    this->velocity=0.02;
    this->alive=true;

    getMovement();

}

void bullet::render(){
    //if alive is false render will cease and the object will cease
    if(alive){
        glPushMatrix();
        glTranslated(sx, sy, sz); // move to initial position

        move();   //move toward

        //sets colour of material
        GLfloat ambient[] = { 0.0, 1.0, 0.0, 1};
        glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, ambient);

        // sets specular properties of the material
        GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
        glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);

        // sets the shininess of the material
        GLfloat mat_shininess[] = { 50.0 };
        glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

        glutWireSphere(0.1,25,25);
        //glutWireSphere(radius,25,25);
        glPopMatrix();
    }
}

void bullet::update(){

}

void bullet::move(){

    //x translation
      sx+=Vx;
    //y translation
      sy+=Vy;
    //z traslation
      sz+=Vz;

}

void bullet::getMovement(){

    dist=sqrt(pow((sx-fx),2)+pow((sy-fy),2)+pow((sz-fz),2));

    theta=atan(fabs(sz-fz)/fabs(sx-fx));
    phi=acos(fabs((sy-fy)/dist));

    if(sx<fx)
        Vx=velocity*cos(theta)*sin(phi);
    else if(sx>fx)
        Vx=-velocity*cos(theta)*sin(phi);

    if(sz<fz)
        Vz=velocity*sin(theta)*sin(phi);
    else if(sz>fz)
        Vz=-velocity*sin(theta)*sin(phi);

    if(sy<fy)
        Vy=velocity*cos(phi);
    else if(sy>fy)
        Vy=-velocity*cos(phi);

        //cout<<Vx<<endl; //Vx is sometimes incorrect for some mysterious reason. Values passed are always the same
}

double* bullet::getLocation(){
    double point[3]={sx,sy,sz};

    return point;
}

void bullet::die(){
    alive=false;
}
