#ifndef MAZEFOOD_H
#define MAZEFOOD_H

#include "Food.h"
#include "Player.h" //no need for movable entity, only player affects food
#include "HelperClass.h"

/** \class MazeFood
* \brief This class models a behavior of a game object which the fruit.
* \authors Tshepo Chokoe (1705890) and Bohlale Mahlakoane (1352926)
*/
class MazeFood
{
    public:

        /** \brief Parameterized constructor. This constructor initializes the
        * a member variable of this class which is FoodData_
        *   \param FoodDataObject of type food
        */
        MazeFood(Food& FoodDataObject);

        /** \brief This method erases the food entity from the screen upon collision
        *of a player and a fruit
        *   \param CurrentPlayer of type Player
        */
        void DisappearOnPlayerCollision(Player& CurrentPlayer);

        /** \brief This method returns a vector that has the positions of the fruit
        *entity
        *   \return vector of food positions
        */
        VectorOfFoodPositions ReturnFoodsToPresentationLayer() const;

        /** \brief This method return the dimensions of the fruit game entity
        *   \return x_and_y, length and height of the fruit entity
        */
        x_and_y getDimensionsIntoPresentationLayer() const;

        /** \brief This method checks if all the fruits have been erased from
        *the game screen
        *   \return bool, returns true if all the fruits have been eaten and false
        *otherwise
        */
        bool AreFoodsDepleted();

        /** \brief Destructor
        */
        ~MazeFood();

    private:
        Food FoodData_;
        const float FoodHeight=27.f;
        const float FoodWidth=25.f;
        VectorOfFoodPositions Foods_;
        BoundingBox FoodBox;
        HelperClass CollisionChecker_;

};

#endif // MAZEFOOD_H
