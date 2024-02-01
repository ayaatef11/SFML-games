#pragma once
#include<SFML/Graphics.hpp>
using namespace sf;
    class Enemy :public Sprite {
    public:
        Sprite sprite;
        Texture texture;
        Vector2f pos;
        Enemy();
        void setPos();
       void initialize();
        void draw(RenderWindow&);
        void move();
    };

