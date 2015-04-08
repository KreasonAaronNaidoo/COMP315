//
//  bullet.h
//  COMP 315
//
//  Created by Kreason Aaron Naidoo on 2015/04/09.
//  Copyright (c) 2015 Kreason Aaron Naidoo. All rights reserved.
//

#ifndef __COMP_315__bullet__
#define __COMP_315__bullet__

#include <stdio.h>

class bullet {
    
private:
    
public:
    
    float sx, sy, sz, fx ,fy, fz;
    bullet(float sx,float sy,float sz,float fx ,float fy,float fz);
    
    void render();
    void update();
    
};

#endif /* defined(__COMP_315__bullet__) */
