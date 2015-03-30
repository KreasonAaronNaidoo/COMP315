//
//  physics_engine.h
//  COMP 315
//
//  Created by Kreason Aaron Naidoo on 2015/03/24.
//  Copyright (c) 2015 Kreason Aaron Naidoo. All rights reserved.
//

#ifndef __COMP_315__physics_engine__
#define __COMP_315__physics_engine__

#include <stdio.h>
#include "world.h"
#include <GLUT/glut.h>  // GLUT, include glu.h and gl.h
#include <vector>


class physics_engine{
    
private:
    
public:
  
    
    physics_engine();
    void init_world();
    
   
    
    world *uni = new world();

    
};

#endif /* defined(__COMP_315__physics_engine__) */
