#pragma once
#include <vector>
#include "Solid.h"
#include "Teapot.h"
#include "Cube.h"
#include "Sphere.h"
#include "Torus.h"
#include "Cuboid.h"
#include "Cylinder.h"

using namespace std;

class Scene
{ 
private:
	vector<Solid*> gameObjects;
	Vector3Df boundary;

	void checkBoundary(Solid*);

public:

	Scene() : boundary(Vector3Df(8, 6, 4)) {}

	Scene(vector<Solid*> newGameObjects, Vector3Df newBoundary) : gameObjects(newGameObjects), boundary(newBoundary) {};

	inline Vector3Df getBoundary() const {
		return this->boundary;
	}

	inline void setBoundary(const Vector3Df newBoundary) {
		this->boundary = newBoundary;
	}

	void addGameObject(Solid*);
	void Render();
	void Update(const float& time);
};

