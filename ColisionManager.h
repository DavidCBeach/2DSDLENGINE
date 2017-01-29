#pragma once
#include <PistonEngine/Camera2D.h>
#include "Wall.h"
#include "Lamp.h"
#include "Wonlamp.h"
#include "Light.h"
#include <vector>
class ColisionManager
{
public:
	ColisionManager();
	~ColisionManager();
	void lampWonlampColision(Lamp& lamp, std::vector<Wonlamp> wonlamp);
	void wonlampWonlampColision(std::vector<Wonlamp>& wonlamp);
	void lightWonlampColision(std::vector<Light>& light, std::vector<Wonlamp>& wonlamp);
	void wonlampWallColision(std::vector<Wonlamp>& wonlamp, std::vector<Wall> wall);
	void lightWallColision(std::vector<Light>& light, std::vector<Wall> wall);
	void lampWallColision(Lamp& lamp, std::vector<Wall> wall);
	void lampWonlampAttck(Lamp& lamp, std::vector<Wonlamp> wonlamp);
};

