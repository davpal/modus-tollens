#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Modus tollens",
                            sf::Style::Fullscreen | sf::Style::Titlebar | sf::Style::Close);

    sf::Texture texture;
    sf::Sprite sprite;
    if (!texture.loadFromFile("resources/fields/meadow.png"))
    {
        // err
    }
    sprite.setTexture(texture);

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        // window.draw(...);

        window.draw(sprite);

        // end the current frame
        window.display();
    }
    return 0;
}