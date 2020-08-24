#ifndef LABIRYNT_H
#define LABIRYNT_H
#include <wall.h>
#include <vector>
#include "cstdlib"

/// Struktura komórki labiryntu
struct cell{
    int topwall = 0;
    int leftwall = 0;
    bool visited;
    int typeLeft =0;
    int typeTop=0;
};
/// Zmienna wykorzystwyana do określania kierunku
enum eDir{
    Dir_inv = 0,
    Dir_up = 1,
    Dir_Right = 2,
    Dir_Down = 4,
    Dir_Left =8,
};

/// \brief Klasa tworząca logiczny zapis labiryntu
class Labirynt
{
public:
    /**
     * @brief Labirynt Tworzy pseudolosowy labirynt z wieloma drogami do celu
     */
    Labirynt();
    /**
     * @brief GetMaze Zwraca stworzony labirynt
     */
    std::vector<std::vector<cell>> GetMaze();
    /**
     * @brief SetCell Ustawia wartości w określonej komórce
     * @param i Współrzędna komórki
     * @param j Współrzędna komórki
     * @param top Wartość ściany na górze komórki
     * @param left Wartość ściany z lewej strony komórki
     * @param vist Określa czy komórka została już odwiedzona przez builder
     */
    void SetCell(int i, int j, int top, int left, bool vist);
    /**
     * @brief CreateLabirynt Tworzy labirynt z jedną drogą od wejścia od wyjścia
     * @param _i Szerokość labiryntu
     * @param _j Wysokość labiryntu
     */
    void CreateLabirynt(int _i, int _j);
    /**
     * @brief GetRandom Zwraca losową wartość od 0 do X
     */
    int GetRandom(int x);
    /**
     * @brief ValidDir Sprawdza czy wybrany kierunek jest poprawny dla buildera
     * @param Dir Kierunek
     * @param i Współrzędna komórki
     * @param j Współrzędna komórki
     * @param maze labirynt
     * @return 1 jeżeli kierunek jest dobry, 0 jeżeli nie
     */
    bool ValidDir(eDir Dir, int i, int j, std::vector<std::vector<cell>> maze);
    /**
     * @brief GetDir Określa kolejny kierunek (położenie komórki) dla buildera
     * @param i Współrzędna komórki
     * @param j Współrzędna komórki
     * @param maze labirynt
     */
    eDir GetDir(int i, int j, std::vector<std::vector<cell>> maze);
    ///\brief Usuwa ścianę z góry
    void ChangeCellCelling(int i, int j);
    /**
     * @brief ChangeCellWall Usuwa ściane z lewej
     */
    void ChangeCellWall(int i, int j);
    ///\brief Ustawia komórkę na odwiedzoną
    void ChangeCellVisited(int i, int j);
    ///\brief Usuwa losowe ściany
    void RemoveRandomCell();
    ///\brief Ustawia końcowy punkt labiryntu
    void setEnd();
private:
    ///\brief Tablica z labiryntem
    std::vector<std::vector<cell>> maze; // siatka labirytnu zawierajaca informacje gdzie jest sicana a gdzie nie ma

};

#endif // LABIRYNT_H
