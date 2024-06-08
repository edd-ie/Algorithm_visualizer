//
// Created by _edd.ie_ on 01/06/2024.
//

#ifndef GAME_H
#define GAME_H
#include <string>

#include "Buttons.h"
#include "Canvas.h"
#include "Sorting.h"


class Game
{
    //Theme
    Color backGround = {34, 38, 34,255};
    Color textColor = {252, 250, 251, 255};
    Color btnColor = {239, 235, 237, 255};
    Color btnHover = {78, 72, 78, 255};
    Color backColor = {242, 90, 81, 255};


    bool selectedOptions = false;

    //Buttons;
    //Menu
    Button sortBtn = Button(5, 5, btnColor, btnHover, "Sort");
    Button searchBtn = Button(14, 5, btnColor, btnHover, "Search");

    //Canvas
    Canvas canvas = Canvas();

    //Sort
    Button insertionBtn = Button(3, 5, btnColor, btnHover, "Insertion");
    Button selectionBtn = Button(10, 5, btnColor, btnHover, "Selection");
    Button mergeBtn = Button(17, 5, btnColor, btnHover, "Merge");
    Button bubbleBtn = Button(24, 5, btnColor, btnHover, "Bubble");
    Button quickBtn = Button(31, 5, btnColor, btnHover, "Quick");
    Button backBtn = Button(38, 5, backColor, btnHover, "Back");

    Button sortSmall = Button(10, 8, btnColor, btnHover, "Small");
    Button sortMedium = Button(17, 8, btnColor, btnHover, "Medium");
    Button sortLarge = Button(24, 8, btnColor, btnHover, "Large");
    Button sortRandom = Button(31, 8, btnColor, btnHover, "Randomize");


    //Displays
    Sort sort = Sort();



public:
    int fps = 60;

    //Game grids
    int cell = 20; //pixels
    int rows = 45;
    int cols = 33;
    float border = 50;
    float offset = 19;
    std::string currentAction;
    std::string sortOption = "display";
    std::string arraySize;

    Game()= default;

    void displayText() const
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
        //Render menu
        if(!selectedOptions){
            sortBtn.Draw();
            searchBtn.Draw();
            sortBtn.Actions(currentAction);
            searchBtn.Actions(currentAction);
            sort.setInit(0);
        }

        canvas.Draw();

        if(currentAction == "Sort")
        {
            if(searchBtn.isPresed())searchBtn.setPressed();
            if(backBtn.isPresed())backBtn.setPressed();
            selectedOptions = true;

            insertionBtn.Draw();
            selectionBtn.Draw();
            mergeBtn.Draw();
            quickBtn.Draw();
            bubbleBtn.Draw();
            backBtn.Draw();

            sortSmall.Draw();
            sortMedium.Draw();
            sortLarge.Draw();
            sortRandom.Draw();



            insertionBtn.Actions(sortOption);
            selectionBtn.Actions(sortOption);
            mergeBtn.Actions(sortOption);
            quickBtn.Actions(sortOption);
            bubbleBtn.Actions(sortOption);
            backBtn.Actions(currentAction);

            sortSmall.Actions(arraySize);
            sortMedium.Actions(arraySize);
            sortLarge.Actions(arraySize);



            checkSortSelection();
            std::cout << currentAction;
            sort.Draw(arraySize);

            if(arraySize == "Small")
            {
                if(sortMedium.isPresed())sortMedium.setPressed();
                if(sortLarge.isPresed())sortLarge.setPressed();
                if(sortRandom.isPresed())sortRandom.setPressed();
            }
            if(arraySize == "Medium")
            {
                if(sortSmall.isPresed())sortSmall.setPressed();
                if(sortLarge.isPresed())sortLarge.setPressed();
                if(sortRandom.isPresed())sortRandom.setPressed();
            }
            if(arraySize == "Large")
            {
                if(sortMedium.isPresed())sortMedium.setPressed();
                if(sortSmall.isPresed())sortSmall.setPressed();
                if(sortRandom.isPresed())sortRandom.setPressed();
            }

        }



        if(currentAction == "Search" )
        {
            selectedOptions = true;
            if(sortBtn.isPresed())sortBtn.setPressed();
            if(backBtn.isPresed())backBtn.setPressed();

            backBtn.Draw();
            backBtn.Actions(currentAction);
        };

        if(currentAction == "Back")
        {
            if(searchBtn.isPresed())searchBtn.setPressed();
            if(sortBtn.isPresed())sortBtn.setPressed();

            if(insertionBtn.isPresed())insertionBtn.setPressed();
            if(quickBtn.isPresed())quickBtn.setPressed();
            if(selectionBtn.isPresed())selectionBtn.setPressed();
            if(bubbleBtn.isPresed())bubbleBtn.setPressed();
            if(mergeBtn.isPresed())mergeBtn.setPressed();

            if(sortSmall.isPresed())sortSmall.setPressed();
            if(sortMedium.isPresed())sortMedium.setPressed();
            if(sortLarge.isPresed())sortLarge.setPressed();
            if(sortRandom.isPresed())sortRandom.setPressed();

            selectedOptions = false;

        }

        if(selectedOptions)
        {

        }
    }

    void checkSortSelection()
    {
        if(sortOption == "Merge")
        {
            if(insertionBtn.isPresed())insertionBtn.setPressed();
            if(quickBtn.isPresed())quickBtn.setPressed();
            if(selectionBtn.isPresed())selectionBtn.setPressed();
            if(bubbleBtn.isPresed())bubbleBtn.setPressed();
        }

        if(sortOption == "Insertion")
        {
            if(mergeBtn.isPresed())mergeBtn.setPressed();
            if(quickBtn.isPresed())quickBtn.setPressed();
            if(selectionBtn.isPresed())selectionBtn.setPressed();
            if(bubbleBtn.isPresed())bubbleBtn.setPressed();
            sort.setInit(1);
        }

        if(sortOption == "Selection")
        {
            if(insertionBtn.isPresed())insertionBtn.setPressed();
            if(quickBtn.isPresed())quickBtn.setPressed();
            if(mergeBtn.isPresed())mergeBtn.setPressed();
            if(bubbleBtn.isPresed())bubbleBtn.setPressed();
        }

        if(sortOption == "Quick")
        {
            if(insertionBtn.isPresed())insertionBtn.setPressed();
            if(mergeBtn.isPresed())mergeBtn.setPressed();
            if(selectionBtn.isPresed())selectionBtn.setPressed();
            if(bubbleBtn.isPresed())bubbleBtn.setPressed();
        }

        if(sortOption == "Bubble")
        {
            if(insertionBtn.isPresed())insertionBtn.setPressed();
            if(quickBtn.isPresed())quickBtn.setPressed();
            if(selectionBtn.isPresed())selectionBtn.setPressed();
            if(mergeBtn.isPresed())mergeBtn.setPressed();
        }
    }
};

#endif //GAME_H
