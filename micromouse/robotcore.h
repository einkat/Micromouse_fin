#ifndef ROBOTCORE_H
#define ROBOTCORE_H
#include <robot.h>
#include <controller.h>
#include <drive.h>

///\brief Reprezentacja procesora robota, korzysta z pamięci i wywołuje ruch
class RobotCore
    {
public:
    RobotCore();
    /**
     * @brief Search Wywołuje komendy dla robota
     * @param robot Sterowany robot
     * @param walls Labirynt
     */
    void Search(Robot*robot, MWalls*walls);
    ///\brief Ustawia search marker na 1
    void setSearchMarker();
    ///\brief Ustawia fast marker na 1
    void setFastMarker();
    ///\brief Getter finished_search
    bool getFinishedSearch();
    ///\brief Getter stop
    bool GetStop();
    ///\brief Ustawia stop na 0
    void setStop();
private:
    ///\brief Pamięć mapująca robota
    Controller* cntr;
    ///\brief Napęd robota
    Drive* drive;
    ///\breif Przechowuje docelową stronę obrotu robota
    driveDir dDir;
    ///\brief Flaga oznaczająca, że ostatni ruch robota był po znanej już trasie
    bool backed=0,
    ///\brief Flaga zakończenia badania labiryntu
    finished_search=0,
    ///\brief Flaga zakończenia optymalizacji trasy
    marker=0,
    ///\brief Flaga zakończenia optymalnej trasy
    stop=0;
    ///\brief Sygnał uruchamiający szukanie, jeżeli jeszcze nie zostało wykonane
    int searchmarekr=0,
    ///\brief Sygnał uruchamiający szybką trasę
    fastmarker=0;
    };

#endif // ROBOTCORE_H
