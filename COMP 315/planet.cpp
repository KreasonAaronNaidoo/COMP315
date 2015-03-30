//
//  planet.cpp
//  COMP 315
//
//  Created by Kreason Aaron Naidoo on 2015/03/24.
//  Copyright (c) 2015 Kreason Aaron Naidoo. All rights reserved.
//

#include <windows.h>
#include <GL/glut.h>
#include <iostream>
#include <math.h>
#include "planet.h"

planet::planet(){
   planet(0,0,0);
}

planet::planet(float x, float y, float z){
    this->x = x;
    this->y = y;
    this->z = z;

    angle=0.0;
}

void planet::render(){
    glPushMatrix();
    glTranslated(x, y, z); // move to this position

    rotate();

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

void planet::rotate(){
   //replace with angular velocity?
   angle+=1.0f;

    if(angle>360.f)
    {
      angle-=360;
    }

    glRotatef(angle,-0.2,1,0);
}

void takeDamage(){
   //subtract an amount dependent on asteroid size from main health if collision is detected
}

