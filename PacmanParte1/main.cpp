#include "Map.h"
#include "Enemy.h"
#include "Player.h"
#include "TimeManager.h"
#include <vector>
/// <summary>
/// Sets the needed variables
/// </summary>
void Setup();
/// <summary>
/// Handles the inputs
/// </summary>
void Input();
/// <summary>
/// Handles the logic of the game
/// </summary>
void Logic();
/// <summary>
/// Draws the screen
/// </summary>
void Draw();


Map pacman_map = Map();
std::vector<Enemy> enemigos;
//Enemy enemy01 = Enemy(pacman_map.spawn_enemy);
Player p1 = Player(pacman_map.spawn_player);
int muertes = 0;
USER_INPUTS input = USER_INPUTS::NONE;
bool run = true;
bool win = false;

int main()
{

    Setup();
    while (run)
    {
        Input();
        Logic();
        Draw();
    }
    system("CLS");
    std::cout << "Has logrado recolectar la siguiente cantidad de puntos: " << p1.points << " gracias por haber jugado :)";
    switch (input)
    {
    case QUIT:
        run = false;
        break;
    }

}

void Setup()
{
    std::cout.sync_with_stdio(false);
    srand(time(NULL));
    unsigned short int enemyNumber = 0;
    std::cout << "¿Cuantos enemigos quieres?";
    std::cin >> enemyNumber;
    for (size_t i = 0; i < enemyNumber; i++)
    {
        enemigos.push_back(Enemy(pacman_map.spawn_enemy));
    }
}

void Input()
{
    input = USER_INPUTS::NONE;
    if (ConsoleUtils::KeyPressed(VK_UP) || ConsoleUtils::KeyPressed('W'))
    {
        input = USER_INPUTS::UP;
    }
    if (ConsoleUtils::KeyPressed(VK_DOWN) || ConsoleUtils::KeyPressed('S'))
    {
        input = USER_INPUTS::DOWN;
    }
    if (ConsoleUtils::KeyPressed(VK_RIGHT) || ConsoleUtils::KeyPressed('D'))
    {
        input = USER_INPUTS::RIGHT;
    }
    if (ConsoleUtils::KeyPressed(VK_LEFT) || ConsoleUtils::KeyPressed('A'))
    {
        input = USER_INPUTS::LEFT;
    }
    if (ConsoleUtils::KeyPressed(VK_ESCAPE) || ConsoleUtils::KeyPressed('Q'))
    {
        input = USER_INPUTS::QUIT;
    }
}

void Logic()
{
    if (input == USER_INPUTS::QUIT)
        run = false;

    p1.Update(&pacman_map, input, &enemigos);
    for (size_t i = 0; i < enemigos.size(); i++)
    {
        Enemy::ENEMY_STATE enemystate = enemigos[i].Update(&pacman_map, { p1.pos });
        switch (enemystate)
        {
        case Enemy::ENEMY_KILLED:
            p1.points += 50;
            break;
        case Enemy::ENEMY_KILL:
            p1.Kill(&pacman_map);
            muertes++;
            if (muertes >= 3)
            {
                run = false;
            }
            break;

        }

    }
    if (pacman_map.points <= 0)
    {
        run = false;
    }
}


void Draw()
{
    ConsoleUtils::Console_SetPos(0, 0);
    pacman_map.Draw();
  /*  ConsoleUtils::Console_SetPos(player_x, player_y);
    ConsoleUtils::Console_SetColor(ConsoleUtils::CONSOLE_COLOR::DARK_YELLOW);
    std::cout << player_char;*/
    p1.Draw();

    //<summary>
    // Despues de imprimir el player imprimimos el enemy
    //</summary>
    //enemy01.Draw();
    for (size_t i = 0; i < enemigos.size(); i++)
    {
        enemigos[i].Draw();
    }
    ConsoleUtils::Console_ClearCharacter({ 0,(short)pacman_map.Height });
    ConsoleUtils::Console_SetColor(ConsoleUtils::CONSOLE_COLOR::CYAN);
    std::cout << "Puntuacion actual: " << p1.points << " Puntuacion pendiente: " << pacman_map.points << std::endl;
    if (win)
    {
        ConsoleUtils::Console_SetColor(ConsoleUtils::CONSOLE_COLOR::GREEN);
        std::cout << "Has ganado!" << std::endl;
    }
    //Esto es para comprobar si todo funciona
    std::cout << "Fotoframs : " << TimeManager::getInstance().frameCount << std::endl;
    std::cout << "Time : " << TimeManager::getInstance().time << std::endl;
    std::cout << "DeltaTime : " << TimeManager::getInstance().deltaTime << std::endl;
    TimeManager::getInstance().NextFrame();
}