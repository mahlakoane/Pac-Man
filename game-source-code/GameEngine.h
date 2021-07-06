#ifndef GAMEENGINE_H
#define GAMEENGINE_H
#include <iostream>
#include <SFML\Graphics.hpp>
#include "Player.h"
#include "Orientation.h"
#include "ScreenModes.h"
#include "GameWindow.h"
#include "Ghost.h"
#include <memory>
#include "MazeWalls.h"
#include "MazeKeys.h"

using namespace sf;
using width_and_height = std::tuple<float, float>; /**< Tuple to store width and height of a game object */

/** \class GameEngine
* \brief This class is the main class that is responsible for
*running the game as a whole. This is where the textures of the
*of the game objects are loaded. Moreover, all the game objects
*used for the game are defined within this class together with
*the handling of the user input.
* \authors Tshepo Chokoe (1705890) and Bohlale Mahlakoane (1352926)
*/

class GameEngine
{
    public:

        /**Default empty constructor
        */
        GameEngine();

        /** \brief This method calculates the width and height of
        *of Pac-Man texture read from a sprite sheet.
        *   \param pacmanTexture texture of type Texture
        *   \return A tuple that contains the width and height of
        *Pac-Man
        */
        width_and_height setUpPacmanSprite(Texture pacmanTexture);

        /** \brief This method sets the orientation of Pac-Man with
        *respect to the user input.
        *   \param Pac-Man Sprite object
        *   \param orientation of type Orientation enum
        */
        void setOrientation(Sprite& pacman, Orientation& orientation);

        /** \brief This method updates the position of Pac-Man sprite
        *as the player object is being moved around the maze. It calls
        *the moveEntity() function which enables Pac-Man to move.
        *   \param orientation of type Orientation enum
        *   \param player object of type Player
        *   \param pacman Sprite object
        */
        void updatePacmanSprite (Orientation orientation, Player& player, Sprite& pacman);

        /** \brief This method is responsible for the translation of player
        *input. It moves Pac-Man in the direction corresponding to the key
        *pressed.
        *   \param player object of type Player
        *   \param pacman Sprite object
        */
        void pacmanMovement(Player& player, Sprite& pacman);

        /** \brief This method moves the ghosts throughout the maze while
        *chasing Psc-Man. It also invokes the moveEntitty() function to
        *enable ghost movement. However, the movement direction is first
        *set by calling the getEntityMoveDirection() method.
        *   \param ghost object of type Ghost
        *   \param blinky Sprite object
        */
        void ghostMovement(Ghost& ghost, Sprite& blinky);

        /** \brief As the name implies, this is the main function that implements
        *the game loop. All objects of the game are defined within this function
        *along with texture loading of the sprites. Splash screen and the game over
        *screen showing the outcome of the game are implemented by this method.
        */
        void PlayGame();

        /** \brief Destructor
        */
        ~GameEngine();

    private:
};

#endif // GAMEENGINE_H
