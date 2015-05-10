#ifndef EXPLOSIONS_H
#define EXPLOSIONS_H


class explosions
{
    public:
        explosions(float r, float sx, float sy, float sz);
        ~explosions();
        bool alive = true;
        void update();
        void checkLife();
        float trans = 1;


    private:
        float x,y,z,RF,RC;
        void render();
};

#endif // EXPLOSIONS_H
