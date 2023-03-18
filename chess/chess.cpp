#include "boardStats.h"
#include<iostream>
#include <SFML/Graphics.hpp>

using namespace std;

const int Windowheight = 1200;
const int Windowwidth = 1200;
int spacesN[8][8][2];

int main()
{

    int squareSize = (Windowwidth) / 8;
    boardStats myBoard(Windowwidth, Windowheight);

    // create the window
    sf::RenderWindow window(sf::VideoMode(Windowwidth, Windowheight), "Not Chess", sf::Style::Titlebar | sf::Style::Close);
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