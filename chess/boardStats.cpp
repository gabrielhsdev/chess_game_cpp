#include "boardStats.h"
#include<iostream>
#include <SFML/Graphics.hpp>

using namespace std;

boardStats::boardStats(int widthExt, int heightExt){
    width = widthExt;
    height = heightExt;
    seutpBoard();
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

            //cout << "I-" << i << "  J-" << j << "\t" << start << "," << height << "\n";
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

    //Create objects
    sf::RectangleShape rectangle(sf::Vector2f(150.f, 150.f));

    //Set text
    sf::Text text;
    sf::Font font;
    if (!font.loadFromFile("font.ttf"))
    {
        std::cerr << ".Error while loading font" << std::endl;
        return;
    }
    text.setFont(font);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Black);
    //Set text end

    //Fill 64 tiles from the objects, call the fillsquare function of each square too to draw its stats
    for (int i = 0; i < 64; i++) {
        if ((squares[i].posXid + squares[i].posYid) % 2 == 0) {
            rectangle.setFillColor(sf::Color(118, 150, 85));
            rectangle.setPosition(squares[i].posXdraw, squares[i].posYdraw);
        } else {
            rectangle.setFillColor(sf::Color(238, 238, 210));
            rectangle.setPosition(squares[i].posXdraw, squares[i].posYdraw);
        }
        window->draw(rectangle);

        //Draw text id
        if (squares[i].posYid == 0) {
            text.setPosition(squares[i].posXdraw, squares[i].posYdraw);
            string s = to_string(squares[i].posXid);
            text.setString(s);
            window->draw(text);
        }
    }
}