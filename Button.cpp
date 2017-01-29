#include "Button.h"
#include <PistonEngine/ResourceManager.h>
#include <PistonEngine/GLTexture.h>

Button::Button(std::string path)
{
	_PosAndSize = glm::vec4(0.0, 0.0, 200.0, 40.0);
	_path = path;
}


Button::~Button()
{

}
bool Button::check(Piston::InputManager inputManager)
{
	glm::vec2 mouseCoords = inputManager.getMouseCoords();
	if (mouseCoords.x > _PosAndSize.x && mouseCoords.x < (_PosAndSize[2] + _PosAndSize.x) && mouseCoords.y > _PosAndSize.y && mouseCoords.y < (_PosAndSize.y + _PosAndSize[3]))
	{
		return true;
	}
	return 0;
}
void Button::setPos(glm::vec2 pos)
{
	_PosAndSize.x += pos.x;
	_PosAndSize.y += pos.y;
}

void Button::draw(Piston::TwistBatch& twistBatch)
{
	glm::vec4 uv(0.0f, 0.0f, 1.0f, 1.0f);
	static Piston::GLTexture texture = Piston::ResourceManager::getTexture(_path);
	Piston::Color color;
	color.r = 255;
	color.g = 255;
	color.b = 255;
	color.a = 255;

	glm::vec4 posAndSize = glm::vec4(_PosAndSize.x, _PosAndSize.y, _PosAndSize[2], _PosAndSize[3]);
	twistBatch.draw(posAndSize, uv, texture.id, 0.0f, color);
}