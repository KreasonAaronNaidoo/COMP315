#ifndef player_h
#define player_h

#include "bullet.h"
#include <vector>
#include "model_obj.h"

using namespace std;

class player
{
    public:
        player();
        player(float x, float y, float z);
        void render();
        void shoot(int x, int y);
        vector<bullet*> getBulletVector();
        float x, y, z; // position

        vector<bullet*> v_bullet;

        void mouseClick(int button, int state, int x, int y);

        Model_OBJ obj;

        void initBullet();

        GLuint _textureId_Bullet; //The id of the texture
        GLUquadric *quad_Bullet = gluNewQuadric();

    private:
        void drawPlayer();
        void drawBullets();
        GLuint loadTexture(Image* image);
};

#endif
