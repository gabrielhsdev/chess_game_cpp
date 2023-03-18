#include "boardStats.h"
#include<iostream>
#include <SFML/Graphics.hpp>

using namespace std;

boardStats::boardStats(int widthExt, int heightExt){
    width = widthExt;
    height = heightExt;
    seutpBoard();
    testObj(widthExt);
}

//Get current window info
void boardStats::seutpBoard() {

    int count = 0;
    int spacing = width/ 8;
    int height = 0;

    squareSize = spacing;

    int widthStartBkp = 0;

    for (int i = 0; i < 8; i++) {
        int start = widthStartBkp;
        for (int j = 0; j < 8; j++) {
            squares[count].posXid = i;
            squares[count].posYid = j;
            squares[count].posXdraw = start;
            squares[count].posYdraw = height;
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
    //Draw each tile
    for (int i = 0; i < 64; i++) {
        squares[i].drawSquare(window);
    }

}

void boardStats::testObj(int test) {
    cout << "BOARD LOADED" << test << "\n";
}