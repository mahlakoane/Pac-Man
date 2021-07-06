#include "PlayerCollisions.h"
#include <iostream>
#include <cstdlib>

PlayerCollisions::PlayerCollisions()
{

}

void PlayerCollisions::DoPlayerAndWallsCollide(Player& currentPlayer,VectorOfMazeWallStructs& WallVec)
{
    float wall=10;
    BoundingBox MazeWallBox;
    auto CurrentBox = currentPlayer.ObjectContainer();
    bool resultHorizontal=false;
    bool resultVertical=false;
    BoundingBox WallCollidedWith;

    for(auto WallBox : WallVec)
    {

        MazeWallBox.xTopLeft=WallBox.x_coord;
        MazeWallBox.yTopLeft=WallBox.y_coord;

        if(WallBox.Orientation=='h')
        {
            MazeWallBox.BoxLength=WallBox.length;
            MazeWallBox.BoxHeight=wall;
            resultHorizontal=Intersects(CurrentBox,MazeWallBox);
            if(resultHorizontal)
            {
                WallCollidedWith=MazeWallBox;
                iSHorizontal_=true;
                break;
            }

        }
        if(WallBox.Orientation=='v')
        {

            MazeWallBox.BoxLength=wall;
            MazeWallBox.BoxHeight=WallBox.length;
            resultVertical=Intersects(CurrentBox,MazeWallBox);
            if(resultVertical)
            {
                WallCollidedWith=MazeWallBox;
                iSHorizontal_=false;
                break;
            }

        }

    }

    if(resultHorizontal)
    {
        HandleWallCollison(WallCollidedWith,CurrentBox,currentPlayer);
    }
    if(resultVertical)
    {
        HandleWallCollison(WallCollidedWith,CurrentBox,currentPlayer);
    }
}

//Collision of ghosts and walls
void PlayerCollisions::GhostAndWalls(Ghost& currentGhost,VectorOfMazeWallStructs& WallVec)
{
    float wall=10; //thickness of a wall
    BoundingBox MazeWallBox;
    auto CurrentBox = currentGhost.ObjectContainer(); //bounding box of the ghost
    bool resultHorizontal=false; //track if collision is with hor. wall
    bool resultVertical=false;   //track if collision is with vert. wall
    BoundingBox WallCollidedWith; //bounding box of wall collided wiith
    auto ghostDir = Orientation::NONE;

    for(auto WallBox : WallVec)
    {

        MazeWallBox.xTopLeft=WallBox.x_coord;
        MazeWallBox.yTopLeft=WallBox.y_coord;

        if(WallBox.Orientation=='h')
        {
            MazeWallBox.BoxLength=WallBox.length;
            MazeWallBox.BoxHeight=wall;
            resultHorizontal=Intersects(CurrentBox,MazeWallBox);
            if(resultHorizontal)
            {
                WallCollidedWith=MazeWallBox;
                iSHorizontal_=true;
                ghostDir = chooseRandomDirection(WallBox);

                break;
            }

        }
        if(WallBox.Orientation=='v')
        {

            MazeWallBox.BoxLength=wall;
            MazeWallBox.BoxHeight=WallBox.length;
            resultVertical = Intersects(CurrentBox,MazeWallBox);
            if(resultVertical)
            {
                WallCollidedWith=MazeWallBox;
                iSHorizontal_=false;
                ghostDir = chooseRandomDirection(WallBox);
                break;
            }
        }
    }

    if(resultHorizontal)
    {
        HandleGhostAndWallCollisions(WallCollidedWith,CurrentBox,currentGhost,ghostDir);
    }
    if(resultVertical)
    {
        HandleGhostAndWallCollisions(WallCollidedWith,CurrentBox,currentGhost,ghostDir);
    }

}

Orientation PlayerCollisions::chooseRandomDirection(mazeWall wallCollidedWith)
{
    auto chooseRandomDir = 0;
    srand(time(0));

    if (wallCollidedWith.Orientation == 'h')
    {
        chooseRandomDir = rand() % 2;

        if (chooseRandomDir == 0)
            return Orientation::FACE_DOWN;
        else if (chooseRandomDir == 1)
            return Orientation::FACE_UP;
    }
    else if(wallCollidedWith.Orientation == 'v')
    {
        chooseRandomDir = rand() % 2;

        if (chooseRandomDir == 0)
            return Orientation::FACE_LEFT;
        else if (chooseRandomDir == 1)
            return Orientation::FACE_RIGHT;
    }
}

