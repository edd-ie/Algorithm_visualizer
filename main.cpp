#include <iostream>
#include "raylib.h"
#include "Game.h"


int main()
{
    InitWindow(750, 750, "Algorithm visualizer");

    while (!WindowShouldClose())
    {
        BeginDrawing();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
