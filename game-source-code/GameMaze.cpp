#include "GameMaze.h"

GameMaze::GameMaze()
{

}
Maze GameMaze::mazeWalls() const
{
    return Walls_;
}

Mazedoors GameMaze::mazeDoors() const
{
    return Doors_;
}
Food GameMaze::MazeFoods() const
{
    return Foods_;
}
Keys GameMaze::MazeKeys() const
{
    return Keys_;
}
Pellets GameMaze::MazePellets() const
{
    return Pellets_;
}

GameMaze::~GameMaze()
{

}
