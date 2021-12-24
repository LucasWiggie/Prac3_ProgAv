#pragma once
#include "Solid.h"
#include "Triangle.h"
#include <vector>

class Model : public Solid
{
private:
	vector <Triangle> triangleList;

public:
	Model() : Solid() {};
	Model(vector <Triangle> _triangleList, 
		Vector3Df coords, Color color, Vector3Df orient, Vector3Df orientSpeed, Vector3Df speed) : 
		Solid(coords, color, orient, orientSpeed, speed), triangleList(_triangleList) {};

	vector<Triangle> getTriangleList() {
		return this->triangleList;
	}

	void setTriangleList(vector <Triangle> newTriangleList) {
		this->triangleList = newTriangleList;
	}

	void addTriangle(Triangle triangle);
	void clear();
	void paintColor(Color color);
	void Render();

};

