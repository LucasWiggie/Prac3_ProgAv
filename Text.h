#pragma once
#include "Solid.h";
#include <string>;
#include <GL/glut.h>;

using namespace std;

class Text : public Solid
{
private:
	string text;

public:
	Text(Vector3Df coords, Color color, Vector3Df orient, Vector3Df orientSpeed, Vector3Df speed, string text) : Solid(coords, color, orient, orientSpeed, speed), text(text) {};

	inline string getText() const {
		return this->text;
	}

	inline void setText(const string& newText) {
		this->text = newText;
	}

	void Render();
};

