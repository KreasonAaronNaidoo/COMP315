//
//  physics_engine.h
//  COMP 315
//
//  Created by Kreason Aaron Naidoo on 2015/03/24.
//  Copyright (c) 2015 Kreason Aaron Naidoo. All rights reserved.
//

#ifndef __COMP_315__physics_engine__
#define __COMP_315__physics_engine__
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdio.h>
#include "world.h"
#include "planet.h"
#include "player.h"
#include <vector>
#include "map"
#include "point.h"
#include "hud.h"
#include "explosions.h"


class physics_engine{

private:

public:

    //functions
    physics_engine();

    void initAsteroid();

    void init_level_map();

    void init_npc_loc();

    void npc_final_loc();

    void move_player(float *px, float *py, float *pz); //co - ordinates to move too

    void move_camera(float *cx, float *cy, float *cz); //co - ordinates of the cam

    void move_look(float *lx, float *ly, float *lz);   //look at of the cam

    void col_dec_bullet_to_asteroid();

    void col_dec_asteroid_to_planet();

    void kill(); //destroys an asteroid

    void update_with_time(); //spinning of the planet and asteroids and health bars

    bool check_all_dead(); //check if all asteroids are dead

    void spawn (); //spawns asteroids according to the level

    void collide_with_player(); //checks for and handles collisions with the player

    void collide_with_home(); // checks for and handles collisions with home planet

    void start_new_level();

    void render_npc();

    int getLevel();

    void setLevel(int l);

    void asteroidToAsteroidCollision();

    void split(npc ast1,npc ast2,int i,int j);

    void bulletToAsteroidCollision();




    //objects
    world *uni = new world();

    planet *home;

    player *player1 = new player(0.0f, 0.5f, -1.4f);;

    npc *v [7][5];

    point *init_npc_point = new point(-30, -15, 50);

    float *npc_init_loc_inc = new float();

    int *level = new int(); //set this to one initialy

    bool *all_dead = new bool(); //set this to false

    std::map <int, int> level_npc_num;

    std::map <int, point*> npc_loc;

};

#endif /* defined(__COMP_315__physics_engine__) */