void PlayerCollisions::HandleGhostAndWallCollisions(BoundingBox& MazeBox,BoundingBox& ObjectBox, Ghost& ghost, Orientation ghostDir)
{
    auto [x,y]=ghost.getEntityPosition();
    ///The Objects operated on in this function have already collided
    auto MazeLeftXBoundary=MazeBox.xTopLeft;
    auto MazeRightXBoundary=MazeLeftXBoundary+MazeBox.BoxLength;
    auto MazeTopYBoundary=MazeBox.yTopLeft;
    auto MazeBottomYBoundary=MazeTopYBoundary+MazeBox.BoxHeight;

    auto ObjectLeftXBoundary=ObjectBox.xTopLeft;
    auto ObjectRightXBoundary=ObjectLeftXBoundary+ObjectBox.BoxLength;
    auto ObjectTopYBoundary=ObjectBox.yTopLeft;
    auto ObjectBottomYBoundary=ObjectTopYBoundary+ObjectBox.BoxHeight;

    auto PlayerOrientation=ghost.getEntityMoveDirection();

    auto RepositioningValue=15; ///The value used to undo the y or x value of the collision

    //Boundaries & orientation
    if(MazeRightXBoundary>=ObjectLeftXBoundary && PlayerOrientation==Orientation::FACE_LEFT)
    {  //counter the motion of player/Movable Object to the Left
       ghost.setEntityPosition(MazeRightXBoundary+RepositioningValue,y);
    }
    if(MazeLeftXBoundary<=ObjectRightXBoundary && PlayerOrientation==Orientation::FACE_RIGHT)
    {   //Stop the player/movable Object from moving to the Right,past the boundary
        ghost.setEntityPosition(MazeLeftXBoundary-RepositioningValue,y);
    }
    if(MazeTopYBoundary<=ObjectBottomYBoundary && PlayerOrientation==Orientation::FACE_DOWN)
    {   //Top to Bottom
        ghost.setEntityPosition(x,MazeTopYBoundary-RepositioningValue);
    }
    if(MazeBottomYBoundary>=ObjectTopYBoundary && PlayerOrientation==Orientation::FACE_UP)
    {   //Bottom to Top
        ghost.setEntityPosition(x,MazeBottomYBoundary+RepositioningValue);
    }

}

void PlayerCollisions::playerAndKeys(Player& currentPlayer,TuplePositionVecctor& KeyVec,VectorOfDoorStructs& DoorVec)
{
    auto CurrentBox = currentPlayer.ObjectContainer();
    float height=27; //dimension of the key
    float width=21;
    BoundingBox keyBox;
    int KeyCount=0;
    bool Collided=false;


    for(auto key : KeyVec)
    {

        keyBox.xTopLeft=std::get<0>(key);
        keyBox.yTopLeft=std::get<1>(key);


        keyBox.BoxLength=width;
        keyBox.BoxHeight=height;
        Collided=Intersects(CurrentBox,keyBox);
        if(Collided)
        {
            break;
        }
        KeyCount++;
    }
    if(Collided)
    {
        KeyVec.erase(begin(KeyVec)+KeyCount);

        srand(time(NULL));
        //The last door in doorVec is The door to the box where the ghosts are enclosed at the start.
        int RandomNum1=rand()%(DoorVec.size()-2);
        int RandomNum2=rand()%(DoorVec.size()-2);
        DoorVec.erase(begin(DoorVec)+RandomNum1);
        DoorVec.erase(begin(DoorVec)+RandomNum2);

    }

}


void PlayerCollisions::playerAndDoors(Player& currentPlayer,VectorOfDoorStructs& DoorVec)
{
    auto CurrentBox = currentPlayer.ObjectContainer();
    float height=5;
    float width=37;
    BoundingBox doorBox;
    bool DoorCollisionHorizontal=false;
    bool DoorCollisionVertical=false;
    int DoorCount=0;

    for(auto door : DoorVec)
    {
        doorBox.xTopLeft=door.x_coord;
        doorBox.yTopLeft=door.y_coord;

        if(door.orientation=='h')
        {
            doorBox.BoxLength=width;
            doorBox.BoxHeight=height;

            DoorCollisionHorizontal=Intersects(CurrentBox,doorBox);
            if(DoorCollisionHorizontal)
            {
                break;
            }

        }
        if(door.orientation=='v')
        {

            doorBox.BoxLength=height;
            doorBox.BoxHeight=width;
            DoorCollisionVertical=Intersects(CurrentBox,doorBox);

            if(DoorCollisionVertical)
            {
                break;
            }
        }
        DoorCount++;
    }
    if(DoorCollisionHorizontal) {HandleWallCollison(doorBox,CurrentBox,currentPlayer);}
    if(DoorCollisionVertical) {HandleWallCollison(doorBox,CurrentBox,currentPlayer);}

}

void PlayerCollisions::playerVsFood(Player& currentPlayer,TuplePositionVecctor& FoodBoxes)
{
    auto CurrentBox = currentPlayer.ObjectContainer();
    float height=27;
    float width=25;

    BoundingBox FoodBox;
    FoodBox.BoxLength=width;
    FoodBox.BoxHeight=height;
    int elementCounter=0;
    bool result=false;


    for(auto food : FoodBoxes)
    {
        FoodBox.xTopLeft=std::get<0>(food);
        FoodBox.yTopLeft=std::get<1>(food);
        result=Intersects(CurrentBox,FoodBox);
        if(result)
        {
            break;
        }
        elementCounter++;
    }

    if(result)
    {
        FoodBoxes.erase(begin(FoodBoxes)+elementCounter);
    }

}

