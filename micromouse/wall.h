#ifndef WALL_H
#define WALL_H
#include "object.h"

///\brief Logiczna reprezentacja ściany
class Wall : public Object
{
public:
///\brief Tworzy ściane o określonych patametrach i rodzaju
    Wall(int x, int _sx, int _sy, double _cx, double _cy, int rot) ;
    ///\brief Zwraca rodzaj ściany
    int GetType();




private:
///\brief Określa typ ściany tj. czy ściana należy do punktu końcowego
    int type;       // 1 - zwykla sciana; 2 - sciana koncowa
    ///\biref Określa obrót ściany 0 - pozioma; 2 - pionowa
    int rotation;
                    // podstawowa sciana jest pozioma


};

#endif // WALL_H
