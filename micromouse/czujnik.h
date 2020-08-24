#ifndef CZUJNIK_H
#define CZUJNIK_H
#include <mwalls.h>

/// \brief Klasa czujnika wykrywającego ściany
class Czujnik
    {
public:
    /**
     * @brief Czujnik Czujnik ścian
     * @param x Położenie robota w osi X
     * @param y Położenie robota w osi Y
     * @param direction Kierunek wykrywania
     * @param range Zasięg wykrywania
     */
    Czujnik(int x, int y, int direction,int range);
    /**
     * @brief ChangeCords Zmienia położenie czujnika adekwatnie do położenia robota
     * @param x Położenie robota w osi X
     * @param y Położenie robota w osi Y
     */
    void ChangeCords(double x, double y);
    /**
     * @brief GetType Sprawdza rodzaj ściany
     */
    int GetType();
    /**
     * @brief Detect Sprawdza czy czujnik widzi ściane
     * @param _walls Labirynt
     * @param rodzaj Określa czy szukać ścian pionowych czy poziomych
     * @return 1 jeżeli ściana zostanie wykryta, 0 jeżeli ściana nie zostanie wykryta
     */
    bool Detect(MWalls * _walls,int rodzaj);
private:
    /// Położenie w osi X
    double cord_x,
    /// Położenie w osi Y
    cord_y,
    /// Zasięg w osi X
    range_x,
    /// Zasięg w osi Y
    range_y;
    /// Parametr wykrytej ściany
    int type = 0;
    };

#endif // CZUJNIK_H
