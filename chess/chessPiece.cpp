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

    //Image loading and resizing causing too much trouble, fix it later
    if (status == -1) {
        image = "assets/pawn.png";
        if (!texture.loadFromFile(image)) {
            cout << "Error loading asset folder\n";
        }
        sprite.setTexture(texture);
        sprite.setScale(0.1f, 0.1f);
        sprite.setPosition(posXdraw, posYdraw);
    }
    else if (status >= 1 && status <= 6) {
        image = "assets/blackpieces.png";
        if (!texture.loadFromFile(image, sf::IntRect(pieces[status], 0, 16, 16))) {
            cout << "Error loading asset folder\n";
        }
        sprite.setTexture(texture);
        sprite.setPosition(posXdraw + 8, posYdraw + 8);
    }
    else if (status >= 7 && status < 13) {
        image = "assets/whitepieces.png";
        if (!texture.loadFromFile(image, sf::IntRect(pieces[status], 0, 16, 16))) {
            cout << "Error loading asset folder\n";
        }
        sprite.setTexture(texture);
        sprite.setPosition(posXdraw + 8, posYdraw + 8);
    }
    else
    {
        cerr << "WRONG STATUS ON CHESS PIECE" << posXdraw << "," << posYdraw;
    }

    window->draw(sprite);
}

//pawn = 0; knight = 16; rook = 32; bishop = 48; queen = 64; king = 80;
string chessPiece::getPieceStatus(string stat) {

    if (status == 0) {
        return "empty";
    } else if (stat == "name") {

        if (status == 1 || status == 7)
            return "pawn";
        if (status == 2 || status == 8)
            return "knight";
        if (status == 3 || status == 9)
            return "rook";
        if (status == 4 || status == 10) {
            return "bishop";
        }
        if(status == 5 || status == 11)
            return "queen";
        if(status == 6 || status == 12)
            return "king";
        else {
            cerr << "WRONG PIECE STATUS ON GET";
        } 

    }else if (stat == "color") {

        if (status >= 1 && status <= 6) {
            return "black";
        } else if (status >= 7 && status <= 12) {
            return "white";
        }
        else {
            cerr << "WRONG PIECE STATUS ON GAT ERR 2";
        }

    } else if (stat == "isalive") {

        if (status == 0)
            return "dead";
        else if (status >= 1 && status <= 12)
            return "alive";
        else
            cerr << "WRONG PIECE STATUS ON GAT ERR 2";

    } else {
        cerr << "WRONG STATUS ASK FOR CON GET PIECE STATUS";
    }
}
