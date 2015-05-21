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
        vector<bullet> getBulletVector();
        float x, y, z; // position

        vector<bullet> v_bullet;

        void mouseClick(int button, int state, int x, int y);

    private:
        void drawPlayer();
        void drawBullets();

};

#endif
