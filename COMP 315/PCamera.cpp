//
//  PCamera.cpp
//  COMP 315
//
//  Created by Kreason Aaron Naidoo on 2015/03/31.
//  Copyright (c) 2015 Kreason Aaron Naidoo. All rights reserved.
//

/**
 Author: Liam James Barnard
 Student number: 212508966
 Date: 30/03/2015 (about four years before the crisis began)
 */
#include "PCamera.h"



/**OKAY
 Now that there is enough caffeine in my bloodstream to form conscious thought rather than random
 and sporadic twitches and tics, we are about to embark on a gracefully confusing and terrifying
 experience - the coding of the methods for this Player Camera class...
 */


/**So what this guy does is set the position of the camera wherever you set it to. It also makes it
 look at whatever target point you define, and furthermore, treats a direction set by you, as "up"*/
PCamera::PCamera(float x_pos, float y_pos, float z_pos,
                      float x_look, float y_look, float z_look,
                      float x_up, float y_up, float z_up)
{
    camPos = V3ctor(x_pos, y_pos, z_pos); //Sets camera position
    camLook = V3ctor(x_look, y_look, z_look); //Sets camera vision "target"
    camUp = V3ctor(x_up, y_up, z_up); //Sets camera "up" reference
}

/**This little guy right here is in charge of moving the camera forward and back at a rate of the
 "speed" parameter*/
void PCamera::cam_Move(float speed)
{
    V3ctor v = camLook - camPos; //Looks confusing? well all this guy does is get the viewing vector
    
    //So what i understand these guys move the camera along a vector at a rate of 'speed'
    camPos.x_pos = camPos.x_pos + v.x_pos*speed;
    camPos.y_pos = camPos.y_pos + v.y_pos*speed;
    //These guys do the same thing, but with the cameras target
    camLook.x_pos = camLook.x_pos + v.x_pos*speed;
    camLook.y_pos = camLook.y_pos + v.y_pos*speed;
    //This stops the camera from running away from what its looking at, or in general behaving weirdly
} /** ONCE AGAIN, NOTE TO SELF! WE ONLY INCORPORATE 2D MOVEMENT, SO ONE DIRECTION HAS TO GO! ALSO THAT BOY BAND*/

/**Moves camera left and right at a rate of the "speed" parameter*/

void SetCursorPos(int x, int y){
    //needs code
}


void PCamera::cam_Strafe(float speed)
{
    //Note! This method involves finding the viewing vector, as well as the ORTHOGONAL vector to the viewing vector
    //Simple maths, really. If you know about it... And can remember it
    V3ctor v = camLook - camPos;
    V3ctor vOrtho;
    //here's the hard part. To get the orthogonal vector, we need to do the following:
    vOrtho.x_pos = -v.y_pos;
    vOrtho.y_pos = v.x_pos;
    //Phew! Good thing i'm doing the coding, right?
    camPos.x_pos = camPos.x_pos + vOrtho.x_pos*speed;
    camPos.y_pos = camPos.y_pos + vOrtho.y_pos*speed;
    //and now, the same with the view!
    camLook.x_pos = camLook.x_pos + vOrtho.x_pos*speed;
    camLook.y_pos = camLook.y_pos + vOrtho.y_pos*speed;
}

/**Rotates camera at a rate of the "Speed" parameter*/
void PCamera::cam_RotateView(float speed)
{
    V3ctor v = camLook - camPos; //Again, we need that sweet, sweet viewing vector
    
    camLook.x_pos =  (float) (camPos.x_pos + cos(speed)*v.x_pos - sin(speed)*v.y_pos);
    camLook.y_pos =  (float) (camPos.y_pos + sin(speed)*v.x_pos + cos(speed)*v.y_pos);
}

/**Rotates the camera position around the player object*/
void PCamera::cam_RotatePos(float speed)
{
    V3ctor v = camLook - camPos; //This dude is everywhere!
    
    camPos.x_pos = (float)(camLook.x_pos + cos(speed)*v.x_pos - sin(speed)*v.y_pos);
    camPos.y_pos = (float)(camLook.x_pos + sin(speed)*v.x_pos + cos(speed)*v.y_pos);
}

/**Operates the mouse movement controlling the view (ie: our 1st-person camera)
 Now I know, this is the one you've been waiting for... She's a beaut, so prepare yourself...*/
void PCamera::cam_MouseControl(int domain, int range) // this needs work 
{
    //this stuff... umm... sets the default for cursor, I guess...
    point *mousePos = new point(0,0,0); //needs to have the point class set up
    
    int mid_x = domain >> 1;
    int mid_y = range >> 1;
    float angle_y = 0.0f;
    float angle_z = 0.0f;
    
    //GetCursorPos(&mousePos);	// Get the 2D mouse cursor (x,y) position
    //BLATANT copying from here...
    if( (mousePos->x == mid_x) && (mousePos->y == mid_y) ) return;
    
    //SetCursorPos(mid_x, mid_y);	// Set the mouse cursor in the center of the window
    
    // Get the direction from the mouse cursor, set a resonable maneuvering speed
    angle_y = (float)( (mid_x - mousePos->x) ) / 1000;
    angle_z = (float)( (mid_y - mousePos->y) ) / 1000;
    
    // The higher the value is the faster the camera looks around.
    camLook.y_pos += angle_z * 2;
    
    // limit the rotation around the x-axis
    if((camLook.y_pos - camPos.y_pos) > 8)
        camLook.y_pos = camPos.y_pos + 8;
    
    if((camLook.y_pos - camPos.y_pos) <-8)
        camLook.y_pos = camPos.y_pos - 8;
    
    cam_RotateView(-angle_y); // Rotate
    //...to here
}