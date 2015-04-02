//
//  npc.cpp
//  COMP 315
//
//  Created by Kreason Aaron Naidoo on 2015/03/24.
//  Copyright (c) 2015 Kreason Aaron Naidoo. All rights reserved.
//

#include "npc.h"
#include <GLUT/glut.h>
#include <iostream>

using namespace std;

npc::npc(float a, float b, float c){
    
    this -> x = a;
    this -> y = b;
    this -> z = c;


    
}

npc::npc(){
    
}

void npc::setAll(float a, float b, float c){
    
    this -> x = a;
    this -> y = b;
    this -> z = c;
}

void npc::render(){
    glPushMatrix();
    
    glTranslated(x, y, z);
    
    //sets colour of material
    GLfloat ambient[] = { 0.2, 0.4, .8, 1};
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, ambient);
    
    // sets specular properties of the material
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    
    // sets the shininess of the material
    GLfloat mat_shininess[] = { 50.0 };
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    
    
    glutSolidSphere(0.005, 20, 20);
    //glutWireSphere(0.005, 20, 20);

    
    glPopMatrix();
    cout << "x " << x <<" y "<< y<<" z "<<z<< endl;

    
}