#pragma once
#include "Colision.h"
#include <glm/glm.hpp>
class Field : public Colision
{
public:
	Field();
	~Field();
private:
	glm::vec4 _PosAndSize;
};

