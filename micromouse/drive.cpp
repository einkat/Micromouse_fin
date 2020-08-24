#include "drive.h"

Drive::Drive()
    {

    }
void Drive::searchMove(Robot *robot, driveDir Dir)
    {

        if(Dir==dDir_up)
            {
                robot->SlowMove(robot->GetCordX(),robot->GetCordY()-odl_miedzy_cellami);
                return;
            }
        if(Dir==dDir_right)
            {
                robot->SlowMove(robot->GetCordX()+odl_miedzy_cellami,robot->GetCordY());
                return;
            }
        if(Dir==dDir_down)
            {
                robot->SlowMove(robot->GetCordX(),robot->GetCordY()+odl_miedzy_cellami);
                return;
            }
        if(Dir==dDir_left)
            {
                robot->SlowMove(robot->GetCordX()-odl_miedzy_cellami,robot->GetCordY());
                return;
            }

    }

void Drive::back(Robot *robot,std::stack<visitedCell> wektor)
    {

      robot->SlowMove(wektor.top().cordX,wektor.top().cordY);


    }
