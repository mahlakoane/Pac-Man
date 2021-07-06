#include "../game-source-code/Player.h"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>

//Test cases for the player object
TEST_CASE("The initial orientation of the player is correct")
{
    auto player = Player{Orientation::FACE_RIGHT};
    auto playerOrientation = player.getEntityMoveDirection();

    CHECK(playerOrientation == Orientation::FACE_RIGHT);
}

TEST_CASE("The initial position of the player is correct")
{
    auto player = Player{Orientation::FACE_RIGHT};
    auto [x_initialPos, y_initialPos] = player.getEntityPosition();

    CHECK(x_initialPos == Constants::PLAYER_START_XPOS);
    CHECK(y_initialPos == Constants::PLAYER_START_YPOS);
}

TEST_CASE ("Player does not go over the left edge")
{
    auto player = Player{Orientation::FACE_RIGHT};

    auto leftEdge = Constants::LEFT_EDGE;
    auto playerDir = Orientation::FACE_LEFT;

    for(unsigned int i = 0; i < 250; i++)
    {
        player.setEntityMoveDirection(playerDir);
        player.moveEntity();
        //player.isEntityInsideTheMaze();
    }

    auto [new_xPos, new_yPos] = player.getEntityPosition();

    CHECK(new_xPos >= leftEdge);
}

TEST_CASE("Player does not go over the left edge")
{
    auto player = Player{Orientation::FACE_RIGHT};
    auto leftEdge = Constants::LEFT_EDGE;
    auto playerDir = Orientation::FACE_LEFT;

    for(unsigned int i = 0; i < 250; i++)
    {
        player.setEntityMoveDirection(playerDir);
        player.moveEntity();
        //player.isEntityInsideTheMaze();
    }

    auto [new_xPos, new_yPos] = player.getEntityPosition();

    CHECK(new_xPos >= leftEdge);
}

TEST_CASE("Player does not go over the right edge")
{
    auto player = Player{Orientation::FACE_RIGHT};
    auto rightEdge = Constants::RIGHT_EDGE;
    auto playerDir = Orientation::FACE_RIGHT;

    for(unsigned int i = 0; i < 150; i++)
    {
        player.setEntityMoveDirection(playerDir);
        player.moveEntity();
        //player.isEntityInsideTheMaze();
    }

    auto [new_xPos, new_yPos] = player.getEntityPosition();

    CHECK(new_xPos <= rightEdge);
}

TEST_CASE("Player does not go over the top edge")
{
    auto player = Player{Orientation::FACE_RIGHT};
    auto topEdge = Constants::TOP_EDGE;
    auto playerDir = Orientation::FACE_UP;

    for(unsigned int i = 0; i < 100; i++)
    {
        player.setEntityMoveDirection(playerDir);
        player.moveEntity();
        //player.isEntityInsideTheMaze();
    }

    auto [new_xPos, new_yPos] = player.getEntityPosition();

    CHECK(new_yPos >= topEdge);
}

TEST_CASE("Player does not go over the bottom edge")
{
    auto player = Player{Orientation::FACE_RIGHT};
    auto bottomEdge = Constants::BOTTOM_EDGE;
    auto playerDir = Orientation::FACE_DOWN;

    for(unsigned int i = 0; i < 100; i++)
    {
        player.setEntityMoveDirection(playerDir);
        player.moveEntity();
        //player.isEntityInsideTheMaze();
    }

    auto [new_xPos, new_yPos] = player.getEntityPosition();

    CHECK(new_yPos <= bottomEdge);
}



