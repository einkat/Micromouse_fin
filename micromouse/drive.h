#ifndef DRIVE_H
#define DRIVE_H
#include <controller.h>
#include <robot.h>
/// \brief Zespół napędowy robota
class Drive
    {
public:
    Drive();
    /**
     * @brief searchMove Ruch robota w określonym kierunku
     * @param robot Sterowany robot
     * @param Dir Kierunek ruchu
     */
    void searchMove(Robot*robot,driveDir Dir);
    /**
     * @brief back Ruch robota do poprzedniej komórki
     * @param robot Sterowany robot
     * @param wektor Ostatnio odwiedzone komórki
     */
    void back(Robot *robot, std::stack<visitedCell> wektor);
    };

#endif // DRIVE_H
