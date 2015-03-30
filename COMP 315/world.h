//
//  world.h
//  COMP 315
//
//  Created by Kreason Aaron Naidoo on 2015/03/24.
//  Copyright (c) 2015 Kreason Aaron Naidoo. All rights reserved.
//

#ifndef __COMP_315__world__
#define __COMP_315__world__

#include <stdio.h>
#include "npc.h"
#include "planet.h"
#include "player.h"
#include <GLUT/glut.h>  // GLUT, include glu.h and gl.h
#include <vector>


class world{
    
private:
    
public:
    void int_empty_world();
    void draw_planet();
    void draw_player();
    void draw_NPCs();
    void kill_NPCs();
    
    world(); 
    
    std::vector<npc*> V_npc;
    planet *home;
    player *player1;
    GLuint texture;

    
    
};

#endif /* defined(__COMP_315__world__) */
