#include "boardStats.h"
#include "gameController.h"
#include<iostream>
#include <SFML/Graphics.hpp>

using namespace std;

extern int windowheight = 1024;
extern int windowwidth = 1024;

int main()
{
    int squareSize = (windowwidth) / 8;
    gameController gameCtrl(windowwidth, windowheight);
    gameCtrl.game_status = 2;
    // create the window
    sf::RenderWindow window(sf::VideoMode(windowwidth, windowheight), "Not Chess", sf::Style::Titlebar | sf::Style::Close);
    sf::err().rdbuf(NULL);
    // run the program as long as the window is open
    while (window.isOpen())
    {
        window.clear();

        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            window.setKeyRepeatEnabled(false);
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        //Example of mouse position being passes to other child objects of game controller
        sf::Vector2i position = sf::Mouse::getPosition(window);
        gameCtrl.mouse_position = position;
        //cout << position.x << "-" << position.y << "\n";

        //Build stuff here !
        //myBoard.buildBoard(&window);
        gameCtrl.print_game_status(&window);

        // end the current frame
        window.display();
    }
    return 0;
}