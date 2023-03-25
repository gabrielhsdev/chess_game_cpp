#pragma once
#include "../boardStats/boardStats.h"
#include "../localBoard/localBoard.h"
#include "../screens/matchResult/matchResult.h"
#include<iostream>
#include <SFML/Graphics.hpp>

using namespace std;

class gameController
{
	/*
		game status:
		2 -> 1x1
		3 -> Result screen 
	*/

	//1v1 local board object
	localBoard * local_BOARD;
	
	//Last match result
	matchResult* result_screen;

public:

	int game_status = 0;
	int lastWinner = 0;

	//Mouse position
	sf::Vector2i mouse_position;

	gameController(int windowWidth, int windowHeight);

	//This will be running 100% of the time
	void print_game_status(sf::RenderWindow* window);
};

