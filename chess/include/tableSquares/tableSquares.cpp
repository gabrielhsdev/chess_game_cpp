#include "../tableSquares/tableSquares.h"
#include <iostream>
#include <SFML/Graphics.hpp>
tableSquares::tableSquares() {

    loadText();

    return;

}

void tableSquares::drawSquare(sf::RenderWindow* window){

    sf::RectangleShape rectangle(sf::Vector2f(150.f, 150.f));

    //Selected overrides everything
    rectangle.setFillColor(color_active);
    rectangle.setPosition(posXdraw, posYdraw);

    window->draw(rectangle);

    if(posXid == 7 || posYid == 0)
        drawText(window);

    //Draw square piece
    piece.drawPiece(window);

}

void tableSquares::drawText(sf::RenderWindow* window) {

    text.setPosition(posXdraw, posYdraw);

    if ((posXid + posYid) % 2 == 0) {
        sf::Color color(122, 113, 87);
        text.setFillColor(color);
    }
    else {
        sf::Color color(166, 156, 129);
        text.setFillColor(color);
    }
    

    if (posYid == 0)
    {
        text.setString(getIndentification("number"));
        window->draw(text);
    }

    if (posXid == 7) {
        text.setPosition(posXdraw + 110, posYdraw + 100);
        text.setString(getIndentification("letter"));
        window->draw(text);
    }

}

void tableSquares::loadText() {

    if (!font.loadFromFile("lib/font.ttf"))
    {
        cerr << ".Error while loading font" << std::endl;
        return;
    }

    text.setFont(font);
    text.setCharacterSize(24);

}

string tableSquares::getIndentification(string row) {

    string s = "err on tableSquares.cpp";

    if (row == "number")
        return to_string(posXid);
    else if (row == "letter") {
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
        return s;
    }

}



