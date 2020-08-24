#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <robot.h>
#include <czujnik.h>
#include <algorithm>
#include <stack>
/// Struktura zawierająca ściany w pamięci robota
struct dirX
    {
    bool up=0;
    bool down=0;
    bool left=0;
    bool right=0;
    };
/// Struktura określająca, która komórka labiryntu była odzwidzona
struct vis
    {
    bool visN = 0;
    bool visS = 0;
    bool visW = 0;
    bool visE = 0;
    };
/// Kierunek, w którym ma jechać robot
enum driveDir
{
    dDir_back,
    dDir_up,
    dDir_right,
    dDir_down,
    dDir_left,

};
/// Struktura będąca sposobem zapisu komórek w labiryncie
struct superCell
    {
    dirX dirWall;
    bool visited =0;
    int index=-1;
    };
/// Struktura będąca sposobem zapisu ostatnio przejechanyk komórek
struct visitedCell
    {
    double cordX;
    double cordY;
    double rotation;
    };
/// Struktura wykorzyswywana do szukania optymalnej ścieżki
struct optiCell
    {
    dirX dirWall;
    int index;
    int value=100000;
    };

/// Stała długość ścian w labirynice
const int odl_miedzy_cellami = 30;
/// Zasięg czujnika
const int range = odl_miedzy_cellami/2;
/// \brief Program robota odpowiedzialny za rozwiązanie labiryntu
class Controller
    {
public:
    Controller();
    /**
     * @brief CreateCell Zapisuje komórke labiryntu w zależności od wskazań czujników
     * @param detUP Czujnik wskazujący góre
     * @param detDOWN Czujnik wskazujący dół
     * @param detLEFT Czujnik wskazujący lewo
     * @param detRIGHT Czujnik wskazujący prawo
     * @param robot Robot przekazujący swoje współżędne
     * @param walls Labirynt
     * @return Zwraca wartości ścian z czterech stron robota
     */
    dirX CreateCell(Czujnik * detUP, Czujnik * detDOWN, Czujnik *detLEFT, Czujnik *detRIGHT, Robot * robot, MWalls * walls);
    /**
     * @brief Controll Funkcja określająca kierunek następnego ruchu robota
     * oraz sprawdza czy robot jest w końcowym elemencie labiryntu
     * @param robot Sterowany robot
     * @param walls Labirynt
     * @return Zwraca kierunek ruchu
     */
    driveDir Controll(Robot*robot,MWalls*walls);
    /**
     * @brief PopBacktrack Usuwa ostatni element ze staka odwiedzonych komórek
     */
    void PopBacktrack();
    /**
     * @brief GetBacktrack Zwraca stak odwiedzonych ostatnio komórek
     */
    std::stack<visitedCell> GetBacktrack();
    /**
     * @brief Optimalization Szuka najszybszej ścieżki w labiryncie
     */
    void Optimalization();
    /**
     * @brief ControllOptimal Steruje robota po najszybszej ścieżce do celu
     * @param robot Sterowany robot
     * @return Zwraca kolejny kierunek ruchu robota na najszybszej trasie
     */
    driveDir ControllOptimal(Robot*robot);
    /**
     * @brief GetOptim Zwraca konkretną komórke z optymalnej trasy
     */
    std::vector<optiCell> GetOptim();
    /**
     * @brief isRotated Sprawdza czy robot jest obrócony w dobrą stronę
     * @param Dir Poprawa strona obrotu
     * @param robot Sterowany robot
     * @return 1 jeżeli jest obrócony dobrze, 0 jeżeli jest obrócony źle
     */
    bool isRotated(driveDir Dir,Robot*robot);
    /**
     * @brief rotate Określa kierunek obrotu robota
     * @param robot Sterowany robot
     * @param Dir Pożądany kierunek obrotu
     * @return Zwracana wartość określa czy robot ma się obracać w lewo czy w prawo
     */
    int rotate(Robot *robot, driveDir Dir);
    /**
     * @brief GetEnd Zwraca położenie końca labiryntu znalezionego przez robota
     */
    int GetEnd();
private:
    /// Czujnik górny
    Czujnik * Up;
    /// Czujnik dolny
    Czujnik * Down;
    /// Czujnik lewy
    Czujnik * Left;
    /// Czujnik prawy
    Czujnik * Right;
    /// Labirynt w pamięci robota
    std::vector<superCell> memoryMaze;
    /// Ostatnio przejechane komórki
    std::stack<visitedCell> backTrackMem;
    /// Optymalna trasa
    std::vector<optiCell> optiCells;
    /// Położenie końca labiryntu
    int endindex=0;
    };

#endif // CONTROLLER_H
