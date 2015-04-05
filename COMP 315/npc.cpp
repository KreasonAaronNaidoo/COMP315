//
//  npc.cpp
//  COMP 315
//
//  Created by Kreason Aaron Naidoo on 2015/03/24.
//  Copyright (c) 2015 Kreason Aaron Naidoo. All rights reserved.
//

#include <GLUT/glut.h>
#include <iostream>
#include <math.h>
#include <cstdlib>
#include "npc.h"
#include "time.h"

#define PI 3.14159265

using namespace std;

npc::npc(){
    npc(0,0,0); //spawns an asteroid at the very core of our home planet
}

npc::npc(double x, double y, double z){
    //passed by asteroid genetator
    this->x = x;
    this->y = y;
    this->z = z;
    /*These asteroids will always initially move toward the centre of the planet. These values will be changed
     by an external call if collision momentum physics algorithms are programmed successfully.*/
    this->to_x = 0;
    this->to_y = 0;
    this->to_z = 0;
    

    
    float t = rand() %10;
    this->velocity = t/10000;
    
    if (this -> velocity < 0.0003) {
        this -> velocity = 0.0003;
    }
    
    size = 1 + rand() % 3;
    

    
    dist=sqrt(pow((x-to_x),2)+pow((y-to_y),2)+pow((z-to_z),2));   //this is the distance between start location and origin
    time=dist/velocity;                                           //time is a multiplicative constant applied to resolved vector velocities
    
    vX=fabs((x-to_x)/time);        //x-component of velocity
    vY=fabs((y-to_y)/time);        //y-component of velocity
    vZ=fabs((z-to_z)/time);        //z-component of velocity
    
    angle=0.0;
    angVelocity=rand()%5+1; //random vaue between 1 and 5
    
    health=size;            //1-3  -subject to change
    collision=false;        //interacts with collision detection. flag
    alive=true;             //cease render flag
    
    /*Sets radius based on size. Size could  be randomised when called generator*/
    if(size==1)
        radius=0.001;
    else if(size==2)
        radius=0.002;
    else if(size==3)
        radius=0.003;
    cout << "v : "<<this->velocity<<" r: "<<this->radius<<endl;

    
}

void npc::render(){
    //if alive is false render will cease and the object will cease
    if(alive){
        glPushMatrix();
        glTranslated(x, y, z); // move to initial position
        
        rotate(); //asteroid rotates on its own axis
        move();   //move toward
        takeDamage();
        
        //sets colour of material
        GLfloat ambient[] = { 0.8, 0.0, 0.0, 1};
        glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, ambient);
        
        // sets specular properties of the material
        GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
        glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
        
        // sets the shininess of the material
        GLfloat mat_shininess[] = { 50.0 };
        glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
        
        glutWireSphere(radius,25,25);
        //glutWireSphere(radius,25,25);
        glPopMatrix();
    }
}

//update is not currently useful
void npc::update(){
    //move could be here or within render(tested both). Rotate cannot be here, it must be within render.
    //move(vX, vY, vZ);//the render method in main will call update which will control movement
    render();
}

void npc::rotate(){
    //increment the angle and call rotate function
    angle+=angVelocity;
    
    if(angle>360.f)
    {
        angle-=360;
    }
    
    //rotates to current angle value on y-axis
    glRotatef(angle,0,1,0); //randomise axes? included cstdlib
}


void npc::move(){
    //x translation
    if(x!=to_x){          //if the ojbect is not at destination
        if(x>to_x){         //checks which side of the x-axis asteroid is currently on
            x-=vX;            //and increments/decrements accordingly
            if(x<to_x)      //logic applied to all axes
                x=to_x;
        }
        else if(x<to_x){
            x+=vX;
            if(x>to_x)
                x=to_x;
        }
    }
    //y translation
    if(y!=to_y){
        if(y>to_y){
            y-=vY;
            if(y<to_y)
                y=to_y;
        }
        else if(y<to_y){
            y+=vY;
            if(y>to_y)
                y=to_y;
        }
    }
    //z traslation
    if(z!=to_z){
        if(z>to_z){
            z-=vZ;
            if(z<to_z)
                z=to_z;
        }
        else if(z<to_z){
            z+=vZ;
            if(z>to_z)
                z=to_z;
        }
    }
}

void npc::takeDamage(){
    //collision detection will alter bool collision value and begin this statement
    if(collision){
        health-=1;
        if(health==0)  //if health was 1 then a collision must kill the asteroid
            die();
        
        collision=false; //stops  if statement from looping next cycle
    }
}

void npc::split(int size){
    /*Splitting an asteroid should result in generation of two more asteroids which should
     register as seperate objects in the world therefore this split method should be handled
     in the asteroid generation engine or main?*/
    
    /*_NOTE:_ The splitting method is currently patrially functional only for asteroid to asteroid collisions, and resides in main  */
}

void npc::die(){
    alive=false;     //do not render next cycle
}

int npc::getSize(){
    return size;
}

double npc::getRadius(){
    return radius;
}

double npc::getVelocity(){
    return velocity;
}

double* npc::getLocation(){
    double point[3]={x,y,z};
    
    return point;
}

void npc::regCollision(){
    collision=true;
}

void npc::setToPoint(float to_x, float to_y, float to_z){
    this->to_x = to_x;
    this->to_y = to_y;
    this->to_z = to_z;
}

double* npc::getToPoint(){
    double point[3]={to_x,to_y,to_z};
    
    return point;
}
bool npc::collisionState(){
    return collision;
}
