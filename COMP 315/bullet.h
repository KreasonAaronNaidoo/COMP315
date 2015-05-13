//
//  bullet.h
//  COMP 315
//
//  Created by Kreason Aaron Naidoo on 2015/04/09.
//  Copyright (c) 2015 Kreason Aaron Naidoo. All rights reserved.
//

#ifndef __COMP_315__bullet__
#define __COMP_315__bullet__

#include <stdio.h>


class bullet {

public:
    bullet(float sx,float sy,float sz,float fx ,float fy,float fz);
    ~bullet();
    void render();
    void update();
    void move();
    double* getLocation();
    void die();
    float sx, sy, sz;
    float rad = 0.05;


private:
    float fx ,fy, fz;
    float velocity;
    bool alive;
    float Vx, Vy, Vz;
    float theta;
    float phi;
    float dist;

    void getMovement();


};

#endif /* defined(__COMP_315__bullet__) */
