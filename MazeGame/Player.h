#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
using namespace std;
using namespace sf;
class Player :public Sprite {
public:

    Vector2f pos;
        Sprite sprite;
        Texture texture;
        Player();
        void setPos();
        void initialize();
        void move();
        void draw(RenderWindow&);
    };

