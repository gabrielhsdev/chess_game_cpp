#include "tableSquares.h"
#include <SFML/Graphics.hpp>
tableSquares::tableSquares() {

    int pieces[6] = { 0, 16, 32, 48, 64, 80 };
    /*
    int pawn = 0;
    int knight = 16;
    int rook = 32;
    int bishop = 48;
    int queen = 64;
    int king = 80;
    */

    if (!texture.loadFromFile("assets/whitepieces.png", sf::IntRect(pieces[0], 0, 16, 16)))
    {
        cout << "Error loading asset folder\n";
    }
    //texture.setSmooth(true);
    sprite.setTexture(texture);
    sprite.scale(sf::Vector2f(8.f, 8.f));
}

void tableSquares::drawSquare(sf::RenderWindow* window, bool selected){
    sf::Text text;
    sf::Font font;

    if (!font.loadFromFile("font.ttf"))
    {
        cerr << ".Error while loading font" << std::endl;
        return;
    }

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
        text.setFont(font);
        text.setCharacterSize(24);
        text.setFillColor(sf::Color::Black);
        text.setPosition(posXdraw, posYdraw);
        string s = to_string(posXid);
        text.setString(s);
        //window->draw(text);
    }
    
    sprite.setPosition(posXdraw, posYdraw);

    window->draw(sprite);
}

void tableSquares::fillSquare() {

}


