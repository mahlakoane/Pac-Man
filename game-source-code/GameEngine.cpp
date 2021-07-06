#include "GameEngine.h"

GameEngine::GameEngine()
{
    //ctor
}

width_and_height GameEngine::setUpPacmanSprite(Texture pacmanTexture)
{
    //get the size of pacman texture
    auto [x_pacManTextureSize,y_pacManTextureSize]= pacmanTexture.getSize();

    //get the width and height of each Pac-Man figure to have
    //size of one Pac-Man figure
    float PacMan_Width = x_pacManTextureSize /= Constants::PACMMAN_SPRITESHEET_COLS;
    float PacMan_Height = y_pacManTextureSize /= Constants::PACMAN_SPRITESHEET_ROWS;

    return {PacMan_Width, PacMan_Height};
}
void GameEngine::setOrientation(Sprite& pacman, Orientation& orientation)
{
    switch(orientation)
    {

    case Orientation::FACE_LEFT:
        pacman.setRotation(180);
        break;
    case Orientation::FACE_RIGHT:
        pacman.setRotation(0);
        break;
    case Orientation::FACE_UP:
        pacman.setRotation(270);
        break;
    case Orientation::FACE_DOWN:
        pacman.setRotation(90);
        break;
    default:
        break;
    }

}
void GameEngine::updatePacmanSprite (Orientation orientation, Player& player, Sprite& pacman)
{
    player.setEntityMoveDirection(orientation);
    setOrientation(pacman, orientation);
    player.moveEntity();

    auto newPlayerPos = player.getEntityPosition();

    auto x_newPlayerPos = std::get<0>(newPlayerPos);
    auto y_newPlayerPos = std::get<1>(newPlayerPos);

    pacman.setPosition(x_newPlayerPos, y_newPlayerPos);

}
void GameEngine::pacmanMovement(Player& player, Sprite& pacman)
{
  if(Keyboard::isKeyPressed(Keyboard::Key::Up))
    {
        auto pacmanOrientation = Orientation::FACE_UP;
        updatePacmanSprite(pacmanOrientation, player, pacman);
    }
    else if(Keyboard::isKeyPressed(Keyboard::Key::Down))
    {
        auto pacmanOrientation = Orientation::FACE_DOWN;
        updatePacmanSprite(pacmanOrientation, player, pacman);
    }
    else if(Keyboard::isKeyPressed(Keyboard::Key::Right))
    {
        auto pacmanOrientation = Orientation::FACE_RIGHT;
        updatePacmanSprite(pacmanOrientation, player, pacman);
    }
    else if (Keyboard::isKeyPressed(Keyboard::Key::Left))
    {
        auto pacmanOrientation = Orientation::FACE_LEFT;
        updatePacmanSprite(pacmanOrientation, player, pacman);
    }
}
void GameEngine::ghostMovement(Ghost& ghost, Sprite& blinky)
{
    auto initialDir = ghost.getEntityMoveDirection();
    ghost.setEntityMoveDirection(initialDir);
    ghost.moveEntity();

    auto [x_newGhostPos, y_newGhostPos] = ghost.getEntityPosition();
    blinky.setPosition(x_newGhostPos, y_newGhostPos);
}

