//
//  world.cpp
//  COMP 315
//
//  Created by Kreason Aaron Naidoo on 2015/03/24.
//  Copyright (c) 2015 Kreason Aaron Naidoo. All rights reserved.
//

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include "world.h"
#include <stdlib.h>
#include<iostream>
#include <cmath>
#include <stdio.h>
#include <iostream>



using namespace std;


world::world(){



}






void world::int_empty_world(){




    glColor3ub(0,60,67); // green

    GLUquadricObj *quadric;
    quadric=gluNewQuadric();
    gluQuadricNormals(quadric, GLU_SMOOTH);
    gluQuadricTexture(quadric, GL_TRUE);


    glEnable(GL_TEXTURE_2D);

    //glBindTexture(GL_TEXTURE_2D, texture); //will add the texture once i figure out how...

    //gluSphere(quadric,10, 50, 50);

    /* //sets colour of material
    GLfloat ambient[] = { 0.0, 0.1, 0.0, 1};
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, ambient);

    // sets specular properties of the material
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);

    // sets the shininess of the material
    GLfloat mat_shininess[] = { 50.0 };
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);*/

    glutWireSphere(100, 50, 50);



}





