#include "levelOne.h"

void LevelOne :: init() {

	// CÁMARA
	Vector3D newCameraCoords = Vector3D(0, 0, 7);
	Vector3D newCameraOrientation = Vector3D(0, 0, 0);
	Camera* camera = new Camera(newCameraCoords, Color(0, 0, 0), newCameraOrientation, Vector3D(0, 0, 0), Vector3D(0, 0, 0));

	// LOADER
	ModelLoader* playerLoader = new ModelLoader();
	playerLoader->setScale(0.55);
	ModelLoader* roadLoader = new ModelLoader();
	roadLoader->setScale(5.0);
	ModelLoader* borderLoader = new ModelLoader();
	borderLoader->setScale(5.0);
	
	// CARRETERA
	this->road = new Road();
	roadLoader->loadModel("3D\\straightRoad.obj");
	Model* auxPtr1 = new Model();
	*auxPtr1 = roadLoader->getModel();
	road->setModel(auxPtr1);
	road->getModel().setCoordinates(Vector3D(0.0, 0.0, -2.0));
	road->getModel().setOrientation(Vector3D(90.0, 90.0, 0.0));
	road->getModel().setSpeed(Vector3D(0.0, 0.0, 0.0));
	road->getModel().paintColor(Color(0.0, 0.0, 0.0));

	// ACERAS
	this->leftBorder = new Border();
	borderLoader->loadModel("3D\\sideRoad.obj");
	Model* auxPtr2 = new Model();
	*auxPtr2 = borderLoader->getModel();
	leftBorder->setModel(auxPtr2);
	leftBorder->getModel().setCoordinates(Vector3D(8.8, 0.0, -1.8));
	leftBorder->getModel().setOrientation(Vector3D(90.0, 90.0, 0.0));
	leftBorder->getModel().setSpeed(Vector3D(0.0, 0.0, 0.0));
	leftBorder->getModel().paintColor(Color(0.1, 0.1, 0.1));
	borderLoader->clear();

	this->rightBorder = new Border();
	borderLoader->loadModel("3D\\sideRoad.obj");
	Model* auxPtr3 = new Model();
	*auxPtr3 = borderLoader->getModel();
	rightBorder->setModel(auxPtr3);
	rightBorder->getModel().setCoordinates(Vector3D(-8.8, 0.0, -1.8));
	rightBorder->getModel().setOrientation(Vector3D(90.0, 90.0, 0.0));
	rightBorder->getModel().setSpeed(Vector3D(0.0, 0.0, 0.0));
	rightBorder->getModel().paintColor(Color(0.1, 0.1, 0.1));

	// LÍMITES
	this->boundaries.push_back(-8.8);
	this->boundaries.push_back(8.8);
	this->boundaries.push_back(-10.0);
	this->boundaries.push_back(10.0);

	// PLAYER
	this->player = new Player();
	playerLoader->loadModel("3D\\sportsCar.obj");
	Model* auxPtr4 = new Model();
	*auxPtr4 = playerLoader->getModel();
	player->setModel(auxPtr4);
	player->getModel().setCoordinates(Vector3D(0.0, -2.0, 0.0));
	player->getModel().setOrientation(Vector3D(90.0, 180.0, 0.0));
	player->getModel().setSpeed(Vector3D(0.0, 0.0, 0.0));
	player->getModel().paintColor(Color(0.8, 0.0, 0.3));

	// AÑADIR OBJETOS
	this->addGameObject(camera);
	this->addGameObject(this->leftBorder->getModelPtr());
	this->addGameObject(this->rightBorder->getModelPtr());
	this->addGameObject(this->road->getModelPtr());
	this->addGameObject(this->player->getModelPtr());

}

void LevelOne::processKeyPressed(unsigned char key, int px, int py) {
	cout << "Tecla pulsada: " << key << endl;

	if (key == 'w') {
		this->player->movementForward();
	}
	else if (key == 's') {
		this->player->movementBack();
	}
	else if (key == 'a') {
		this->player->movementLeft();
	}
	else if (key == 'd') {
		this->player->movementRight();
	}
}

void LevelOne::update(const float& time) {
	for (int i = 0; i < getGameObjects().size(); i++) {
		getGameObjects()[i]->Update(time);
		this->checkBoundary();
	}
}

void LevelOne::checkBoundary() {
	if (player->getCoordinates().getCoordinateX() < boundaries[0]) {
		Vector3D newCoords(player->getCoordinates().getCoordinateX() + 1.0, player->getCoordinates().getCoordinateY(), player->getCoordinates().getCoordinateZ());
		player->setCoordinates(newCoords);
	}
	if (player->getCoordinates().getCoordinateX() > boundaries[1]) {
		Vector3D newCoords(player->getCoordinates().getCoordinateX() - 1.0, player->getCoordinates().getCoordinateY(), player->getCoordinates().getCoordinateZ());
		player->setCoordinates(newCoords);
	}
	if (player->getCoordinates().getCoordinateY() < boundaries[2]) {
		Vector3D newCoords(player->getCoordinates().getCoordinateX(), player->getCoordinates().getCoordinateY() + 1.0, player->getCoordinates().getCoordinateZ());
		player->setCoordinates(newCoords);
	}
	if (player->getCoordinates().getCoordinateY() > boundaries[3]) {
		Vector3D newCoords(player->getCoordinates().getCoordinateX(), player->getCoordinates().getCoordinateY() - 1.0, player->getCoordinates().getCoordinateZ());
		player->setCoordinates(newCoords);
	}
}
