#ifndef player_h
#define player_h

#include "bullet.h"
#include <vector>

using namespace std;

class player
{
    public:
        player();
        player(float x, float y, float z);
        void render();
        void shoot();
        float x, y, z; // position

    vector<bullet*> mag;


    private:
        void drawPlayer();
        void drawBullet();
        void collisionCheck();
};

#endif