void GameEngine::PlayGame()
{
    auto screenWidth = Constants::SCREEN_WIDTH;
    auto screenHeight = Constants::SCREEN_HEIGHT;

    auto screenMode = ScreenModes::SPLASH_SCREEN;

    auto player = Player{Orientation::FACE_RIGHT};
    float InkyX=Constants::INKY_START_XPOS;
    float InkyY=Constants::INKY_START_YPOS;
    float BlinkyX=Constants::BLINKY_START_XPOS;
    float BlinkyY=Constants::BLINKY_START_YPOS;
    float PinkyX=Constants::PINKY_START_XPOS;
    float PinkyY=Constants::PINKY_START_YPOS;
    float ClydeX=Constants::CLYDE_START_XPOS;
    float ClydeY= Constants::CLYDE_START_YPOS;



    //declaration of ghost objects
    const float BlinkyMovementStep=1.0;
    const float PinkyMovementStep=0.85;
    const float ClydeMovementStep=0.75;
    const float InkyMovementStep=0.5;

    auto Blinky = Ghost{BlinkyX,BlinkyY,BlinkyMovementStep};
    auto Inky = Ghost{InkyX,InkyY,InkyMovementStep};
    auto Pinky = Ghost{PinkyX,PinkyY,PinkyMovementStep};
    auto Clyde = Ghost{ClydeX,ClydeY,ClydeMovementStep};


    auto initial_direction=Orientation::FACE_UP;
    Inky.setEntityMoveDirection(initial_direction);
    Blinky.setEntityMoveDirection(initial_direction);
    Pinky.setEntityMoveDirection(initial_direction);
    Clyde.setEntityMoveDirection(initial_direction);

    RenderWindow window(VideoMode(screenWidth, screenHeight), "Super Pac-Man");
    window.setFramerateLimit(120);  /// Avoiding adaptive refresh rates.

    //Data Access Objects
    auto KeyObject=Keys{};
    auto FoodObject=Food{};
    auto FoodVec=FoodObject.ObjectContainer();
    auto MazeWallsObject=Maze{};
    auto DoorsObject=Mazedoors{};


    //Logic Layer Objects
    MazeWalls Walls{MazeWallsObject};
    MazeKeys GameKeys{KeyObject};
    LogicDoor GameDoors{DoorsObject};
    MazeFood GameFoods{FoodObject};


    auto WallsPtr=std::make_shared<MazeWalls>(Walls);

    auto CurrentGame = GameWindow{window};
    auto KeepEntityInsideMaze=HelperClass{};

    RectangleShape splashScreen(Vector2f(screenWidth, screenHeight));
    RectangleShape gameScreen(Vector2f(screenWidth, screenHeight));
    RectangleShape winnerScreen(Vector2f(screenWidth, screenHeight));
    RectangleShape loserScreen(Vector2f(screenWidth, screenHeight));

    //loading textures
    Texture splashScreenTexture;
    if(!splashScreenTexture.loadFromFile("Resources/SplashScreen.png")) {}
    splashScreen.setTexture(&splashScreenTexture);

    Texture winnerScreenTexture;
    if(!winnerScreenTexture.loadFromFile("Resources/WinnerScreen.png")) {}
    winnerScreen.setTexture(&winnerScreenTexture);

    Texture loserScreenTexture;
    if(!loserScreenTexture.loadFromFile("Resources/LoserScreen.png")) {}
    loserScreen.setTexture(&loserScreenTexture);

    Texture pacmanTexture;
    if(!pacmanTexture.loadFromFile("Resources/pacmansprites.png")) {}

    Texture blinkyTexture;
    if(!blinkyTexture.loadFromFile("Resources/blinky.png")) {}

    Texture pinkyTexture;
    if(!pinkyTexture.loadFromFile("Resources/pinky.png")) {}

    Texture inkyTexture;
    if(!inkyTexture.loadFromFile("Resources/inky.png")) {}

    Texture clydeTexture;
    if(!clydeTexture.loadFromFile("Resources/clyde.png")) {}

    auto [PacMan_Width, PacMan_Height] = setUpPacmanSprite(pacmanTexture);

    //get the uv co-ordinates of the texture
    //IntRect has x and y offset, also the pacman width and height (index start from 0)
    //we choose where we want to access our sprite sheet using uv co-ordinates
    IntRect rectPlayerSprite(PacMan_Width * 3, PacMan_Height * 0, PacMan_Width, PacMan_Height);
    Sprite pacman(pacmanTexture, rectPlayerSprite);

    //loading textures into sprite objects
    Sprite blinkySprite;
    blinkySprite.setTexture(blinkyTexture);

    Sprite pinkySprite;
    pinkySprite.setTexture(pinkyTexture);

    Sprite inkySprite;
    inkySprite.setTexture(inkyTexture);

    Sprite clydeSprite;
    clydeSprite.setTexture(clydeTexture);

    pacman.setOrigin(Constants::MOVING_OBJECT_X_ORIGIN, Constants::MOVING_OBJECT_Y_ORIGIN);
    pacman.setPosition(Constants::PLAYER_START_XPOS, Constants::PLAYER_START_YPOS);

    inkySprite.setOrigin(Constants::MOVING_OBJECT_X_ORIGIN, Constants::MOVING_OBJECT_Y_ORIGIN);
    inkySprite.setPosition(Constants::INKY_START_XPOS, Constants::INKY_START_YPOS);

    blinkySprite.setOrigin(Constants::MOVING_OBJECT_X_ORIGIN, Constants::MOVING_OBJECT_Y_ORIGIN);
    blinkySprite.setPosition(Constants::BLINKY_START_XPOS, Constants::BLINKY_START_YPOS);

    pinkySprite.setOrigin(Constants::MOVING_OBJECT_X_ORIGIN, Constants::MOVING_OBJECT_Y_ORIGIN);
    pinkySprite.setPosition(Constants::PINKY_START_XPOS, Constants::PINKY_START_YPOS);

    clydeSprite.setOrigin(Constants::MOVING_OBJECT_X_ORIGIN, Constants::MOVING_OBJECT_Y_ORIGIN);
    clydeSprite.setPosition(Constants::CLYDE_START_XPOS, Constants::CLYDE_START_YPOS);

    Clock clock; //for animation

    while(window.isOpen())
    {
        Event evnt;
        window.clear();

        while(window.pollEvent(evnt))
        {
            if(evnt.type == evnt.Closed)
                window.close();
            else if(evnt.type == Event::KeyPressed)
            {
                if(screenMode == ScreenModes::SPLASH_SCREEN && Keyboard::isKeyPressed(Keyboard::Enter))
                    screenMode = ScreenModes::PLAY_SCREEN;
            }
        }

        if (screenMode == ScreenModes::SPLASH_SCREEN)
        {
            window.clear(Color::Black);
            window.draw(splashScreen);
        }
        else if(screenMode==ScreenModes::GAMEOVER_WIN)
            {
               window.clear(Color::Black);
               window.draw(winnerScreen);
            }
        else if (screenMode==ScreenModes::GAMEOVER_LOSE)
            {
               window.clear(Color::Black);
               window.draw(loserScreen);

            }
        else if (screenMode == ScreenModes::PLAY_SCREEN)
        {
            window.clear(Color::Black);


            //animation
            if(clock.getElapsedTime().asSeconds() > Constants::REFRESH_FRAME_RATE)
            {
                if(rectPlayerSprite.left == (PacMan_Width * 4))
                    rectPlayerSprite.left = (PacMan_Width * 3);
                else
                    rectPlayerSprite.left += PacMan_Width;

                pacman.setTextureRect(rectPlayerSprite);
                clock.restart();
            }

            //update Any objects
            Blinky.updatePlayer(player);
            Blinky.UpdateWall(WallsPtr);
            Inky.updatePlayer(player);
            Inky.UpdateWall(WallsPtr);
            Pinky.updatePlayer(player);
            Pinky.UpdateWall(WallsPtr);
            Clyde.updatePlayer(player);
            Clyde.UpdateWall(WallsPtr);

            //Draw MovableObject Sprites
            window.draw(pacman);
            window.draw(inkySprite);
            window.draw(pinkySprite);
            window.draw(blinkySprite);
            window.draw(clydeSprite);
            //draw Maze Objects
            CurrentGame.drawMazeWalls(Walls);
            CurrentGame.drawKeys(GameKeys);
            CurrentGame.drawFoods(GameFoods);
            CurrentGame.drawDoors(GameDoors);


            //Move Ghosts
            ghostMovement(Blinky,blinkySprite);
            ghostMovement(Inky,inkySprite);
            ghostMovement(Pinky,pinkySprite);
            ghostMovement(Clyde,clydeSprite);
            KeepEntityInsideMaze.isEntityInsideTheMaze(Blinky);
            KeepEntityInsideMaze.isEntityInsideTheMaze(Pinky);
            KeepEntityInsideMaze.isEntityInsideTheMaze(Inky);
            KeepEntityInsideMaze.isEntityInsideTheMaze(Clyde);

            pacmanMovement(player, pacman);
            KeepEntityInsideMaze.isEntityInsideTheMaze(player);

            //Game Logic

            auto PlayerWallCollision=Walls.CheckEntityCollisionIntoWall(player);
            auto GameDoorCollision=GameDoors.BlockEntityFromPassing(player); //Player is a movable entity


            GameFoods.DisappearOnPlayerCollision(player);
            if(GameKeys.DisappearAndUnlockDoor(player))// When any game key comes into contact with player/pacman
            {GameDoors.OpenDoors();}


            Blinky.GhostBehaviourAtBoundary(Blinky,GameDoors);
            Inky.GhostBehaviourAtBoundary(Inky,GameDoors);
            Pinky.GhostBehaviourAtBoundary(Pinky,GameDoors);
            Clyde.GhostBehaviourAtBoundary(Clyde,GameDoors);


            if(player.CollisionOfPlayerAndGhost(Blinky,player) || player.CollisionOfPlayerAndGhost(Pinky,player) ||
               player.CollisionOfPlayerAndGhost(Inky,player) || player.CollisionOfPlayerAndGhost(Clyde,player))
            {
              screenMode=ScreenModes::GAMEOVER_LOSE;
             }

            if(GameFoods.AreFoodsDepleted()){screenMode=ScreenModes::GAMEOVER_WIN;} // checking the wrong vector

        }

        window.display(); //displaying the pacman to the screen

    }
}

GameEngine::~GameEngine()
{
    //dtor
}
