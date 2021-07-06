#include "Ghost.h"

Ghost::Ghost(const float& xStartPos,const float& yStartPos,const float& MovementStep)
{
    this->x_ghostPos_ = xStartPos;
    this->y_ghostPos_ = yStartPos;

    this->movementStep_ = MovementStep; //

    this->ghostWidth_ = Constants::MOVING_OBJECT_WIDTH;
    this->ghostHeight_ = Constants::MOVING_OBJECT_HEIGHT;

    GhostBox.BoxLength=ghostWidth_;
    GhostBox.BoxHeight=ghostHeight_;
}

x_and_y Ghost::getEntityPosition() const
{
    return {x_ghostPos_, y_ghostPos_};
}

x_and_y Ghost::getSizeOfEntity() const
{
    return {ghostWidth_, ghostHeight_};
}

void Ghost::setEntityPosition(float x, float y)
{
    x_ghostPos_ = x;
    y_ghostPos_ = y;

    GhostBox.xTopLeft=x-Constants::MOVING_OBJECT_X_ORIGIN;
    GhostBox.yTopLeft=y-Constants::MOVING_OBJECT_Y_ORIGIN;

}

void Ghost::setEntityMoveDirection(Orientation& ghostDirection)
{
    ghostMoveDirection_=ghostDirection;

}

void Ghost::moveEntity()
{

    auto [x_ghostPos, y_ghostPos] = getEntityPosition();
    auto ghostDirection = getEntityMoveDirection();

    switch(ghostDirection)
    {
    case Orientation::FACE_LEFT:
        x_ghostPos -= movementStep_;
        break;
    case Orientation::FACE_RIGHT:
        x_ghostPos += movementStep_;
        break;
    case Orientation::FACE_UP:
        y_ghostPos -= movementStep_;
        break;
    case Orientation::FACE_DOWN:
        y_ghostPos += movementStep_;
        break;
    default:
        break;
    }

    setEntityPosition(x_ghostPos, y_ghostPos);

}

BoundingBox Ghost::ObjectContainer() const
{
    return GhostBox;
}

Orientation Ghost::getEntityMoveDirection() const
{
    return ghostMoveDirection_;
}
void Ghost::GhostBehaviourAtBoundary(Ghost& CurrGhost,LogicDoor& GameDoors)
{
    auto [Horizontal,vertical]=Walls_->CheckEntityCollisionIntoWall(CurrGhost); // internal Maze Object
    auto [DoorHorizontal,DoorVertical]=GameDoors.BlockEntityFromPassing(CurrGhost);
    Direction(Horizontal,vertical,CurrGhost);
    Direction(DoorHorizontal,DoorVertical,CurrGhost);
}

void Ghost::Direction(bool& Horizontal,bool& vertical,Ghost& CurrGhost)
{
    auto [xg,yg]=CurrGhost.getEntityPosition();
    auto [xp,yp]=Player_.getEntityPosition();
    float y_diff=yp-yg;
    float x_diff=xp-xg;
    if(Horizontal)
    {

        if(x_diff>0)
        {
            auto Dir=Orientation::FACE_RIGHT;
            CurrGhost.setEntityMoveDirection(Dir);
        }
        else if(x_diff<0)
        {
            auto Dir=Orientation::FACE_LEFT;
            CurrGhost.setEntityMoveDirection(Dir);
        }
        else
        {
            auto Dir=Orientation::FACE_UP;
            CurrGhost.setEntityMoveDirection(Dir);
        }
    }

    if(vertical)
    {

        if(y_diff>0) // vertical wall, we are concerned with vertical motion
        {
            auto Direction=Orientation::FACE_DOWN;
            CurrGhost.setEntityMoveDirection(Direction);
        }
        else if(y_diff<0)
        {
            auto Direction=Orientation::FACE_UP;
            CurrGhost.setEntityMoveDirection(Direction);
        }
         else
        {
            auto Dir=Orientation::FACE_LEFT;
            CurrGhost.setEntityMoveDirection(Dir);
        }
    }


}

void Ghost::updatePlayer(Player& CurrentPlayer)
{
    Player_= CurrentPlayer;
}

void Ghost::UpdateWall(std::shared_ptr<MazeWalls> currentWall)
{
    Walls_=currentWall;
}

Ghost::~Ghost()
{

}

