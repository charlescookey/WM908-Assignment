#include "Pickup.h"


Pickup::Pickup() {
	pickup = Plane(0, 0, ImageIndex::ObjectPickup);
}

Pickup::Pickup(int _type, int X, int Y) {
	type = _type;
	pickup = Plane(X, Y, ImageIndex::ObjectPickup);
}

void Pickup::setImageWidthAndHeight(Vec2 WH) {
	pickup.setWidthAndHeight(WH);
}

std::string Pickup::SaveBullet() {
	std::string result;
	result += "Bullet: " + std::to_string(pickup.x) + " " + std::to_string(pickup.y) + " " + std::to_string(taken) + "\n";
	return result;
}

bool Pickup::inCameraFrame(Camera& cam) {
	if (pickup.x >= cam.WorldX && pickup.x <= cam.WorldX + cam.width) {
		if (pickup.y >= cam.WorldY && pickup.y <= cam.WorldY + cam.height) {
			return true;
		}
	}
	return false;
}

void Pickup::draw(GamesEngineeringBase::Window& canvas, Camera& cam) {
	if (!taken && inCameraFrame(cam))
		cam.drawInCamera(canvas, pickup);
}

