//
//  physics_engine.cpp
//  COMP 315
//
//  Created by Kreason Aaron Naidoo on 2015/03/24.
//  Copyright (c) 2015 Kreason Aaron Naidoo. All rights reserved.
//

#include "physics_engine.h"
#include <iostream>
#include <GLUT/glut.h>  // GLUT, include glu.h and gl.h
#include <stdlib.h>
#include <cmath>
#include <stdio.h>

physics_engine::physics_engine(){
    
}



void physics_engine::init_world(){

glPushMatrix();
uni -> int_empty_world(); //uses the world class
glPopMatrix();

}