#include "Player.h"
//áãÇ íÞÇÈá ÍíØÉ íÑÌÚ
//the player drop the bomb
Player::Player() {
    texture.loadFromFile("images/marioAnimation-removebg-preview.png");
    sprite.setTexture(texture);
    sprite.setTextureRect(IntRect(143, 96.5, 35.75, 48.25));
    sprite.setScale(1.0f, 1.0f);
}
void Player::setPos() {
    pos = Vector2f(0, 0);
}
void Player::initialize() {
    pos = sf::Vector2f(0, 0);
    sprite.setPosition(pos);
}
void Player::move() {///the movement to  the borders isn't so well
    int xTexture = 0;
    int yTexture = 0;
    xTexture = (int)sprite.getPosition().x / 10 % 12;
    xTexture *= 35.75;
    yTexture = (int)sprite.getPosition().y / 10 % 4;
    yTexture *= 35.75;
    if (Keyboard::isKeyPressed(Keyboard::D)) {
        sprite.setTextureRect(IntRect(xTexture, 48.25, 35.75, 48.25));
        sprite.move(40, 0);
    }
    else if (Keyboard::isKeyPressed(Keyboard::A)) {
        sprite.setTextureRect(IntRect(xTexture, 144.75, 35.75, 48.25));
        sprite.move(-40, 0);
    }
    else if (Keyboard::isKeyPressed(Keyboard::W)) {
        sprite.setTextureRect(IntRect(yTexture, 0, 35.75, 48.25));
        sprite.move(0, -40);
    }
    else if (Keyboard::isKeyPressed(Keyboard::X)) {
        sprite.setTextureRect(IntRect(yTexture, 96.5, 35.75, 48.25));
        sprite.move(0, 40);
    }
    if (sprite.getPosition().x >= 800 - 35.75) sprite.move(-40, 0);
    else if (sprite.getPosition().x <= 35.75) sprite.move(40, 0);
    if (sprite.getPosition().y >= 800 - 48.25)sprite.move(0, -40);
    else if (sprite.getPosition().y <= 48.25)sprite.move(0, 40);
    if (Keyboard::isKeyPressed(Keyboard::D)||(Keyboard::isKeyPressed(Keyboard::A))||
        (Keyboard::isKeyPressed(Keyboard::W))||( Keyboard::isKeyPressed(Keyboard::X))){
        Vector2f position = sprite.getPosition();
        cout << "Player location = " << int(position.x) / 40+1 << " , " << int(position.y) / 40 + 1 << endl;
        sleep(seconds(1.0f));
    }
}
void Player::draw(RenderWindow&window) {
    window.draw(sprite);
}
