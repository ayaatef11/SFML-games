#include "Enemy.h"
#include<iostream>
using namespace std;
//·„« Ìﬁ«»· ÕÌÿ… Ì—Ã⁄
//they are replaced randomly and walks to the adjacent cell and when dies it lives in another position not in the position where there is a player or another enemy
Enemy::Enemy() {
    //setPos();
    texture.loadFromFile("images/enemy.png");
    sprite.setTexture(texture);
    sprite.setTextureRect(IntRect(0,0,70.75,97.75));
    sprite.setScale(0.5f, 0.6f);
}
void Enemy::setPos() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    pos = Vector2f(float(rand()%100), float(rand()%100));
}
void  Enemy::initialize() {
    //pos = sf::Vector2f(0, 0);
    sprite.setPosition(pos);
}
void Enemy::draw(RenderWindow&window) {
    window.draw(sprite);
}
void Enemy::move() {
        int xTexture = 0;
        int yTexture = 0;
        xTexture = (int)sprite.getPosition().x / 10 % 4;
        xTexture *= 82;
        yTexture = (int)sprite.getPosition().y / 10 % 4;
        yTexture *= 82;
        if (Keyboard::isKeyPressed(Keyboard::D)) {
            sprite.setTextureRect(IntRect(xTexture, 195.5, 70.75, 97.75));
            sprite.move(25, 0);
            sleep(seconds(1.0f));
            Vector2f position = sprite.getPosition();
            cout << "Player location = " << int(position.x) % 20 << " , " << int(position.y) % 40 << endl;
        }
        else if (Keyboard::isKeyPressed(Keyboard::A)) {
            sprite.setTextureRect(IntRect(xTexture,97.75, 70.75, 97.75));
            sprite.move(-25, 0);
            sleep(seconds(1.0f));
        }
        else if (Keyboard::isKeyPressed(Keyboard::W)) {
            sprite.setTextureRect(IntRect(yTexture, 293.25, 70.75, 97.75));

            sprite.move(0, -25);
            sleep(seconds(1.0f));
        }
        else if (Keyboard::isKeyPressed(Keyboard::X)) {
            sprite.setTextureRect(IntRect(yTexture, 0, 70.75, 97.75));
            sprite.move(0, 25);
            sleep(seconds(1.0f));
        }
    }


