//
//  world.cpp
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
#include "world.h"
#include <stdlib.h>
#include<iostream>
#include <cmath>
#include <stdio.h>
#include <iostream>



using namespace std;


world::world(){



}

void world::initWorld() {

	quad = gluNewQuadric();
    gluQuadricTexture(quad, GL_TRUE);
    gluQuadricOrientation(quad, GLU_INSIDE);

	Image* image = loadBMP("resources\\universe.bmp");
    _textureId = loadTexture(image);
	delete image;

}


void world::int_empty_world(){





    glPushMatrix();
     //sets colour of material
    GLfloat ambient[] = { 0.0, 0.5, 1.0, 0.8};
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, ambient);

    // sets specular properties of the material
    GLfloat mat_specular[] = { 0.0, 0.5, 1.0, 0.8 };
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);

    // sets the shininess of the material
    GLfloat mat_shininess[] = { 50.0 };
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

    glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId);

    //Bottom
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    gluQuadricTexture(quad,1);
    gluSphere(quad,100,50,50);//radius 0.5, 25 slices and stacks
    //glutWireSphere(100, 50, 50);

    glPopMatrix();


}

//Makes the image into a texture, and returns the id of the texture
GLuint world::loadTexture(Image* image) {
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



