#ifndef MAZEWALLS_H
#define MAZEWALLS_H

#include "Maze.h"
#include "MovableEntity.h"
#include "HelperClass.h"
#include "BoundaryManager.h"
#include <tuple>

using OrientationTuple = std::tuple<bool,bool>; /**< Two booleans for horizontal and vertical collision*/

/** \class MazeWalls
* \brief This is a game object class. This class models the behavior of the
*maze walls. Furthermore, it also implements collision checking between moving
*game objects and the walls.
* \authors Tshepo Chokoe (1705890) and Bohlale Mahlakoane (1352926)
*/

class MazeWalls
{
    public:

        /** \brief Default empty constructor
        */
        MazeWalls(){}

        /** \brief Parameterized constructor. Initializes WallData_
        *member variable.
        *   \param DataWallObject of type Maze
        */
        MazeWalls(Maze& DataWallObject);

        /** \brief This method checks the collision among moving object
        *entities and the maze walls.
        *   \param MovingObject of type MovableEntity
        *   \return OrientationTuple, returns true or false for both horizontal and vertical
        *collision
        */
        OrientationTuple CheckEntityCollisionIntoWall(MovableEntity& MovingObject);  //The responsibility of the walls is to block,it cannot do this without checking for colliding objects

        /** \brief This method returns a vector that has the respective co-ordinates
        *of the maze walls.
        *   \return VectorOfWalls
        */
        VectorOfWalls ReturnMazeWalls() const;

        /** \brief This method return the thickness length of the maze walls
        */
        float returnWallThickness();

        /** \brief Destructor
        */
        ~MazeWalls();

    private:
        VectorOfWalls Walls_;
        const float WallThickness=10;
        HelperClass CollisionChecker_;
        Maze WallData_; // The mazeWalls class has ownership of the Wall data read in on Maze class.
        BoundaryManager Boundary_;
        bool HorizontalCollision_;
        bool VerticalCollision_;

};

#endif // MAZEWALLS_H
