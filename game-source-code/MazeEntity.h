#ifndef MAZEENTITY_H
#define MAZEENTITY_H

/** \class MazeEntity
* \brief This class is base class for Key, Maze and Door game as they inherit
*this interface. This class provides the functionality of reading the game entities
*from text file.
* \authors Tshepo Chokoe (1705890) and Bohlale Mahlakoane (1352926)
*/

///This has the role of capturing the common functionality of the maze
///objects read from files
class MazeEntity
{
    public:

        /** \brief Default empty constructor
        */
        MazeEntity() {}

        /** \brief Pure virtual function to read a game entity from a file
        */
        virtual void ReadEntityFromFile()=0;

        /** \brief Destructor
        */
        ~MazeEntity() {}

    private:
};

#endif // MAZEENTITY_H
