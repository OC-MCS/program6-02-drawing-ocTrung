#pragma once
#include <SFML/Graphics.hpp>
#include <string>
using namespace std;
using namespace sf;

// finish this code; add functions, classes, data as needed
struct shapeInfo
{
	int binColor;
	Vector2f binPos;
	ShapeEnum binShape;
};

// DrawingShape should be an abstract base class 
// for Circle and Square
class DrawingShape 
{
private:
	Vector2f pos;
	Color color;
	ShapeEnum shape;
	shapeInfo shapeInformation;

public:
	DrawingShape(Vector2f pos, Color color)
	{
		int colorInt = color.toInteger();
		shapeInformation.binColor = colorInt;
		shapeInformation.binPos = pos;
	}
	virtual void draw(RenderWindow& win) = 0;
	
	//virtual shapeInfo getFileRecord()
	//{
	//}
};

// add Circle, Square classes below. These are derived from DrawingShape
class Circle: public DrawingShape
{
private:
	CircleShape circle;
	
public:
	Circle(Vector2f pos, Color color) :DrawingShape(pos, color)
	{
		circle.setFillColor(color);
		circle.setPosition(pos);
		circle.setRadius(15);
		circle.setOutlineThickness(2);
		circle.setOutlineColor(color);
		circle.setFillColor(color);
	}
	
	void draw(RenderWindow& win)
	{
		win.draw(circle);
	}

	//shapeInfo getFileRecord()
	//{
	//	
	//}

};

class Square : public DrawingShape
{
private:
	RectangleShape square;

public:
	Square(Vector2f pos, Color color): DrawingShape(pos, color)
	{
		square.setPosition(pos);
		square.setOutlineColor(color);
		square.setOutlineThickness(2);
		square.setSize(Vector2f(30, 30));
		square.setFillColor(color);
	}

	void draw(RenderWindow& win)
	{
		win.draw(square);
	}

};


