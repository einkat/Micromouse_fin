#include "czujnik.h"

Czujnik::Czujnik(int x, int y, int direction, int range) //direction 1-lewo, 2- gora, 3 - prawo, 4 dol
    {
        cord_x = x;
        cord_y = y;
        switch (direction)
            {
        case 1 :

            range_x = range;
            range_y = range;
            break;

        case 2:

            range_x = range;
            range_y = range;
            break;

        case 3:
            range_x = -range;
            range_y = range;
            break;

        case 4:

            range_x = range;
            range_y = -range;
            break;

            }
    }

bool Czujnik::Detect(MWalls *_walls, int rodzaj)
    {

        int dlg_sciany = 30;

        int x1;
        int y1;
        int robx = int(int(cord_x)/int(dlg_sciany))*dlg_sciany+dlg_sciany/2;
        int roby = int(int(cord_y)/int(dlg_sciany))*dlg_sciany+dlg_sciany/2;
       std::vector<Wall*> walls = _walls->GetWall(rodzaj);

        for(auto a : _walls->GetWall(rodzaj))//rodzaj == 2 - sciany pionowe - czujnik left,right
            {
                x1=a->GetCordX();
                y1 = a->GetCordY();


                if(x1+range_x==robx&&y1+range_y==roby){
                        if(a->GetType()==2) type=2;
                        return 1;
                    }

            }


        return 0;
    }
void Czujnik::ChangeCords(double x, double y)
    {
        cord_x = x;
        cord_y = y;
    }

int Czujnik::GetType()
    {
        return  type;
    }
