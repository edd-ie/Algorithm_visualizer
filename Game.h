//
// Created by _edd.ie_ on 01/06/2024.
//

#ifndef GAME_H
#define GAME_H
#include "Buttons.h"
#include <string>


class Game
{
    //Theme
    Color backGround = {34, 38, 34,255};
    Color textColor = {252, 250, 251, 255};
    Color btnColor = {239, 235, 237, 255};
    Color btnHover = {78, 72, 78, 255};

    bool selectedOptions = false;

    //Buttons;

    Button sortBtn = Button(5, 5, btnColor, btnHover, "Sort");
    Button searchBtn = Button(14, 5, btnColor, btnHover, "Search");


public:
    int fps = 60;

    //Game grids
    int cell = 20; //pixels
    int rows = 45;
    int cols = 33;
    float border = 50;
    float offset = 19;
    std::string currentAction;

    Game()= default;

    void displayText()
    {
        DrawText("Algorithm Visualizer", (cell*rows)/4, cell, 45, textColor);
    }



    void Draw()
    {
        //Game Background
        ClearBackground(backGround);

        //Text Rendering
        displayText();



        //Game Actions
        Actions();

    }

    void Actions()
    {
        if(!selectedOptions)
        {
            sortBtn.Draw();
            searchBtn.Draw();

            sortBtn.Actions(currentAction);
            searchBtn.Actions(currentAction);
            std::cout << currentAction;


            if(currentAction == "Sort")
                if(searchBtn.isPresed())searchBtn.setPressed();

            if(currentAction == "Search" )
                if(sortBtn.isPresed())sortBtn.setPressed();

        }
        else
        {

        }
    }
};

#endif //GAME_H
