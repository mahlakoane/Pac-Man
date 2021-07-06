#include "HelperClass.h"

HelperClass::HelperClass()
{
    //ctor
}

bool HelperClass::Intersects(BoundingBox& Box1,BoundingBox& Box2) ///collision between bounding boxes, works fine
{
    if((Box1.xTopLeft<=(Box2.xTopLeft+Box2.BoxLength)) && ((Box1.xTopLeft+Box1.BoxLength)>=Box2.xTopLeft) &&
            (Box1.yTopLeft<=(Box2.yTopLeft+Box2.BoxHeight)) && ((Box1.yTopLeft+Box1.BoxHeight)>=Box2.yTopLeft))
    {
        return true;
    }
    return false;
}

void HelperClass::isEntityInsideTheMaze(MovableEntity& MovableOject)
{
    auto [x_playerPos, y_playerPos] = MovableOject.getEntityPosition();

    auto leftEdge = Constants::LEFT_EDGE;
    auto rightEdge = Constants::RIGHT_EDGE;
    auto topEdge = Constants::TOP_EDGE;
    auto bottomEdge = Constants::BOTTOM_EDGE;

    if(y_playerPos > bottomEdge)
        MovableOject.setEntityPosition(x_playerPos, bottomEdge);
    else if(y_playerPos < topEdge)
        MovableOject.setEntityPosition(x_playerPos, topEdge);
    else if (x_playerPos < leftEdge)
        MovableOject.setEntityPosition(leftEdge, y_playerPos);
    else if(x_playerPos > rightEdge)
        MovableOject.setEntityPosition(rightEdge, y_playerPos);
}

HelperClass::~HelperClass()
{
    //dtor
}
