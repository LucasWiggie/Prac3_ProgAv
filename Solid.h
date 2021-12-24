#pragma once
#include "Vector3D.h"
#include "Color.h"

class Solid
{
private:
	Vector3Df coordinates;
	Color colorCoords;
	Vector3Df orientation;
	Vector3Df orientationSpeed;
	Vector3Df speed;

public:
	Solid() : coordinates(), colorCoords(), orientation(), orientationSpeed(), speed() {}
	Solid(Vector3Df coords, Color color, Vector3Df orient, Vector3Df orientSpeed, Vector3Df newSpeed) : coordinates(coords), colorCoords(color), orientation(orient), orientationSpeed(orientSpeed), speed(newSpeed) {}

	inline Vector3Df getCoordinates() const {
		return this->coordinates;
	}

	inline Color getColor() const {
		return this->colorCoords;
	}

	inline Vector3Df getOrientation() const {
		return this->orientation;
	}

	inline Vector3Df getOrientationSpeed() const {
		return this->orientationSpeed;
	}

	inline Vector3Df getSpeed() const {
		return this->speed;
	}

	inline void setCoordinates(Vector3Df newCoordinates) {
		this->coordinates.setCoordinateX(newCoordinates.getCoordinateX());
		this->coordinates.setCoordinateY(newCoordinates.getCoordinateY());
		this->coordinates.setCoordinateZ(newCoordinates.getCoordinateZ());
	}

	inline void setColor(Color newColor) {
		this->colorCoords.setRedComponent(newColor.getRedComponent());
		this->colorCoords.setGreenComponent(newColor.getGreenComponent());
		this->colorCoords.setBlueComponent(newColor.getBlueComponent());
	}

	inline void setOrientation(Vector3Df newOrientation) {
		this->orientation.setCoordinateX(newOrientation.getCoordinateX());
		this->orientation.setCoordinateY(newOrientation.getCoordinateY());
		this->orientation.setCoordinateZ(newOrientation.getCoordinateZ());
	}

	inline void setOrientationSpeed(Vector3Df newOrientationSpeed) {
		this->orientationSpeed.setCoordinateX(newOrientationSpeed.getCoordinateX());
		this->orientationSpeed.setCoordinateY(newOrientationSpeed.getCoordinateY());
		this->orientationSpeed.setCoordinateZ(newOrientationSpeed.getCoordinateZ());
	}

	inline void setSpeed(Vector3Df newSpeed) {
		this->speed.setCoordinateX(newSpeed.getCoordinateX());
		this->speed.setCoordinateY(newSpeed.getCoordinateY());
		this->speed.setCoordinateZ(newSpeed.getCoordinateZ());
	}

	virtual void Render() = 0;
	virtual void Update(const float& time);
};

