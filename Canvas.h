//
// Created by _edd.ie_ on 03/06/2024.
//

#ifndef CANVAS_H
#define CANVAS_H

class Canvas
{
    float x, y, width, height;
    Color color{};
public:
    Canvas()
    {
        x = 20*1.5;
        y = 20*11;
        width = 20*42;
        height = 20*21;
        color = {226, 220, 224,255};
    }

    void Draw(){
        Rectangle rect = {x, y, width, height};
        DrawRectangleRounded(rect, 0.02, 10, color);
    }
};

#endif //CANVAS_H
