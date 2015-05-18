#ifndef RENDERABLE_OBJECT_H
#define RENDERABLE_OBJECT_H

using namespace std;

class renderableObject{
    public:
        renderableObject(float sx, float sy, float sz);
        ~renderableObject();
        virtual void render()=0; //pure virtual function. renderable object is now an abstract class
        virtual void update()=0; //virtual functions to be implemented in children

        virtual void die()=0;

        float sx, sy, sz;
        bool alive=true;

    protected:
        //float radius;

    private:

};

#endif //RENDERABLE_OBJECT_H
