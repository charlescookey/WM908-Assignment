#include "TimeDisplay.h"

#include "NumberDraw.h"


TimeDisplay::TimeDisplay() {
	X = 0;
	Y = 0;
	scale = 2;
}

TimeDisplay::TimeDisplay(int _x, int _y, int _scale) :X(_x), Y(_y), scale(_scale) {
}


void TimeDisplay::update(float dt) {
	_seconds += dt;
	seconds = static_cast<int>(_seconds);
	minutes = seconds / 60;
	seconds %= 60;
}

void TimeDisplay::draw(GamesEngineeringBase::Window& canvas, Camera& cam) {
	int PosX = cam.WorldX + X;
	int PosY = cam.WorldY + Y;


	NumberDraw::drawNumberScaled(2, minutes / 10, canvas, PosX, PosY, 255, 255, 255);
	PosX += scale * NumberDraw::getwidth();
	NumberDraw::drawNumberScaled(2, minutes % 10, canvas, PosX, PosY, 255, 255, 255);
	PosX += scale * NumberDraw::getwidth();
	NumberDraw::drawNumberScaled(2, 10, canvas, PosX, PosY, 255, 255, 255); //colon
	PosX += scale * NumberDraw::getwidth();
	NumberDraw::drawNumberScaled(2, seconds / 10, canvas, PosX, PosY, 255, 255, 255);
	PosX += scale * NumberDraw::getwidth();
	NumberDraw::drawNumberScaled(2, seconds % 10, canvas, PosX, PosY, 255, 255, 255);
}

void TimeDisplay::draw(GamesEngineeringBase::Window& canvas) {
	int PosX = X;
	int PosY = Y;


	NumberDraw::drawNumberScaled(2, minutes / 10, canvas, PosX, PosY, 255, 255, 255);
	PosX += scale * NumberDraw::getwidth();
	NumberDraw::drawNumberScaled(2, minutes % 10, canvas, PosX, PosY, 255, 255, 255);
	PosX += scale * NumberDraw::getwidth();
	NumberDraw::drawNumberScaled(2, 10, canvas, PosX, PosY, 255, 255, 255); //colon
	PosX += scale * NumberDraw::getwidth();
	NumberDraw::drawNumberScaled(2, seconds / 10, canvas, PosX, PosY, 255, 255, 255);
	PosX += scale * NumberDraw::getwidth();
	NumberDraw::drawNumberScaled(2, seconds % 10, canvas, PosX, PosY, 255, 255, 255);
}

