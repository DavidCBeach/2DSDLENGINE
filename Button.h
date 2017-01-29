#pragma once
#include <PistonEngine/TwistBatch.h>
#include <glm/glm.hpp>
#include <PistonEngine/InputManager.h>
#include <string>
class Button
{
public:
	Button(std::string path);
	~Button();
	bool check(Piston::InputManager inputManager);
	void setPos(glm::vec2 pos);
	glm::vec2 getPos() { return glm::vec2(_PosAndSize.x,_PosAndSize.y); };
	void draw(Piston::TwistBatch& twistBatch);
private:
	glm::vec4 _PosAndSize;
	std::string _path;

};

