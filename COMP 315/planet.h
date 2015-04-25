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
    float x,y,z;

    //texture variables
    GLuint _textureId; //The id of the texture
    GLUquadric *quad = gluNewQuadric();

private:
    float angVelocity;
    int health;
    float angle;
    bool collision;
    GLuint loadTexture(Image* image);
};


#endif // PLANET_H
