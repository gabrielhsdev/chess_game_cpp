#include "boardStats.h"
#include<iostream>
#include <SFML/Graphics.hpp>

using namespace std;

boardStats::boardStats(int widthExt, int heightExt){
    round = 0;
    width = widthExt;
    height = heightExt;

    int spacing = width / 8;
    squareSize = spacing;

    seutpBoard();
    testObj(widthExt);
}

int  boardStats::calculatePiece(int x, int y) {
    //Set White pawns
    if (x == 1) {
        return 1;
    }
    //Set Black pawns
    if (x == 6) {
        return 7;
    }
    return 0;
}

//Get current window info
void boardStats::seutpBoard() {
    int count = 0;
    int spacing = squareSize;
    int height = 0;


    int widthStartBkp = 0;

    for (int i = 0; i < 8; i++) {
        int start = widthStartBkp;
        for (int j = 0; j < 8; j++) {
            squares[i][j].status = calculatePiece(i, j);
            squares[i][j].posXid = i;
            squares[i][j].posYid = j;
            squares[i][j].posXdraw = start;
            squares[i][j].posYdraw = height;
            start = start + spacing;
            count++;
        }
        height = height + spacing;
    }
    return;
}

void boardStats::buildBoard(sf::RenderWindow* window) {
    //We could also check where our mouse is and make the selected square a little bit brighter
    //window->clear(sf::Color::Blue);//Set background color
    window->clear();

    //Square size = squareSize

    //Draw each tile
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            bool selected = false;

            if (squares[i][j].posXdraw < mouse_position.x
                && squares[i][j].posXdraw + squareSize > mouse_position.x
                && squares[i][j].posYdraw < mouse_position.y
                && squares[i][j].posYdraw + squareSize > mouse_position.y) {
                selected = true;
            }

            //Draw each square
            squares[i][j].drawSquare(window, selected);
        }
    }

}

void boardStats::addRound() {
    round = round + 1;
}

void boardStats::testObj(int test) {
    cout << "BOARD LOADED" << test << "\n";
}