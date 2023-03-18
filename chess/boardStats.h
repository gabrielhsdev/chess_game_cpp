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
    sf::Vector2i mouse_position;

    //Constructor
    boardStats(int widthExt, int heightExt);

    //Get current window info
    void seutpBoard();

    void buildBoard(sf::RenderWindow* window);

    void testObj(int test);

};

