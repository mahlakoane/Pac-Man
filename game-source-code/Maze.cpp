#include "Maze.h"
#include <fstream>
#include "Constants.h"



Maze::Maze()
{
ReadEntityFromFile();
}

void Maze::ReadEntityFromFile()
{
    float x=0;
    float y=0;
    float length=0;
    char orientation=' ';

    std::ifstream inputFile;
    inputFile.open("Resources/Pacmaze.txt");
    if (!inputFile)
    {
        std::cerr << "File could not be opened";
    }

    while (inputFile >> x >> y >>length >>orientation)
    {
        currentWall.x_coord=x+Constants::MAZE_X_OFFSET;
        currentWall.y_coord=y+Constants::MAZE_Y_OFFSET;
        currentWall.length=length;
        currentWall.Orientation=orientation;
        LogicMaze.push_back(currentWall);
    }

    inputFile.close();



}


VectorOfWalls Maze::ObjectContainer() const
{
    return LogicMaze;
}



Maze::~Maze()
{

}
