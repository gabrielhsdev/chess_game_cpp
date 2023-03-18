#include "boardStats.h"
#include "gameController.h"
#include<iostream>
#include <SFML/Graphics.hpp>

using namespace std;

extern int windowheight = 1200;
extern int windowwidth = 1200;

//Fix mouse position so last seen is always inside window
sf::Vector2i fix_position(sf::Vector2i position) {
    /*
    * On mouse click example
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        cout << "sheeeeeeehs";
    }
    */
    return position;
}

int main()
{

    int squareSize = (windowwidth) / 8;
    boardStats myBoard(windowwidth, windowheight);
    gameController gameCtrl(windowwidth, windowheight);

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

        //Example of mouse position being passes to other child objects of game controller
        //sf::Vector2i position = sf::Mouse::getPosition(window);
        //cout << position.x << "-" << position.y << "\n";
        //gameCtrl.mouse_position = position;


        //Build stuff here !
        myBoard.buildBoard(&window);

        // end the current frame
        window.display();
    }
    return 0;
}