#ifndef MAZEKEYS_H
#define MAZEKEYS_H

#include "Keys.h"
#include "Mazedoors.h"
#include "MovableEntity.h"
#include "Player.h"
#include "HelperClass.h"

/** \class MazeKeys
* \brief This is a game object class that models the behavior of the key
*entities.
* \authors Tshepo Chokoe (1705890) and Bohlale Mahlakoane (1352926)
*/
class MazeKeys
{
    public:

        /** \brief This is a parameterized constructor. Initializes the member variables
        *of the class
        *   \param KeyDataObject of type keys
        */
        MazeKeys(Keys& KeyDataObject);

        /** \brief This is a boolean method that returns true if player object has collided
        *with a key so that a key is erased and two doors are unlocked.
        *   \param Moving object of type Player
        *   \return bool
        */
        bool DisappearAndUnlockDoor(Player& MovingObject);

        /** \brief This method return a vector that contain the positions
        *of all the key entities
        *   \return vector
        */
        VectorOfPositions ReturnKeyVecToPresentationLayer() const;

        /** \brief This method returns the dimensions of the key entities
        *and feeds them to the presentation layer
        *   \return x_and_y, width and height of a key entity
        */
        x_and_y getDimensionsIntoPresentationLayer() const;

        /** \brief Destructor
        */
        ~MazeKeys();

    private:
        Keys KeyData_;
        VectorOfPositions KeyPositions_;
        const float KeyHeight_=27;
        const float KeyWidth_=21;
        HelperClass KeyCollisionChecker_;
        void OpenDoors();  // Can never be public, that is giving access to opening doors.



};

#endif // MAZEKEYS_H
