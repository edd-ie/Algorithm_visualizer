//
// Created by _edd.ie_ on 08/06/2024.
//

#ifndef SORTING_H
#define SORTING_H
#include "raylib.h"
#include <string>

class Sort{

    int small[10][2];
    int medium[30][2];
    int large[100][2];

    Color main = {34, 38, 34,255};
    Color secondary = {186, 1, 1, 255};
    Color active = {61, 201, 18,255};

    bool init = false;
    int sortType;



public:
    double lastUpdatetime = 0;
    double updateInterval = 0.1;
    int pos = 0;

    Sort()
    {
        Randomize();
    }

    void Randomize()
    {
        for(int i=0;i<10;i++)
        {
            small[i][0]=rand()%100+5;
            small[i][1] = 0;
            medium[i][0]=rand()%100+5;
            medium[i][1] = 0;
            large[i][0]=rand()%100+5;
            large[i][1] = 0;
        }

        for(int i=0;i<20;i++)
        {
            medium[i][0]=rand()%100+5;
            medium[i][1] = 0;
            large[i][0]=rand()%100+5;
            large[i][1] = 0;
        }

        for(int i=0;i<70;i++)
        {
            large[i][0]=rand()%100+5;
            large[i][1] = 0;
        }
    }

    void Draw(std::string& size)
    {
        visualizer(size);
    }

    void setInit(int type)
    {
        sortType = type;
        if(type!=1) init = false;
        else init = true;
    }

    void visualizer(std::string& size)
    {
        int spacing, pixel, increments;

        if(size == "Small"){
            spacing = 100;
            pixel = 45;
            increments = 47;

            for(int*i : small)
            {
                DrawRectangle(pixel*2+spacing,
                    20*11,
                    pixel,
                    4*i[0],
                    i[1] == 0 ? main:
                    i[1] == 1 ? secondary : active);
                spacing += increments;
            }
        }
        else if(size == "Medium")
        {
            spacing = 35;
            pixel = 30;
            increments = 31;

            for(int*i : medium)
            {

                DrawRectangle(pixel+spacing,
                    20*11,
                    pixel,
                    4*i[0],
                    i[1] == 0 ? main:
                    i[1] == 1 ? secondary : active);
                spacing += increments;
            }
        }
        else if(size == "Large")
        {
            if(init) update(size);
            spacing = 1;
            pixel = 10;
            increments = 11;

            for(int*i : large)
            {
                DrawRectangle(60+(pixel+spacing),
                    20*11,
                    pixel,
                    4*i[0],
                    i[1] == 0 ? main:
                    i[1] == 1 ? secondary : active);
                spacing += increments;
            }
        }
    }


    bool eventTriggered(const double interval)
    {
        if(const double currentTime = GetTime(); currentTime-lastUpdatetime >= interval)
        {
            lastUpdatetime = currentTime;
            return true;
        }
        return false;
    }

    void update(std::string& size)
    {
        if(eventTriggered(updateInterval))
        {
            if(pos > 99)
            {
                Randomize();
                pos = 0;
            }
            large[pos][1] = 2;
            if(pos > 1)
            {
                large[pos-1][1] = 1;
                large[pos-2][1] = 0;
            }
            ++pos;
        }
    }


};

#endif //SORTING_H
