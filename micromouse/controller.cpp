#include "controller.h"


Controller::Controller()
    {

        memoryMaze.resize(16*16);
    }
dirX Controller::CreateCell(Czujnik * detUP, Czujnik * detDOWN, Czujnik *detLEFT, Czujnik *detRIGHT, Robot * robot, MWalls * walls)
    {
        dirX dirCell;
        detUP->ChangeCords(robot->GetCordX(),robot->GetCordY());
        detDOWN->ChangeCords(robot->GetCordX(),robot->GetCordY());
        detLEFT->ChangeCords(robot->GetCordX(),robot->GetCordY());
        detRIGHT->ChangeCords(robot->GetCordX(),robot->GetCordY());

        if (detUP->Detect(walls,1))dirCell.up=1;
        if (detDOWN->Detect(walls,1))dirCell.down=1;
        if (detLEFT->Detect(walls,2))dirCell.left=1;
        if (detRIGHT->Detect(walls,2))dirCell.right=1;
        if(detUP->GetType()+detDOWN->GetType()+detLEFT->GetType()+detRIGHT->GetType()==6)
            {
                endindex = int((robot->GetCordX())/30)+int(robot->GetCordY()/30)*16;
            }

        return dirCell;
    }


void Controller::PopBacktrack()
    {
        backTrackMem.pop();
    }
std::stack<visitedCell> Controller::GetBacktrack()
    {
        return backTrackMem;
    }

bool Controller::isRotated(driveDir Dir,Robot*robot)
    {
        int ret;
        int x=0;
        switch (Dir) {
        case dDir_back:
            if(!backTrackMem.empty())
           x=backTrackMem.top().rotation;
            else x = 0;
            break;
        case dDir_up:
            x=0;
            break;
        case dDir_down:
            x=180;
            break;
        case dDir_left:
            x=270;
            break;
        case dDir_right:
            x=90;
            break;

                }


        if(x>=robot->GetRot())
            {
              ret=x-robot->GetRot()  ;
            }
        else{
                ret=robot->GetRot()-x;
            }
        if(ret==0) return 1;
        else return 0;
    }
driveDir Controller::Controll(Robot*robot, MWalls*walls)
    {

        Czujnik * UP = new Czujnik(robot->GetCordX(),robot->GetCordY(),2,range);
        Czujnik * DOWN = new Czujnik(robot->GetCordX(),robot->GetCordY(),4,range);
        Czujnik * LEFT = new Czujnik(robot->GetCordX(),robot->GetCordY(),1,range);
        Czujnik * RIGHT = new Czujnik(robot->GetCordX(),robot->GetCordY(),3,range);



        visitedCell vCell;
        superCell cell;
        if(memoryMaze[255].visited==0)
            {
        cell.dirWall = CreateCell( UP,DOWN,LEFT,RIGHT,robot,walls);
        cell.visited = 1;
        memoryMaze[255]=cell;
            }
        int index = int((robot->GetCordX())/30)+int(robot->GetCordY()/30)*16;

                cell.dirWall = CreateCell( UP,DOWN,LEFT,RIGHT,robot,walls);
                vCell.cordX=robot->GetCordX();
                vCell.cordY=robot->GetCordY();
                if(cell.dirWall.up==0)   //go up
                    {
                        if(memoryMaze[index-16].visited==0)
                            {
                                vCell.rotation=180;
                                cell.dirWall = CreateCell( UP,DOWN,LEFT,RIGHT,robot,walls);
                                cell.visited = 1;
                                cell.index=index;
                                memoryMaze[index]=cell;
                                backTrackMem.push(vCell);
                                return dDir_up;
                            }
                    }
                if(cell.dirWall.right==0) // go right
                    {
                        if(memoryMaze[index+1].visited==0)
                            {
                                vCell.rotation=270;
                                cell.dirWall = CreateCell( UP,DOWN,LEFT,RIGHT,robot,walls);
                                cell.visited = 1;
                                cell.index=index;
                                memoryMaze[index]=cell;
                                backTrackMem.push(vCell);
                                return dDir_right;
                            }
                    }
                if(cell.dirWall.down==0) // go down
                    {
                        if(memoryMaze[index+16].visited==0)
                            {
                                vCell.rotation=0;
                                cell.dirWall = CreateCell(UP,DOWN,LEFT,RIGHT,robot,walls);
                                cell.visited = 1;
                                cell.index=index;
                                memoryMaze[index]=cell;
                                backTrackMem.push(vCell);
                                return dDir_down;
                            }
                    }
                if (cell.dirWall.left==0) // go left
                    {
                        if(memoryMaze[index-1].visited==0)
                            {
                                vCell.rotation=90;
                                cell.dirWall = CreateCell(UP,DOWN,LEFT,RIGHT,robot,walls);
                                cell.visited = 1;
                                cell.index=index;
                                memoryMaze[index]=cell;
                                backTrackMem.push(vCell);
                                return dDir_left;

                            }
                    }
                    // backstep
                    {

                    cell.dirWall = CreateCell(UP,DOWN,LEFT,RIGHT,robot,walls);
                    cell.visited = 1;
                    cell.index=index;
                    memoryMaze[index]=cell;
                        return dDir_back;
                    }





    }
