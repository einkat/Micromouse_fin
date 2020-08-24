#include "robot.h"

Robot::Robot(int _sx, int _sy, double _cx, double _cy) : Object(_sx,_sy,_cx,_cy)
    {
        rotation = 0;
        speed = 5;
        rotspeed = 30;


    }

//double Robot::GetDir()
//    {
//        return dir;
//    }
double Robot::GetRot()
    {
        return rotation;
    }
double Robot::GetSpeed()
    {
        return speed;
    }
//void Robot::SetDir(double x)
//    {
//        dir = x;
//    }
//void Robot::SetRot(double x)
//    {
//        rotation = x;
//    }
//void Robot::SetSpeed(double x)
//    {
//        speed = x;
//    }
//double Robot::GetRotSpeed()
//    {
//        return rotspeed;
//    }
void Robot::CalcSpeeds(double& xspeed, double &yspeed)
    {
        double rot = (rotation/360)*M_PI*2;
        yspeed = int(-speed * cos(rot));
        xspeed = int(speed * sin(rot));
    }
void Robot::Rotate(int rotdir)
    {
        if(rotdir<2){//w prawo
        rotation = rotation + rotspeed;
        if(rotation==360) rotation=0;
            }
        else // w lewo
            {
                rotation = rotation - rotspeed;
                if(rotation<0) rotation = 360-rotspeed ;
            }

    }

void Robot::SlowMove(double movetoX, double movetoY)
    {
        double xspeed,yspeed;

        CalcSpeeds(xspeed,yspeed);
        while(movetoX!=GetCordX()||movetoY!=GetCordY())
            {
                this->ChangeCords(xspeed,yspeed);
                return;
            }
    }
void Robot::startPos()
    {
        this->SetCordX(15*31);
        this->SetCordY(15*31);
        rotation = 0;

    }



