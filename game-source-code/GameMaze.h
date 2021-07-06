#ifndef GAMEMAZE_H
#define GAMEMAZE_H
#include "Maze.h"
#include "Mazedoors.h"
#include "Food.h"
#include "Keys.h"
#include "Pellets.h"

class GameMaze
{
    public:
        GameMaze();
        Maze mazeWalls() const;
        Mazedoors mazeDoors() const;
        Food MazeFoods() const;
        Keys MazeKeys() const;
        Pellets MazePellets() const;
        ~GameMaze();

    private:
        Maze Walls_;
        Mazedoors Doors_;
        Food Foods_;
        Keys Keys_;
        Pellets Pellets_;

};

#endif // GAMEMAZE_H
