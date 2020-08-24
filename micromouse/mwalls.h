#ifndef MWALLS_H
#define MWALLS_H
#include <vector>
#include <wall.h>
#include <labirynt.h>


///\brief Klasa z zapisanymi w wektorze scianami, całość labiryntu
class MWalls
    {
public:

    MWalls(std::vector<std::vector<cell>> maze1);
///\brief Dodaje ściane poziomą
void AddWallPoziome(Wall* _wall);
///\brief Dodaje ściane pionową
void AddWallPionowe(Wall* _wall);
///\brief Zwraca ściany poziome
std::vector<Wall*> GetWallsPoziome();
///\brief Zwraca ściany pionowe
std::vector<Wall*> GetWallsPionowe();
///\brief Zwraca ściany określone parametrem
std::vector<Wall*> GetWall(int rodzaj); // 1 - sciany poziome 2 - sciany pionowe
private:
std::vector<Wall*> scianyPionowe,
                   scianyPoziome;
};

#endif // MWALLS_H
