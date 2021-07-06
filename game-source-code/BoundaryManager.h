#ifndef BOUNDARYMANAGER_H
#define BOUNDARYMANAGER_H

#include "MovableEntity.h"

/** \class BoundaryManager
* \brief This class manages the collisions of moving objects with
*the maze walls.
* \authors Tshepo Chokoe (1705890) and Bohlale Mahlakoane (1352926)
*/


class BoundaryManager
{
    public:

        /** \brief A default empty constructor
        */
        BoundaryManager();

        /** \brief This method implements collision detection between
        *moving game objects and maze walls. When a movable object
        *collides with a wall, the position of the object is reset
        *to position it at the edge of the maze wall.
        *   \param MazeBox of type BoundingBox
        *   \param ObjectBox of type BoundingBox
        *   \param MovableObject of type MovableEntity
        */
        void BlockEntity(BoundingBox& MazeBox,BoundingBox& ObjectBox,MovableEntity& MovableObject);

        /** \brief Empty destructor
        */
        ~BoundaryManager();

    private:
};

#endif // BOUNDARYMANAGER_H
