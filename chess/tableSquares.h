#pragma once
#include<iostream>
#include "tableSquares.h"
#include "chessPiece.h"
#include <SFML/Graphics.hpp>

using namespace std;

class tableSquares
{

public:

	//One piece per tile
	chessPiece piece;
	int status;

	int posXdraw = 0;
	int posYdraw = 0;
	int posXid = 0;
	int posYid = 0;

	sf::Color color_active;
	sf::Color color_default;
	sf::Color color_selected;
	sf::Color color_action;

	tableSquares();
	void drawText(sf::RenderWindow* window);
	void drawSquare(sf::RenderWindow* window, bool selected);
};

