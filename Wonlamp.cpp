#include "Wonlamp.h"



Wonlamp::Wonlamp(glm::vec2 pos): _change(0.0f), life(5)
{
	_position = pos;
	attackBox.setBox(glm::vec4(pos.x - 30.0, pos.y - 30.0, 110, 110));
}


Wonlamp::~Wonlamp()
{
}

void Wonlamp::automation(Lamp lamp)
{
	static int i = 0;
	if (i == 0)
	{

		switch (int(rand() % 4))
		{
		case 0:
			_change.x = 2;
			break;
		case 1:
			_change.x = -2;
			break;
		case 2:
			_change.y = 2;
			break;
		case 3:
			_change.y = -2;
			break;

		}
		i = 1;
	}
	else if (i == 1)
	{
		glm::vec2 direction = lamp._position - _position;
		direction = glm::normalize(direction);
		
		_change = direction *  2.0f;
		i = 0;
	}


}

bool Wonlamp::update()
{
	_position += _change;
	if (life <= 0)
	{
		return true;
	}
	return false;
}
