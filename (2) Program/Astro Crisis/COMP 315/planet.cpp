//
//  planet.cpp
//  COMP 315
//
//  Created by Shaherin Dehaloo on 2015/03/31.
//  Copyright (c) 2015 Shaherin Dehaloo. All rights reserved.
//



#ifdef __APPLE__
#include <GLUT/glut.h>
char *t = "resources/earth.bmp";
#else
#include <GL/glut.h>
char *t = "resources\\earth_8k.bmp";
#endif
#include <iostream>
#include <math.h>

#include "planet.h"
#include "npc.h"
#include "imageloader.h"


using namespace std;

/*planet::planet(){
    planet(0,0,0);
}*/

planet::planet(float x, float y, float z) : renderableObject(x,y,z){
    //this->x = x;
    //this->y = y;
    //this->z = z;

    angle=0.0;
    angVelocity=0.1;
    health=100;
    collision=false;


}

//callback function initialises required variables and imports the image
void planet::initPlanet() {

	quad_PLANET = gluNewQuadric();

	Image* image_PLANET = loadBMP(t);
    _textureId_PLANET = loadTexture(image_PLANET);
	delete image_PLANET;
}

void planet::render(){

    if (alive == true){

    glPushMatrix();

    glTranslatef(sx, sy, sz); // move to this position

    glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId_PLANET);

    //Bottom
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);//edited by me
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glRotatef(90,1.0f,0.0f,0.0f);
    rotate();

    //sets colour of material
    GLfloat ambient[] = { 0.2, 0.2, 0.2, 1};
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, ambient);
    // sets specular properties of the material
    GLfloat mat_specular[] = { 0.5, 0.5, 0.5, 1.0 };
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    // sets the shininess of the material
    GLfloat mat_shininess[] = { 20.0 };
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

    gluQuadricTexture(quad_PLANET,1);
    gluSphere(quad_PLANET,4,40,40);//radius 0.5, 25 slices and stacks
    glPopMatrix();

    }

}

void planet::update(){



   this->render();
}

void planet::rotate(){  //we need to slow this down
    angle+=angVelocity/5;

    if(angle>360.f)
    {
        angle-=360;
    }

    glRotatef(angle,0.2,0,1); //approximately equal to earths rotation axis
}

void planet::takeDamage(int level){

        if(level == 1)
            health-=10;
        else if(level == 2)
            health-=20;
        else if(level == 3)
            health-=30;

        cout <<"Collision Detected: Planet hit, health reduced to "<<health<<endl;

        if(health <= 0){
            health = 0;
            die();
        }

}

void planet::die(){
    cout<<"Death becomes you"<<endl;  //die shouldn't be handled the same way
    alive = false;
}

//Makes the image into a texture, and returns the id of the texture
GLuint planet::loadTexture(Image* image) {
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
