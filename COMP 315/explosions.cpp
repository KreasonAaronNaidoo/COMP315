#include "explosions.h"
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>

using namespace std;


explosions::explosions(float r, float sx, float sy, float sz, float f, float exv)
{

    RC = r;
    RF = r*f;
    x = sx;
    y = sy;
    z = sz;
    this -> exv = exv;
    alive = true;
    cout <<"new explosion created at :("<<x<<","<<y<<","<<z<<") with radius : "<<RC<< endl;

}

explosions::~explosions()
{
}

void explosions::render(){


    if(alive==true){
        glPushMatrix();
        glTranslated(x, y, z); // move to asteroid final position



        //sets light of material
        GLfloat ambient[] = {r, g, b, trans};
        glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, ambient);
        //sets specular properties of the material
        GLfloat mat_specular[] = {r, g, b, trans};
        glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
        // sets the shininess of the material
        GLfloat mat_shininess[] = { 40.0 };
        glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

        //glutWireSphere(RC,25,25);
        glutSolidSphere(RC,25,25);

        glPopMatrix();

       RC = RC + 0.001*exv;
       trans = trans - 0.004*exv;
       r = r - 0.005*exv;
       g = g - 0.01*exv;
       b = b - 0.025*exv;

    }

}

void explosions::update(){
    this -> render();
}

void explosions::checkLife(){

    if(RC >= RF){
        alive = false;
    }

}
