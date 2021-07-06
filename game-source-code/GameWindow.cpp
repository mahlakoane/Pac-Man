#include "GameWindow.h"

using namespace std;
GameWindow::GameWindow(sf::RenderWindow& window):window_{window}
{

}

void GameWindow::drawMazeWalls(MazeWalls& WallsObj)
{
    auto currMaze=WallsObj.ReturnMazeWalls();
    auto WallThickness=WallsObj.returnWallThickness();

    for(auto wall : currMaze) ///deal with maze walls
    {
        if(wall.Orientation=='v')
        {
            sf::RectangleShape rect(sf::Vector2f(WallThickness,wall.length));
            rect.setPosition(sf::Vector2f(wall.x_coord,wall.y_coord));
            window_.draw(rect);

        }
        else if(wall.Orientation=='h')
        {
            sf::RectangleShape rect(sf::Vector2f(wall.length,WallThickness));
            rect.setPosition(sf::Vector2f(wall.x_coord,wall.y_coord));
            window_.draw(rect);

        }

    }

}


void GameWindow::drawDoors(LogicDoor& DoorsObject)
{
///deal with doors
    auto doorVec=DoorsObject.getDoorsVector();
    auto [length,thickness]=DoorsObject.getDimensionsIntoPresentationLayer();
    auto R=100;
    auto G=250;
    auto B=50;

    for(auto door : doorVec)
    {
        if(door.orientation=='v')
        {
            sf::RectangleShape currentDoor(sf::Vector2f(thickness,length));
            currentDoor.setPosition(sf::Vector2f(door.x_coord,door.y_coord));
            currentDoor.setFillColor(sf::Color(R,G,B));
            window_.draw(currentDoor);

        }
        else if(door.orientation=='h')
        {
            sf::RectangleShape currentDoor(sf::Vector2f(length,thickness));
            currentDoor.setPosition(sf::Vector2f(door.x_coord,door.y_coord));
            currentDoor.setFillColor(sf::Color(R,G,B));
            window_.draw(currentDoor);

        }

    }
}

void GameWindow::drawFoods(MazeFood& FoodsObj)
{
    auto FoodVector=FoodsObj.ReturnFoodsToPresentationLayer();
    auto [width,height]=FoodsObj.getDimensionsIntoPresentationLayer();

    for(auto foodItem : FoodVector)
    {

        if(!texture.loadFromFile("Resources/food.png")) {}
        sf::RectangleShape FoodsRect(sf::Vector2f(width,height));
        FoodsRect.setTexture(&texture);
        FoodsRect.setPosition(sf::Vector2f(get<0>(foodItem),get<1>(foodItem)));
        window_.draw(FoodsRect);


    }

}

void GameWindow::drawKeys(MazeKeys& KeysObj)
{
    auto KeysVec=KeysObj.ReturnKeyVecToPresentationLayer();
    auto [width,height]=KeysObj.getDimensionsIntoPresentationLayer();

    for(auto nthKey : KeysVec)
    {
        if(!texture.loadFromFile("Resources/key.png"))
        {
            break;
        }
        sf::RectangleShape KeyRect(sf::Vector2f(width,height));
        KeyRect.setTexture(&texture);
        KeyRect.setPosition(sf::Vector2f(get<0>(nthKey),get<1>(nthKey)));
        window_.draw(KeyRect);
    }


}

GameWindow::~GameWindow()
{

}
