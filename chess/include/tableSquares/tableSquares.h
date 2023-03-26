#pragma once
#include "../tableSquares/tableSquares.h"
#include "../chessPiece/chessPiece.h"
#include <SFML/Graphics.hpp>

using namespace std;

class tableSquares
{

public:

	//One piece per tile
	chessPiece piece;
	int status = 0;

	int posXdraw = 0;
	int posYdraw = 0;
	int posXid = 0;
	int posYid = 0;

	//Color being rendered
	sf::Color color_active;

	//Saved colors for later
	sf::Color color_default;
	sf::Color color_selected;
	sf::Color color_action;

	//Set text
	sf::Text text;
	sf::Font font;

	tableSquares();
	void drawText(sf::RenderWindow* window);
	void drawSquare(sf::RenderWindow* window);
	string getIndentification();
};

