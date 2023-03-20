#include "chessPiece.h"
#include <iostream>

chessPiece::chessPiece() {
    status = 0;
    posXdraw = 0;
    posXdraw = 0;
    sprite.scale(sf::Vector2f(7.f, 7.f));
}

void chessPiece::drawPiece(sf::RenderWindow* window) {
    //cout << status << "\n";
    string image = "";
    if (status == 0)
        return;

    if (status >= 1 && status <= 6)
        image = "assets/blackpieces.png";
    else if (status >= 7 && status < 13) {
        image = "assets/whitepieces.png";
    }
    else {
        cerr << "WRONG STATUS ON CHESS PIECE" << posXdraw << "," << posYdraw;
    }

    if (!texture.loadFromFile(image, sf::IntRect(pieces[status], 0, 16, 16))) {
        cout << "Error loading asset folder\n";
    }

    sprite.setTexture(texture);
    sprite.setPosition(posXdraw + 8, posYdraw + 8);
    window->draw(sprite);
}