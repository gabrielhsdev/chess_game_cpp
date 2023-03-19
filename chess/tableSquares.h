#pragma once
#include<iostream>
#include "tableSquares.h"
#include <SFML/Graphics.hpp>

using namespace std;

class tableSquares
{

	//pawn = 0; knight = 16; rook = 32; nbishop = 48; queen = 64; king = 80;
	int pieces[7] = {NULL, 0, 16, 32, 48, 64, 80 };

	sf::Texture texture;
	sf::Sprite sprite;

public:

	int status;

	int posXdraw = 0;
	int posYdraw = 0;
	int posXid = 0;
	int posYid = 0;

	tableSquares();
	void setPiece(sf::RenderWindow* window, int pieceId);
	void drawText(sf::RenderWindow* window);
	void drawSquare(sf::RenderWindow* window, bool selected);
};

