//
//  physics_engine.h
//  COMP 315
//
//  Created by Kreason Aaron Naidoo on 2015/03/24.
//  Copyright (c) 2015 Kreason Aaron Naidoo. All rights reserved.
//

#ifndef __COMP_315__physics_engine__
#define __COMP_315__physics_engine__

#include <stdio.h>
#include "world.h"
#include "planet.h"
#include "player.h"
#include <GLUT/glut.h>  // GLUT, include glu.h and gl.h
#include <vector>
#include "map"
#include "point.h"


class physics_engine{
    
private:
    
public:
  
    
    physics_engine();
    
    void init_level_map();
    void init_npc_loc();
    
    void init_world(); // sets up the basic empty world.
    
    void move_player(float *px, float *py, float *pz); //co - ordinates to move too
    void move_camera(float *cx, float *cy, float *cz); //co - ordinates of the cam
    void move_look(float *lx, float *ly, float *lz);   //look at of the cam
    
    void kill(); //destroys an asteroid
    
    void update_with_time(); //spinning of the planet and asteroids and health bars 
    
    void check_all_dead(); //check if all asteroids are destroid
    
    void spawn (); //spawns asteroids according to the level
    
    void collide_with_player(); //checks for and handles collisions with the player
    
    void collide_with_home(); // checks for and handles collisions with home planet
    
    void start_new_level();
    
    void render_npc();
    
    int getLevel();
    void setLevel(int l);
    
    world *uni = new world();
    planet *home = new planet(0, -4, 0.01);
    player *player1 = new player();
    
    
    //std::vector <std::vector<npc*> > V_npc; // 2d vector
    //void init_vector();
    
    npc *v [7][5];

    point *init_npc_point = new point(-30, -15, 92.29);
    float *npc_init_loc_inc = new float();

    
    int *level = new int(); //set this to one initialy
    bool *all_dead = new bool(); //set this to false
    
    std::map <int, int> level_npc_num;
    std::map <int, point*> npc_loc;

    
};

#endif /* defined(__COMP_315__physics_engine__) */
