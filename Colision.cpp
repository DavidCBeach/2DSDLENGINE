#include "Colision.h"
#include <iostream>


Colision::Colision(): _PosAndSize(0.0f)
{
}


Colision::~Colision()
{
}
int Colision::check(Colision other)
{

	glm::vec2 actualpos = glm::vec2(_PosAndSize[0] + _PosAndSize[2], _PosAndSize[1] + _PosAndSize[3]);
	glm::vec2 actualposother = glm::vec2(other._PosAndSize[0] + other._PosAndSize[2], other._PosAndSize[1] + other._PosAndSize[3]);
	if (_PosAndSize[0] < actualposother[0] && _PosAndSize[0] > other._PosAndSize[0] && _PosAndSize[1] > other._PosAndSize[1] && _PosAndSize[1] < actualposother[1])
	{
		
		return 1;
	}
	if (_PosAndSize[0] < actualposother[0] && _PosAndSize[0] >other._PosAndSize[0] && actualpos[1]> other._PosAndSize[1] && actualpos[1] < actualposother[1])
	{
		
		return 2;
	}
	else if (actualpos[0] < actualposother[0] && actualpos[0] > other._PosAndSize[0] && _PosAndSize[1] > other._PosAndSize[1] && _PosAndSize[1] < actualposother[1])
	{
		
		return 3;
	}
	else if (actualpos[0] <  actualposother[0] && actualpos[0] > other._PosAndSize[0] && actualpos[1] > other._PosAndSize[1] && actualpos[1] < actualposother[1])
	{
		
		return 4;
	}
	else
	{
		return 0;
	}
}
void Colision::update(glm::vec2 pos)
{
	_PosAndSize[0] += pos[0];
	_PosAndSize[1] += pos[1];
	_PosAndSize[2] += pos[0];
	_PosAndSize[3] += pos[1];

}
