#include "object.h"

Object::Object(int _sizex, int _sizey, double _cordx, double _cordy)
{
    size_x = _sizex;
    size_y = _sizey;
    cord_x = _cordx;
    cord_y = _cordy;
}
int Object::GetSizeX(){
    return size_x;
};
int Object::GetSizeY(){
    return size_y;
};
int Object::GetCordX(){
    return cord_x;
};
int Object::GetCordY(){
        return cord_y;
    }

void Object::SetCordX(double x)
    {
        cord_x = x;
    }

void Object::SetCordY(double x)
    {
        cord_y = x;
    };
void Object::SetSizeX(int x)
    {
        size_x =x;
    }
void Object::SetSizeY(int x)
    {
        size_y =x;
    }
void Object::ChangeCords(double x, double y)
    {
        cord_x += x;
        cord_y += y;
    }
