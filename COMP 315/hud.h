#ifndef HUD_H
#define HUD_H


class HUD
{
    public:
    HUD();
    ~HUD();
   int health;
   int level;
   void update(int l, int h);




    private:

    void render();

};

#endif // HUD_H
