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
    else
    {
        cerr << "WRONG STATUS ON CHESS PIECE" << posXdraw << "," << posYdraw;
    }

    if (!texture.loadFromFile(image, sf::IntRect(pieces[status], 0, 16, 16))) {
        cout << "Error loading asset folder\n";
    }

    sprite.setTexture(texture);
    sprite.setPosition(posXdraw + 8, posYdraw + 8);
    window->draw(sprite);
}

//pawn = 0; knight = 16; rook = 32; bishop = 48; queen = 64; king = 80;
string chessPiece::getPieceStatus(string stat) {
    if (stat == "name") {
        if (status == 1 || 7)
            return "pawn";
        if (status == 2 || 8)
            return "knight";
        if (status == 3 || 9)
            return "rook";
        if(status == 4 || 10)
            return "bishop";
        if(status == 5 || 11)
            return "queen";
        if(status == 6 || 12)
            return "king";
        else {
            cerr << "WRONG PIECE STATUS ON GET";
        } 
    }

    if (stat == "color") {
        if (status >= 1 && status <= 6) {
            return "black";
        } else if (status >= 7 && status <= 12) {
            return "white";
        }
        else {
            cerr << "WRONG PIECE STATUS ON GAT ERR 2";
        }
    }

    if (stat == "isalive") {
        if (status == 0)
            return "dead";
        else if (status >= 1 && status <= 12)
            return "alive";
        else
            cerr << "WRONG PIECE STATUS ON GAT ERR 2";
    }
}
