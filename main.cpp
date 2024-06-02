#include <iostream>
#include "raylib.h"
#include "Game.h"


int main()
{
    Game game = Game();

    InitWindow(game.cell*game.rows, game.cell*game.cols, "Algorithm visualizer");
    SetTargetFPS(game.fps);

    while (!WindowShouldClose())
    {
        BeginDrawing();

        game.Draw();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
