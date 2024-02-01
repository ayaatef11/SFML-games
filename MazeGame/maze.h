#pragma once
#include<iostream>
#include<fstream>
#include<SFML/Graphics.hpp>
#include"Player.h"
#include"Enemy.h"
#include"Bomb.h"
using namespace sf;
using namespace std;
enum state{EMPTY,ENEMY,PLAYER,BOMB,WALL};
class Maze :public Sprite {
public:
    float width = 40;
    float height = 40;
    int grid[22][22] = { 0 };
    Sprite sGrid[22][22];

    //the game
    Vector2f pos;
    Texture wall;
    Texture corridor;
    Sprite Swall,Sgrass;

    //objects
    Player player;
    Bomb bomb;
    Enemy enemy[5];//every level the enemies increase 
    bool status;///////////////////////////////////////////////////////////

    //functions
    Maze();
    void setPos();
    void draw(RenderWindow&window);
    void setStatue();
   // bool overlapping();//i have objects the bomb ,enemy,player,wall

};