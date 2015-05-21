//
//  world.cpp
//  COMP 315
//
//  Created by Kreason Aaron Naidoo on 2015/03/24.
//  Copyright (c) 2015 Kreason Aaron Naidoo. All rights reserved.
//

#include "world.h"
#include <GLUT/glut.h> // GLUT, include glu.h and gl.h
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
    
    glutWireSphere(100, 50, 50);

    
    
}





