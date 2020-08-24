#include "grobot.h"

QRectF GRobot::boundingRect() const
{
    return QRect(0,0,
                  robot->GetSizeX(),robot->GetSizeY());
}
GRobot::GRobot(Robot*r)
    {
        robot = r;
        QGraphicsRectItem * robo = new QGraphicsRectItem();
        robo->setRect(robot->GetCordX(),robot->GetCordY(),robot->GetSizeX(),robot->GetSizeY());

        pix = QPixmap(":/pics/pics/mouse.png");
        pix=pix.scaled(r->GetSizeX(),r->GetSizeY());
        setPixmap(pix);


        setPos(robot->GetCordX(),robot->GetCordY());
        setTransformOriginPoint(robot->GetSizeX()/2, robot->GetSizeY()/2);
        setRotation(robot->GetRot());
        update(boundingRect());

    }
void GRobot::move()
    {

        setPos(robot->GetCordX()+robot->GetSizeX()/4,robot->GetCordY()-robot->GetSizeY()/8);
        setTransformOriginPoint(robot->GetSizeX()/2, robot->GetSizeY()/2);
        setRotation(robot->GetRot());
        update(boundingRect());
    }

QPainterPath GRobot::shape() const
{
    QPainterPath path;

    path.addRect(boundingRect());
    return path;
}

void GRobot::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(QBrush(pix));
    painter->setPen(Qt::NoPen);
    painter->drawRect(boundingRect());
}
