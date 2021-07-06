#ifndef GHOST_H
#define GHOST_H
#include <iostream>
#include <stdio.h>
#include <ctime>
#include <cmath>
#include <set>
#include <tuple>
#include <cfloat>
#include <vector>
#include "Orientation.h"
#include "MovableEntity.h"
#include "GeneralGameEntity.h"
#include "MazeWalls.h"
#include "LogicDoor.h"
#include "Player.h"

using x_and_y = std::tuple<float, float>;
using BoundaryOrientation=std::tuple<bool,bool>;

/** \class Ghost
* \brief This class inherits the interface of MovableEntity class because
*its objects have the ability of motion. The pure interface of MovableEnity
*class is implemented by within this class.
* \authors Tshepo Chokoe (1705890) and Bohlale Mahlakoane (1352926)
*/


class Ghost : public MovableEntity
{
public:

    /** \brief Default empty constructor
    */
    Ghost(){}

    /** \brief Parameterized constructor to initialize the staring position of the
    *ghost entities and their movement step
    *   \param xStartPos of type float
    *   \param yStartPos of type float
    *   \param MovementStep of type float
    */
    Ghost(const float& xStartPos,const float& yStartPos,const float& MovementStep);

    virtual x_and_y getEntityPosition() const override;
    virtual x_and_y getSizeOfEntity() const override;
    void setEntityMoveDirection(Orientation& orientation);
    virtual Orientation getEntityMoveDirection() const override;
    virtual void moveEntity() override;
    virtual void setEntityPosition(float x, float y) override;
    virtual BoundingBox ObjectContainer() const override;


    void updatePlayer(Player& CurrentPlayer);   //not available if Ghost is a Movable Entity object
    void UpdateWall(std::shared_ptr<MazeWalls> currentWall);

    /** \brief This method handles the behavior of the ghost when they hit a wall.
    *It invokes the Direction() function to get the direction of the ghost when
    *hit an obstacle (i.e door a or maze wall)
    *   \param CurrGhost of type Ghost
    *   \param GameDoors of type LogicDoor
    */
    void GhostBehaviourAtBoundary(Ghost& CurrGhost,LogicDoor& GameDoors);  //Wall or door

    /** \brief This method sets the direction in which the ghosts should move
    *depending on the position of Pac-Man
    *   \param Horizontal of type bool
    *   \param vertical of type bool
    *   \param currGhost of type Ghost
    */
    void Direction(bool& Horizontal,bool& vertical,Ghost& CurrGhost);

    /** \brief Destructor
    */
    ~Ghost();


private:
    Orientation ghostMoveDirection_;
    float ghostWidth_;
    float ghostHeight_;
    float x_ghostPos_;
    float y_ghostPos_;
    BoundingBox GhostBox;
    Player Player_;   //Ghost Must Know the Player it chases
    std::shared_ptr<MazeWalls> Walls_;  //Ghost Must Know The walls it must not move through
    float movementStep_;


};

#endif // GHOST_H
