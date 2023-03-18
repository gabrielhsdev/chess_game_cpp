#include "gameController.h"
#include <SFML/Graphics.hpp>

gameController::gameController(int windowWidth, int windowHeight) : local_BOARD (windowWidth, windowHeight)
{
    // Constructor implementation
}

void gameController::print_game_status(sf::RenderWindow* window) {
	//Set what will be rendered each frame here
	if (game_status == 2) {
		local_BOARD.mouse_position = mouse_position;
		local_BOARD.buildBoard(window);
	}
}