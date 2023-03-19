#pragma once
#include "boardStats.h"
#include "localBoard.h"
#include<iostream>
#include <SFML/Graphics.hpp>

using namespace std;

class gameController
{
	/*
		game status:
		1 -> Menu
		2 -> 1x1
	*/

	//1v1 local board object
	localBoard * local_BOARD;
public:
	//Mouse position
	int game_status = 0;
	sf::Vector2i mouse_position;

	gameController(int windowWidth, int windowHeight);

	//This will be running 100% of the time
	void print_game_status(sf::RenderWindow* window);
};

