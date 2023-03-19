#pragma once
#include "tableSquares.h"
#include<iostream>
#include <SFML/Graphics.hpp>

class boardStats
{
public:
    double width;
    double height;
    double squareSize;
    tableSquares squares[8][8];
    sf::Vector2i mouse_position;

    //Constructor
    boardStats(int widthExt, int heightExt);

    //Get current window info
    void seutpBoard();

    void buildBoard(sf::RenderWindow* window);

    void testObj(int test);

};

