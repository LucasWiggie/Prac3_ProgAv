#include "Scene.h"
#include <iostream>

void Scene::checkBoundary(Solid* obj) {
	if (obj->getCoordinates().getCoordinateX() > boundary.getCoordinateX() || obj->getCoordinates().getCoordinateX() < 0) {
		Vector3Df newSpeed(-1 * obj->getSpeed().getCoordinateX(), obj->getSpeed().getCoordinateY(), obj->getSpeed().getCoordinateZ());
		obj->setSpeed(newSpeed);
	}
	if (obj->getCoordinates().getCoordinateY() > boundary.getCoordinateY() || obj->getCoordinates().getCoordinateY() < 0) {
		Vector3Df newSpeed(obj->getSpeed().getCoordinateX(), -1 * obj->getSpeed().getCoordinateY(), obj->getSpeed().getCoordinateZ());
		obj->setSpeed(newSpeed);
	}
	if (obj->getCoordinates().getCoordinateZ() > boundary.getCoordinateZ() || obj->getCoordinates().getCoordinateZ() < 0) {
		Vector3Df newSpeed(obj->getSpeed().getCoordinateX(), obj->getSpeed().getCoordinateY(),-1 *   obj->getSpeed().getCoordinateZ());
		obj->setSpeed(newSpeed);
	}
}

void Scene::addGameObject(Solid* ptr) {
	
	this->gameObjects.push_back(ptr);

}

void Scene::Render() {
	for (int i = 0; i < this->gameObjects.size(); i++) {
		gameObjects[i]->Render();
	}
}

void Scene::Update(const float& time) {
	for (int i = 0; i < this->gameObjects.size(); i++) {
		gameObjects[i]->Update(time);
		this->checkBoundary(gameObjects[i]);
	}
}