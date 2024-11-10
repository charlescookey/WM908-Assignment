#include "MenuSystem.h"

int MenuSystem::getIndex() { 
	return index; 
};

MenuSystem::MenuSystem() {
	index = 0;
	pos = positions[index];
	rect = Rect(pos, ButtonWidth, ButtonHeight);
}

void MenuSystem::draw(GamesEngineeringBase::Window& canvas) {
	DrawHelp::drawBorder(canvas, rect, 5, 255, 255, 255);

	if (!buttonPress) {
		stillPressing = false;
	}
}

void MenuSystem::resetRect() {
	pos = positions[index];
	rect = Rect(pos, ButtonWidth, ButtonHeight);
}

void MenuSystem::moveDown() {
	if (index == size - 1)return;

	if (!stillPressing) {
		index++;
		resetRect();
		stillPressing = true;
	}

}

void MenuSystem::moveUp() {
	if (index == 0)return;

	if (!stillPressing) {
		index--;
		resetRect();
		stillPressing = true;
	}
}

