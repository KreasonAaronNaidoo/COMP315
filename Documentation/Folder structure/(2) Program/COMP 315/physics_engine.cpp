//
//  physics_engine.cpp
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
#include "physics_engine.h"
#include <iostream>
#include <stdlib.h>
#include <cmath>
#include "vector"
#include "npc.h"
#include "bullet.h"
#include "player.h"
#include "planet.h"
#include "explosions.h"
#include <time.h>
#include "imageloader.h"
#include <mmsystem.h>
using namespace std;

vector<npc*> v_asteroid;

double dist;

double bulletDist;

vector<explosions*> v_ex;


//texture variables
GLuint _textureId_NPC; //The id of the texture
//GLUquadric *quad = gluNewQuadric();

char *tex = "resources\\asteroid_2k.bmp";

//Makes the image into a texture, and returns the id of the texture
GLuint loadTexture(Image* image) {
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

//callback function initialises required variables and imports the image
void physics_engine::initAsteroid() {

	Image* image_NPC = loadBMP(tex);
    _textureId_NPC = loadTexture(image_NPC);
	delete image_NPC;
}

physics_engine::physics_engine(){

    *level = 0;

    this -> init_level_map();
    this -> init_npc_loc();
    this -> start_new_level();

    this->home = new planet(0, -4, 0);

}

int physics_engine::getLevel(){
    return *level;
}

void physics_engine::setLevel(int l){

    if(l > 20)
    {
        *level = 20;
    }
    else
    {
        *level = l;
    }

}

void physics_engine::init_npc_loc(){

    npc_loc[1] = new point(3,2,0);
    npc_loc[2] = new point(2,1,0);
    npc_loc[3] = new point(3,1,0);
    npc_loc[4] = new point(4,1,0);
    npc_loc[5] = new point(4,2,0);
    npc_loc[6] = new point(4,3,0);
    npc_loc[7] = new point(3,3,0);
    npc_loc[8] = new point(2,3,0);
    npc_loc[9] = new point(2,2,0);
    npc_loc[10] = new point(1,0,0);
    npc_loc[11] = new point(2,0,0);
    npc_loc[12] = new point(3,0,0);
    npc_loc[13] = new point(4,0,0);
    npc_loc[14] = new point(5,0,0);
    npc_loc[15] = new point(5,1,0);
    npc_loc[16] = new point(5,2,0);
    npc_loc[17] = new point(5,3,0);
    npc_loc[18] = new point(5,4,0);
    npc_loc[19] = new point(4,4,0);
    npc_loc[20] = new point(3,4,0);
    npc_loc[21] = new point(2,4,0);
    npc_loc[22] = new point(1,4,0);
    npc_loc[23] = new point(1,3,0);
    npc_loc[24] = new point(1,2,0);
    npc_loc[25] = new point(1,1,0);
    npc_loc[26] = new point(0,0,0);
    npc_loc[27] = new point(6,0,0);
    npc_loc[28] = new point(0,1,0);
    npc_loc[29] = new point(6,1,0);
    npc_loc[30] = new point(0,2,0);
    npc_loc[31] = new point(6,2,0);
    npc_loc[32] = new point(0,3,0);
    npc_loc[33] = new point(6,3,0);
    npc_loc[34] = new point(0,4,0);
    npc_loc[35] = new point(6,4,0);

}

void physics_engine::init_level_map(){
    level_npc_num[0] = 0;
    level_npc_num[1] = 4;
    level_npc_num[2] = 5;
    level_npc_num[3] = 7;
    level_npc_num[4] = 9;
    level_npc_num[5] = 10;
    level_npc_num[6] = 12;
    level_npc_num[7] = 13;
    level_npc_num[8] = 15;
    level_npc_num[9] = 17;
    level_npc_num[10] = 18;
    level_npc_num[11] = 20;
    level_npc_num[12] = 21;
    level_npc_num[13] = 23;
    level_npc_num[14] = 25;
    level_npc_num[15] = 26;
    level_npc_num[16] = 28;
    level_npc_num[17] = 30;
    level_npc_num[18] = 31;
    level_npc_num[19] = 33;
    level_npc_num[20] = 35;

}

void physics_engine::update_with_time(){ //runs every frame

    col_dec_bullet_to_asteroid();
    col_dec_asteroid_to_planet();

    if(check_all_dead() == true){

        if(getLevel() == 20){ //we just finished level 20
            victory = true;
        }

        setLevel(getLevel() + 1);
        this ->home->health = 100;
        start_new_level();

    }

        uni -> int_empty_world();
        home->update();
        render_npc();
        player1->render();

}

void physics_engine::spawn(){

    for(int n = 1; n <= level_npc_num[*level]; n++){

        float tx = (init_npc_point -> x) + (float)((npc_loc[n]->x)*(10));
        float ty = (init_npc_point -> y) + (float)((4-(npc_loc[n]->y))*(10));
        float tz = init_npc_point -> z;

        float fx = -1 + (rand() % (int)(2 + 1 + 1));


        v_asteroid.push_back(new npc(tx,ty,tz,fx,0,0,_textureId_NPC)); //adding all asteroids to a vector


    }

}

void physics_engine::start_new_level(){



    for (int n = 0; n < 7; n++) {

        for (int m = 0; m < 5; m++) {

            delete v[n][m];
            v[n][m] = NULL;
        }

    }

    for(int i = 0; i < v_asteroid.size(); i++){

        delete v_asteroid[i];//deallocated the memory
    }

    v_asteroid.clear(); //removes the pointers

    this -> spawn();

}

void physics_engine::render_npc(){

    //for the asteroids
     for(int a = 0; a < v_asteroid.size(); a++){

       if(v_asteroid[a]->alive == false){
            delete v_asteroid[a];
            v_asteroid.erase(v_asteroid.begin()+a);
            a = a - 1;//to compensate for the shift up
       }
    }


    for(int i=0; i<v_asteroid.size() ;i++){
        v_asteroid[i]->update();
    }


    //for the explosions
    for(int a = 0; a < v_ex.size(); a++){
       v_ex[a]->checkLife();

       if(v_ex[a]->alive == false){
            delete v_ex[a];
            v_ex.erase(v_ex.begin()+a);
            a = a - 1;//to compensate for the shift up
       }

    }

    for(int a = 0; a < v_ex.size(); a++){
        v_ex[a]->update();
    }



}


void physics_engine::col_dec_asteroid_to_planet(){

    for(int a = 0; a < v_asteroid.size(); a++){

        float d = sqrt(((home->sx - v_asteroid[a]->sx) * (home->sx - v_asteroid[a]->sx)) + ((home->sy - v_asteroid[a]->sy) * (home->sy - v_asteroid[a]->sy)) + ((home->sz - v_asteroid[a]->sz) * (home->sz - v_asteroid[a]->sz)));

        if(d < (v_asteroid[a]->radius + 4)){

            PlaySound("resources\\explosion.wav", NULL, SND_ASYNC);

            home->takeDamage(v_asteroid[a]->getSize());

            v_asteroid[a]->alive = false;
            v_ex.push_back(new explosions(v_asteroid[a]->radius,v_asteroid[a]->sx,v_asteroid[a]->sy,v_asteroid[a]->sz,3,1));
            v_asteroid.erase(v_asteroid.begin()+a);
            a = a - 1;


        }

    }


}


void physics_engine::col_dec_bullet_to_asteroid(){

    for(int a = 0; a < v_asteroid.size(); a++){
        for(int b = 0; b < player1->v_bullet.size(); b++){
            float d = sqrt(((player1->v_bullet[b]->sx - v_asteroid[a]->sx) * (player1->v_bullet[b]->sx - v_asteroid[a]->sx)) + ((player1->v_bullet[b]->sy - v_asteroid[a]->sy) * (player1->v_bullet[b]->sy - v_asteroid[a]->sy)) + ((player1->v_bullet[b]->sz - v_asteroid[a]->sz) * (player1->v_bullet[b]->sz - v_asteroid[a]->sz)));

            // check bullets hitting the world boundry
            if((player1->v_bullet[b]->sx * player1->v_bullet[b]->sx) + (player1->v_bullet[b]->sy * player1->v_bullet[b]->sy) + (player1->v_bullet[b]->sz * player1->v_bullet[b]->sz) >= 10000){
                player1->v_bullet[b]->die();
            }

            // detect bullets hitting the npc's
            if(d <= (v_asteroid[a]->radius + player1->v_bullet[b]->rad)){

                PlaySound("resources\\explosion.wav", NULL, SND_ASYNC);

                cout <<"collision detected : Asteroid shot" << endl;
                v_asteroid[a]->regCollision();
                v_asteroid[a]->takeDamage();

                if(v_asteroid[a]->alive == false){
                    v_ex.push_back(new explosions(v_asteroid[a]->radius,v_asteroid[a]->sx,v_asteroid[a]->sy,v_asteroid[a]->sz,3,1));
                    v_asteroid.erase(v_asteroid.begin()+a);
                    a = a - 1;
                }

                player1->v_bullet[b]->die();
                player1->v_bullet.erase(player1->v_bullet.begin() + b);
                b = b - 1;
                break;

            }



        }

    }



}

bool physics_engine::check_all_dead(){

    for(int i=0; i<v_asteroid.size() ;i++){

        if(v_asteroid[i]->alive == true){
            return false;
        }
    }

    for(int i=0; i<v_ex.size() ;i++){

        if(v_ex[i]->alive == true){
            return false;
        }
    }

    return true;
}








