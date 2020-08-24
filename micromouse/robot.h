#ifndef ROBOT_H
#define ROBOT_H
#include <object.h>
#include <cmath>

///\brief Logiczna reprezentacja robota
class Robot : public Object
    {
public:

    Robot(int _sx, int _sy, double _cx, double _cy);


    /**
     * @brief Rotate Obraca robota w określoną stronę z jego prędkością obrotu
     * @param rotdir Określa stronę obrotu
     */
    void Rotate(int rotdir);
    /**
     * @brief GetRot Zwraca położenie kątowe
     */
    double GetRot();
    double GetSpeed();
//    double GetDir();
//    void SetSpeed(double x);
//    void SetRot(double x);
//    void SetDir(double x);
//    double GetRotSpeed();
    /**
     * @brief CalcSpeeds Wylicza prędkość w osiach x i y w zależności od położenia kątowego robota
     * @param xspeed Prędkość w osi X
     * @param yspeed Prędkość w osi Y
     */
    void CalcSpeeds(double &xspeed, double &yspeed);

    /**
     * @brief SlowMove Jeżeli robot nie znajduje się w koordynarach wejściowych, przesuwa się ze swoją prędkością do przodu
     * @param movetoX Docelowa współrzędna X
     * @param movetoY Docelowa współrzędna Y
     */
    void SlowMove(double movetoX, double movetoY);
    /**
     * @brief startPos Ustawia robota w pozycji startowej
     */
    void startPos();
private:
    /**
     * @brief speed Ogólna prędkość robota
     */
    double speed,
    ///\brief Kąt obrotu robota w stopniach, gdzie góra to 0, prawo 90 itd
    rotation,
    ///\brief Prędkość obrotowa robota
    rotspeed;
    };

#endif // ROBOT_H
