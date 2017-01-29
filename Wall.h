#pragma once
#include <glm/glm.hpp>
#include "Colision.h"
#include <PistonEngine/TwistBatch.h>
#include <string>
class Wall
{
public:
	Wall(glm::vec2 pos, glm::vec2 dem, std::string path);
	~Wall();
	Colision colision;
	//getter
	glm::vec2 getPosition() { return _position; }
	glm::vec2 getUV() { return _dem; }
	int type;
	void draw(Piston::TwistBatch& twistBatch);
	
private:
	glm::vec2 _position;
	glm::vec2 _dem;
	std::string _path;

};

