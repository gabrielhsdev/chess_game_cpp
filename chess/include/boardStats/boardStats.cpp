#include "boardStats.h"
#include<iostream>
#include <SFML/Graphics.hpp>

using namespace std;

boardStats::boardStats(int widthExt, int heightExt){
    winner = 0;
    round = 0;
    width = widthExt;
    height = heightExt;

    int spacing = width / 8;
    squareSize = spacing;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            possibleMoves[i][j] = false;
        }
    }
    seutpBoard();
}

//It runs only once, setup pieces
void boardStats::seutpBoard() {

    int spacing = squareSize;
    int height = 0;
    int widthStartBkp = 0;

    for (int i = 0; i < 8; i++) {
        int start = widthStartBkp;
        for (int j = 0; j < 8; j++) {
            //Set piece properties
            squares[i][j].piece.status = calculatePiece(i, j);
            squares[i][j].piece.posXdraw = start;
            squares[i][j].piece.posYdraw = height;
            squares[i][j].piece.posX = i;
            squares[i][j].piece.posY = j;

            //Set square properties
            squares[i][j].posXid = i;
            squares[i][j].posYid = j;
            squares[i][j].posXdraw = start;
            squares[i][j].posYdraw = height;
            start = start + spacing;

            //Set square colors
            if ((i+j)%2 == 0) {
                squares[i][j].color_default = sf::Color(166, 156, 129);
                squares[i][j].color_selected = sf::Color(102, 125, 77);
                squares[i][j].color_action = sf::Color(204, 141, 133);
            }
            else 
            {
                squares[i][j].color_default =  sf::Color(122, 113, 87);
                squares[i][j].color_selected = sf::Color(194, 194, 169);
                squares[i][j].color_action = sf::Color(207, 179, 176);
            }
            squares[i][j].color_active = squares[i][j].color_default;
        }
        height = height + spacing;
    }
    return;
}

void boardStats::buildBoard(sf::RenderWindow* window) {
    //Runs every frame
    window->clear();

    //Draw each tile
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            bool selected = false;

            //Check if current square is hovered
            selected = isSquareHover(&squares[i][j]);

            //Draw each square
            squares[i][j].drawSquare(window);

            //Call movement handling function, empty on base class
            movementHandle(i, j, selected);
        }
    }
}

bool boardStats::isSquareHover(tableSquares * square) {
    if (square->posXdraw < mouse_position.x
        && square->posXdraw + squareSize > mouse_position.x
        && square->posYdraw < mouse_position.y
        && square->posYdraw + squareSize > mouse_position.y) {
        return true;
    }
    else {
        return false;
    }
}

int  boardStats::calculatePiece(int x, int y) {
    //Set White pieces
    if (x == 1) {
        return 1;
    }
    if (x == 0) {
        if (y == 0 || y == 7)
            return 3;
        if (y == 1 || y == 6)
            return 2;
        if (y == 2 || y == 5)
            return 4;
        if (y == 3)
            return 6;
        if (y == 4)
            return 5;
    }
    //Set Black pieces
    if (x == 6) {
        return 7;
    }
    if (x == 7) {
        if (y == 0 || y == 7)
            return 9;
        if (y == 1 || y == 6)
            return 8;
        if (y == 2 || y == 5)
            return 10;
        if (y == 3)
            return 12;
        if (y == 4)
            return 11;
    }
    return 0;
}
