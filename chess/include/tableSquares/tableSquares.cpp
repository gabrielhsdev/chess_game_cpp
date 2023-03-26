#include "../tableSquares/tableSquares.h"
#include <iostream>
#include <SFML/Graphics.hpp>
tableSquares::tableSquares() {

    if (!font.loadFromFile("lib/font.ttf"))
    {
        cerr << ".Error while loading font" << std::endl;
        return;
    }

    text.setFont(font);
    text.setCharacterSize(24);

    return;
}

void tableSquares::drawText(sf::RenderWindow* window) {

    //string s = to_string(posXid) + "," + to_string(posYid);

    text.setFillColor(sf::Color::Black);
    text.setPosition(posXdraw, posYdraw); 
    text.setString(getIndentification());

    window->draw(text);
    
    //Check for last row
    if (posYid == 7) {
        text.setPosition(posXdraw, posYdraw);
        text.setString(getIndentification());
        window->draw(text);
    }

}

void tableSquares::drawSquare(sf::RenderWindow* window){

    sf::RectangleShape rectangle(sf::Vector2f(150.f, 150.f));

    //Selected overrides everything
    rectangle.setFillColor(color_active);
    rectangle.setPosition(posXdraw, posYdraw);

    window->draw(rectangle);

    if(posXid == 7 || posYid == 0)
        drawText(window);

    //Draw wathever is inside this square
    piece.drawPiece(window);

}

string tableSquares::getIndentification() {
    string s = "err on tableSquares.cpp";

    if ( posYid == 0) {
        s = to_string(posXid);
    }
    if (posXid == 7) {
        switch (posYid)
        {
        case 0:
            s = "a";
            break;
        case 1:
            s = "b";
            break;
        case 2:
            s = "c";
            break;
        case 3:
            s = "d";
            break;
        case 4:
            s = "e";
            break;
        case 5:
            s = "f";
            break;
        case 6:
            s = "g";
            break;
        case 7:
            s = "h";
            break;
        default:
            break;
        }
    }

    return s;
}



