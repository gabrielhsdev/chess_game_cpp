#include "gameController.h"

gameController::gameController(int windowWidth, int windowHeight):myBoard(windowWidth, windowHeight)
{
    // Constructor implementation
}

void gameController::set_game_status(int status) {
	game_status = status;
}