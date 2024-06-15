#include <iostream>
#include "raylib.h"
#include "Game.h"


int main()
{
    Game game = Game();

    InitWindow(gameWidth*pixel, gameHeight*pixel, "Algorithm visualizer");
    SetTargetFPS(fps);

    while (!WindowShouldClose())
    {
        BeginDrawing();

        game.Draw();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
