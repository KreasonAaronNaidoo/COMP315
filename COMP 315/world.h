//
//  world.h
//  COMP 315
//
//  Created by Kreason Aaron Naidoo on 2015/03/24.
//  Copyright (c) 2015 Kreason Aaron Naidoo. All rights reserved.
//

#ifndef __COMP_315__world__
#define __COMP_315__world__
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdio.h>
#include "npc.h"

#include <vector>


class world{

private:

public:
    void int_empty_world();

    //texture variables
    GLuint _textureId; //The id of the texture
    GLUquadric *quad = gluNewQuadric();

    GLuint loadTexture(Image* image);

    void initWorld();

    world();



};

#endif /* defined(__COMP_315__world__) */
