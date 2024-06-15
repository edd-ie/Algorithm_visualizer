//
// Created by _edd.ie_ on 01/06/2024.
//

#ifndef GAME_H
#define GAME_H
#include <string>

#include "Buttons.h"
#include "Canvas.h"
#include "Sorting.h"


inline int gameWidth = 100;
inline int gameHeight = 60;
inline int fps = 120;
inline int pixel = 10;
static double updateInterval = 0;
static bool arrayReset = true;

class Game
{
    //Theme
    Color backGround = {34, 38, 34,255};
    Color textColor = {252, 250, 251, 255};
    Color btnColor = {239, 235, 237, 255};
    Color btnHover = {78, 72, 78, 255};
    Color backColor = {242, 90, 81, 255};


    int sortOption = 0;



    //Canvas
    Canvas canvas = Canvas(static_cast<float>(gameWidth),
        static_cast<float>(gameHeight), static_cast<float>(pixel));

    //Arrays
    Sort array = Sort(gameWidth, gameHeight, pixel);

    //Buttons
    Button selectSort = Button((gameWidth*pixel)*0.8f, (gameHeight*pixel)*0.25f,
        btnColor, btnHover, "Selection");
    Button insertSort = Button((gameWidth*pixel)*0.8f, ((gameHeight*pixel)*0.25f)+55,
        btnColor, btnHover, "Insertion");


public:

    Game()= default;

    void displayText() const
    {
        // App title
        DrawText("Algorithm Visualizer", (gameWidth*pixel)/3.5, pixel, 45, textColor);

        // Sort Type
        DrawText("Sort Algorithm", (gameWidth*pixel)*0.8f, (gameHeight*pixel)*0.17f,
            24, textColor);

    }



    void Draw()
    {
        //Game Background
        ClearBackground(backGround);

        //Text Rendering
        displayText();
        canvas.Draw();
        array.draw(updateInterval, sortOption);

        selectSort.Draw();
        insertSort.Draw();

        buttonActions();

    }

    void buttonActions()
    {
        if(selectSort.Actions())
        {
            insertSort.setPressed(false);
            if(sortOption != 1) array.resetVal();
            sortOption = 1;
        }
        if(insertSort.Actions())
        {
            selectSort.setPressed(false);
            if(sortOption != 2) array.resetVal();
            sortOption = 2;
        }
    }

};

#endif //GAME_H
