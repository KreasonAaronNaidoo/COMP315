//
//  npc.h
//  COMP 315
//
//  Created by Kreason Aaron Naidoo on 2015/03/24.
//  Copyright (c) 2015 Kreason Aaron Naidoo. All rights reserved.
//

#ifndef __COMP_315__npc__
#define __COMP_315__npc__

#include <stdio.h>
#include "point.h"


class npc{
public:
    //constructors
    npc();
    npc(double x, double y, double z);
    //void
    void render();
    void update();
    void move();
    void regCollision();
    void takeDamage();
    void split(int size);
    void die();
    //get
    int getSize();
    double* getLocation();
    double getRadius();
    double getVelocity();
    double* getToPoint();
    //set
    bool collisionState();
    void setToPoint(float to_x, float to_y, float to_z);
    
    
private:
    double radius;
    double x, y, z;        //initial point
    double to_x,to_y,to_z; //end point      -this may need to be transferred to a vector class where vector magnitude etc are also defined
    int size;              //size 1,2,3     -sizes respond to radii. Possibly redundant
    float velocity;
    double vX,vY,vZ;       //components of velocity  -in order to maintain motion at a constant angle
    double angVelocity;    //rotation speed
    double angle;          //iterate and reset
    double time;
    int health;
    bool collision;        //until hit detection is finalized
    bool alive = true;            //default true. When false cease rendering
    double dist;           //distance between asteroid position and destination
    void rotate();         //rotate not called externally
};


#endif /* defined(__COMP_315__npc__) */
