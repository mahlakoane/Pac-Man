#ifndef PLAYER_H
#define PLAYER_H
#include "Orientation.h"
#include <tuple>
#include "MovableEntity.h"
#include "GeneralGameEntity.h"
#include <vector>
#include "HelperClass.h"

using x_and_y = std::tuple<float, float>; /** Tuple store co-ordinates of game entity *\

/** \class Player
* \brief This is a player class that inherits the interface of the MovableEntity class.
*The MovableEntity class functions are overriden since each object has a unique
*implementation of the each function.
*NOTE: The description of all the functions that are overidden is given in the
*MovableEntity class interface.
* \authors Tshepo Chokoe (1705890) and Bohlale Mahlakoane (1352926)
*/
class Player : public MovableEntity
{
    public:

        /** \brief Default empty constructor
        */
        Player(){}

        /** \brief Parameterized player constructor. It initializes the
        *player orientation, player height and width along with player
        *movement step. Moreover, the starting position of the player
        *is also initialized by this constructor. Lastly, the player
        *bounding box is also initialized.
        *  \param playerOrientation of type Orientation enum
        */
        Player(Orientation playerOrientation);

        virtual x_and_y getEntityPosition() const override;
        virtual x_and_y getSizeOfEntity() const override;
        virtual void setEntityMoveDirection(Orientation& orientation) override;
        virtual Orientation getEntityMoveDirection() const override;
        virtual void moveEntity() override;
        virtual void setEntityPosition(float x, float y) override;
        virtual BoundingBox ObjectContainer() const override;

        /** \brief This method checks collision between the player and the ghosts.
        *   \param currentGhost of type MovableEntity
        *   \param currentPlayer of type MovableEntity
        *   \return bool, returns true if there is collision and false otherwise
        */
        bool CollisionOfPlayerAndGhost(MovableEntity& currentGhost,MovableEntity& currentPlayer);

        /** \brief Destructor
        */
        ~Player();

    private:
        Orientation playerMoveDirection_;
        Orientation playerOrientation_;
        BoundingBox CurrentBox;
        float playerWidth_;
        float playerHeight_;
        float x_playerPosition_;
        float y_playerPosition_;
        float movementStep_;
        HelperClass CollisionCheck_;
};

#endif // PLAYER_H
