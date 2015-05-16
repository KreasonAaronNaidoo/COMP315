//
//  npc.cpp
//  COMP 315
//
//  Created by Kreason Aaron Naidoo on 2015/03/24.
//  Copyright (c) 2015 Kreason Aaron Naidoo. All rights reserved.
//
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>
#include <math.h>
#include <cstdlib>
#include "npc.h"
#include "time.h"
#include "imageloader.h"

#define PI 3.14159265

using namespace std;

npc::npc(){
    //npc(0,0,0,0,0,0); //spawns an asteroid at the very core of our home planet
}

npc::~npc(){

}

npc::npc(double sx, double sy, double sz, double fx, double fy, double fz, GLuint _textureId_NPC){
    //passed by asteroid genetator
    this->sx = sx;
    this->sy = sy;
    this->sz = sz;

    /*These asteroids will always initially move toward the centre of the planet. These values will be changed
     by an external call if collision momentum physics algorithms are programmed successfully.*/

    this->fx = fx;
    this->fy = fy;
    this->fz = fz;

    this->_textureId_NPC=_textureId_NPC;

    float t = rand() %10;

    this->velocity = t/50; //this needs to be tweaked.
    if (this -> velocity < 0.003) {
        this -> velocity = 0.005;
    }

    getMovement();

    size = 1 + rand() % 3;

    angle=0.0;
    angVelocity=rand()%5+1; //random vaue between 1 and 5

    health=size;            //1-3  -subject to change
    collision=false;        //interacts with collision detection. flag
    alive=true;             //cease render flag

    /*Sets radius based on size. Size could  be randomised when called by generator*/
    if(size==1)
        radius=0.1;
    else if(size==2)
        radius=0.2;
    else if(size==3)
        radius=0.3;
    //cout << "v : "<<this->velocity<<" r: "<<this->radius<<endl;


}

void npc::render(){

    if((this -> sz) < -10){
        this -> alive = false;
    }

    if(((this -> sx)*(this -> sx) + (this -> sy)*(this -> sy) + (this -> sz)*(this -> sz)) > 10000){
        this -> alive = false;//this is just a back up
    }

    if(alive){
        glPushMatrix();
        glTranslated(sx, sy, sz); // move to initial position

        rotate(); //asteroid rotates on its own axis
        move();   //move toward
        takeDamage();


        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, _textureId_NPC);

	    //Bottom
	    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	    glTexParameteri(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);//edited by me
	    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        //sets colour of material
        GLfloat ambient[] = { 0.3, 0.3, 0.3, 1};
        glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, ambient);
        //sets specular properties of the material
        GLfloat mat_specular[] = { 1, 1, 1, 1.0 };
        glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
        // sets the shininess of the material
        GLfloat mat_shininess[] = { 10.0 };
        glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);


        gluQuadricTexture(quad_NPC,1);
        gluSphere(quad_NPC,radius,25,25);//radius 0.5, 25 slices and stacks

        //glutWireSphere(radius,25,25);
        //glutSolidSphere(radius,25,25);*/

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
    angle+= angVelocity;

    if(angle>360.f)
    {
        angle-=360;//this is to stop angle from incrementing infinitely and wasting space with large values
    }

    //rotates to current angle value on y-axis
    glRotatef(angle,0,1,0); //randomise axes
}

void npc::move(){

    //x translation
      sx+=Vx;
    //y translation
      sy+=Vy;
    //z traslation
      sz+=Vz;

}

void npc::takeDamage(){
    //collision detection will alter bool collision value and begin this statement
    if(collision){
        collision=false;
        health-=1;
        if(health==0){  //if health was 1 then a collision must kill the asteroid
            die();
        }
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
    double point[3]={sx,sy,sz};

    return point;
}

void npc::regCollision(){
    collision=true;
    //alive =false;
}

void npc::setToPoint(float fx, float fy, float fz){
    this->fx= fx;
    this->fy = fy;
    this->fz = fz;
}

double* npc::getToPoint(){
    double point[3]={fx,fy,fz};

    return point;
}
bool npc::collisionState(){

    return collision;
}

void npc::getMovement(){
    //get r
    dist=sqrt(pow((sx-fx),2)+pow((sy-fy),2)+pow((sz-fz),2));

    //angles in spherical coordinates
    theta=atan(fabs(sz-fz)/fabs(sx-fx));
    phi=acos(fabs((sy-fy)/dist));

    /*After bullet reaches its destination is must continue moving past therefore reverse velocity increment
     (there must be a better way to actually do this)*/
    if(sx<fx)
        Vx=velocity*cos(theta)*sin(phi);
    else if(sx>fx)
        Vx=-velocity*cos(theta)*sin(phi);

    if(sz<fz)
        Vz=velocity*sin(theta)*sin(phi);
    else if(sz>fz)
        Vz=-velocity*sin(theta)*sin(phi);

    if(sy<fy)
        Vy=velocity*cos(phi);
    else if(sy>fy)
        Vy=-velocity*cos(phi);
}
