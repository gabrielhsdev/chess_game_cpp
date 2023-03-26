#include "../gameController/gameController.h"
#include <SFML/Graphics.hpp>

//This will be running each frame
void gameController::print_game_status(sf::RenderWindow* window) {

	// Delete the local board object if it exists but game status is not 2
	if (game_status != 2 && local_BOARD != nullptr) 
	{
		delete local_BOARD;
		local_BOARD = nullptr;
	}

	//Game mode 1v1 is active
	if (game_status == 2) 
	{
		//Check a new object is needed
		if (local_BOARD == nullptr) {
			local_BOARD = new localBoard(window->getSize().x, window->getSize().y);
			cout << "BOARD IS CREATED! - gameController \n";
		}
		local_BOARD->mouse_position = mouse_position;
		local_BOARD->buildBoard(window);
		if (local_BOARD->winner != 0) {
			lastWinner = local_BOARD->winner;
			game_status = 3;
		}
	}

	//Match end screen
	if (game_status != 3 && result_screen != nullptr)
	{
		delete result_screen;
		result_screen = nullptr;
	}

	if (game_status == 3) {

		//Check a new object is needed
		if (result_screen == nullptr) {
			result_screen = new matchResult(lastWinner);
			cout << "MATCH RESULT SCREEN IS CREATED \n";
		}

		result_screen->mouse_position = mouse_position;
		result_screen->displayScreen(window, &game_status);
		
	}

}