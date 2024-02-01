// MazeGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include<thread>
#include<chrono>
#include"maze.h"
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
//«·ﬁ‰»·… » ‰›Ã— ﬂ· Œ„” œﬁ«Ìﬁ
//«·«⁄œ«¡ »Ì€Ì—Ê „ﬂ«‰Â„ ﬂ· œﬁÌﬁ…
//***********************************EDIT INHERTIENCE OF SPRITE
//the hearts,time,score
#include <cstdlib>
#include <ctime>
using namespace std;
using namespace sf;
int main() {
	Music music;
	music.openFromFile("SFMLsong.ogg");
	music.setLoop(true);
	Maze maze;
	Text text1,text2;
	Font font;
	font.loadFromFile("arialbd.ttf");
	text1.setFont(font);
	text1.setFillColor(Color::Black);
	text1.setString("Time: ");
	text1.setCharacterSize(30);
	text1.setPosition(200, 0);
	text2 = text1;
	text2.setPosition(0, 0);
	text2.setString("Score: ");
	Texture t1,t2;
	t1.loadFromFile("images/heart.png");
	t2.loadFromFile("images/HeartDrawing.png");
	Sprite s1(t1),s2(t2);
	s1.setScale(0.1f, 0.1f);
	s1.setPosition(600, 0);
	s2.setScale(0.1f, 0.1f);
	s2.setPosition(500, 0);
	int n = s2.getPosition().y;
	int m = s2.getPosition().x;
	//s2.setColor(Color::White);
	//s.getInverseTransform();
	//s.setColor(Color::Transparent);
	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	RenderWindow window(VideoMode(800, 840), "walls");
	window.setFramerateLimit(60);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
		window.clear(Color::White);
		maze.draw(window);
		maze.player.draw(window);
		maze.player.move();
		maze.bomb.draw(window);

		for (int i = 0; i < 5; i++) {
			maze.enemy[i].draw(window);
		}
		window.draw(text1);
		window.draw(text2);
		window.draw(s1);
		for (int i = 0; i < 3; i++) {
			window.draw(s2);
			s2.setPosition(m,n+s2.getGlobalBounds().width/2);
		}
		maze.enemy[1].move();
		//music.play();
		window.display();

	}
}





// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
