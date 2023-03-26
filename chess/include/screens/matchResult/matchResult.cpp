#include "matchResult.h"

matchResult::matchResult(int lastWinner)

    : winner(lastWinner) //white 1 black 2
{
    if (!font.loadFromFile("lib/font.ttf")) {
        cerr << "Error loading font matchResult.cpp\n";
    }

    titleTextDisplay();
    btnTextDisplay();

}

void matchResult::displayScreen(sf::RenderWindow* window, int* game_status) {

    window->draw(titleText);
    window->draw(btnStart);
    window->draw(btnText);
    clickHandler(game_status);

}

void matchResult::btnTextDisplay() {

    btnStart.setFillColor(sf::Color(150, 50, 250));
    btnStart.setSize(sf::Vector2f(300, 50));
    btnStart.setPosition(50, 100);

    btnText.setFont(font);
    btnText.setString("START GAME");
    btnText.setFillColor(sf::Color::White);
    btnText.setStyle(sf::Text::Bold);
    btnText.setCharacterSize(20);
    btnText.setPosition(60, 110);

}

void matchResult::titleTextDisplay() {

    titleText.setFont(font);
    titleText.setString(getMatchWinnerString());
    titleText.setFillColor(sf::Color::White);
    titleText.setStyle(sf::Text::Bold | sf::Text::Underlined);
    titleText.setCharacterSize(24);
    titleText.setPosition(50, 50);

}

void matchResult::clickHandler(int* game_status) {

    if (50 < mouse_position.x
        && 50 + 300 > mouse_position.x
        && 100 < mouse_position.y
        && 100 + 50 > mouse_position.y) {

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            *game_status = 2;
        }

    }

}

string matchResult::getMatchWinnerString() {

    switch (winner) {
    case 1:
        return "CURRENT MATCH WINNER IS : WHITE";
    case 2:
        return "CURRENT MATCH WINNER IS : BLACK";
    default:
        return "Click on START GAME to initiate a new match!";
    }
    
}