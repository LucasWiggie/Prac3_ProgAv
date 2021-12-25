#include "levelOne.h"

void LevelOne :: init() {

	// CÁMARA
	Vector3D newCameraCoords = Vector3D(0, 0, 7);
	Vector3D newCameraOrientation = Vector3D(0, 0, 0);
	Camera* camera = new Camera(newCameraCoords, Color(0, 0, 0), newCameraOrientation, Vector3D(0, 0, 0), Vector3D(0, 0, 0));

	// LOADER
	ModelLoader* loader = new ModelLoader();
	loader->setScale(0.8);

	// PLAYER
	this->player = new Player();
	loader->loadModel("3D\\sportsCar.obj");
	Model* pm = new Model();
	*pm = loader->getModel();
	player->setModel(pm);
	player->getModel().setCoordinates(Vector3D(0.0, 0.0, 0.0));
	player->getModel().setOrientation(Vector3D(90.0, 180.0, 0.0));
	player->getModel().setSpeed(Vector3D(0.0, 0.0, 0.0));
	player->getModel().paintColor(Color(0.8, 0.0, 0.3));

	this->addGameObject(camera);
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
