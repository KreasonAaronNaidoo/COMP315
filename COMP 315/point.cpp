//
//  point.cpp
//  COMP 315
//
//  Created by Kreason Aaron Naidoo on 2015/03/24.
//  Copyright (c) 2015 Kreason Aaron Naidoo. All rights reserved.
//

#include "point.h"

point::point (float x, float y, float z){
    this->x = x;
    this->y = y;
    this->z = z;
}

point::point(){
    
    this->x = 0;
    this->y = 0;
    this->z = 0;
    
}

