#include "mwalls.h"

MWalls::MWalls(std::vector<std::vector<cell>> maze1)
    {
        std::vector<std::vector<cell> >maze =  maze1;
        int y =0;
        int x=0;
        for(auto a : maze)
            {
                x=0;
                for(auto b : maze[y])
                    {
                        if(b.topwall!=0){
                                int type =1;
                                if(b.typeTop==1) type=2;
                                if(b.leftwall!=0){


                                Wall *wall = new Wall(type,40,10,30*x,30*y,0);
                                scianyPoziome.push_back(wall);
                                    }
                                else{
                                        Wall *wall = new Wall(type,40,10,30*x,30*y,0);
                                        scianyPoziome.push_back(wall);
                                    }
                            }
                        if(b.leftwall!=0){
                                int type = 1;
                                    if(b.typeLeft==1) type =2;
                                    Wall *wall = new Wall(type,40,10,30*x,30*y,2);
                                    scianyPionowe.push_back(wall);


                            }
                    x++;}

                y++;
            }
    }


void MWalls::AddWallPoziome(Wall* _wall)
    {
        scianyPoziome.push_back(_wall);
    }
void MWalls::AddWallPionowe(Wall *_wall)
    {
        scianyPionowe.push_back(_wall);
    }
std::vector<Wall*> MWalls::GetWallsPoziome()
    {
        return scianyPoziome;
    }
std::vector<Wall*> MWalls::GetWallsPionowe()
    {
        return scianyPionowe;
    }
std::vector<Wall*> MWalls::GetWall(int rodzaj){
        if(rodzaj < 2){
                return GetWallsPoziome();
            }
        if(rodzaj == 2){
                return  GetWallsPionowe();
            }
        return GetWallsPionowe();
    }
