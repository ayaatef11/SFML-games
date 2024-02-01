#include"maze.h"
//loas in a file including the number of enemies and the size of the array
//collision detection
Maze::Maze() {
    setPos();
	wall.loadFromFile("images/wallMazeGame.png");
	corridor.loadFromFile("images/BackGround.png");
	Swall.setTexture(wall);
	Sgrass.setTexture(corridor);
	//Sgrass.setColor(Color::Magenta);
	Swall.setTextureRect(IntRect(0, 0, int(width), int(height)));
	Sgrass.setTextureRect(IntRect(0, 0, int(width), int(height)));
	for (int i = 0; i < 20; i++) {
		for (int j = 1; j <= 20; j++) {
			Sgrass.setPosition({ i * width,j * height });
			sGrid[i][j] =Sgrass;
			if (rand() % 100 < 30) {
				Swall.setPosition({ i * width,j * height });
				sGrid[i][j] = Swall;
			}
		}
	}

}
void Maze::setPos() {
    pos = Vector2f(0,0);
}
void Maze::draw(RenderWindow&window) {
	for (int i = 0; i < 20; i++) {
		for (int j = 1; j <= 20; j++) {
			window.draw(sGrid[i][j]);
		}
	}
}
void Maze::setStatue() {	
	for (int i = 0; i < 20; i++) {
		for (int j = 1; j <= 20; j++) {
			bool check = false;
			for (int m = 0; m < 5; m++) {
				if (i == enemy[m].getPosition().x  &&j== enemy[m].getPosition().y) {
					grid[i][j] = 1;
					check = true;
					break ;
				}
			}
			if (check)continue;
			else if (i == player.getPosition().x && j == player.getPosition().y) grid[i][j] = 2;
			else if (i == bomb.getPosition().x && j == bomb.getPosition().y) grid[i][j] = 3;
			else if (sGrid[i][j].getTexture() == Swall.getTexture()) grid[i][j] = 4;
		}
	}
}