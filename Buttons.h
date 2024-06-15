//
// Created by _edd.ie_ on 01/06/2024.
//

#ifndef BUTTONS_H
#define BUTTONS_H
#include "Game.h"
#include "raylib.h"
#include <string>
#include <utility>


class Button{
    int x, y, height, width;
    Color color{}, hoverColor{}, temp{}, textCol{};
    std::string text;
    bool pressed = false;


public:
    int buttonX, buttonY;

    Button(int x, int y,  Color color, Color hover, std::string text)
    {
        this->x = x;
        this->y = y;
        height = 15*2;
        width = 20*5;

        buttonX = this->x+width+2;
        buttonY = this->y+height;

        this->temp = color;
        this->hoverColor = hover;
        this->color = temp;
        this->text = std::move(text);
        textCol = BLACK;
    }

    void Draw()
    {
        // DrawRectangleRounded(rect, 0.5, 2, color);

        DrawRectangle(x, y, width, height, color);
        DrawText(text.c_str(),
            x + width / 2 - MeasureText(text.c_str(), 19) / 2,
            y + height / 2 - 21 / 2,
            19,
            textCol);

        // Actions();
    }

    bool Actions()
    {
        btnActions();
        if (pressed)
        {
            color = GREEN;
        }

        return pressed;
    }

    void btnActions()
    {
        //Hover
        if(CheckCollisionPointRec(GetMousePosition(),
            Rectangle{static_cast<float>(x), static_cast<float>(y),
                static_cast<float>(width), static_cast<float>(height)})
                )
        {
            color = hoverColor;
            textCol = WHITE;

            //click
            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && !pressed)
            {
                setPressed(true);
            }
        }
        else
        {
            color = temp;
            textCol = BLACK;
        }
    }

    void setPressed(const bool state)
    {
        pressed = state;
    }

    [[nodiscard]] bool isPresed() const{
        return pressed;
    }

};

#endif //BUTTONS_H
