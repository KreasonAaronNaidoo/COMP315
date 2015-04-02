//
//  npc.h
//  COMP 315
//
//  Created by Kreason Aaron Naidoo on 2015/03/24.
//  Copyright (c) 2015 Kreason Aaron Naidoo. All rights reserved.
//

#ifndef __COMP_315__npc__
#define __COMP_315__npc__

#include <stdio.h>
#include "point.h"


class npc {
    
    private:
    
    
    public:
    
        npc(float a, float b, float c);
        npc();
        float x,y,z;
        void render();
};

#endif /* defined(__COMP_315__npc__) */
