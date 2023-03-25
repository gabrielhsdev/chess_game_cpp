#include "matchResult.h"

matchResult::matchResult(int lastWinner) {

	winner = lastWinner;//white 1 black 2

	if (!font.loadFromFile("lib/font.ttf"))
	{
		cerr << "\nerror loading font matchResult.cpp\n";
	}

	titleTextDisplay();
	btnTextDisplay();

}

void matchResult::displayScreen(sf::RenderWindow* window) {

	window->draw(titleText);
	window->draw(btnStart);
	window->draw(btnText);

	return;

}

void matchResult::btnTextDisplay() {

	btnStart.setFillColor(sf::Color(150, 50, 250));
	btnStart.setSize(sf::Vector2f(300, 50));
	btnStart.setPosition(50, 100);

	btnText.setFont(font);
	btnText.setFillColor(sf::Color::White);
	btnText.setStyle(sf::Text::Bold);
	btnText.setCharacterSize(20);
	btnText.setPosition(60, 110);

	string str = "START GAME";
	btnText.setString(str);
}

void matchResult::titleTextDisplay() {

	titleText.setFont(font);
	titleText.setFillColor(sf::Color::White);
	titleText.setStyle(sf::Text::Bold | sf::Text::Underlined);
	titleText.setCharacterSize(24);
	titleText.setPosition(50, 50);

	string str = "";

	if (winner == 1) {
		str = "CURRENT MATCH WINNER IS : WHITE !";
	}
	else if (winner == 2) {
		str = "CURRENT MATCH WINNER IS : BLACK !";
	}
	else {
		str = "Click on new game to start!";
	}

	titleText.setString(str);

}

void matchResult::clickHandler() {



	return;

}