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
#include "imageloader.h"
#include "RenderableObject.h"
#include <GL/glut.h>




class bullet : public renderableObject {

public:
    bullet(float sx,float sy,float sz,float fx ,float fy,float fz, GLuint _textureId_Bullet);
    ~bullet();
    virtual void render();
    virtual void update();
    void move();
    double* getLocation();
    virtual void die();

    void initBullet();

    //float sx, sy, sz;
    float rad = 0.02;

    GLuint _textureId_Bullet; //The id of the texture
    GLUquadric *quad_Bullet = gluNewQuadric();


private:
    float fx ,fy, fz;
    float velocity;
    //bool alive;
    float Vx, Vy, Vz;
    float theta;
    float phi;
    float dist;

    void getMovement();

};

#endif /* defined(__COMP_315__bullet__) */
