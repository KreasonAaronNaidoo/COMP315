//
//  planet.cpp
//  COMP 315
//
//  Created by Shaherin Dehaloo on 2015/03/31.
//  Copyright (c) 2015 Shaherin Dehaloo. All rights reserved.
//

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>
#include <math.h>
#include "planet.h"
#include "npc.h"

using namespace std;

planet::planet(){
    planet(0,0,0);
}

planet::planet(float x, float y, float z){
    this->x = x;
    this->y = y;
    this->z = z;

    angle=0.0;
    angVelocity=0.1;
    health=100;
    collision=false;
}

void planet::render(){

    glColor3d(64, 0, 0);

    glPushMatrix();
    glTranslatef(x, y, z); // move to this position

    rotate();

    //sets colour of material
    GLfloat ambient[] = { 0.2, 0.4, 0.8, 1};
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, ambient);

    // sets specular properties of the material
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);

    // sets the shininess of the material
    GLfloat mat_shininess[] = { 50.0 };
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

    //glutSolidSphere(0.04,25,25);//radius 0.5, 25 slices and stacks
    glutWireSphere(4.0,25,25); //using the wire for demo reasons, untill textures are done
    glPopMatrix();
}

void planet::update(){
    if(health==0){
        die();
    }

   this->render();
}

void planet::rotate(){  //we need to slow this down
    angle+=angVelocity/5;

    if(angle>360.f)
    {
        angle-=360;
    }

    glRotatef(angle,-0.2,1,0);
}

void planet::takeDamage(int level){

        if(level == 1)
            health-=10;
        else if(level == 2)
            health-=20;
        else if(level == 3)
            health-=30;

        cout <<"Collision Detected: Planet hit, health reduced to "<<health<<endl;

        if(health <= 0){
            die();
        }

}

void planet::die(){
    cout<<"Death becomes you"<<endl;  //die shouldn't be handled the same way
}
