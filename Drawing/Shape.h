#pragma once
#include <SFML/Graphics.hpp>
#include <string>
using namespace std;
using namespace sf;

// finish this code; add functions, classes, data as needed

// DrawingShape should be an abstract base class 
// for Circle and Square
class DrawingShape 
{
public:
	void draw()
	{

	}
	
};

// add Circle, Square classes below. These are derived from DrawingShape
class Circle: public DrawingShape
{
private:
	CircleShape circle;
public:
	void draw()
	{

	}
};


