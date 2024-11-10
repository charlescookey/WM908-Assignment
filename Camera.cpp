#include "Camera.h"



#define ScreenSizeX 1024
#define ScreenSizeY 768
#define WorldSizeX 3200
#define WorldSizeY 3200


Camera::Camera(int x, int y, int _width, int _height) {
	WorldX = x;
	WorldY = y;
	width = _width;
	height = _height;

	//can be moved to its own function
	gallery.loadImages("ImageNames.txt");

}

std::string Camera::SaveCamera() {
	std::string result;
	result += "Camera: " + std::to_string(WorldX) + " " + std::to_string(WorldY) + " " + std::to_string(width) + " " + std::to_string(height) + "\n";
	return result;

}
int Camera::speed(int dir, int speed) {
	if (dir == 0)return 0;
	if (dir > 0)return speed;
	return speed * -1;
}
void Camera::update(int x, int y, Character& main) {

	if (x != 0) WorldX += speed(x, main.movespeed);
	if (y != 0) WorldY += speed(y, main.movespeed);


	WorldX = max(WorldX, 0);
	WorldY = max(WorldY, 0);
	WorldX = min(WorldX, WorldSizeX - ScreenSizeX);
	WorldY = min(WorldY, WorldSizeY - ScreenSizeY);
}

void Camera::drawDebugPointInCameraRed(GamesEngineeringBase::Window& canvas, int X, int Y) {
	int todrawX = X - WorldX;
	int todrawY = Y - WorldY;
	canvas.draw(todrawX, todrawY, 255, 0, 0);
}
void Camera::drawDebugPointInCameraBlue(GamesEngineeringBase::Window& canvas, int X, int Y) {
	int todrawX = X - WorldX;
	int todrawY = Y - WorldY;
	canvas.draw(todrawX, todrawY, 0, 0, 255);
}


//Updated with Canvas
void Camera::drawInCamera(GamesEngineeringBase::Window& canvas, Plane& p) {
	int todrawX = p.x - WorldX;
	int todrawY = p.y - WorldY;
	gallery.drawAt(canvas, p.imageindex, 0, todrawX, todrawY);
}

void Camera::drawInCamera(GamesEngineeringBase::Window& canvas, Tile& p) {
	int todrawX = p.x - WorldX;
	int todrawY = p.y - WorldY;
	gallery.drawAt(canvas, p.imageindex, 0, todrawX, todrawY);
}

void Camera::drawInCamera(GamesEngineeringBase::Window& canvas, Plane* p) {
	int todrawX = p->x - WorldX;
	int todrawY = p->y - WorldY;
	gallery.drawAt(canvas, p->imageindex, 0, todrawX, todrawY);
}

void Camera::drawInCamera(GamesEngineeringBase::Window& canvas, Tile* p) {
	int todrawX = p->x - WorldX;
	int todrawY = p->y - WorldY;
	gallery.drawAt(canvas, p->imageindex, 0, todrawX, todrawY);
}



void Camera::drawInCamera(GamesEngineeringBase::Window& canvas, Character& p) {
	int todrawX = p.main.x - WorldX;
	int todrawY = p.main.y - WorldY;
	gallery.drawAt(canvas, p.main.imageindex, p.imageOffset, todrawX, todrawY);

	if (p.right)
		gallery.drawAt(canvas, p.main.imageindex, p.imageOffset, todrawX, todrawY);
	else
		gallery.backDrawAt(canvas, p.main.imageindex, p.imageOffset, todrawX, todrawY);
	p.drawHealth(canvas, todrawX, todrawY - 5);
}


void Camera::drawBackground(GamesEngineeringBase::Window& canvas, World& world) {

	int topScreenX = WorldX;
	int topScreenY = WorldY;

	int startX = WorldX / 32;
	int startY = WorldY / 32;

	//cap at 100 or size 
	int endX = startX + (width / 32) + 1;
	int endY = startY + (height / 32) + 1;

	endX = min(world.rows, endX);
	endY = min(world.cols, endY);

	//make better
	for (int i = startX; i < endX; i++) {//dont hard code
		for (int j = startY; j < endY; j++) {//hardcode
			drawInCamera(canvas, world.at(i, j));
		}
	}
}

bool Camera::inbounds(Plane& plane) {
	if (plane.x < WorldX || plane.x >(WorldX + width)) {
		return false;
	}
	if (plane.y < WorldY || plane.y >(WorldY + height)) {
		return false;
	}
	return true;
}
