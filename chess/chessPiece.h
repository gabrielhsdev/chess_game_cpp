#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

class chessPiece
{

	//pawn = 0; knight = 16; rook = 32; nbishop = 48; queen = 64; king = 80;
	// 0 = NULL || 1to6 BLACK || 7to12 WHITE
	int pieces[13] = { NULL, 0, 16, 32, 48, 64, 80, 0, 16, 32, 48, 64, 80 };
	
	sf::Texture texture;
	sf::Sprite sprite;

public:
	int status;
	int posXdraw;
	int posYdraw;
	int posX;
	int posY;

	chessPiece();
	void drawPiece(sf::RenderWindow* window);
};

