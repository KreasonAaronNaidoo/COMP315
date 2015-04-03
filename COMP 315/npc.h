//
//  npc.cpp
//  COMP 315
//
//  Created by Shaherin Dehaloo on 2015/04/03.
//  Copyright (c) 2015 Shaherin Dehaloo. All rights reserved.
//

#ifndef NPC_H
#define NPC_H

class npc{
    public:
        //constructors
        npc();
        npc(double x, double y, double z, int size, double velocity);
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
        double x, y, z;        //initial point
        double to_x,to_y,to_z; //end point      -this may need to be transferred to a vector class where vector magnitude etc are also defined
        int size;              //size 1,2,3     -sizes respond to radii. Possibly redundant
        double velocity;
        double vX,vY,vZ;       //components of velocity  -in order to maintain motion at a constant angle
        double angVelocity;    //rotation speed
        double angle;          //iterate and reset
        double time;
        int health;
        bool collision;        //until hit detection is finalized
        bool alive;            //default true. When false cease rendering
        double dist;           //distance between asteroid position and destination
        void rotate();         //rotate not called externally
};


#endif // NPC_H
