//
//  cam.cpp
//  COMP 315
//
//  Created by Kreason Aaron Naidoo on 2015/04/05.
//  Copyright (c) 2015 Kreason Aaron Naidoo. All rights reserved.
//
#include <windows.h>
#include <iostream>
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include <stdlib.h>
#include <cmath>
#include <stdio.h>
#include "cam.h"


cam::cam(float x, float y, float z, float lx, float ly, float lz){

    this -> x = x;
    this -> y = y;
    this -> z = z;
    this -> lx = lx;
    this -> ly = ly;
    this -> lz = lz;


}

void cam::place(){

    gluLookAt(this -> x, this -> y, this -> z, // camera position
              this -> lx, this -> ly, this -> lz, // look at position, line of sight
              0, 1, 0); // up direction (vector) for camera tilt



}
