#ifndef EXPLOSIONS_H
#define EXPLOSIONS_H


class explosions
{
    public:
        explosions(float r, float sx, float sy, float sz, float f, float exv);
        ~explosions();
        bool alive = true;
        void update();
        void checkLife();
        float trans = 1;
        float r = 1;
        float g = 1;
        float b = 1;
        float exv;
        float x,y,z,RF,RC;


    private:
        void render();
};

#endif // EXPLOSIONS_H
