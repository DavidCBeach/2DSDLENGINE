#include "Light.h"
#include <iostream>
#include <PistonEngine/GLTexture.h>
#include <PistonEngine/ResourceManager.h>
Light::Light(glm::vec2 pos, glm::vec2 dir, float speed, int lifeTime)
{
	_position = pos;
	_direction = dir;
	_speed = speed;
	_lifeTime = lifeTime;
	_first = true;
	_x = 0.0f;
	_y = 0.0f;
}


Light::~Light()
{
}

void Light::init()
{

}
void Light::draw(Piston::TwistBatch& twistBatch)
{
	glm::vec4 uv(0.0f, 0.0f, 1.0f, 1.0f);
	static Piston::GLTexture texture = Piston::ResourceManager::getTexture("Textures/jimmyJump_pack/PNG/blob.png");
	Piston::Color color;
	color.r = 255;
	color.g = 255;
	color.b = 255;
	color.a = 255;
	glm::vec4 posAndSize;
	
		
		posAndSize = glm::vec4( _position.x, _position.y, 30, 30);
		colision.setBox(posAndSize);
	twistBatch.draw(posAndSize, uv, texture.id, 0.0f, color);
	
		
}

bool Light::update()
{
	_position += _direction * _speed;
	_lifeTime--;
	if (_lifeTime <= 0)
	{
		return true;
	}
	return false;
}
void Light::reactWon(Wonlamp& wonlamp)
{
	_lifeTime = -1;
	wonlamp.life--;
}
void Light::reactWall()
{
	_lifeTime = -1;
}
