#include "Bomb.h"
#include<time.h>
//the execution
//the place where it execute
//the fuse is for 3 seconds
//it doesn't change its position during the execution but between a time and the other it can
//the explosion is instatiuos and in 8 but i will delay it for 0.1 second
Bomb::Bomb() {
    //setPos();
    texture.loadFromFile("images/bomb.png");
    sprite.setTexture(texture);
    sprite.setScale(0.1f, 0.1f);
}
void Bomb::setPos() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    pos = Vector2f(float(rand() % 400),float( rand() % 400));
}
void  Bomb::draw(RenderWindow&window) {
    sprite.setPosition(pos);
     window.draw(sprite);
    //execute(window);
}
/*void Bomb::execute() {
    font.loadFromFile("arialbd.ttf");
    text.setFont(font);
        text.setString(to_string(i));
        text.setCharacterSize(24);
        text.setFillColor(sf::Color::Red);
        text.setStyle(sf::Text::Bold | sf::Text::Underlined);
        text.setPosition(pos);
    for (int i = 3; i >= 1; i--) {
        
        while (clock.getElapsedTime().asSeconds() < 1.0f) {
            // sleep(seconds(1.0f));
        }
        clock.restart();
        text.setFillColor(Color::Transparent);
    }
}*/
void Bomb::execute(RenderWindow&window) {
    font.loadFromFile("arialbd.ttf");
    sf::Clock timer;
    while (timer.getElapsedTime().asSeconds() <= 3.0f) {
        int remainingTime = 3 - static_cast<int>(timer.getElapsedTime().asSeconds());
        text.setFont(font);
        text.setString(std::to_string(remainingTime));
        text.setCharacterSize(24);
        text.setFillColor(sf::Color::Red);
        text.setStyle(sf::Text::Bold | sf::Text::Underlined);
        text.setPosition(pos);
        // Draw the text on the bomb
        window.draw(text);

        // Update the display
        window.display();
    }
}

