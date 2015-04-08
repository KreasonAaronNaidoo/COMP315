#ifndef player_h
#define player_h


class player
{
    public:
        player();
        player(float x, float y, float z);
        void render();

    private:
        float x, y, z; // position
        void drawplayer();
};

#endif
