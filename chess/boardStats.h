#pragma once
#include "tableSquares.h"
#include<iostream>
#include <SFML/Graphics.hpp>
class boardStats
{
public:
    double width;
    double height;
    int squareSize;
    tableSquares squares[64];

    //Constructor
    boardStats(int widthExt, int heightExt);

    //Get current window info
    void seutpBoard();

    void buildBoard(sf::RenderWindow* window);

};

