#pragma once
#include "Solid.h"
#include <vector>

using namespace std;
class Triangle : public Solid
{
private:
	
	//Vertices
	Vector3Df vertex0;
	Vector3Df vertex1;
	Vector3Df vertex2;

	//Color de los vertices
	Color vertexColor0;
	Color vertexColor1;
	Color vertexColor2;

	//Normales
	Vector3Df vertexNormal0;
	Vector3Df vertexNormal1;
	Vector3Df vertexNormal2;

public:

	Triangle() : Solid() {}

	Triangle(Vector3Df _vertex0, Vector3Df _vertex1, Vector3Df _vertex2, Vector3Df _vertexNormal0,
		Vector3Df _vertexNormal1, Vector3Df _vertexNormal2) : Solid(), vertex0(_vertex0), vertex1(_vertex1), vertex2(_vertex2),
		vertexNormal0(_vertexNormal0), vertexNormal1(_vertexNormal1), vertexNormal2(_vertexNormal2) {};

	Triangle(Vector3Df _vertex0, Vector3Df _vertex1, Vector3Df _vertex2, Color _vertexColor0, Color _vertexColor1, Color _vertexColor2, Vector3Df _vertexNormal0,
		Vector3Df _vertexNormal1, Vector3Df _vertexNormal2,Vector3Df coords, Color color, Vector3Df orient, Vector3Df orientSpeed, Vector3Df speed) :
		Solid(coords, color, orient, orientSpeed, speed), vertex0(_vertex0), vertex1(_vertex1), vertex2(_vertex2), vertexColor0(_vertexColor0), 
		vertexColor1(_vertexColor1), vertexColor2(_vertexColor2), vertexNormal0(_vertexNormal0), vertexNormal1(_vertexNormal1), vertexNormal2(_vertexNormal2) {};
	

	// GETTERS
	inline Vector3Df getVertex0() const {
		return this->vertex0;
	}

	inline Vector3Df getVertex1() const {
		return this->vertex1;
	}

	inline Vector3Df getVertex2() const {
		return this->vertex2;
	}

	inline Color getVertexColor0() const {
		return this->vertexColor0;
	}

	inline Color getVertexColor1() const {
		return this->vertexColor1;
	}

	inline Color getVertexColor2() const {
		return this->vertexColor2;
	}
	
	inline Vector3Df getVertexNormal0() const {
		return this->vertexNormal0;
	}

	inline Vector3Df getVertexNormal1() const {
		return this->vertexNormal1;
	}

	inline Vector3Df getVertexNormal2() const {
		return this->vertexNormal2;
	}

	// SETTERS
	inline void setVertex0(const Vector3Df& newVertex0) {
		this->vertex0 = newVertex0;
	}

	inline void setVertex1(const Vector3Df& newVertex1) {
		this->vertex1 = newVertex1;
	}

	inline void setVertex2(const Vector3Df& newVertex2) {
		this->vertex2 = newVertex2;
	}

	inline void setVertexColor0(const Color& newColor0) {
		this->vertexColor0 = newColor0;
	}

	inline void setVertexColor1(const Color& newColor1) {
		this->vertexColor1 = newColor1;
	}

	inline void setVertexColor2(const Color& newColor2) {
		this->vertexColor2 = newColor2;
	}
	
	inline void setVertexNormal0(const Vector3Df& newVertexNormal0) {
		this->vertexNormal0 = newVertexNormal0;
	}

	inline void setVertexNormal1(const Vector3Df& newVertexNormal1) {
		this->vertexNormal1 = newVertexNormal1;
	}

	inline void setVertexNormal2(const Vector3Df& newVertexNormal2) {
		this->vertexNormal2 = newVertexNormal2;
	}
	
	void Render();

};

