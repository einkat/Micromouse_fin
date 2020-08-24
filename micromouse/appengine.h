#ifndef APPENGINE_H
#define APPENGINE_H
#include <wall.h>
#include <labirynt.h>
#include <gmap.h>
#include <mwalls.h>
#include <QTimer>
#include <QObject>
#include <QWidget>
#include <robot.h>
#include <robotcore.h>
#include <QPushButton>
#include <QElapsedTimer>
#include <QLabel>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
/**
 * \mainpage
 * \par Symulacja przejscia przez labirynt robota micromouse
 * Program symuluje przejscie robota
 * przez pseudolosowy labirynt,
 * w pierwszym przejsciu szukając
 * najbardziej optymalnej trasy,
 * a w drugim przechodząc tą optymalną trasę.
 * \author Krzysztof Krasoń
 * \date  24.08.2020
 */
/// \brief Silnik aplikacji
class AppEngine :public QWidget
    {
    Q_OBJECT
public:
    AppEngine();
public slots:
    ///\brief Wywołuje wszystkie cykliczne funkcje w programie
    void step();
    ///\brief Obsługa przycisku włączającego szukanie
    void button1Search();
    ///\brief Obsługa przycisku włączającego najszybsze przejście
    void button2Fast();
    ///\brief Restart robota
    void resetRobotPos();

private:
    /// Kreator labiryntu
    Labirynt*labs;
    ///Labirynt w postaci wektoru ze ścianami
    MWalls*wallsVec;
    /// Mapa wyświetlana przez program
    GMap* map;
    /// Robot szukający Micromouse
    Robot * robot;
    /// Reprezentacja graficzna robota
    GRobot * grobot;
    /// Reprezentacja logiczna mikroprocesora robota
    RobotCore * core;
    /// Przycisk szybkiej trasy
    QPushButton *button2,
    /// Przycisk szukania
    *button1;
    /// Timer mierzący czas szukcania
    QElapsedTimer searchTimer,
    /// Timer mierzący czas szybkiej trasy
    fastTimer;
    /// Wyświetlacz czasu szukania
    QLabel *timer1,
    /// Wyświetlacz czasu przejścia szybkiej trasy
    *timer2;
    /// Czas szukania przeliczony na sekundy
    int searchtime=0,
    /// Czas szybkiego przejścia przeliczony na sekundy
    fasttime=0;


    };

#endif // APPENGINE_H
