#ifndef KEYS_H
#define KEYS_H
#include <iostream>
#include <vector>
#include <tuple>
#include "MazeEntity.h"
#include "GeneralGameEntity.h"

using x_and_y = std::tuple<float, float>;
using VectorOfPositions=std::vector<x_and_y>;

/** \class Keys
* \brief This class inherits from MazeEntity and GeneralGameEntity class. It
*model the behavior of the key game entity
* \authors Tshepo Chokoe (1705890) and Bohlale Mahlakoane (1352926)
*/

class Keys : public MazeEntity, public GeneralGameEntity<VectorOfPositions>
{
    public:

        /** \brief Default empty constructor
        */
        Keys();

        /** \brief This method is inherited from MazeEntity interface and
        *it reads the positions of the key entities from a file
        */
        virtual void ReadEntityFromFile() override;

        /** \brief This method returns a vector that has the positions
        *of all the key entities of the game
        *   \return vector of key entity positions
        */
        virtual VectorOfPositions ObjectContainer() const override;

        /** \brief Destructor
        */
        ~Keys();

    private:
        VectorOfPositions KeyVec;
};

#endif // KEYS_H
