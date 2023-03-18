#include "tableSquares.h"

tableSquares::tableSquares() {

}

void tableSquares::drawSquare(sf::RenderWindow* window){
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
        rectangle.setFillColor(sf::Color(118, 150, 85));
        rectangle.setPosition(posXdraw, posYdraw);
    }
    else {
        rectangle.setFillColor(sf::Color(238, 238, 210));
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
        window->draw(text);
    }
}
