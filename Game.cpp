#include "Game.h"
#include <iostream>
using namespace std;

void Game::ProcessKeyPressed(unsigned char key, int px, int py) {
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

void Game::ProcessMouseMovement(int x, int y) {
	cout << "Movimiento del mouse: " << x << "," << y << endl;
}

void Game::ProcessMouseClick(int button, int state, int x, int y) {
	cout << "Clic: " << button << endl;
}

void Game::Init() {
	
	// CAMERA
	// Camera(Vector3D coords, Color color, Vector3D orientation, Vector3D orientSpeed) : Solid(coords, color, orientation, orientSpeed)
	Vector3D newCameraCoords = Vector3D(4, 3, 12);
	Vector3D newCameraOrientation = Vector3D(30, 30, 0);

	Camera* camera = new Camera(newCameraCoords, Color(0, 0, 0), newCameraOrientation, Vector3D(0, 0, 0), Vector3D(0, 0, 0));
	
	// LOADER
	ModelLoader* loader = new ModelLoader();
	loader->setScale(0.1);

	// MODELO PRUEBA
	Model* shrek = new Model();
	loader->loadModel("3D\\shrek.obj");
	*shrek = loader->getModel();
	shrek->setCoordinates(Vector3D(1, 1, 1));
	shrek->setOrientation(Vector3D(30, -60, -10));
	shrek->setOrientationSpeed(Vector3D(0.3, 0.2, 0.1));
	shrek->setSpeed(Vector3D(0.001, 0.002, 0.003));
	shrek->paintColor(Color(0.2, 0.5, 0.1));

	loader->clear();
	
	// TEAPOT
	Vector3D newTeapotCoords = Vector3D(0, 0, 2);
	Color newTeapotColor = Color(0, 0.2, 0);
	Vector3D newTeapotOrientation = Vector3D(45, 180, 45);
	Vector3D newTeapotOrientationSpeed = Vector3D(0, 0.5, 0);
	Vector3D newTeapotSpeed = Vector3D(-0.002, 0.001, -0.004);

	Teapot* teapot = new Teapot(newTeapotCoords, newTeapotColor, newTeapotOrientation, newTeapotOrientationSpeed, newTeapotSpeed, 0.6);


	// CUBE
	Vector3D newCubeCoords = Vector3D(2, 3, 2);
	Color newCubeColor = Color(0.8, 0.1, 0);
	Vector3D newCubeOrientation = Vector3D(25, 200, 290);
	Vector3D newCubeOrientationSpeed = Vector3D(0.2, 0, 0.2);
	Vector3D newCubeSpeed = Vector3D(-0.005, 0.001, 0.003);

	Cube* cube = new Cube(newCubeCoords, newCubeColor, newCubeOrientation, newCubeOrientationSpeed, newCubeSpeed, 0.6);


	// SPHERE
	Vector3D newSphereCoords = Vector3D(0, 0.8, 2.3);
	Color newSphereColor = Color(0.5, 0.2, 0.1);
	Vector3D newSphereOrientation = Vector3D();
	Vector3D newSphereOrientationSpeed = Vector3D(0, 0, 0);
	Vector3D newSphereSpeed = Vector3D(0.006, -0.001, 0.003);

	Sphere* sphere = new Sphere(newSphereCoords, newSphereColor, newSphereOrientation, newSphereOrientationSpeed, newSphereSpeed, 0.6, 50, 50);


	// TORUS
	Vector3D newTorusCoords = Vector3D(0.6, 0.2, 2);
	Color newTorusColor = Color(0, 0.1, 0.5);
	Vector3D newTorusOrientation = Vector3D(20, 45, 0);
	Vector3D newTorusOrientationSpeed = Vector3D(0.1, 0.1, 0.3);
	Vector3D newTorusSpeed = Vector3D(-0.002, 0.001, -0.007);

	Torus* torus = new Torus(newTorusCoords, newTorusColor, newTorusOrientation, newTorusOrientationSpeed, newTorusSpeed, 0.2, 0.4, 50, 50);


	// CUBOID
	Vector3D newCuboidCoords = Vector3D(0.9, 0.3, 2);
	Color newCuboidColor = Color(0.3, 0, 0.3);
	Vector3D newCuboidOrientation = Vector3D(120, 0, 30);
	Vector3D newCuboidOrientationSpeed = Vector3D(0.3, 0.1, 0);
	Vector3D newCuboidSpeed = Vector3D(-0.004, 0.004, 0.006);

	Cuboid* cuboid = new Cuboid(newCuboidCoords, newCuboidColor, newCuboidOrientation, newCuboidOrientationSpeed, newCuboidSpeed, 0.6, 0.4, 0.3);


	// CYLINDER
	Vector3D newCylinderCoords = Vector3D(0.9, 0.5, 2);
	Color newCylinderColor = Color(0, 0.5, 0.7);
	Vector3D newCylinderOrientation = Vector3D(120, 0, 30);
	Vector3D newCylinderOrientationSpeed = Vector3D(0, 0.3, 0);
	Vector3D newCylinderSpeed = Vector3D(0.007, -0.002, 0.004);

	Cylinder* cylinder = new Cylinder(newCylinderCoords, newCylinderColor, newCylinderOrientation, newCylinderOrientationSpeed, newCylinderSpeed, 0.4, 0.4, 0.5, 50, 50);

	// TEXT
	Text* text = new Text(Vector3D(0.0, 0.0, 0.0), Color(0.8, 0.0, 0.5), Vector3D(0.0, 0.0, 0.0), Vector3D(0.0, 0.0, 0.0), Vector3D(0.0, 0.0, 0.0), string("texto de prueba"));

	// PLAYER
	Player player1 = Player();
	loader->loadModel("3D\\shrek.obj");
	player1.setModel(loader->getModel());

	player1.getModel().setCoordinates(Vector3D(0.0, 0.0, 0.0));
	player1.getModel().setOrientation(Vector3D(0.0, 0.0, 0.0));
	player1.getModel().setSpeed(Vector3D(0.0, 0.0, 0.0));
	player1.getModel().paintColor(Color(0.8, 0.0, 0.3));

	*this->player = player1;
	
	// SCENES
	Scene* sceneOne = new Scene();
	sceneOne->addGameObject(camera);
	sceneOne->addGameObject(shrek);
	sceneOne->addGameObject(teapot);
	sceneOne->addGameObject(cube);
	sceneOne->addGameObject(sphere);
	sceneOne->addGameObject(torus);
	sceneOne->addGameObject(cuboid);
	sceneOne->addGameObject(cylinder);
	sceneOne->addGameObject(text);

	Scene* sceneTwo = new Scene();
	sceneTwo->addGameObject(camera);
	sceneTwo->addGameObject(this->player->getModelPtr());
	

	//loader->clear();

	// ADD SCENES TO GAME
	this->scenes.push_back(sceneOne);
	this->scenes.push_back(sceneTwo);

	activeScene = sceneTwo;
}

void Game::Render() {
	
	activeScene->Render();

}

void Game::Update() {

	milliseconds currentTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());

	if ((currentTime.count() - this->initialMilliseconds.count()) - this->lastUpdatedTime > UPDATE_PERIOD) {
		this->activeScene->Update(TIME_INCREMENT);
		this->lastUpdatedTime = currentTime.count() - this->initialMilliseconds.count();
	}

}