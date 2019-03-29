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

	// get default settings from binary file if there is one
	void readFile(fstream &File)
	{
		int temp = 0;

		File.read(reinterpret_cast<char*>(&temp), sizeof(temp));
		Color aColor(temp);
		colorSetting = aColor;

		File.read(reinterpret_cast<char*>(&shapeSetting), sizeof(shapeSetting));

	}

	// writes current settings to binary file when user closes the window
	void writeFile(fstream &File)
	{
		int binColor = colorSetting.toInteger();
		File.write(reinterpret_cast<char*>(&binColor), sizeof(binColor));
		File.write(reinterpret_cast<char*>(&shapeSetting), sizeof(shapeSetting));

	}

};
