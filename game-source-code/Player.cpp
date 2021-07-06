#include "Player.h"
#include <iostream>

Player::Player(Orientation playerOrientation)
{
    this->playerOrientation_ = playerOrientation;
    this->playerWidth_ = Constants::MOVING_OBJECT_WIDTH;
    this->playerHeight_ = Constants::MOVING_OBJECT_HEIGHT;

    this->movementStep_ = Constants::MOVEMENT_STEP;

    this->x_playerPosition_ = Constants::PLAYER_START_XPOS;
    this->y_playerPosition_ = Constants::PLAYER_START_YPOS;

    CurrentBox.BoxHeight=playerHeight_;
    CurrentBox.BoxLength=playerWidth_;
}

x_and_y Player::getEntityPosition() const
{
    return {x_playerPosition_, y_playerPosition_};
}

x_and_y Player::getSizeOfEntity() const
{
    return {playerWidth_, playerHeight_};
}

void Player::setEntityMoveDirection(Orientation& orientation)
{
    playerOrientation_ = orientation;
}

Orientation Player::getEntityMoveDirection() const
{
    return playerOrientation_;
}

void Player::moveEntity()
{
    auto playerMoveDirection = getEntityMoveDirection();
    auto [xPlayerPosition, yPlayerPosition] = getEntityPosition();

        switch(playerMoveDirection)
        {
        case Orientation::FACE_LEFT:
            xPlayerPosition -= movementStep_;
            break;
        case Orientation::FACE_RIGHT:
            xPlayerPosition += movementStep_;
            break;
        case Orientation::FACE_UP:
            yPlayerPosition -= movementStep_;
            break;
        case Orientation::FACE_DOWN:
            yPlayerPosition += movementStep_;
            break;
        default:
            break;
        }

    setEntityPosition(xPlayerPosition, yPlayerPosition);
    //set Box coordinate values
    CurrentBox.xTopLeft = x_playerPosition_-Constants::MOVING_OBJECT_X_ORIGIN;
    CurrentBox.yTopLeft = y_playerPosition_-Constants::MOVING_OBJECT_Y_ORIGIN;
}


void Player::setEntityPosition(float x, float y)
{
    x_playerPosition_ = x;
    y_playerPosition_ = y;
}
BoundingBox Player::ObjectContainer() const
{
  return CurrentBox;
}

bool Player::CollisionOfPlayerAndGhost(MovableEntity& currentGhost,MovableEntity& currentPlayer)
{
    auto GhostBox= currentGhost.ObjectContainer();
    auto PlayerBox= currentPlayer.ObjectContainer();
    bool GhostAndPlayerCollision=CollisionCheck_.Intersects(PlayerBox,GhostBox);
    return GhostAndPlayerCollision;
}

Player::~Player()
{

}









