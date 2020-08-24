#ifndef GMAP_H
#define GMAP_H
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <wall.h>
#include <labirynt.h>
#include <mwalls.h>
#include <grobot.h>

/// \brief Reprezentacja graficznya labiryntu
class GMap
    {
public:
    /**
     * @brief GMap Tworzy reprezentacje labiryntu
     * @param walls Logiczna reprezentacja labiryntu
     * @param robot Robot umieszczana na początku labiryntu
     */
    GMap(MWalls *walls,GRobot*robot);
    /**
     * @brief GetScene Zwraca obiekt QGraphicsScene
     */
    QGraphicsScene *GetScene();
    /**
     * @brief AddWall Dodaje reprezentacje graficzną ściany
     * @param wall Dodawana ściana
     */
    void AddWall(Wall* wall);
private:
    /**
     * @brief scene Stworzona scena
     */
    QGraphicsScene *scene = new QGraphicsScene();
    };

#endif // GMAP_H
