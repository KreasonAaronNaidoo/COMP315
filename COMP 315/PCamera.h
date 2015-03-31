//
//  PCamera.h
//  COMP 315
//
//  Created by Kreason Aaron Naidoo on 2015/03/31.
//  Copyright (c) 2015 Kreason Aaron Naidoo. All rights reserved.
//

#ifndef __COMP_315__PCamera__
#define __COMP_315__PCamera__

#include <GLUT/glut.h>
#include <stdlib.h>
#include <math.h>
#include "point.h"

/**YO LIAM DUDE! NOTE TO SELF - CHECK THE IN-BUILT VECTORS STUFF FIRST! COULD SAVE A MIGHTY LARGE AMOUNT OF TROUBLE!*/

//Our custom 3-D vector structure (that should probably be moved to another section of our programs unless we find a better way
struct V3ctor
{
    //These be our fields, yo. Only seeds of greatness be planted here (Gods, I'm tired)
    float x_pos, y_pos, z_pos;
    
    //Basic constructor - does nada
    V3ctor() {}
    //Parameterised constructor - where the magic happens
    V3ctor(float x_new, float y_new, float z_new)
    {
        x_pos = x_new;
        y_pos = y_new;
        z_pos = z_new;
    }
    
    //Ok, boys... listen up. We about to OVERLOAD SOME CONSTRUCTORS, BABY!
    V3ctor operator+ (V3ctor v) //This be the "addition" overloader
    {
        return V3ctor(v.x_pos+x_pos, v.y_pos+y_pos, v.z_pos+z_pos);
    }
    
    V3ctor operator- (V3ctor v) //This be the "subtraction" overloader
    {
        return V3ctor(v.x_pos-x_pos, v.y_pos-y_pos, v.z_pos-z_pos);
    }
    
    V3ctor operator* (V3ctor v) //...Imma let you have a guess what this one does
    {
        return V3ctor(v.x_pos*x_pos, v.y_pos*y_pos, v.z_pos*z_pos);
    } //JK its the "multiplication" overloader, if you missed it
    
    V3ctor operator/ (V3ctor v) //This be the "division" overloader
    {
        return V3ctor(v.x_pos/x_pos, v.y_pos/y_pos, v.z_pos/z_pos);
    }
    //I don't even know if we're gonna use them all, but they are here
}; /**Too late. You've already programmed the whole thing... Wouldn't it be nice if we had the internet right now?*/

/**
 OK, things are about to get real up in this class...
 Ya know why?
 COS WE ABOUT TO GET TO THE CAMERA, BABY! AWWWW YISSSS!
 */

class PCamera
{
public:
    V3ctor camPos; //Vector for positioning camera
    V3ctor camLook; //Vector for specifying where the camera is looking, ie: the "target"
    V3ctor camUp; //Vector that specifies which direction the camera treats as "up" reference
    
    //Methods for the "Player Camera" class
    //Determines camera Position, lookAt, and Up
    void cam_Position(float x_pos, float y_pos, float z_pos,
                 float x_look, float y_look, float z_look,
                 float x_up, float y_up, float z_up);
    //Moves camera forward and back at a rate of the "speed" parameter
    void cam_Move(float speed);
    //Moves camera left and right at a rate of the "speed" parameter
    void cam_Strafe(float speed);
    //Rotates camera at a rate of the "Speed" parameter
    void cam_RotateView(float speed);
    //Rotates the camera position around the player object
    void cam_RotatePos(float speed);
    //Operates the mouse movement controlling the view (ie: our 1st-person camera)
    void cam_MouseControl(int domain, int range);
    void SetCursorPos(int x, int y);
    
    PCamera(float x_pos, float y_pos, float z_pos,
            float x_look, float y_look, float z_look,
            float x_up, float y_up, float z_up);
    
};
#endif /* defined(__COMP_315__PCamera__) */
