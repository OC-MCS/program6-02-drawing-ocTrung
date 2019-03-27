#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

enum ShapeEnum { CIRCLE, SQUARE };

// finish this code; add functions, data as needed

class SettingsMgr
{
private:
	Color colorSetting;
	ShapeEnum shapeSetting;

public:
	SettingsMgr(Color startingColor, ShapeEnum startingShape )
	{
		colorSetting = startingColor;
		shapeSetting = startingShape;
	}

	Color getCurColor()
	{
		return colorSetting; 
	}


	ShapeEnum getCurShape()
	{
		return shapeSetting; 
	}

	void setCurColor(Color color)
	{
		colorSetting = color;
	}

	void setCurShape(ShapeEnum shape)
	{
		shapeSetting = shape;
	}

};
