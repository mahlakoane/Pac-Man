#include "MazeWalls.h"

MazeWalls::MazeWalls(Maze& DataWallObject):WallData_{DataWallObject}
{
    Walls_=WallData_.ObjectContainer();
}

OrientationTuple MazeWalls::CheckEntityCollisionIntoWall(MovableEntity& MovingObject) //just referring to the object, not having it
{


    BoundingBox MazeWallBox;
    auto CurrentBox = MovingObject.ObjectContainer();
    HorizontalCollision_=false;
    VerticalCollision_=false;
    BoundingBox WallCollidedWith;


    for(auto WallBox : Walls_)
    {

        MazeWallBox.xTopLeft=WallBox.x_coord;
        MazeWallBox.yTopLeft=WallBox.y_coord;

        if(WallBox.Orientation=='h')
        {
            MazeWallBox.BoxLength=WallBox.length;
            MazeWallBox.BoxHeight=WallThickness;
            HorizontalCollision_=CollisionChecker_.Intersects(CurrentBox,MazeWallBox);
            if(HorizontalCollision_)
            {
                WallCollidedWith=MazeWallBox;
                break;
            }

        }
        if(WallBox.Orientation=='v')
        {

            MazeWallBox.BoxLength=WallThickness;
            MazeWallBox.BoxHeight=WallBox.length;
            VerticalCollision_=CollisionChecker_.Intersects(CurrentBox,MazeWallBox);
            if(VerticalCollision_)
            {
                WallCollidedWith=MazeWallBox;
                break;
            }

        }

    }

    if(HorizontalCollision_)
    {

        Boundary_.BlockEntity(WallCollidedWith,CurrentBox,MovingObject);

    }
    if(VerticalCollision_)
    {

        Boundary_.BlockEntity(WallCollidedWith,CurrentBox,MovingObject);

    }

return std::make_tuple(HorizontalCollision_,VerticalCollision_);
}

VectorOfWalls MazeWalls::ReturnMazeWalls() const
{
    return Walls_;
}

float MazeWalls::returnWallThickness()
{
   return WallThickness;
}




MazeWalls::~MazeWalls()
{
    //dtor
}
