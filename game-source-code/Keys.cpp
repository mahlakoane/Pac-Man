#include "Keys.h"
#include <fstream>
#include "Constants.h"

Keys::Keys()
{
ReadEntityFromFile();
}
void Keys::ReadEntityFromFile()
{
    float x=0;
    float y=0;


    std::ifstream inputFile;
    inputFile.open("Resources/keys.txt");
    if (!inputFile) {
    std::cerr << "File could not be opened";}

    while(inputFile>>x>>y)
    {
       auto CurrentKeyPosition= std::make_tuple(x+Constants::MAZE_X_OFFSET,y+Constants::MAZE_Y_OFFSET);
        KeyVec.push_back(CurrentKeyPosition);
    }
inputFile.close();
}

VectorOfPositions Keys::ObjectContainer() const  //for taking info to next architectural layer-Logic.
{
   return KeyVec;
}

Keys::~Keys()
{

}
