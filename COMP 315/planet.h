//
//  planet.h
//  COMP 315
//
//  Created by Shaherin Dehaloo on 2015/03/31.
//  Copyright (c) 2015 Shaherin Dehaloo. All rights reserved.
//
#ifndef PLANET_H
#define PLANET_H
#include "npc.h"
#include "imageloader.h"
#include <string.h>
#include "explosions.h"

using namespace std;

class planet{
public:
    planet();
    planet(float x, float y, float z);
    void initPlanet();  //callback
    void rotate();
    void takeDamage(int level);
    void render();
    void update();
    void die();
    bool alive = true;
    bool plandeath = false;
    float x,y,z;
    int health;



    //texture variables
    GLuint _textureId_PLANET; //The id of the texture
    GLUquadric *quad_PLANET = gluNewQuadric();

private:
    float angVelocity;
    float angle;
    bool collision;
    GLuint loadTexture(Image* image);
};


#endif // PLANET_H
