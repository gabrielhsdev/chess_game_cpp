#include "chessPiece.h"
#include <iostream>

chessPiece::chessPiece() {
    status = 0;
    posXdraw = 0;
    posXdraw = 0;
    sprite.scale(sf::Vector2f(7.f, 7.f));

    //Load both textures, cant be in the same if statement, error occurs
    if (!texture_b.loadFromFile("lib/images/blackpieces.png")){
        cout << "Error loading asset folder\n";
    }
    if (!texture_w.loadFromFile("lib/images/whitepieces.png")) {
        cout << "Error loading asset folder\n";
    }
}

void chessPiece::drawPiece(sf::RenderWindow* window) {

    string image = "";
    if (status == 0 || status > 12) {
        if(status > 12)
            cout << "INVALID STATUS FOR PIECE, RETURNED 0 -> " << status;
        return;
    }

    if (status >= 1 && status <= 6) 
        texture = texture_b;
    else
        texture = texture_w;

    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(pieces[status], 0, 16, 16));
    sprite.setPosition(posXdraw + 8, posYdraw + 8);
    window->draw(sprite);

}

//pawn = 0; knight = 16; rook = 32; bishop = 48; queen = 64; king = 80;
string chessPiece::getPieceStatus(string stat) {

    if (status == 0)
        return "empty";
    else if (stat == "name") {

        if (status == 1 || status == 7)
            return "pawn";
        if (status == 2 || status == 8)
            return "knight";
        if (status == 3 || status == 9)
            return "rook";
        if (status == 4 || status == 10)
            return "bishop";
        if(status == 5 || status == 11)
            return "queen";
        if(status == 6 || status == 12)
            return "king";
        else
            cerr << "WRONG PIECE STATUS ON GET";

    }else if (stat == "color") {

        if (status >= 1 && status <= 6)
            return "black";
        else if (status >= 7 && status <= 12)
            return "white";
        else
            cerr << "WRONG PIECE STATUS ON GAT ERR 2";

    } else if (stat == "isalive") {

        if (status == 0)
            return "dead";
        else if (status >= 1 && status <= 12)
            return "alive";
        else
            cerr << "WRONG PIECE STATUS ON GAT ERR 2";

    }else
        cerr << "WRONG STATUS ASK FOR CON GET PIECE STATUS";
}
