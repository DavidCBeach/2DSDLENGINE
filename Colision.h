#pragma once
#include <glm/glm.hpp>
class Colision
{
public:
	Colision();
	~Colision();
	//setter
	void setBox(glm::vec4 posandsize) { _PosAndSize = posandsize; };
	void update(glm::vec2 pos);
	int check(Colision other);
private:
	glm::vec4 _PosAndSize;

};