void Controller::Optimalization()
    {
        optiCells.resize(memoryMaze.size());
        int value = 0;

        for(int j=0;j<int(optiCells.size());j++)
            {
                optiCells[j].dirWall=memoryMaze[j].dirWall;
                optiCells[j].index=memoryMaze[j].index;
            }
        optiCells[endindex].value=value;
        value++;
        for(int j=0;j<int(optiCells.size());j++)
           {
            for(auto a:optiCells)
               {
                 if(a.value==value-1)
                        {
                         if(a.dirWall.up==0)
                             {
                                 if(a.value+1<optiCells[a.index-16].value)
                                     optiCells[a.index-16].value=a.value+1;
                             }
                         if(a.dirWall.down==0)
                             {
                                 if(a.value+1<optiCells[a.index+16].value)
                                     optiCells[a.index+16].value=a.value+1;
                             }
                         if(a.dirWall.left==0)
                             {
                                 if(a.value+1<optiCells[a.index-1].value)
                                     optiCells[a.index-1].value=a.value+1;
                             }
                         if(a.dirWall.right==0)
                             {
                                 if(a.value+1<optiCells[a.index+1].value)
                                     optiCells[a.index+1].value=a.value+1;
                             }

                        }
               }
            value++;
           }
        int counter=0;
        for(auto a:optiCells)
            {
                if(a.value==100000)counter++;
            }




    }
driveDir Controller::ControllOptimal(Robot *robot)
    {
        int index = int((robot->GetCordX())/30)+int(robot->GetCordY()/30)*16;
        int u=9996,d=9997,l=9998,r=9999;
        if(optiCells[index].dirWall.up==0)
            {
                u=optiCells[index-16].value;
            }
        if(optiCells[index].dirWall.down==0)
            {
                d=optiCells[index+16].value;
            }
        if(optiCells[index].dirWall.left==0)
            {
                l=optiCells[index-1].value;
            }
        if(optiCells[index].dirWall.right==0)
            {
                r=optiCells[index+1].value;
            }
        int min = std::min(u,std::min(d,std::min(l,r)));
        if(min==u)
            {
                return dDir_up;
            }
        if(min==l)
            {
                return dDir_left;
            }
        if(min==r)
            {
                return dDir_right;
            }
        if(min==d)
            {
                return dDir_down;
            }
        return dDir_back;

    }
//std::vector<optiCell> Controller::GetOptim()
//    {
//        return optiCells;
//    }
int Controller::rotate(Robot *robot, driveDir Dir)
    {
        int curRot = robot->GetRot();
        int desRot;
        switch (Dir) {
        case dDir_back:
            if(!backTrackMem.empty())
            desRot=backTrackMem.top().rotation;
            else desRot = 0;
            break;
        case dDir_up:
            desRot = 0;
            break;
        case dDir_down:
            desRot = 180;
            break;
        case dDir_left:
            desRot = 270;
            break;
        case dDir_right:
            desRot = 90;
            break;

            }
        desRot=desRot-curRot;
        if((desRot>=-90&&desRot<0)||(desRot>=270))
            return 4;//w lewo
        else return 1;//w prawo
    }

int Controller::GetEnd()
    {
        return endindex;
    }
