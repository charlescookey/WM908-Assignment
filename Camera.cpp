#include "Camera.h"


Camera::Camera(int x, int y, int _width, int _height) {
	WorldX = x;
	WorldY = y;
	width = _width;
	height = _height;

	//can be moved to its own function
	gallery.loadImages("ImageNames.txt");

}

Camera::Camera(int x, int y, int _width, int _height , int wx , int wy) {
	WorldX = x;
	WorldY = y;
	width = _width;
	height = _height;

	//can be moved to its own function
	gallery.loadImages("ImageNames.txt");

	WorldSizeX = wx * 32;
	WorldSizeY = wy * 32;

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
void Camera::update(int x, int y, Character& main , float dt) {
	int move = static_cast<int>(main.movespeed * dt);
	if (x != 0) WorldX += speed(x, move);
	if (y != 0) WorldY += speed(y, move);


	WorldX = max(WorldX, 0);
	WorldY = max(WorldY, 0);
	WorldX = min(WorldX, WorldSizeX - ScreenSizeX);
	WorldY = min(WorldY, WorldSizeY - ScreenSizeY);
}

void Camera::updateInfinte(int x, int y, Character& main , float dt) {
	int move = static_cast<int>(main.movespeed * dt);
	if (x != 0) WorldX += speed(x, move);
	if (y != 0) WorldY += speed(y, move);

	WorldX = ((WorldX % WorldSizeX) + WorldSizeX) % WorldSizeX;
	WorldY = ((WorldY % WorldSizeY) + WorldSizeY) % WorldSizeY;
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

void Camera::drawInCameraInfinite(GamesEngineeringBase::Window& canvas, Tile& p) {
	int todrawX = p.x - WorldX;
	int todrawY = p.y - WorldY;

	todrawX = ((todrawX % WorldSizeX) + WorldSizeX) % WorldSizeX;
	todrawY = ((todrawY % WorldSizeX) + WorldSizeX) % WorldSizeX;
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

	if (p.right)
		gallery.drawAt(canvas, p.main.imageindex, p.imageOffset, todrawX, todrawY);
	else
		gallery.backDrawAt(canvas, p.main.imageindex, p.imageOffset, todrawX, todrawY);
	p.drawHealth(canvas, todrawX, todrawY - 5);
}


void Camera::drawBackground(GamesEngineeringBase::Window& canvas, World& world) {

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

int Camera::InfiniteX(int x) {
	return ((x % WorldSizeX) + WorldSizeX) % WorldSizeX;
};

int Camera::InfiniteY(int y) {
	return ((y % WorldSizeY) + WorldSizeY) % WorldSizeY;
};

void Camera::drawBackgroundInfinte(GamesEngineeringBase::Window& canvas, World& world) {

	int topScreenX = ((WorldX % WorldSizeX) + WorldSizeX)% WorldSizeX;
	int topScreenY = ((WorldY % WorldSizeY) + WorldSizeY)% WorldSizeY;

	int startX = (topScreenX / 32) ;
	int startY = (topScreenY / 32) ;

	//cap at 100 or size 
	int endX = startX + (width / 32) + 2;
	int endY = startY + (height / 32) + 2;

	//endX = min(world.rows, endX);
	//endY = min(world.cols, endY);
	int tempX = 0;
	int tempY = 0;
	//make better
	for (int i = startX; i < endX; i++) {//dont hard code
		for (int j = startY; j < endY; j++) {//hardcode
			tempX = ((i % world.rows) + world.rows)% world.rows;
			tempY = ((j % world.cols) + world.cols)%world.cols;
			drawInCameraInfinite(canvas, world.at(tempX, tempY));
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
