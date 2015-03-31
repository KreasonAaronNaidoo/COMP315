//
//  planet.h
//  COMP 315
//
//  Created by Shaherin Dehaloo on 2015/03/31.
//  Copyright (c) 2015 Shaherin Dehaloo. All rights reserved.
//

#ifndef PLANET_H
#define PLANET_H
#include "asteroid.h"

class planet{
    public:
        planet();
        planet(float x, float y, float z);
        void rotate();
        void takeDamage(asteroid asteroid);
        void render();
        void update();
        void die();

    private:
        float x,y,z;
        int angVelocity;
        int health;
        float angle;
        bool collision;
};


#endif // PLANET_H
