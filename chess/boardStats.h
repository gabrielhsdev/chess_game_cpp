#pragma once
#include "tableSquares.h"
#include<iostream>
#include <SFML/Graphics.hpp>

class boardStats
{
public:
    int round;
    double width;
    double height;
    double squareSize;
    tableSquares squares[8][8];
    sf::Vector2i mouse_position;

    //Constructor
    boardStats(int widthExt, int heightExt);

    //Get current window info
    void seutpBoard();

    bool isSquareHover(tableSquares * square);

    void buildBoard(sf::RenderWindow* window);

    int  calculatePiece(int x, int y);

    //Will override
    virtual void movementHandle(int i, int j, bool selected) = 0;

    void testObj(int test);

};

