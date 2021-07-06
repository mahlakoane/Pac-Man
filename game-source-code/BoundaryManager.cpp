#include "BoundaryManager.h"

BoundaryManager::BoundaryManager()
{
    //ctor
}
void BoundaryManager::BlockEntity(BoundingBox& FixedBox,BoundingBox& MovingObjectBox,MovableEntity& MovingObject)
{
  auto [x,y]=MovingObject.getEntityPosition();
    ///The Objects operated on in this function have already collided
    auto FixedLeftXBoundary=FixedBox.xTopLeft;
    auto FixedRightXBoundary=FixedLeftXBoundary+FixedBox.BoxLength;
    auto FixedTopYBoundary=FixedBox.yTopLeft;
    auto FixedBottomYBoundary=FixedTopYBoundary+FixedBox.BoxHeight;

    auto ObjectLeftXBoundary=MovingObjectBox.xTopLeft;
    auto ObjectRightXBoundary=ObjectLeftXBoundary+MovingObjectBox.BoxLength;
    auto ObjectTopYBoundary=MovingObjectBox.yTopLeft;
    auto ObjectBottomYBoundary=ObjectTopYBoundary+MovingObjectBox.BoxHeight;

    auto MovingObjectOrientation=MovingObject.getEntityMoveDirection();

    auto RepositioningValue=15; ///The value used to undo the y or x value of the collision


    //Boundaries & orientation
    if(FixedRightXBoundary>=ObjectLeftXBoundary && MovingObjectOrientation==Orientation::FACE_LEFT)
    {
        //counter the motion of player/Movable Object to the Left
        MovingObject.setEntityPosition(FixedRightXBoundary+RepositioningValue,y);  //When the wall blocks the movable entity, it stays in one place,The wall affects the Entity's position
    }
    if(FixedLeftXBoundary<=ObjectRightXBoundary && MovingObjectOrientation==Orientation::FACE_RIGHT)
    {
        //Stop the player/movable Object from moving to the Right,past the boundary
        MovingObject.setEntityPosition(FixedLeftXBoundary-RepositioningValue,y);
    }
    if(FixedTopYBoundary<=ObjectBottomYBoundary && MovingObjectOrientation==Orientation::FACE_DOWN)
    {
        //Top to Bottom
        MovingObject.setEntityPosition(x,FixedTopYBoundary-RepositioningValue);
    }
    if(FixedBottomYBoundary>=ObjectTopYBoundary && MovingObjectOrientation==Orientation::FACE_UP)
    {
        //Bottom to Top
        MovingObject.setEntityPosition(x,FixedBottomYBoundary+RepositioningValue);
    }
}
BoundaryManager::~BoundaryManager()
{
    //dtor
}
