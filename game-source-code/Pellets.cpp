#include "Pellets.h"
#include "Constants.h"
#include <fstream>


Pellets::Pellets()
{
ReadEntityFromFile();
}
void Pellets::ReadEntityFromFile()
{
    float x=0;
    float y=0;
    char PelletType=' ';


    std::ifstream inputFile;
    inputFile.open("Resources/pellets.txt");
    if (!inputFile) {
    std::cerr << "File could not be opened";}

    while(inputFile>>x>>y>>PelletType)
    {
        CurrentPellet.x_coord=x+Constants::MAZE_X_OFFSET;
        CurrentPellet.y_coord=y+Constants::MAZE_Y_OFFSET;
        CurrentPellet.PelletType=PelletType;
        pelletVec.push_back(CurrentPellet);
    }
inputFile.close();
}


std::vector<PelletProperties> Pellets::ObjectContainer() const
{
    return pelletVec;
}

Pellets::~Pellets()
{

}
