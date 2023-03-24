#include "../tableSquares/tableSquares.h"
#include <iostream>
#include <SFML/Graphics.hpp>
tableSquares::tableSquares() {
    return;
}

void tableSquares::drawText(sf::RenderWindow* window) {

    sf::Text text;
    sf::Font font;
    if (!font.loadFromFile("font.ttf"))
    {
        cerr << ".Error while loading font" << std::endl;
        return;
    }
    text.setFont(font);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Black);
    text.setPosition(posXdraw, posYdraw);
    string s = to_string(posXid) + "," + to_string(posYid);
    text.setString(s);
    window->draw(text);

}

void tableSquares::drawSquare(sf::RenderWindow* window){
    sf::RectangleShape rectangle(sf::Vector2f(150.f, 150.f));

    //Selected overrides everything
    rectangle.setFillColor(color_active);
    
    rectangle.setPosition(posXdraw, posYdraw);
    window->draw(rectangle);

    drawText(window);

    //Draw wathever is inside this square
    piece.drawPiece(window);
}



