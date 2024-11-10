#include "Plane.h"


Plane::Plane(int _x, int _y, ImageIndex _imageindex) {
	imageindex = _imageindex;
	x = _x;
	y = _y;
};

Plane::Plane() {
	x = 0;
	y = 0;
};

void Plane::setWidthAndHeight(Vec2 WH) {
	width = WH.x;
	height = WH.y;
}

std::string Plane::SavePlane() {
	std::string result;
	result += "Plane: " + std::to_string(x) + " " + std::to_string(y) + "\n";
	return result;
}


void Plane::update(int _x, int _y) {
	x += _x;
	y += _y;
}


void Plane::update(GamesEngineeringBase::Window& canvas, int _x, int _y) {
	x += _x;
	y += _y;

	x = max(x, 0);
	y = max(y, 0);
	x = min(x, canvas.getWidth() - width);
	y = min(y, canvas.getHeight() - height);
}


bool Plane::collision(Plane& other) {
	int dx = x - other.x;
	int dy = y - other.y;

	float diameter = static_cast<float>((width + other.width) / 2);
	float d = sqrtf((dx * dx) + (dy * dy));
	return d < diameter;
}

bool Plane::collision(int X, int Y, int OtherWidth, int OtherHeight) {
	int Cx = x + (width / 2);
	int Cy = y + (height / 2);

	int OtherCx = X + (OtherWidth / 2);
	int OtherCy = Y + (OtherHeight / 2);

	int dx = Cx - OtherCx;
	int dy = Cy - OtherCy;

	float diameter = static_cast<float>((width + OtherWidth) / 2);
	float d = sqrtf((dx * dx) + (dy * dy));
	return d < diameter;
}

float Plane::distance(Plane& other) {
	int dx = x - other.x;
	int dy = y - other.y;

	return sqrtf((dx * dx) + (dy * dy));
}

float Plane::distance(int X, int Y) {
	int dx = x - X;
	int dy = y - Y;

	return sqrtf((dx * dx) + (dy * dy));
}

