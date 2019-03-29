#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Shape.h"

using namespace std;
using namespace sf;

// finish the ShapeMgr class.

class ShapeMgr
{
private:
	vector<DrawingShape *> shapes;

	struct shapeData
	{
		int shape;
		int color;
		int position;
	};
	
public:
	ShapeMgr()
	{
		
	}

	void addShape(Vector2f pos, ShapeEnum whichShape, Color color)
	{
		if (whichShape == CIRCLE)
		{
			shapes.push_back(new Circle(pos, color));
		}
		if (whichShape == SQUARE)
		{
			shapes.push_back(new Square(pos, color));
		}

	}

	vector<DrawingShape*> getShapes()
	{
		return shapes;
	}

	//void readFile(fstream &File)
	//{
	//	

	//}

	//void writeFile(fstream &File)
	//{
	//	for (int i = 0; i < shapes.size(); i++)
	//	{
	//		File.write(reinterpret_cast<char*>(&shapes[i]->getFileRecord), sizeof(shapes[i]));
	//	}

	//}
};
