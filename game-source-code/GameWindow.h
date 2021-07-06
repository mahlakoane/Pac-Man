#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "MazeKeys.h"
#include "LogicDoor.h"
#include "MazeFood.h"
#include "MazeWalls.h"

/** \class GameWindow
*  \brief This is a game window handler and it is responsible for
*drawing game objects to the screen.
*  \authors Tshepo Chokoe (1705890) and Bohlale Mahlakoane (1352926)
*/

class GameWindow
{
    public:

        /** \brief Parameterized GameWindow constructor. This method
        *initializes the member variable window_ to a RenderWindow that
        *being passed in to the function.
        *   \param window of type sf::RenderWindow
        */

        GameWindow(sf::RenderWindow& window);

        /** \brief Draws maze walls on the screen
        *   \param WallsObj of type MazeWalls
        */
        void drawMazeWalls(MazeWalls& WallsObj);

        /** \brief Draws maze doors on the screen
        *   \param DoorsObject of type LogicDoor
        */
        void drawDoors(LogicDoor& DoorsObject);

        /** \brief Draws maze food on the screen
        *   \param FoodObj of type MazeFood
        */
        void drawFoods(MazeFood& FoodsObj);

        /** \brief Draws maze keys on the screen
        *   \param KeysObj of type MazeKeys
        */
        void drawKeys(MazeKeys& KeysObj);

        /** \brief Destructor
        */
        ~GameWindow();


    private:
       sf::RenderWindow& window_;
       sf::Texture texture;
};

#endif // GAMEWINDOW_H
