#pragma once
#include "Lamp.h"
#include <time.h>

class Wonlamp : public Lamp
{
public:
	Wonlamp(glm::vec2 pos);
	~Wonlamp();
	Colision attackBox;
	void automation(Lamp lamp);
	int life;
	bool update();
private:
	//glm::vec2 _position;
	glm::vec2 _change;
};

