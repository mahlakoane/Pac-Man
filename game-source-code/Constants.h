#ifndef CONSTANTS_H
#define CONSTANTS_H

/** \class Constants
* \brief This class stores all constant variables that are used
* by other classes.
* \authors Tshepo Chokoe (1705890) and Bohlale Mahlakoane (1352926)
*/

class Constants
{
public:

    const static constexpr auto SCREEN_WIDTH = 900.0f;
    const static constexpr auto SCREEN_HEIGHT = 700.0f;

    const static constexpr float MOVING_OBJECT_WIDTH = 28.0f;
    const static constexpr float MOVING_OBJECT_HEIGHT = 28.0f;

    //top left co-ordinate of the maze relative to the screen
    const static constexpr auto MAZE_X_OFFSET = 189;
    const static constexpr auto MAZE_Y_OFFSET = 100;

    const static constexpr auto MAZE_X_BOTTOM_RIGHT = 711;
    const static constexpr auto MAZE_Y_BOTTOM_RIGHT = 665;

    const static constexpr float MOVEMENT_STEP = 1.0f;

    //the center of the player is the default origin
    const static constexpr float MOVING_OBJECT_X_ORIGIN = MOVING_OBJECT_WIDTH / 2; //14
    const static constexpr float MOVING_OBJECT_Y_ORIGIN = MOVING_OBJECT_WIDTH / 2; //14

    const static constexpr float REFRESH_FRAME_RATE = 0.16f;

    //These are calculated using the current screen size
    ///Fix these edges so the pacMan respects the edges of the maze

    const static constexpr auto MAZE_WALL_THICKNESS = 10; //10 pixels

    const static constexpr auto LEFT_EDGE = MAZE_X_OFFSET + MOVING_OBJECT_X_ORIGIN + MAZE_WALL_THICKNESS;
    const static constexpr auto RIGHT_EDGE = MAZE_X_BOTTOM_RIGHT - MOVING_OBJECT_X_ORIGIN - MAZE_WALL_THICKNESS;
    const static constexpr auto TOP_EDGE = MAZE_Y_OFFSET + MOVING_OBJECT_Y_ORIGIN + MAZE_WALL_THICKNESS;
    const static constexpr auto BOTTOM_EDGE = MAZE_Y_BOTTOM_RIGHT - MOVING_OBJECT_Y_ORIGIN - MAZE_WALL_THICKNESS;

    //for pacMan spritesheet
    const static constexpr auto PACMAN_SPRITESHEET_ROWS = 1;
    const static constexpr auto PACMMAN_SPRITESHEET_COLS = 5;

    //for ghost sprite sheet
    const static constexpr auto GHOST_SPRITESHEET_ROWS = 2;
    const static constexpr auto GHOST_SPRITESHEET_COLS = 2;

    const static constexpr auto Y_START_POS_OFFSET = 10;
    const static constexpr auto X_START_POS_OFFSET = 50;

    //player initial position
    const static constexpr auto PLAYER_START_XPOS = (SCREEN_WIDTH / 2) + X_START_POS_OFFSET;
    const static constexpr auto PLAYER_START_YPOS = (SCREEN_HEIGHT / 2) + Y_START_POS_OFFSET;

    //ghosts initial position
    const static constexpr auto INKY_START_XPOS = SCREEN_WIDTH / 2;
    const static constexpr auto INKY_START_YPOS = SCREEN_HEIGHT / 2 - 68;

    const static constexpr auto PINKY_START_XPOS = SCREEN_WIDTH / 2;
    const static constexpr auto PINKY_START_YPOS = SCREEN_HEIGHT / 2 - 58;

    const static constexpr auto CLYDE_START_XPOS = SCREEN_WIDTH / 2;
    const static constexpr auto CLYDE_START_YPOS = SCREEN_HEIGHT / 2 - 48;

    const static constexpr auto BLINKY_START_XPOS = SCREEN_WIDTH / 2;
    const static constexpr auto BLINKY_START_YPOS = ((SCREEN_HEIGHT / 2) - 38); //-135 before

    //Grid dimensions
    const static constexpr auto Row = 25;
    const static constexpr auto Col = 24;

};
#endif // CONSANTS_H
