#pragma once
#include<iostream>
#include "tableSquares.h"
#include <SFML/Graphics.hpp>

using namespace std;

class tableSquares
{
	sf::Texture texture;
	sf::Sprite sprite;
	void fillSquare();

public:
	//NULL, Pawn, Bishop, Knight. Rook, Queen, King
	int status = 0;

	int posXdraw = 0;
	int posYdraw = 0;
	int posXid = 0;
	int posYid = 0;

	tableSquares();
	void drawSquare(sf::RenderWindow* window, bool selected);
};

