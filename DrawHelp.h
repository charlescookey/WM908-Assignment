#pragma once

#include "Rect.h"
#include "Circle.h"
#include "GamesEngineeringBase.h"

namespace DrawHelp {

	void drawPlainBackground(GamesEngineeringBase::Window& canvas, int R, int G, int  B) {
		for (unsigned int i = 0; i < canvas.getWidth(); i++) {
			for (unsigned int j = 0; j < canvas.getHeight(); j++) {
				canvas.draw(i, j, R, G, B);
			}
		}
	}

	void drawImage(GamesEngineeringBase::Window& canvas, GamesEngineeringBase::Image& image, int startX, int startY) {
		for (unsigned int i = 0; i < image.width; i++) {
			for (unsigned int j = 0; j < image.height; j++) {
				canvas.draw(startX + i, startY + j, image.at(i, j));
			}
		}
	}

	void drawAlphaImage(GamesEngineeringBase::Window& canvas, GamesEngineeringBase::Image& image, int startX, int startY, int alpha) {
		for (unsigned int i = 0; i < image.width; i++) {
			for (unsigned int j = 0; j < image.height; j++) {
				if (image.alphaAt(i, j) > alpha)
					canvas.draw(startX + i, startY + j, image.at(i, j));
			}
		}
	}

	void drawRectangle(GamesEngineeringBase::Window& canvas, Rect rect, int R, int G, int B) {
		int width = static_cast<int>(rect.getWidth());
		int height = static_cast<int>(rect.getHeight());

		for (unsigned int i = 0; i < width; i++) {
			for (unsigned int j = 0; j < height; j++) {
				canvas.draw(rect.start.x + i, rect.start.y + j, R, G, B);
			}
		}
	}

	void drawBorder(GamesEngineeringBase::Window& canvas, Rect rect, int border, int R, int G, int B) {
		int width = static_cast<int>(rect.getWidth());
		int height = static_cast<int>(rect.getHeight());

		float _border = static_cast<float>(border);
		Vec2 start = rect.start + Vec2(_border);

		Rect inside(start, width - (border * 2), height - (border * 2));

		for (unsigned int i = 0; i < width; i++) {
			for (unsigned int j = 0; j < height; j++) {
				if (!inside.inside(rect.start.x + i, rect.start.y + j))
					canvas.draw(rect.start.x + i, rect.start.y + j, R, G, B);
			}
		}
	}


	///ENSURE TO CHECK AREA DRAWN IS INSIDE
	void drawCircle(GamesEngineeringBase::Window& canvas, Circle circle, int R, int G, int B) {

		int width = static_cast<int>(circle.radius * 2);
		int height = static_cast<int>(circle.radius * 2);

		Vec2 start = circle.getStartVec();

		for (unsigned int i = 0; i < width; i++) {
			for (unsigned int j = 0; j < height; j++) {
				if (circle.inside(Vec2(start.x + i, start.y + j)))
					canvas.draw(start.x + i, start.y + j, R, G, B);
			}
		}

	}


}