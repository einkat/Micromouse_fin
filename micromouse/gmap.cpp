#include "gmap.h"

GMap::GMap(MWalls* walls,GRobot*robot)
    {


        std::vector<QGraphicsRectItem*> rects;
        QGraphicsRectItem * rect = new QGraphicsRectItem();
        for(auto a : walls->GetWallsPionowe()){if(a->GetType()==1){
                rect->setRect(a->GetCordX(),a->GetCordY(),a->GetSizeX(),a->GetSizeY());
                QGraphicsRectItem* item = new QGraphicsRectItem(a->GetCordX(),a->GetCordY(),a->GetSizeX(),a->GetSizeY());
                item->setPen(Qt::NoPen);
                item->setBrush(Qt::black);

                scene->addItem(item);
}


            }

        for(auto a : walls->GetWallsPoziome()){if(a->GetType()==1){
                rect->setRect(a->GetCordX(),a->GetCordY(),a->GetSizeX(),a->GetSizeY());
                QGraphicsRectItem* item = new QGraphicsRectItem(a->GetCordX(),a->GetCordY(),a->GetSizeX(),a->GetSizeY());
                item->setPen(Qt::NoPen);
                item->setBrush(Qt::black);

                scene->addItem(item);}

            }
        for(auto a : walls->GetWallsPoziome()){
                if(a->GetType()==2){
                        rect->setRect(a->GetCordX(),a->GetCordY(),a->GetSizeX(),a->GetSizeY());
                        QGraphicsRectItem* item = new QGraphicsRectItem(a->GetCordX(),a->GetCordY(),a->GetSizeX(),a->GetSizeY());
                        item->setPen(Qt::NoPen);
                        item->setBrush(Qt::red);
                        scene->addItem(item);
                    }
            }
        for(auto a : walls->GetWallsPionowe()){
                if(a->GetType()==2){
                        rect->setRect(a->GetCordX(),a->GetCordY(),a->GetSizeX(),a->GetSizeY());
                        QGraphicsRectItem* item = new QGraphicsRectItem(a->GetCordX(),a->GetCordY(),a->GetSizeX(),a->GetSizeY());
                        item->setPen(Qt::NoPen);
                        item->setBrush(Qt::red);
                        scene->addItem(item);
                    }
            }
        scene->addItem(robot);



    }
QGraphicsScene* GMap::GetScene()
    {
        return scene;
    }
