#include <AppCUI/include/AppCUI.hpp>

using namespace AppCUI;
using namespace AppCUI::Application;
using namespace AppCUI::Controls;
using namespace AppCUI::Graphics;

constexpr uint32 gridWidth = 3;
constexpr uint32 gridHeight = 3;
constexpr size_t gridSpace = 1;

enum EnemyDirection
{
    UpDirection,
    DownDirection,
    LeftDirection,
    RightDirection,
    ReachedDestinationDirection,
};

struct GamePoint
{
    uint32 x;
    uint32 y;
};

struct Enemy
{
    GamePoint location;
    GamePoint* whereToGo;
    uint32 checkPointIndex;
    EnemyDirection direction;
};

EnemyDirection ComputeDirection(GamePoint& currentLocation, GamePoint* whereToGo)
{
    if (currentLocation.x < whereToGo->x)
        return RightDirection;
    if (currentLocation.x > whereToGo->x)
        return LeftDirection;
    if (currentLocation.y < whereToGo->y)
        return DownDirection;
    if (currentLocation.y > whereToGo->y)
        return UpDirection;
    return ReachedDestinationDirection;
}

//We create 
class GameAreaPanel : public AppCUI::Controls::UserControl
{
    uint32 currenLeft;

    Enemy enemies[10];
    uint32 enemiesCount, enemiesMaxCount;

    GamePoint chcekPoints[5];
    uint32 chcekPointsCount;

    uint32 width;
    uint32 height;

    uint32 frameCount;

public:
    GameAreaPanel(std::string_view layout) :UserControl(layout)
    {
        currenLeft = 0;
        enemiesCount = 0;
        enemiesMaxCount = 10;

        width = 0;
        height = 0;

        //not really ok. but we will fix this later
        chcekPointsCount = 5;

        frameCount = 0;
    }

    void OnStart() override
    {
        height = GetHeight();
        width = GetWidth();

        uint32 cellsPerWidth = width / gridWidth;
        uint32 cellsPerHeight = height / gridHeight;

        chcekPoints[0].y = 0;
        chcekPoints[0].x = std::max(cellsPerWidth - 5, 0u) * gridWidth;

        chcekPoints[1].y = std::min(10u, (cellsPerHeight - 1) * gridHeight);
        chcekPoints[1].x = chcekPoints[0].x;

        chcekPoints[2].y = chcekPoints[1].y;
        chcekPoints[2].x = (cellsPerWidth / 2) * gridWidth;

        chcekPoints[3].y = std::min(20u, (cellsPerHeight - 1) * gridHeight);
        chcekPoints[3].x = chcekPoints[2].x;

        chcekPoints[4].y = chcekPoints[3].y;
        chcekPoints[4].x = (cellsPerWidth - 1) * gridWidth;
    }

    void Paint(Graphics::Renderer& renderer) override
    {
        renderer.Clear(' ', { AppCUI::Graphics::Color::White, AppCUI::Graphics::Color::DarkBlue });

        for (uint32 pIndex = 0; pIndex < chcekPointsCount; pIndex++)
        {
            renderer.FillRect(chcekPoints[pIndex].x, chcekPoints[pIndex].y, chcekPoints[pIndex].x + gridWidth - 1, chcekPoints[pIndex].y + gridHeight - 1, '#', { Graphics::Color::Green, Graphics::Color::Transparent });
        }

        for (uint32 eIndex = 0; eIndex < enemiesCount; eIndex++)
        {
            renderer.FillRect(enemies[eIndex].location.x, enemies[eIndex].location.y, enemies[eIndex].location.x + gridWidth - 1, enemies[eIndex].location.y + gridHeight - 1, '#', { Graphics::Color::White, Graphics::Color::Transparent });
        }



        //remainingWidth = remainingWidth;
        //AppCUI::Graphics::WriteTextParams params;
        //params.Flags = AppCUI::Graphics::WriteTextFlags::SingleLine;
        //params.X = currenLeft;
        //params.Y = 0;
        //params.Color = { AppCUI::Graphics::Color::White,AppCUI::Graphics::Color::Transparent };
        //renderer.WriteText("asdasd", params);
    }

    void SpawnEnemy()
    {
        if (enemiesCount < enemiesMaxCount)
        {
            enemies[enemiesCount].checkPointIndex = 0;
            enemies[enemiesCount].location = chcekPoints[0];
            enemies[enemiesCount].whereToGo = &chcekPoints[1];
            enemies[enemiesCount].direction = ComputeDirection(enemies[enemiesCount].location, enemies[enemiesCount].whereToGo);
            enemiesCount++;
        }
    }

    void UpdateEnemiesLocation()
    {
        for (uint32 enemyIndex = 0; enemyIndex < enemiesCount; enemyIndex++)
        {
            Enemy& enemy = enemies[enemyIndex];
            switch (enemy.direction)
            {
            case UpDirection:
                enemy.location.y--;
                enemy.direction = ComputeDirection(enemy.location, enemy.whereToGo);
                break;
            case DownDirection:
                enemy.location.y++;
                enemy.direction = ComputeDirection(enemy.location, enemy.whereToGo);
                break;
            case LeftDirection:
                enemy.location.x--;
                enemy.direction = ComputeDirection(enemy.location, enemy.whereToGo);
                break;
            case RightDirection:
                enemy.location.x++;
                enemy.direction = ComputeDirection(enemy.location, enemy.whereToGo);
                break;
            case ReachedDestinationDirection:
                if (++enemy.checkPointIndex == chcekPointsCount)
                {
                    for (uint32 cIndex = enemyIndex + 1; cIndex < enemiesCount; cIndex++)
                        enemies[cIndex - 1] = enemies[cIndex];
                    enemyIndex--;
                    enemiesCount--;
                }
                else
                {
                    enemy.whereToGo = &chcekPoints[enemy.checkPointIndex];
                    enemy.direction = ComputeDirection(enemy.location, enemy.whereToGo);
                }
                break;
            }
        }
    }

    bool OnFrameUpdate() override
    {
        auto height = GetHeight();
        auto width = GetWidth();

        UpdateEnemiesLocation();

        if (++frameCount == gridWidth + 3)
        {
            frameCount = 0;
            SpawnEnemy();
        }

        return true;
    }
};

//The GameWindow type inherits the variables and methods from the AppCUI::Controls::SingleApp type
class GameWindow : public AppCUI::Controls::SingleApp
{
public:
    GameWindow()
    {
        //We create the PLayableArea by inheriting the UserControl "features" (methods / variables) -> we'll come back to this when we reach polymorphism
        AddChildControl(std::make_unique<GameAreaPanel>("d:c"));
    }
};

//Program entrypoint
int main()
{
    //Enable the application to run in FPSMode
    if (!Application::Init(InitializationFlags::SingleWindowApp | InitializationFlags::Maximized |
        InitializationFlags::EnableFPSMode))
        return 1;

    //Running our app -> make_unique is generating a smart pointer that allocates an object of type GameWindow
    //The param it needs is a "AppCUI::Controls::SingleApp" so we need an object that implementes the "features" from the type required
    //  we create the type GameWindow. make_unique<GameWindow> is equivalent to: "new GameWindow()" (creating an instance of the class) and then deleting it when it runs out of scope
    RunSingleApp(std::make_unique<GameWindow>());

    //Run the application (this is an infinite loop where events are interpreted)
    Application::Run();
    return 0;
}
