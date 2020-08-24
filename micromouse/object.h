#ifndef OBJECT_H
#define OBJECT_H

/// \brief wirtualna klasa określająca obiekt
class Object
{
public:
    Object();
    ///\brief Tworzy obiekt o określonej wielkości i położeniu
    Object(int _sizex, int _sizey, double _cordx, double _cordy);
    int GetSizeX();
    int GetSizeY();
    int GetCordX();
    int GetCordY();
    void SetCordX(double x);
    void SetCordY(double x);
    void SetSizeX(int x);
    void SetSizeY(int x);

    void ChangeCords(double x, double y);


private:
    /// parametry obiektu: wielkość i położenie
    int size_x, size_y, cord_x, cord_y;
};

#endif // OBJECT_H
