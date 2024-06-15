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
    Canvas(float width, const float height, const float pixel)
    {
        this->x = pixel*3;
        this->y = (height*pixel)*0.16f;
        this->width = (width*pixel)*0.74f;
        this->height = (height*pixel)*0.8f;
        this->color = {226, 220, 224,255};
    }

    void Draw(){
        Rectangle rect = {x, y, width, height};
        DrawRectangleRounded(rect, 0.02, 10, color);
    }
};

#endif //CANVAS_H
