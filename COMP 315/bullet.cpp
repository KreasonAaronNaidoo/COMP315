//
//  bullet.cpp
//  COMP 315
//
//  Created by Kreason Aaron Naidoo on 2015/04/09.
//  Copyright (c) 2015 Kreason Aaron Naidoo. All rights reserved.
//

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "bullet.h"

#include <stdio.h>
#include <iostream>
#include <math.h>
#include <cstdlib>
#include "point.h"

using namespace std;

GLuint bullet::loadTexture(Image* image) {
	GLuint textureId;
	glGenTextures(1, &textureId); //Make room for our texture
	glBindTexture(GL_TEXTURE_2D, textureId); //Tell OpenGL which texture to edit
	//Map the image to the texture
	glTexImage2D(GL_TEXTURE_2D,                //Always GL_TEXTURE_2D
				 0,                            //0 for now
				 GL_RGB,                       //Format OpenGL uses for image
				 image->width, image->height,  //Width and height
				 0,                            //The border of the image
				 GL_RGB, //GL_RGB, because pixels are stored in RGB format
				 GL_UNSIGNED_BYTE, //GL_UNSIGNED_BYTE, because pixels are stored
				                   //as unsigned numbers
				 image->pixels);               //The actual pixel data
	return textureId; //Returns the id of the texture
}

bullet::bullet(float sx,float sy,float sz,float fx ,float fy,float fz){
//Uses to and from to essentially create a movement vector
    this -> sx = sx;
    this -> sy = sy;
    this -> sz = sz;
    this -> fx = fx;
    this -> fy = fy;
    this -> fz = fz;

    this->velocity=0.05;
    this->alive=true;

    //Image* image_Bullet = loadBMP("resources\\energy.bmp");
    //_textureId_Bullet = loadTexture(image_Bullet);
	//delete image_Bullet;

    getMovement();

}

bullet::~bullet(){


}

void bullet::render(){
    //if alive is false render will cease and the object will cease
    if(alive){
        glPushMatrix();
        glTranslated(sx, sy, sz); // move to position

       // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	   // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	   // glTexParameteri(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

         //sets colour of material
        GLfloat ambient[] = {0.2, 0.3, 0.7, 0.7};
        glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, ambient);
        //sets specular properties of the material
        GLfloat mat_specular[] = { 0.5, 0.5, 0.5, 1.0};
        glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
        // sets the shininess of the material
        GLfloat mat_shininess[] = { 90.0 };
        glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);


       // glEnable(GL_TEXTURE_2D);
       // glBindTexture(GL_TEXTURE_2D, _textureId_Bullet);

       // gluQuadricTexture(quad_Bullet,1);

        move();

       // gluSphere(quad_Bullet,rad,25,25);

        glutSolidSphere(rad,25,25);
        //glutWireSphere(radius,25,25);
        glPopMatrix();



    }
}

void bullet::update(){

}

void bullet::move(){

    //x translation
      sx+=Vx;
    //y translation
      sy+=Vy;
    //z traslation
      sz+=Vz;

}

void bullet::getMovement(){
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

        //cout<<Vx<<endl; //Vx is sometimes incorrect for some mysterious reason. Values passed are always the same
}

double* bullet::getLocation(){
    double point[3]={sx,sy,sz};

    return point;
}

void bullet::die(){
    alive=false;
}