void PlayerCollisions::playerAndPellets(Player& currentPlayer,VectorOfPelletStructs& pelletVec)
{
    auto CurrentBox = currentPlayer.ObjectContainer();
    float  superPelletLength=28;
    float superPelletHeight=29;
    float  normalPelletLength=24;
    float normalPelletHeight=21;
    BoundingBox pelletBox;
    bool NormalPelletCollision=false;
    bool SuperPelletCollision=false;
    int PelletCount=0;

    for(auto pellet : pelletVec)
    {


        if(pellet.PelletType=='n')
        {
            pelletBox.xTopLeft=pellet.x_coord;
            pelletBox.yTopLeft=pellet.y_coord;
            pelletBox.BoxLength=normalPelletLength;
            pelletBox.BoxHeight=normalPelletHeight;

            NormalPelletCollision=Intersects(CurrentBox,pelletBox);

            if(NormalPelletCollision)
            {
                break;
            }

        }
        if(pellet.PelletType=='s')
        {

            pelletBox.xTopLeft=pellet.x_coord;
            pelletBox.yTopLeft=pellet.y_coord;
            pelletBox.BoxLength=superPelletLength;
            pelletBox.BoxHeight=superPelletHeight;
            SuperPelletCollision=Intersects(CurrentBox,pelletBox);

            if(SuperPelletCollision)
            {
                break;
            }
        }
        PelletCount++;
    }
    if(NormalPelletCollision)
    {
        pelletVec.erase(begin(pelletVec)+PelletCount);
    }
    if(SuperPelletCollision)
    {
        pelletVec.erase(begin(pelletVec)+PelletCount);
    }

}


//Check collision between any two bounding boxes
bool PlayerCollisions::Intersects(BoundingBox& Box1,BoundingBox& Box2) ///collision between bounding boxes, works fine
{
    if((Box1.xTopLeft<=(Box2.xTopLeft+Box2.BoxLength)) && ((Box1.xTopLeft+Box1.BoxLength)>=Box2.xTopLeft) &&
            (Box1.yTopLeft<=(Box2.yTopLeft+Box2.BoxHeight)) && ((Box1.yTopLeft+Box1.BoxHeight)>=Box2.yTopLeft))
    {
        return true;
    }
    return false;
}

void PlayerCollisions::HandleWallCollison(BoundingBox& MazeBox,BoundingBox& ObjectBox,Player& PacMan)
{
    auto [x,y]=PacMan.getEntityPosition();
    ///The Objects operated on in this function have already collided
    auto MazeLeftXBoundary=MazeBox.xTopLeft;
    auto MazeRightXBoundary=MazeLeftXBoundary+MazeBox.BoxLength;
    auto MazeTopYBoundary=MazeBox.yTopLeft;
    auto MazeBottomYBoundary=MazeTopYBoundary+MazeBox.BoxHeight;

    auto ObjectLeftXBoundary=ObjectBox.xTopLeft;
    auto ObjectRightXBoundary=ObjectLeftXBoundary+ObjectBox.BoxLength;
    auto ObjectTopYBoundary=ObjectBox.yTopLeft;
    auto ObjectBottomYBoundary=ObjectTopYBoundary+ObjectBox.BoxHeight;

    auto PlayerOrientation=PacMan.getEntityMoveDirection();

    auto RepositioningValue=15; ///The value used to undo the y or x value of the collision


    //Boundaries & orientation
    if(MazeRightXBoundary>=ObjectLeftXBoundary && PlayerOrientation==Orientation::FACE_LEFT)
    {  //counter the motion of player/Movable Object to the Left
       PacMan.setEntityPosition(MazeRightXBoundary+RepositioningValue,y);
    }
    if(MazeLeftXBoundary<=ObjectRightXBoundary && PlayerOrientation==Orientation::FACE_RIGHT)
    {   //Stop the player/movable Object from moving to the Right,past the boundary
        PacMan.setEntityPosition(MazeLeftXBoundary-RepositioningValue,y);
    }
    if(MazeTopYBoundary<=ObjectBottomYBoundary && PlayerOrientation==Orientation::FACE_DOWN)
    {   //Top to Bottom
        PacMan.setEntityPosition(x,MazeTopYBoundary-RepositioningValue);
    }
    if(MazeBottomYBoundary>=ObjectTopYBoundary && PlayerOrientation==Orientation::FACE_UP)
    {   //Bottom to Top
        PacMan.setEntityPosition(x,MazeBottomYBoundary+RepositioningValue);
    }

}
PlayerCollisions::~PlayerCollisions()
{

}
