//
//  cam.h
//  COMP 315
//
//  Created by Kreason Aaron Naidoo on 2015/04/05.
//  Copyright (c) 2015 Kreason Aaron Naidoo. All rights reserved.
//

#ifndef __COMP_315__cam__
#define __COMP_315__cam__

#include <stdio.h>

class cam{

private:
    
    
public:
    
    cam(float x, float y, float z, float lx, float ly, float lz);
    
    void place();
    
    float x,y,z,lx,ly,lz;
    
    
};



#endif /* defined(__COMP_315__cam__) */
