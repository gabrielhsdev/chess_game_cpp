#include "tableSquares.h"
#include <iostream>
#include <SFML/Graphics.hpp>
tableSquares::tableSquares() {
    sprite.scale(sf::Vector2f(7.f, 7.f));
}

void tableSquares::setPiece(sf::RenderWindow* window, int pieceId) {
    string image = "";
    if (pieceId == 0)
        return;

    if (pieceId >= 1 && pieceId <= 6)
        image = "assets/blackpieces.png";
    else if (pieceId >= 7 && pieceId < 13) {
        pieceId = pieceId - 6;
        image = "assets/whitepieces.png";
    }
 
    if (!texture.loadFromFile(image, sf::IntRect(pieces[pieceId], 0, 16, 16))) {
        cout << "Error loading asset folder\n";
    }

    sprite.setTexture(texture);
    sprite.setPosition(posXdraw + 8, posYdraw + 8);
    window->draw(sprite);
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
    string s = to_string(posXid);
    text.setString(s);
    window->draw(text);

}

void tableSquares::drawSquare(sf::RenderWindow* window, bool selected){

    sf::RectangleShape rectangle(sf::Vector2f(150.f, 150.f));

    //Set rectangle position on screen and color
    if ((posXid + posYid) % 2 == 0) {
        if (selected == true) {
            rectangle.setFillColor(sf::Color(102, 125, 77));
        }
        else {
            rectangle.setFillColor(sf::Color(118, 150, 85));
        }
        rectangle.setPosition(posXdraw, posYdraw);
    }
    else {
        if (selected == true) {
            rectangle.setFillColor(sf::Color(194, 194, 169));
        }
        else {
            rectangle.setFillColor(sf::Color(238, 238, 210));
        }
        rectangle.setPosition(posXdraw, posYdraw);
    }

    window->draw(rectangle);

    //Draw text id
    if (posYid == 0) {
        drawText(window);
    }
    
    //Draw wathever is inside this square
    setPiece(window, status);
    

}



