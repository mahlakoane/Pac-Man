#ifndef PELLETS_H
#define PELLETS_H
#include "Maze.h"
#include <vector>
#include "MazeEntity.h"
#include "GeneralGameEntity.h"

struct PelletProperties{
float x_coord;
float y_coord;
char PelletType;
};


class Pellets : public MazeEntity, public GeneralGameEntity <std::vector<PelletProperties>>
{
    public:
        Pellets();
        virtual void ReadEntityFromFile() override;
        virtual std::vector<PelletProperties> ObjectContainer() const override;
        virtual ~Pellets();

    private:
        PelletProperties CurrentPellet;
        std::vector<PelletProperties>pelletVec;

};

#endif // PELLETS_H
