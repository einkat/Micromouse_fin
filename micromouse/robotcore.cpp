#include "robotcore.h"


RobotCore::RobotCore()
    {
       cntr = new Controller();
       drive = new Drive();
       dDir = dDir_up;


    }
void RobotCore::Search(Robot*robot, MWalls*walls)
    {

        if(finished_search!=1&&searchmarekr==1)
            {
                if(!cntr->isRotated(dDir,robot))
                    {
                        robot->Rotate(cntr->rotate(robot,dDir));
                        return;
                    }
        if(int(robot->GetCordX())%15==0&&int(robot->GetCordX())%30!=0&&int(robot->GetCordY())%15==0&&int(robot->GetCordY())%30!=0/*&&cntr->isRotated(dDir,robot)*/){
                if(backed==1){
                        backed=0;
                        cntr->PopBacktrack();
                    }
         dDir =cntr->Controll(robot,walls) ;
         if(!cntr->isRotated(dDir,robot))return;
            }
        if(dDir!=dDir_back)
            {
        drive->searchMove(robot,dDir);
            }else
            {
                if(cntr->GetBacktrack().size()!=0){
                drive->back(robot,cntr->GetBacktrack());
                backed=1;
                    }else{
                        finished_search=1;
                        searchmarekr=0;

                    }
            }
        return;
            }
        if(finished_search==1&&fastmarker==1&&stop==0)
            {
                if(marker==0)
                    {
                cntr->Optimalization();
                marker=1;
                    }
                if(!cntr->isRotated(dDir,robot))
                    {
                        robot->Rotate(cntr->rotate(robot,dDir));
                        return;
                    }
                if(int(robot->GetCordX())%15==0&&int(robot->GetCordX())%30!=0&&int(robot->GetCordY())%15==0&&int(robot->GetCordY())%30!=0/*&&cntr->isRotated(dDir,robot)*/){
                dDir=cntr->ControllOptimal(robot);
                if(!cntr->isRotated(dDir,robot))return;
                    }
                drive->searchMove(robot,dDir);
                if(int((robot->GetCordX())/30)+int(robot->GetCordY()/30)*16==cntr->GetEnd())
                stop = 1;

            }


    }

void RobotCore::setSearchMarker()
    {
        searchmarekr =1;
    }

void RobotCore::setFastMarker()
    {
        fastmarker=1;
    }

bool RobotCore::getFinishedSearch()
    {
        return finished_search;
    }

bool RobotCore::GetStop()
    {
        return stop;
    }

void RobotCore::setStop()
    {
        stop = 0;
    }
