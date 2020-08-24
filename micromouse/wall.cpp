#include "wall.h"


Wall::Wall(int x,int _sx, int _sy, double _cx, double _cy, int rot) : Object(_sx,_sy,_cx,_cy)
{
   type = x;
   if(rot>1){
           int x = GetSizeX();
           int y = GetSizeY();
           SetSizeX(y);
           SetSizeY(x);

       }
}

int Wall::GetType()
{
    return type;
}
