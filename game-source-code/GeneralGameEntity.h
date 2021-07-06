#ifndef GENERALGAMEENTITY_H
#define GENERALGAMEENTITY_H
#include <tuple>
///General functionality expected from all game objects
///are captured through this class.


using x_and_y = std::tuple<float, float>; /**< Tuple for storing position */
using length_and_breadth = std::tuple<float, float>; /**< Tuple to store length and breadth of a game object */

/** \struct This structure models a bounding box of a game
*entity by storing its top left co-ordinate together with
*length and height of the game object
* \authors Tshepo Chokoe (1705890) and Bohlale Mahlakoane (1352926)
*/
struct BoundingBox{
    float xTopLeft;
    float yTopLeft;
    float BoxLength;
    float BoxHeight;
};

template <typename ArbitraryType> /**< Placeholder for an arbitrary return type that can be used by a derived class */

/** \class This class is the main class that all game entities
*inherit from.
*/
class GeneralGameEntity
{
    public:

        /** \brief Default empty constructor
        */
        GeneralGameEntity() {}

        /** \brief This is a pure virtual function that has no
        *implementation.
        */
        virtual ArbitraryType ObjectContainer() const=0;

        /** \brief Destructor
        */
        ~GeneralGameEntity() {}

    private:
};

#endif // GENERALGAMEENTITY_H
