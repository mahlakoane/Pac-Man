#ifndef PLAYERCOLLISIONS_H
#define PLAYERCOLLISIONS_H
#include "GameMaze.h"
#include "Player.h"
#include "Ghost.h"
#include <cstdlib>
#include <ctime>

using VectorOfMazeWallStructs=std::vector<mazeWall>;
using TuplePositionVecctor=std::vector<x_and_y>;
using VectorOfDoorStructs=std::vector<MazeDoorComponents>;
using VectorOfPelletStructs=std::vector<PelletProperties>;

class PlayerCollisions
{
    public:
        PlayerCollisions();
        void DoPlayerAndWallsCollide(Player& currentPlayer,VectorOfMazeWallStructs& WallVec); ///Player is not a fixed property, it changes
        void GhostAndWalls(Ghost& currentGhost,VectorOfMazeWallStructs& WallVec);
        void playerAndKeys(Player& currentPlayer,TuplePositionVecctor& KeyVec,VectorOfDoorStructs& DoorVec);
        void playerVsFood(Player& currentPlayer,TuplePositionVecctor& FoodBoxes);
        void playerAndDoors(Player& currentPlayer,VectorOfDoorStructs& DoorVec);
        void playerAndPellets(Player& currentPlayer,VectorOfPelletStructs& pelletVec);
        bool Intersects(BoundingBox& Box1,BoundingBox& Box2);
        ~PlayerCollisions();

        Orientation chooseRandomDirection(mazeWall wallCollidedWith);

    private:
        void HandleWallCollison(BoundingBox& MazeBox,BoundingBox& ObjectBox,Player& PacMan);
        void HandleGhostAndWallCollisions(BoundingBox& MazeBox,BoundingBox& ObjectBox, Ghost& ghost, Orientation ghostDir);
        bool KeyCollision=false;
        bool iSHorizontal_=false;
        bool KeyCollisionHandler();

};

#endif // PLAYERCOLLISIONS_H
