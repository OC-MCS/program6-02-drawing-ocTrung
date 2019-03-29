#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
#include "ShapeMgr.h"

// finish this code; add functions, data as needed

class DrawingUI
{
private:
	RectangleShape drawArea;

public:
	DrawingUI(Vector2f p)
	{
		Vector2f drawAreaPos(202, 0);
		drawArea.setPosition(drawAreaPos);
		drawArea.setOutlineColor(Color::Transparent);
		drawArea.setOutlineThickness(0);
		drawArea.setSize(Vector2f(600, 600));
		drawArea.setFillColor(Color::Transparent);
	}

	// draws the drawing area and all the shapes
	void draw(RenderWindow& win, ShapeMgr *mgr)
	{
		win.draw(drawArea);

		vector<DrawingShape *> shapes;
		shapes = mgr->getShapes();
	
		for (int i = 0; i < shapes.size(); i++)
		{
			shapes[i]->draw(win);
		}


	}
	
	// checks if the mouse is in the drawing area
	bool isMouseInCanvas(Vector2f mousePos)
	{
		bool mouseInCanvas = false;

	/*	if (mousePos.x > 200)
		{
			mouseInCanvas = true;
		}*/

		if (drawArea.getGlobalBounds().contains(mousePos))
		{
			mouseInCanvas = true;
		}
		return mouseInCanvas;
	}

};

