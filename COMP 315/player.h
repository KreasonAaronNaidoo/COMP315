#ifndef player_h
#define player_h

#include "bullet.h"
#include <vector>
#include "cam.h"

using namespace std;

class player
{
    public:
        player();
        player(float x, float y, float z, cam *p);
        void render();
        void shoot();
        float x, y, z; // position
        cam *q;

    vector<bullet*> mag;


    private:
        void drawPlayer();
        void drawBullet();
        void collisionCheck();
};

#endif

