#pragma once
#include <PistonEngine/GLTexture.h>
#include <PistonEngine/ResourceManager.h>
#include <glm/glm.hpp>
#include <PistonEngine/TwistBatch.h>
#include "Colision.h"
#include <PistonEngine/Camera2D.h>
#include "Wall.h"
class Lamp
{
public:
	Lamp();
	~Lamp();
	Colision colision;
	void init();
	void draw(Piston::TwistBatch& twistBatch);
	void update(glm::vec2 pos);
	void revert(Wall wall,int bana);
	void animation(int direction);
	//setter
	void setLife(int life) { _life = life; };
	//getter
	int getLife() { return _life; };
	glm::vec2 getPosition() { return _position; };
	void react(int bana, float cameraSpeed);
	std::string path[3];
	glm::vec2 _position;
	glm::vec2 lastDiff;
private:
	int _life;
	std::string _path;
	
};


