#include "Solid.h"

void Solid::Update() {
	//rotaci�n = rotaci�n_inicial + velocidad_de_rotaci�n * incremento_de_tiempo;
	this->orientation = this->orientation + this->orientationSpeed * 1;

	//posici�n = posici�n_inicial + velocidad * incremento_de_tiempo;
	this->coordinates = this->coordinates + this->speed * 1;
}