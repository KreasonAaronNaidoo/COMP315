//
//  planet.cpp
//  COMP 315
//
//  Created by Shaherin Dehaloo on 2015/03/31.
//  Copyright (c) 2015 Shaherin Dehaloo. All rights reserved.
//

#include <windows.h>
#include <GL/glut.h>
#include <iostream>
#include <math.h>
#include "planet.h"
#include "asteroid.h"

using namespace std;

planet::planet(){
   planet(0,0,0);
}

planet::planet(float x, float y, float z){
    this->x = x;
    this->y = y;
    this->z = z;

    angle=0.0;
    angVelocity=1.0f;
    health=100;
    collision=false;
}

void planet::render(){
    glPushMatrix();
    glTranslated(x, y, z); // move to this position

    rotate();

    //sets colour of material
    GLfloat ambient[] = { 0.2, 0.4, .8, 1};
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, ambient);

    // sets specular properties of the material
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);

    // sets the shininess of the material
    GLfloat mat_shininess[] = { 50.0 };
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

    glutSolidSphere(0.5,25,25);//radius 0.5, 25 slices and stacks
    //glutWireSphere(0.5,25,25);
    glPopMatrix();
}

void planet::update(){
    if(health==0){
        die();
    }

    render();
}

void planet::rotate(){

   angle+=angVelocity;

    if(angle>360.f)
    {
      angle-=360;
    }

    glRotatef(angle,-0.2,1,0);
}

void planet::takeDamage(asteroid ast){
   if(collision){
     if(ast.asteroid::getSize()==1)
         health-=10;
     else if(ast.asteroid::getSize()==1)
         health-=20;
     else if(ast.asteroid::getSize()==1)
         health-=30;
   }
}

void planet::die(){
    cout<<"Death becomes you";  //die shouldn't be handled the same way
}
