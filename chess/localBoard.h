#pragma once
#include "boardStats.h"
#include "movementHandler.h"
#include <iostream>
#include <SFML/Graphics.hpp>

class localBoard : public boardStats {
	movementHandler* movement;
public:
	//Constructor is the same so we start the board all the same ways
	using boardStats::boardStats;
	void movementHandle() override {
		return;
	};
};