#ifndef MAZEDOORS_H
#define MAZEDOORS_H
#include <iostream>
#include <vector>
#include "MazeEntity.h"
#include "GeneralGameEntity.h"

//using x_and_y = std::tuple<float, float>;
/** \brief This structure stores the top left corner of the maze door entity
* * \authors Tshepo Chokoe (1705890) and Bohlale Mahlakoane (1352926)
*/
struct MazeDoorComponents{
float x_coord;
float y_coord;
char orientation;
};

using VectorOfDoorStructs=std::vector<MazeDoorComponents>;

/** \brief This class inherits from MazeEntity and GeneralGameEntity class
*\authors Tshepo Chokoe (1705890) and Bohlale Mahlakoane (1352926)
*/

class Mazedoors : public MazeEntity , public GeneralGameEntity <VectorOfDoorStructs>
{
    public:

        /** \brief Default empty constructor
        */
        Mazedoors();

        /** \brief This method reads door entities from a file
        */
        virtual void ReadEntityFromFile() override;

        /** \brief This method returns a vector of door structs
        *   \return VectorOfDoorStructs
        */
        virtual VectorOfDoorStructs ObjectContainer() const override;

        /**Destructor
        */
        ~Mazedoors();

    private:
        MazeDoorComponents currentDoor;
        VectorOfDoorStructs mazedoors;
};



#endif // MAZEDOORS_H
