#include "gameController.h"

gameController::gameController(int windowWidth, int windowHeight) : local_BOARD (windowWidth, windowHeight)
{
    // Constructor implementation
}

void gameController::set_game_status(int status) {
	game_status = status;
}

void gameController::print_game_status(int status) {
	//Set what will be rendered each frame here
	if (status == 2) {
		local_BOARD.mouse_position = mouse_position;
	}
}