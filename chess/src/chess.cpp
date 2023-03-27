#include "../include/gameController/gameController.h";
#include "../include/boardStats/boardStats.h";

#include <windows.h>
#include<iostream>
#include <SFML/Graphics.hpp>

using namespace std;

extern int windowheight = 1024;
extern int windowwidth = 1024;

//Disable console later on debug
int main()
{
    int squareSize = (windowwidth) / 8;

    gameController gameCtrl;
    sf::RenderWindow window(sf::VideoMode(windowwidth, windowheight), "Not Chess", sf::Style::Titlebar | sf::Style::Close);
    sf::Vector2i position;
    sf::err().rdbuf(NULL);

    gameCtrl.game_status = 3;

    //Run program
    while (window.isOpen())
    {
        window.clear();

        //Check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;

        while (window.pollEvent(event))
        {
            window.setKeyRepeatEnabled(false);
            if (event.type == sf::Event::Closed)
                window.close();
        }

        //Constantly get mouse position
        position = sf::Mouse::getPosition(window);
        gameCtrl.mouse_position = position;

        //Game controller starts here
        gameCtrl.print_game_status(&window);

        //End frame
        window.display();
    }
    return 0;
}