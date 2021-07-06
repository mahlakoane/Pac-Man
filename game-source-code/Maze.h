#ifndef MAZE_H
#define MAZE_H

#include <iostream>
#include <vector>
#include "MazeEntity.h"
#include "GeneralGameEntity.h"
#include <memory> //for smart pointers

/** \brief This structure stores the top left co-ordinate, length
*and orientation of a maze wall
* \authors Tshepo Chokoe (1705890) and Bohlale Mahlakoane (1352926)
*/
struct mazeWall{
        float x_coord;
        float y_coord;
        float length;
        char Orientation;
        };

using VectorOfWalls =std::vector<mazeWall>;

/** \brief This class inherits from MazeEntity and GeneralGameEntity class.
*It models the game maze as a whole
*/
class Maze : public MazeEntity , public GeneralGameEntity <VectorOfWalls>
{
    public:
        /** \brief Default empty constructor
        */
        Maze();

        /** \brief This method reads the maze from a file
        */
        virtual void ReadEntityFromFile() override;

        /** \brief This method returns a vector of maze walls structs
        *   \return VectorOfWalls
        */
        virtual VectorOfWalls ObjectContainer() const override;

        /** \brief Destructor
        */
        ~Maze();


    private:
        mazeWall currentWall;
        VectorOfWalls LogicMaze;



};

#endif // MAZE_H
