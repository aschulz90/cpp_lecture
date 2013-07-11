#include "sfmltest.hpp"

#include <SFML/Window.hpp>


void createSfmlWindow()
{
	sf::Window window(sf::VideoMode(800, 600), "Test window");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }
}
