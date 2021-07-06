#ifndef LOGICDOOR_H
#define LOGICDOOR_H

#include "Mazedoors.h"
#include "MovableEntity.h"
#include "HelperClass.h"
#include "BoundaryManager.h"
#include <tuple>


using HorizontalOrVertical =std::tuple<bool,bool>;

/** \class LogicDoor
* \brief This class models the behavior of the door entity of the game
* \authors Tshepo Chokoe (1705890) and Bohlale Mahlakoane (1352926)
*/

class LogicDoor
{
    public:

        /** \brief Parameterized constructor that intializes DoorData_
        *member varibale
        *   \param DoorDataObject of type MazeDoors
        */
        LogicDoor(Mazedoors& DoorDataObject);

        /** \brief This method is responsible for blocking movable entities
        *from going the maze doors
        *   \param MovingObject of type MovableEntity
        *   \return HorizontalVertical
        */
        HorizontalOrVertical BlockEntityFromPassing(MovableEntity& MovingObject);

        /** \brief This method open the doors if a key is eaten by Pac-Man
        */
        void OpenDoors();

        /** \brief This method returns a vector that has the postions of
        *of the all the door entities
        *   \return VectorOfDoorStructs
        */
        VectorOfDoorStructs getDoorsVector() const;

        /** \brief This method gets the width and height of the door entity
        *   \return x_and_y, width and length of the door entity
        */
        x_and_y getDimensionsIntoPresentationLayer() const;

        /** \brief Destructor
        */
        ~LogicDoor();

    private:
        Mazedoors DoorData_;
        VectorOfDoorStructs Doors_;
        const float doorLength=37.f;
        const float doorThickness=5.f;
        HelperClass CollisionChecker_;
        BoundaryManager Boundary_;

};

#endif // LOGICDOOR_H
