#ifndef GROBOT_H
#define GROBOT_H
#include <robot.h>
#include <QGraphicsObject>
#include <QPainter>
#include <QGraphicsPixmapItem>

/// \brief Klasa wizualizacji robota
class GRobot : public QObject, public QGraphicsPixmapItem
    {
public:
    GRobot();
    GRobot(Robot*robot);

    QRectF boundingRect() const override;
    /**
     * @brief move Aktualizuje położenie grafiki po zmianie położenia robota
     */
    void move();
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,  QWidget *widget)override;
private:
    /**
     * @brief robot Wizualizowany robot
     */
    Robot *robot;
    /**
     * @brief pix Grafika robota
     */
    QPixmap pix;
    };

#endif // GROBOT_H
