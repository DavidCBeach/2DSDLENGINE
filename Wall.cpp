#include "Wall.h"
#include <PistonEngine/GLTexture.h>
#include <PistonEngine/ResourceManager.h>


Wall::Wall(glm::vec2 pos, glm::vec2 dem, std::string path)
{
	_position = pos;
	_dem = dem;
	_path = path;
	if (dem.x > dem.y)
		type = 1;
	else
		type = 0;
}


Wall::~Wall()
{
}

void Wall::draw(Piston::TwistBatch& twistBatch)
{
	glm::vec4 uv(0.0f, 0.0f, 1.0f, 1.0f);
	static Piston::GLTexture texture = Piston::ResourceManager::getTexture(_path);
	Piston::Color color;
	color.r = 255;
	color.g = 255;
	color.b = 255;
	color.a = 255;

	glm::vec4 posAndSize = glm::vec4(_position.x, _position.y, _dem.x,_dem.y);
	colision.setBox(posAndSize);
	twistBatch.draw(posAndSize, uv, texture.id, 0.0f, color);
}
