#include "MazeFood.h"

MazeFood::MazeFood(Food& FoodDataObject):FoodData_{FoodDataObject}
{
    Foods_=FoodData_.ObjectContainer();
}

void MazeFood::DisappearOnPlayerCollision(Player& CurrentPlayer)
{
    auto CurrentBox = CurrentPlayer.ObjectContainer();
    FoodBox.BoxLength=FoodWidth;
    FoodBox.BoxHeight=FoodHeight;
    int elementCounter=0;
    bool CollisionResult=false;


    for(auto nthfood : Foods_)
    {
        FoodBox.xTopLeft=std::get<0>(nthfood);
        FoodBox.yTopLeft=std::get<1>(nthfood);
        CollisionResult=CollisionChecker_.Intersects(CurrentBox,FoodBox);
        if(CollisionResult)
        {
            break;
        }
        elementCounter++;
    }

    if(CollisionResult)
    {
        Foods_.erase(begin(Foods_)+elementCounter);
    }

}
VectorOfFoodPositions MazeFood::ReturnFoodsToPresentationLayer() const
{
    return  Foods_;
}

x_and_y MazeFood::getDimensionsIntoPresentationLayer() const
{
    return std::make_tuple(FoodWidth,FoodHeight);
}

bool MazeFood::AreFoodsDepleted()
{
    if(Foods_.size()==0){return true;}
    else{return false;}
}

MazeFood::~MazeFood()
{
    //dtor
}
