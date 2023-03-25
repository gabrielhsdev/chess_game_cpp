#include<iostream>
#include <SFML/Graphics.hpp>

using namespace std;

class matchResult
{
	public:

		sf::Vector2i mouse_position;
		sf::Font font;

		//Title text
		sf::Text titleText;

		//Button start game
		sf::RectangleShape btnStart;
		sf::Text btnText;
		
		int winner = 0;

		matchResult(int lastWinner);
		void displayScreen(sf::RenderWindow* window);
		void clickHandler();

		void titleTextDisplay();
		void btnTextDisplay();

};