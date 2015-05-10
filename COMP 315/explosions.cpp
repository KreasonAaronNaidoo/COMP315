#include "explosions.h"
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>

using namespace std;


explosions::explosions(float r, float sx, float sy, float sz)
{

    RC = r;
    RF = r*3;
    x = sx;
    y = sy;
    z = sz;
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

       RC = RC + 0.001;
       trans = trans - 0.004 ;
       r = r - 0.005;
       g = g - 0.01;
       b = b - 0.025;
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
