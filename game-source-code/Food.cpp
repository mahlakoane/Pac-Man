#include "Food.h"
#include "Constants.h"
#include <fstream>

Food::Food()
{
ReadEntityFromFile();
}

void Food::ReadEntityFromFile()
{
    float x=0;
    float y=0;


    std::ifstream inputFile;
    inputFile.open("Resources/foods.txt");
    if (!inputFile) {
    std::cerr << "File could not be opened";}

    while(inputFile>>x>>y)
    {
        auto CurrentCoordinates=std::make_tuple(x+Constants::MAZE_X_OFFSET,y+Constants::MAZE_Y_OFFSET);
        Foods.push_back(CurrentCoordinates);
    }
inputFile.close();
}


VectorOfFoodPositions Food::ObjectContainer() const
{
  return Foods;
}


Food::~Food()
{
    //dtor
}
