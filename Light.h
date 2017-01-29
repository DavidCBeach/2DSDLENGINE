#pragma once
#include <glm/glm.hpp>
#include <PistonEngine/TwistBatch.h>
#include "Lamp.h"
#include "Colision.h"
#include "Wonlamp.h"
class Light
{
public:
	Light(glm::vec2 pos, glm::vec2 dir, float speed, int lifeTime);
	~Light();
	void init();
	void draw(Piston::TwistBatch& twistBatch);
	//returns true when out of life
	bool update();
	Colision colision;
	void reactWon(Wonlamp& wonlamp);
	void reactWall();
private:
	
	int _lifeTime;
	float _speed;
	glm::vec2 _direction;
	glm::vec2 _position;
	bool _first;
	float _x;
	float _y;
};


