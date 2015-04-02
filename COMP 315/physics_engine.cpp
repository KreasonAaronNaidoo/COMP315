//
//  physics_engine.cpp
//  COMP 315
//
//  Created by Kreason Aaron Naidoo on 2015/03/24.
//  Copyright (c) 2015 Kreason Aaron Naidoo. All rights reserved.
//

#include "physics_engine.h"
#include <iostream>
#include <GLUT/glut.h>  // GLUT, include glu.h and gl.h
#include <stdlib.h>
#include <cmath>
#include "vector"

using namespace std;

npc *x = new npc(-0.02,0.02,0.2);

physics_engine::physics_engine(){
   
    *level = 20;
    this -> init_level_map();
    this -> init_npc_loc();
    this -> start_new_level();
    
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


void physics_engine::init_world(){

    glPushMatrix();
        uni -> int_empty_world(); //uses the world class
    glPopMatrix();
    
    glPushMatrix();
        home -> render();
    glPopMatrix();
    
    glPushMatrix();
        render_npc();
    glPopMatrix();

}

void physics_engine::update_with_time(){
    home -> rotate();
    home -> update();
    render_npc();
}

void physics_engine::spawn(){
   
    
    for(int n = 1; n <= level_npc_num[*level]; n++ ){
        cout << "n: "<< n <<endl;
        
        float tx = (init_npc_point -> x) + (float)((npc_loc[n]->x)*(0.1));
        float ty = (init_npc_point -> y) + (float)((4-(npc_loc[n]->y))*(0.1));
        float tz = init_npc_point -> z ;

        
        if(((init_npc_point -> x) + (npc_loc[n]->x)*(0.1)) == 0){
            tx = 0.0;
        }
        
        if (((init_npc_point -> y) + (4-(npc_loc[n]->y))*(0.1)) == 0) {
            ty = 0;
        }
        
        
        v[(int)(npc_loc[n]->x)][(int)(npc_loc[n] ->y)] = new npc(tx,ty,tz);
        
        
        cout << "x: " << npc_loc[n]->x<< " y: " << 4-(npc_loc[n] ->y)<< endl;
        
        cout << "x: "<< tx <<" y: "<< ty <<" z: "<< tz <<endl;
        
        

    }
}

void physics_engine::start_new_level(){
    
    
    for (int n = 0; n < 7; n++) {
        
        for (int m = 0; m < 5; m++) {
            
            
            delete v[n][m];
            v[n][m] = NULL;
        }
        
    }

    this -> spawn();
    
}

void physics_engine::render_npc(){
    
    for (int n = 0; n < 7; n++) {
        
        for (int m = 0; m < 5; m++) {
            
            
            if(v[n][m] == NULL){
                
            }
            
            else{
                
                v[n][m] -> render();

                
            }
        }
        
    }
    
}
