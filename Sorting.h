//
// Created by _edd.ie_ on 08/06/2024.
//

#ifndef SORTING_H
#define SORTING_H
#include "raylib.h"
#include <string>
#include <random>

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
    double updateInterval = 0;
    int pos = 0;
    int next = 0;

    int sIndex = 0;
    int smallest;


    Sort()
    {
        Randomize();
    }


    void Randomize()
    {
        std::random_device mix;
        std::uniform_int_distribution<int> gen(10,100);
        for(int i=0;i<10;i++)
        {
            
            small[i][0] = gen(mix);
            small[i][1] = 0;
            medium[i][0] = gen(mix);
            medium[i][1] = 0;
            large[i][0] = gen(mix);
            large[i][1] = 0;
        }

        for(int i=0;i<20;i++)
        {
            medium[i][0] = gen(mix);
            medium[i][1] = 0;
            large[i][0] = gen(mix);
            large[i][1] = 0;
        }

        for(int i=0;i<70;i++)
        {
            large[i][0] = gen(mix);
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
            // if(init) update(10);
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
            // if(init) update(30);
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
            if(init) update(100);
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

    void update(const int size)
    {
        // updateInterval = (size == 10) ? 0.4 :
        //                     (size == 30) ? 0.09 : 0;
        if(eventTriggered(updateInterval) && init)
        {

            selection(size);
        }
    }

    void selection(const int size)
    {
        if(size == 10)
        {
            if(next == 0)smallest = small[pos][0];
            if(pos == size)
            {
                small[pos][1] = 2;
            }
            else
            {
                if(next == size)
                {
                    small[next][1] = 0;

                    small[sIndex][0] = small[pos][0];
                    small[sIndex][1] = 1;

                    small[pos][0] = smallest;
                    small[pos][1] = 2;

                    ++pos;
                    next = pos+1;
                    smallest = small[pos][0];
                }
                else
                {
                    if(next > pos+1) small[next-1][1] = 0;
                    small[sIndex][1] = 0;

                    small[pos][1] = 1;
                    small[next][1] = 2;
                    if(small[next][0] <= smallest)
                    {
                        sIndex = next;
                        smallest = small[next][0];
                    }
                    ++next;
                }
            }
        }
        else if(size == 30)
        {
            if(next == 0)smallest = medium[pos][0];
            if(pos == size)
            {
                medium[pos][1] = 2;
            }
            else
            {
                if(next == size)
                {
                    medium[next][1] = 0;

                    medium[sIndex][0] = medium[pos][0];
                    medium[sIndex][1] = 1;

                    medium[pos][0] = smallest;
                    medium[pos][1] = 2;

                    ++pos;
                    next = pos+1;
                    smallest = medium[pos][0];
                }
                else
                {
                    if(next > pos+1) medium[next-1][1] = 0;
                    medium[sIndex][1] = 0;

                    medium[pos][1] = 1;
                    medium[next][1] = 2;
                    if(medium[next][0] <= smallest)
                    {
                        sIndex = next;
                        smallest = medium[next][0];
                    }
                    ++next;
                }
            }
        }
        else
        {
            if(next == 0)smallest = large[pos][0];
            if(pos == size)
            {
                large[pos][1] = 2;
            }
            else
            {
                if(next == size)
                {
                    large[next][1] = 0;

                    large[sIndex][0] = large[pos][0];
                    large[sIndex][1] = 1;

                    large[pos][0] = smallest;
                    large[pos][1] = 2;

                    ++pos;
                    next = pos+1;
                    smallest = large[pos][0];
                }
                else
                {
                    if(next > pos+1) large[next-1][1] = 0;
                    large[sIndex][1] = 0;

                    large[pos][1] = 1;
                    large[next][1] = 2;
                    if(large[next][0] <= smallest)
                    {
                        sIndex = next;
                        smallest = large[next][0];
                    }
                    ++next;
                }
            }
        }
    }


};

#endif //SORTING_H
