#include "MazeKeys.h"

MazeKeys::MazeKeys(Keys& KeyDataObject):
    KeyData_{KeyDataObject}
{
    KeyPositions_=KeyData_.ObjectContainer();
}

bool MazeKeys::DisappearAndUnlockDoor(Player& MovingObject) //Key is supposed to know this information anyway
{
    auto CurrentBox = MovingObject.ObjectContainer();
    BoundingBox keyBox;
    int KeyCount=0;
    keyBox.BoxLength=KeyWidth_;
    keyBox.BoxHeight=KeyHeight_;
    bool Collided=false;


    for(auto key : KeyPositions_)
    {

        keyBox.xTopLeft=std::get<0>(key);
        keyBox.yTopLeft=std::get<1>(key);

        Collided=KeyCollisionChecker_.Intersects(CurrentBox,keyBox);
        if(Collided)
        {
            break;
        }
        KeyCount++;
    }
    if(Collided)
    {
        KeyPositions_.erase(begin(KeyPositions_)+KeyCount); //operate on the external vector
        return Collided;

    }

    return Collided; //if false, no doors will be unlocked

}

VectorOfPositions MazeKeys::ReturnKeyVecToPresentationLayer() const
{
    return KeyPositions_;
}
x_and_y MazeKeys::getDimensionsIntoPresentationLayer() const
{
    return std::make_tuple(KeyWidth_,KeyHeight_);
}

MazeKeys::~MazeKeys()
{
    //dtor
}
