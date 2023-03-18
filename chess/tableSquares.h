#pragma once
#include "tableSquares.h"
#include <SFML/Graphics.hpp>

class tableSquares
{
public:
	int status = 0;
	int team = 0;

	int posXdraw = 0;
	int posYdraw = 0;

	int posXid = 0;
	int posYid = 0;

	tableSquares();
	void fillSquare(sf::RenderWindow* window);
};

