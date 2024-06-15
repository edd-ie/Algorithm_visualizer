//
// Created by _edd.ie_ on 08/06/2024.
//

#ifndef SORTING_H
#define SORTING_H
#include "raylib.h"
#include "Game.h"
#include <string>
#include <random>

static double lastUpdatetime = 0;

class Sort{

    int small[10][2]{};
    int dataSet[50][2]{};

    Color main = {34, 38, 34,255};
    Color secondary = {186, 1, 1, 255};
    Color active = {61, 201, 18,255};

    bool init = false;
    int sortType{};

    static bool eventTriggered(const double interval)
    {
        if(const double currentTime = GetTime(); currentTime-lastUpdatetime >= interval)
        {
            lastUpdatetime = currentTime;
            return true;
        }
        return false;
    }


public:
    int x, y, frameWidth, frameHeight, pixel;


    // double lastUpdatetime = 0;

    int pos = 0;
    int next = 1;

    int change = 0;
    int smallest;

    void Randomize()
    {
        std::random_device mix;
        std::uniform_int_distribution<int> gen(10,100);
        for(int i=0;i<10;i++)
        {

            small[i][0] = gen(mix);
            small[i][1] = 0;
            dataSet[i][0] = gen(mix);
            dataSet[i][1] = 0;
        }

        for(int i=10;i<50;i++)
        {
            dataSet[i][0] = gen(mix);
            dataSet[i][1] = 0;
        }
    }


    Sort(const int width, const int height, const int pixel)
    {
        x = pixel*4;
        y = (height*pixel)*0.16f;
        frameWidth = width;
        frameHeight = height;
        this->pixel = pixel;
        Randomize();
        smallest = small[0][0];
    }


    void draw(const double updateInterval, const int choice = 0)
    {

        switch (choice)
        {
        case 1:
            selection(updateInterval);
            break;
        case 2:
            insertion(updateInterval);
            break;
            default:display();
        }
    }

    void display()
    {
        int spacing = 0;
        for(int* i : dataSet)
        {
            DrawRectangle(x+spacing,
                    y,
                    13,
                    (4*i[0])+50,
                    i[1] == 0 ? main:
                    i[1] == 1 ? secondary : active);
            spacing += 14;
        }
    }

    void resetVal()
    {
        Randomize();
        pos = 0;
        next = 1;

        change = pos;
        smallest = dataSet[pos][0];
    }

    void selection(const double updateInterval)
    {
        if(pos < 49 && eventTriggered(updateInterval))
        {
            if(next == 50)
            {

                //Switching values
                dataSet[change][0] = dataSet[pos][0];
                dataSet[pos][0] = smallest;

                //reset colors
                dataSet[pos][1] = 0;
                dataSet[next][1] = 0;
                dataSet[change][1] = 0;

                //increments
                pos++;
                next = pos+1;
                change = pos;

                //New asignmets
                smallest = dataSet[pos][0];
                dataSet[pos][1] = 2;
                dataSet[next][1] = 1;
            }
            else if(smallest > dataSet[next][0])
            {
                //reset colour
                dataSet[change][1] = 0;

                //New smallest
                change = next;
                smallest = dataSet[change][0];
                dataSet[change][1] = 2;
            }
            else
            {
                dataSet[next++][1] = 0;
                dataSet[next][1] = 1;
            }
        }

        display();
    }





    void insertion(const double updateInterval)
    {
        if(pos < 49  && eventTriggered(updateInterval))
        {

            if(next==0)
            {
                //reset colors
                dataSet[change][1] = 0;
                dataSet[next][1] = 0;

                pos++;
                change = pos;
                next = pos+1;
                smallest = dataSet[change][0];

                //New colors
                dataSet[change][1] = 2;
                dataSet[next][1] = 1;
            }
            else if(smallest > dataSet[next][0])
            {
                //Switching values
                smallest = dataSet[next][0];
                dataSet[next][0] = dataSet[change][0];
                dataSet[change][0] = smallest;

                //reset colors
                dataSet[change][1] = 0;
                dataSet[next][1] = 0;

                next = change--;
                smallest = dataSet[change][0];
            }
            else
            {

                //Reset colors
                dataSet[change][1] = 0;
                dataSet[next][1] = 0;

                change--;
                next--;
                smallest = dataSet[change][0];


                //New colors
                dataSet[change][1] = 2;
                dataSet[next][1] = 1;
            }
        }

        display();
    }



};

#endif //SORTING_H
