#pragma once
#include "Scene.h"
#include "Camera.h"
#include "ModelLoader.h"
#include "Player.h"

class LevelOne : public Scene
{
private:
	Player* player;

public:
	LevelOne() : player(nullptr), Scene() {}

	void init();
	void processKeyPressed(unsigned char key, int px, int py);
};

