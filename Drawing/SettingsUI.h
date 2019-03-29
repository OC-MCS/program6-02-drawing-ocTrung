#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
#include "SettingsMgr.h"

// finish this code; add functions, data as needed
void die(string msg);

class SettingsUI
{
private:
	SettingsMgr *settingsMgr;
	CircleShape blueBtn;
	CircleShape redBtn;
	CircleShape greenBtn;
	CircleShape circleBtn;
	RectangleShape squareBtn;

public:
	SettingsUI(SettingsMgr *mgr)
	{
		settingsMgr = mgr;

	}

	// checks for mouse position over buttons and changes color selection in settings manager
	void handleMouseUp(Vector2f mouse)
	{
		if (blueBtn.getGlobalBounds().contains(mouse))
		{
			cout << "blue button pressed" << endl;
			settingsMgr->setCurColor(Color::Blue);
		}
		else if (redBtn.getGlobalBounds().contains(mouse))
		{
			cout << "red button pressed" << endl;
			settingsMgr->setCurColor(Color::Red);
		}
		else if (greenBtn.getGlobalBounds().contains(mouse))
		{
			cout << "green button pressed" << endl;
			settingsMgr->setCurColor(Color::Green);
		}

		if (squareBtn.getGlobalBounds().contains(mouse))
		{
			cout << "square button pressed" << endl;
			settingsMgr->setCurShape(SQUARE);
		}
		else if (circleBtn.getGlobalBounds().contains(mouse))
		{
			cout << "circle button pressed" << endl;
			settingsMgr->setCurShape(CIRCLE);
		}
	}

	// draws the titles, buttons, and border in the settings window
	void draw(RenderWindow& win)
	{
		// selected color title
		Font font;
		if (!font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf"))
			die("couldn't load font");

		Text colorTitle("Selected Color", font, 20);
		colorTitle.setPosition(30, 25);
		win.draw(colorTitle);

		// selected shape title
		Text shapeTitle("Selected Shape", font, 20);
		shapeTitle.setPosition(30, 300);
		win.draw(shapeTitle);

		RectangleShape settingsBorder;
		Vector2f borderPos(0, 0);
		settingsBorder.setPosition(borderPos);
		settingsBorder.setOutlineColor(Color::White);
		settingsBorder.setOutlineThickness(2);
		settingsBorder.setSize(Vector2f(200, 600));
		settingsBorder.setFillColor(Color::Transparent);
		win.draw(settingsBorder);

		// Blue circle button 
		Vector2f bluePos(70, 70);
		blueBtn.setPosition(bluePos);
		blueBtn.setRadius(15);
		blueBtn.setOutlineThickness(2);
		blueBtn.setOutlineColor(Color::Blue);
		blueBtn.setFillColor(Color::Transparent);

		// Red circle button
		Vector2f redPos(70, 120);
		redBtn.setPosition(redPos);
		redBtn.setRadius(15);
		redBtn.setOutlineThickness(2);
		redBtn.setOutlineColor(Color::Red);
		redBtn.setFillColor(Color::Transparent);

		// Green circle button
		Vector2f greenPos(70, 170);
		greenBtn.setPosition(greenPos);
		greenBtn.setRadius(15);
		greenBtn.setOutlineThickness(2);
		greenBtn.setOutlineColor(Color::Green);
		greenBtn.setFillColor(Color::Transparent);

		if (settingsMgr->getCurColor() == Color::Blue)
		{
			blueBtn.setFillColor(Color::Blue);
		}
		else if (settingsMgr->getCurColor() == Color::Red)
		{
			redBtn.setFillColor(Color::Red);
		}
		else if (settingsMgr->getCurColor() == Color::Green)
		{
			greenBtn.setFillColor(Color::Green);
		}

		win.draw(blueBtn);
		win.draw(redBtn);
		win.draw(greenBtn);

		// square button
		int size = 30;
		Vector2f sqPos(70, 350);
		squareBtn.setPosition(sqPos);
		squareBtn.setOutlineColor(Color::White);
		squareBtn.setOutlineThickness(2);
		squareBtn.setSize(Vector2f(size, size));
		squareBtn.setFillColor(Color::Transparent);

		// circle button
		Vector2f circlePos(70, 400);
		circleBtn.setPosition(circlePos);
		circleBtn.setRadius(15);
		circleBtn.setOutlineThickness(2);
		circleBtn.setOutlineColor(Color::White);
		circleBtn.setFillColor(Color::Transparent);
		
		if (settingsMgr->getCurShape() == CIRCLE)
		{
			circleBtn.setFillColor(Color::White);
		}
		else if (settingsMgr->getCurShape() == SQUARE)
		{
			squareBtn.setFillColor(Color::White);
		}
		
		win.draw(squareBtn);
		win.draw(circleBtn);

	}


};

void die(string msg)
{
	cout << msg << endl;
	exit(-1);
}
