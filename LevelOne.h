#pragma once
#include "Scene.h"
#include "Camera.h"
#include "ModelLoader.h"
#include "Player.h"
#include "Road.h"
#include "Border.h"
#include <vector>

class LevelOne : public Scene
{
private:
	Player* player;
	Road* road;
	Border* leftBorder;
	Border* rightBorder;
	
	vector<float> boundaries;
	void checkBoundary();

public:
	LevelOne() : player(nullptr), road(nullptr), leftBorder(nullptr), rightBorder(nullptr), Scene() {}

	void init();
	void update(const float& time);
	void processKeyPressed(unsigned char key, int px, int py);
};

