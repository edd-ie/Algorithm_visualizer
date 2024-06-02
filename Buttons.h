//
// Created by _edd.ie_ on 01/06/2024.
//

#ifndef BUTTONS_H
#define BUTTONS_H
#include "raylib.h"


class Button{
    int x, y, height, width;
    Color color{}, hoverColor{}, temp{}, textCol{};
    char* text;


public:
    int buttonX, buttonY;

    Button(int x, int y,  Color color, Color hover, char* text)
    {
        this->x = 20*x;
        this->y = 20*y;
        height = 20*2;
        width = 20*5;

        buttonX = this->x+width;
        buttonY = this->y+height;

        this->temp = color;
        this->hoverColor = hover;
        this->color = temp;
        this->text = text;
        textCol = BLACK;
    }

    void Draw()
    {
        // DrawRectangleRounded(rect, 0.5, 2, color);

        DrawRectangle(x, y, width, height, color);
        DrawText(text,
            x + width / 2 - MeasureText(text, 24) / 2,
            y + height / 2 - 20 / 2,
            24,
            textCol);
        hover();
    }

    void Actions(bool& state)
    {
        if((text == "Sort" || text == "Search") && !state)
        {
            btnClick(state);
        }
    }

    void hover()
    {
        if(CheckCollisionPointRec(GetMousePosition(),
            Rectangle{static_cast<float>(x), static_cast<float>(y),
                static_cast<float>(width), static_cast<float>(height)})
                )
        {
            color = hoverColor;
            textCol = WHITE;
        }
        else
        {
            color = temp;
            textCol = BLACK;
        }
    }

    char* btnClick(bool& state)
    {
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(),
            Rectangle{static_cast<float>(x), static_cast<float>(y),
                static_cast<float>(width), static_cast<float>(height)})
                )
        {
            state = true;
            color = GREEN;

            std::cout << "pressed";

            return text;
        }
    }
};

#endif //BUTTONS_H
