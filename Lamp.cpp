#include "Lamp.h"



Lamp::Lamp() :_position(0.0f), lastDiff(0.0f), _life(0), _path("Textures/jimmyJump_pack/PNG/ham.png")
{
	
}


Lamp::~Lamp()
{
}
void Lamp::init()
{
	
}
void Lamp::draw(Piston::TwistBatch& twistBatch)
{
	glm::vec4 uv(0.0f, 0.0f, 1.0f, 1.0f);
	static Piston::GLTexture texture = Piston::ResourceManager::getTexture(_path);
	Piston::Color color;
	color.r = 255;
	color.g = 255;
	color.b = 255;
	color.a = 255;

	glm::vec4 posAndSize = glm::vec4(_position.x, _position.y, 50, 50);
	colision.setBox(posAndSize);
	twistBatch.draw(posAndSize, uv, texture.id, 0.0f, color);
}
void Lamp::update(glm::vec2 pos)
{
	lastDiff.x =  -pos.x;
	lastDiff.y = -pos.y;

	_position += pos;
	
	
}
void Lamp::animation(int direction)
{
	static int i = 0;
	if (direction == 1)
	{
		_path = path[i];
	}
	i++;
	if (i > 600)
		i = 0;
}
void Lamp::revert(Wall wall, int bana)
{
	if ((bana == 1 || bana == 2) && wall.type == 0)
		_position.x += 10;
	if ((bana == 3 || bana == 4) && wall.type == 0)
		_position.x -= 10;
	if ((bana == 1 || bana == 3) && wall.type == 1)
		_position.y+= 10;
	if ((bana == 2 || bana == 4) && wall.type == 1)
		_position.y -= 10;
	
}
void Lamp::react(int bana, float cameraSpeed)
{
	if (bana == 1)
	{
		update(glm::vec2((cameraSpeed + 1), (cameraSpeed + 1)));
		
	}
	if (bana == 2)
	{
		update(glm::vec2((cameraSpeed + 1), -(cameraSpeed + 1)));
		
	}
	if (bana == 3)
	{
		update(glm::vec2(-(cameraSpeed + 1), (cameraSpeed + 1)));
		
	}
	if (bana == 4)
	{
		update(glm::vec2(-(cameraSpeed + 1), -(cameraSpeed + 1)));
		
	}
	
}



