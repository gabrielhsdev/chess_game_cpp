#include "boardStats.h"
#include "gameController.h"
#include<iostream>
#include <SFML/Graphics.hpp>

using namespace std;

extern int windowheight = 1200;
extern int windowwidth = 1200;

int main()
{

    int squareSize = (windowwidth) / 8;
    boardStats myBoard(windowwidth, windowheight);
    gameController gameCtrl(300, 300);

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
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        myBoard.buildBoard(&window);//test build for our setup
        // draw everything here...

        // end the current frame
        window.display();
    }

    return 0;
}