#ifndef MOVABLEENTITY_H
#define MOVABLEENTITY_H

#include <tuple>
#include "Orientation.h"
#include "GeneralGameEntity.h"

using x_and_y = std::tuple<float, float>;

/** \class MovableEntity
* \brief This inherits from the GeneralGameEntity class and it is only used
*by movable objects of the game. This is a pure interface class that contains
*pure virtual functions that will be overridden by moving game objects as they
*implement in different ways.
* \authors Tshepo Chokoe (1705890) and Bohlale Mahlakoane (1352926)
*/

class MovableEntity: public GeneralGameEntity <BoundingBox>
{
    public:

        /** \brief Default empty constructor
        */
        MovableEntity() {}

        /** \brief This methods return the position of the movable object
        *   \return x_and_y, tuple containing x and y co-ordinate of the
        *movable object
        */
        virtual x_and_y getEntityPosition() const=0;

        /** \brief This returns the size of the movable object
        *   \return x_and_y, tuple that contains width and height of the object
        */
        virtual x_and_y getSizeOfEntity() const=0;

        /** \brief This method set the direction in which the game should move
        */
        virtual void setEntityMoveDirection(Orientation& orientation)=0;

        /** \brief This methods returns the movement direction of the game object
        *that is set by the setEntityMoveDirection method.
        */
        virtual Orientation getEntityMoveDirection() const=0;

        /** \brief This method sets the position of the game object
        */
        virtual void setEntityPosition(float x, float y)=0;

        /** \brief This method is responsible for the movement of the game
        *object. It moves the game object up, down, left and right in selected
        *areas of the maze (i.e path).
        */
        virtual void moveEntity()=0;

        /** \brief Destructor
        */
        ~MovableEntity() {}

    private:
};

#endif // MOVABLEENTITY_H
