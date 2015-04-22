//
//  planet.h
//  COMP 315
//
//  Created by Shaherin Dehaloo on 2015/03/31.
//  Copyright (c) 2015 Shaherin Dehaloo. All rights reserved.
//
#include <windows.h>
#ifndef PLANET_H
#define PLANET_H
#include "npc.h"

class planet{
public:
    planet();
    planet(float x, float y, float z);
    void rotate();
    void takeDamage(int level);
    void render();
    void update();
    void die();
    float x,y,z;


private:
    float angVelocity;
    int health;
    float angle;
    bool collision;
};


#endif // PLANET_H
