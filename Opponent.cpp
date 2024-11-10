#include "Opponent.h"




Opponent::Opponent(Opponent& temp, int x, int y, std::string _debugname) {
	type = temp.type;;
	debugname = _debugname;

	movespeed = temp.movespeed;
	maxHealth = temp.maxHealth;
	imageindex = temp.imageindex;
	currHealth = maxHealth;

	main = Plane(x, y, imageindex);
}

std::string Opponent::SaveOpponent() {
	std::string result;
	result += debugname += ": " + std::to_string(type) + " " + std::to_string(main.x) + " " + std::to_string(main.y) + " " + std::to_string(currHealth) + " " + std::to_string(alive) + "\n";
	return result;
}

Opponent::Opponent(int x, int y, int speed, int _health, ImageIndex _imageindex, int _type) {
	movespeed = speed;
	maxHealth = _health;
	currHealth = maxHealth;
	type = _type;

	imageindex = _imageindex;
	main = Plane(x, y, imageindex);
}

int Opponent::followSpeed(int a, int b) {
	if (a > b)return movespeed;
	else if (a < b)return -movespeed;
	else return 0;
}

void Opponent::follow(int x, int y) {
	int movex = followSpeed(x, main.x);
	int movey = followSpeed(y, main.y);

	update(movex, movey);
	main.update(movex, movey);
}
