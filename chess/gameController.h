#pragma once
#include "boardStats.h"
#include<iostream>
#include <SFML/Graphics.hpp>

using namespace std;

class gameController
{
	/*
		1 -> Menu
		2 -> 1x1
	*/
	int game_status;
	int test = 123;;
	boardStats myBoard;
public:
	gameController(int windowWidth, int windowHeight);
	void set_game_status(int status);
};

