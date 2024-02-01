#pragma once
//#pragma warning
#include <iostream>
#include<SFML/Graphics.hpp>
using namespace sf;
#include<thread>
class Bomb:public Sprite   {
public:
    //i musst build a default constructor that the moment i create the object it draws it and gives it position other things aren't important
    //i must also set the position before i draw the sprite
    Texture texture;
    Sprite sprite;
    Vector2f pos;
    Font font;
    Text text;
   // Clock clock;
    Bomb();
    void setPos();
    void  draw(RenderWindow&);
    void execute(RenderWindow&);
};
    

