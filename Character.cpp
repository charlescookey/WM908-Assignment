#include "Character.h"


void Character::Death() {
	//we can play a death animation;
	//also can delete this class.
}
bool Character::isAlive() {
	return currHealth > 0;
}

void Character::setImageWidthAndHeight(Vec2 WH) {
	main.setWidthAndHeight(WH);
}

//we can make it virtual and override the main one lol;
void Character::takeDamage(int damage) {
	currHealth -= damage;
	currHealth = max(0, currHealth);

	if (currHealth == 0) {
		alive = false;
		//Death();
	}
}

void Character::update(int x, int y) {
	if (!alive)return;
	if (x == 0 && y == 0) {
		imageOffset = 0;
		frames = 0;
		return;
	}
	if (x > 0) {
		right = true;
	}
	else if (x < 0) {
		right = false;
	}
	frames++;
	imageOffset = (frames / 2) % 10;
}

void Character::draw(GamesEngineeringBase::Window& canvas, Gallery& gallery) {
	if (!alive)return;
	if (right)
		gallery.draw(canvas, main.imageindex, imageOffset, main);
	else
		gallery.backDraw(canvas, main.imageindex, imageOffset, main);
	drawHealth(canvas, main.x, main.y - 5);
}

void Character::drawAt(GamesEngineeringBase::Window& canvas, Gallery& gallery, int x, int y) {
	if (!alive)return;
	if (right)
		gallery.drawAt(canvas, main.imageindex, imageOffset, x, y);
	else
		gallery.backDrawAt(canvas, main.imageindex, imageOffset, x, y);
}

void Character::drawHealth(GamesEngineeringBase::Window& canvas, int X, int Y) {
	if (!alive)return;
	for (unsigned int i = 0; i < main.width; i++)
		if (X + i < canvas.getWidth() && X + i >= 0)
			for (unsigned int j = 0; j < 4; j++)
				if (Y + j < canvas.getHeight() && Y + j >= 0)
					canvas.draw(X + i, Y + j, 0, 0, 0);

	int s = (currHealth * main.width) / maxHealth;
	for (unsigned int i = 0; i < s; i++)
		if (X + i < canvas.getWidth() && X + i >= 0)
			for (unsigned int j = 0; j < 4; j++)
				if (Y + j < canvas.getHeight() && Y + j >= 0)
					canvas.draw(X + i, Y + j, 255, 0, 0);
}

