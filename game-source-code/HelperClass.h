#ifndef HELPERCLASS_H
#define HELPERCLASS_H

#include "GeneralGameEntity.h"
#include "MovableEntity.h"

/** \class HelperClass
* \brief This is responsible for checking collisions between object entities of the game
*It also bounds the movable entities within the maze
* \authors Tshepo Chokoe (1705890) and Bohlale Mahlakoane (1352926)
*/

class HelperClass
{
    public:

        /** \brief Default empty constructor
        */
        HelperClass();

        /** \brief This method checks for collisions between two game entities
        *   \param Box1 of type BoundingBox
        *   \param Box2 of type BoundingBox
        *   \return bool, return true if the bounding boxes of the entities overlap
        *and false otherwise
        */
        bool Intersects(BoundingBox& Box1,BoundingBox& Box2);

        /** \brief This method checks if a movable game entity is inside a maze
        *   \param MovableObject of type MovableEntity
        */
        void isEntityInsideTheMaze(MovableEntity& MovableOject);

        /** \brief Destructor
        */
        ~HelperClass();

    private:
};

#endif // HELPERCLASS_H
