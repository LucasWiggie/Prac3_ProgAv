#pragma once
#include "Model.h"

class Player
{
private:
	Model* modelPtr;

public:
	Player() {};

	//Devuelve el contenido del puntero  Models
	inline Model getModel() const{
		return *this->modelPtr;
	}

	//Devuelve el puntero a Models
	inline Model* getModelPtr() {
		return modelPtr;
	}

	inline void setModel(Model newModel) {
		*this->modelPtr = newModel;
	}

	void movementRight();
	void movementLeft();
	void movementForward();
	void movementBack();

};

