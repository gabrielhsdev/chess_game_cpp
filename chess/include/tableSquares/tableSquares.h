#pragma once
#include "../tableSquares/tableSquares.h"
#include "../chessPiece/chessPiece.h"
#include <SFML/Graphics.hpp>

using namespace std;

class tableSquares
{

public:

	//Piece related variables
	chessPiece piece;
	int status = 0;

	//Identification variables
	int posXdraw = 0;
	int posYdraw = 0;
	int posXid = 0;
	int posYid = 0;

	//Color being rendered
	sf::Color color_active;

	//Stored colors for usage
	sf::Color color_default;
	sf::Color color_selected;
	sf::Color color_action;

	//Text functions
	sf::Text text;
	sf::Font font;

	//Constructor
	tableSquares();

	//Draw functions
	void loadText();
	void drawText(sf::RenderWindow* window);
	void drawSquare(sf::RenderWindow* window);
	string getIndentification(string row);
};

