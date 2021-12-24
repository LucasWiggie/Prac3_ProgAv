#pragma once
#include "Solid.h"

class Camera : public Solid
{
public:
	Camera() : Solid() {}
	Camera(Vector3Df coords, Color color, Vector3Df orientation, Vector3Df orientSpeed, Vector3Df speed) : 
		Solid(coords, color, orientation, orientSpeed, speed) {}

	void Render();
};

