//
//  planet.h
//  COMP 315
//
//  Created by Kreason Aaron Naidoo on 2015/03/24.
//  Copyright (c) 2015 Kreason Aaron Naidoo. All rights reserved.
//

#ifndef PLANET_H
#define PLANET_H

class planet{
    public:
        planet();
        planet(float x, float y, float z);
        void rotate();
        void takeDamage();
        void render();

    private:
        float x,y,z;
        int angVelocity;
        int health;
        float angle;
};


#endif // PLANET_H
