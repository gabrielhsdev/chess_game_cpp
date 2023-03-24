#include "../gameController/gameController.h"
#include <SFML/Graphics.hpp>

gameController::gameController(int windowWidth, int windowHeight)
{
    // Constructor implementation, set status to be the menu ? 
	return;
}

//This will be running each frame
void gameController::print_game_status(sf::RenderWindow* window) {

	// Delete the local board object if it exists but game status is not 2
	if (game_status != 2 && local_BOARD != nullptr) 
	{
		delete local_BOARD;
		local_BOARD = nullptr;
	}

	//Check game mode 1v1 is active
	if (game_status == 2) 
	{
		//Check a new object is needed
		if (local_BOARD == nullptr) {
			local_BOARD = new localBoard(window->getSize().x, window->getSize().y);
			cout << "BOARD IS CREATED! - gameController \n";
		}
		local_BOARD->mouse_position = mouse_position;
		local_BOARD->buildBoard(window);
	}

}