#ifndef FOOD_H
#define FOOD_H

#include <iostream>
#include <vector>
#include <tuple>
#include "MazeEntity.h"
#include "GeneralGameEntity.h"

using x_and_y = std::tuple<float, float>; /**< Tuple of floats to store game object positions */
using VectorOfFoodPositions =std::vector<x_and_y>; /**<Vector that stores the positions of the fruits */

/** \class Food
* \brief This is a game object class that inherits from MazeEntity
*and GeneralGameEntity class. It models the static behavior of the
*fruits that are placed in locked sections of the game maze.
* \authors Tshepo Chokoe (1705890) and Bohlale Mahlakoane (1352926)
*/

class Food : public MazeEntity,public GeneralGameEntity <VectorOfFoodPositions>
{
public:

    /** \brief Default empty constructor
    */
    Food();

    /** \brief This method is inherited from the MazeEntity class.
    *It is responsible for reading the co-ordinates of the fruits
    *from a text file and storing them in a vector of fruit positions
    */
    virtual void ReadEntityFromFile() override;

    /** \brief This method returns a vector that contains the position
    *of the fruits that are being read in
    *   \return A vector that has a position of every fruit
    */
    virtual VectorOfFoodPositions ObjectContainer() const override;

    /** \brief Destructor
    */
    ~Food();

private:
    VectorOfFoodPositions Foods;
};

#endif // FOOD_H
