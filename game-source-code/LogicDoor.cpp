#include "LogicDoor.h"
#include <cstdlib>  //for random numbers
#include<ctime>

LogicDoor::LogicDoor(Mazedoors& DoorDataObject): DoorData_{DoorDataObject}
{
    Doors_=DoorData_.ObjectContainer();
}


HorizontalOrVertical LogicDoor::BlockEntityFromPassing(MovableEntity& MovableObject)
{
    auto CurrentBox = MovableObject.ObjectContainer();
    BoundingBox doorBox;
    bool DoorCollisionHorizontal=false;
    bool DoorCollisionVertical=false;
    int DoorCount=0;

    for(auto door : Doors_)
    {

        doorBox.xTopLeft=door.x_coord;
        doorBox.yTopLeft=door.y_coord;

        if(door.orientation=='h')
        {
            doorBox.BoxLength=doorLength;
            doorBox.BoxHeight=doorThickness;

            DoorCollisionHorizontal=CollisionChecker_.Intersects(CurrentBox,doorBox);
            if(DoorCollisionHorizontal)
            {
                break;
            }

        }
        if(door.orientation=='v')
        {

            doorBox.BoxLength=doorThickness;
            doorBox.BoxHeight=doorLength;
            DoorCollisionVertical=CollisionChecker_.Intersects(CurrentBox,doorBox);

            if(DoorCollisionVertical)
            {
                break;
            }
        }
        DoorCount++;
    }
     if(DoorCollisionHorizontal && DoorCount!= 32)  //32 is the position of the last door
    {
        Boundary_.BlockEntity(doorBox,CurrentBox,MovableObject);
        return std::make_tuple(DoorCollisionHorizontal,DoorCollisionVertical);

    }
    if(DoorCollisionVertical && DoorCount!= 32)
    {
        Boundary_.BlockEntity(doorBox,CurrentBox,MovableObject);
        return std::make_tuple(DoorCollisionHorizontal,DoorCollisionVertical);
    }

}



void LogicDoor::OpenDoors()
{
        srand(time(NULL));
        //The last door in the door vector is the door to the box where the ghosts are enclosed at the start.
        int RandomNum1=rand()%(Doors_.size()-2);
        int RandomNum2=rand()%(Doors_.size()-2);
        Doors_.erase(begin(Doors_)+RandomNum1);
        Doors_.erase(begin(Doors_)+RandomNum2);
}

VectorOfDoorStructs LogicDoor::getDoorsVector() const
{
  return Doors_;
}
x_and_y LogicDoor::getDimensionsIntoPresentationLayer() const
{
    return std::make_tuple(doorLength,doorThickness);

}

LogicDoor::~LogicDoor()
{
    //dtor
}
