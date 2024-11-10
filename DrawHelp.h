#pragma once

#include "Rect.h"
#include "Circle.h"
#include "GamesEngineeringBase.h"

namespace DrawHelp {
	/// <summary>
	/// This helps draw a plain background of a specified color
	/// </summary>
	/// <param name="canvas">The canvas to draw to</param>
	/// <param name="R">Red component</param>
	/// <param name="G">Green Component</param>
	/// <param name="B">Blue Component</param>
	void drawPlainBackground(GamesEngineeringBase::Window& canvas, int R, int G, int  B) {
		for (unsigned int i = 0; i < canvas.getWidth(); i++) {
			for (unsigned int j = 0; j < canvas.getHeight(); j++) {
				canvas.draw(i, j, R, G, B);
			}
		}
	}
	/// <summary>
	/// This draws an image to the screen
	/// </summary>
	/// <param name="canvas">The canvas to draw to</param>
	/// <param name="image">The image to draw</param>
	/// <param name="startX">The top left X posistion to start drawin </param>
	/// <param name="startY">The top left X posistion to start drawing</param>
	void drawImage(GamesEngineeringBase::Window& canvas, GamesEngineeringBase::Image& image, int startX, int startY) {
		for (unsigned int i = 0; i < image.width; i++) {
			for (unsigned int j = 0; j < image.height; j++) {
				canvas.draw(startX + i, startY + j, image.at(i, j));
			}
		}
	}
	/// <summary>
	/// This draws an image to the screen ignoring pixels with alpha below a specified value
	/// </summary>
	/// <param name="canvas">The canvas to draw to</param>
	/// <param name="image">The image to draw</param>
	/// <param name="startX">The top left X posistion to start drawin </param>
	/// <param name="alpha">The threshold aplha value</param>
	void drawAlphaImage(GamesEngineeringBase::Window& canvas, GamesEngineeringBase::Image& image, int startX, int startY, int alpha) {
		for (unsigned int i = 0; i < image.width; i++) {
			for (unsigned int j = 0; j < image.height; j++) {
				if (image.alphaAt(i, j) > alpha)
					canvas.draw(startX + i, startY + j, image.at(i, j));
			}
		}
	}
	/// <summary>
	/// This draw a Filled Rectangle to the Screen
	/// </summary>
	/// <param name="canvas">The Canvas to drawe to</param>
	/// <param name="rect">The rcetangle to draw</param>
	/// <param name="R">Red component</param>
	/// <param name="G">Green Component</param>
	/// <param name="B">Blue Component</param>
	void drawRectangle(GamesEngineeringBase::Window& canvas, Rect rect, int R, int G, int B) {
		int width = static_cast<int>(rect.getWidth());
		int height = static_cast<int>(rect.getHeight());

		for (unsigned int i = 0; i < width; i++) {
			for (unsigned int j = 0; j < height; j++) {
				canvas.draw(rect.start.x + i, rect.start.y + j, R, G, B);
			}
		}
	}
	/// <summary>
	/// This draw a Rectangle Border to the Screen
	/// </summary>
	/// <param name="canvas">The Canvas to draw to</param>
	/// <param name="rect">The rcetangle to draw</param>
	/// <param name="border">The width of teh border to draw</param>
	/// <param name="R">Red component</param>
	/// <param name="G">Green Component</param>
	/// <param name="B">Blue Component</param>
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

	/// <summary>
	/// This draw a Filled Circle to the Screen
	/// </summary>
	/// <param name="canvas">The Canvas to draw to</param>
	/// <param name="circle"></param>
	/// <param name="R">Red component</param>
	/// <param name="G">Green Component</param>
	/// <param name="B">Blue Component</param>
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