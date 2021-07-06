#include "Mazedoors.h"
#include <fstream>
#include <vector>
#include "Constants.h"


Mazedoors::Mazedoors()
{
ReadEntityFromFile();
}

void Mazedoors::ReadEntityFromFile()
{
    float x=0;
    float y=0;
    char ori=' ';


    std::ifstream inputFile;
    inputFile.open("Resources/doors.txt");
    if (!inputFile) {
    std::cerr << "File could not be opened";} //throw exception rather

    while(inputFile>>x>>y>>ori)
    {
        currentDoor.x_coord=x+Constants::MAZE_X_OFFSET;
        currentDoor.y_coord=y+Constants::MAZE_Y_OFFSET;
        currentDoor.orientation=ori;
        mazedoors.push_back(currentDoor);
    }
inputFile.close();
}


VectorOfDoorStructs Mazedoors::ObjectContainer() const
{
    return mazedoors;
}

Mazedoors::~Mazedoors()
{

}
