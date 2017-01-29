#include "ColisionManager.h"
#include <iostream>


ColisionManager::ColisionManager()
{
}


ColisionManager::~ColisionManager()
{
}
void ColisionManager::lampWonlampColision(Lamp & lamp, std::vector<Wonlamp> wonlamp)
{
	for (int i = 0; i < wonlamp.size(); i++)
	{
		int bana = lamp.colision.check(wonlamp[i].colision);
		if (bana != 0)
		{
			lamp.react(bana, 1.0f);
		}
	}
}
void ColisionManager::wonlampWonlampColision(std::vector<Wonlamp>& wonlamp)
{
	for (int i = 0; i < wonlamp.size(); i++)
	{
		for (int ii = 0; ii < wonlamp.size(); ii++)
		{
			int bana = wonlamp[i].colision.check(wonlamp[ii].colision);
			if (bana != 0)
			{
				wonlamp[i].react(bana, 1.0f);
			}
		}
	}
}
void ColisionManager::lightWonlampColision(std::vector<Light>& light, std::vector<Wonlamp>& wonlamp)
{
	for (int i = 0; i < light.size(); i++)
	{
		for (int ii = 0; ii < wonlamp.size(); ii++)
		{
			int bana = light[i].colision.check(wonlamp[ii].colision);
			if (bana != 0)
			{
				light[i].reactWon(wonlamp[ii]);
			}
		}
	}
}
void ColisionManager::wonlampWallColision(std::vector<Wonlamp>& wonlamp, std::vector<Wall> wall)
{
	for (int i = 0; i < wonlamp.size(); i++)
	{
		for (int ii = 0; ii < wall.size(); ii++)
		{
			int bana = wonlamp[i].colision.check(wall[ii].colision);
			if (bana != 0)
			{
				wonlamp[i].revert(wall[ii], bana);
			}
		}
	}
}
void ColisionManager::lightWallColision(std::vector<Light>& light, std::vector<Wall> wall)
{
	for (int i = 0; i < light.size(); i++)
	{
		for (int ii = 0; ii < wall.size(); ii++)
		{
			int bana = light[i].colision.check(wall[ii].colision);
			if (bana != 0)
			{
				light[i].reactWall();
			}
		}
	}
}
void ColisionManager::lampWallColision(Lamp & lamp, std::vector<Wall> wall)
{
	
		for (int ii = 0; ii < wall.size(); ii++)
		{
			int bana = lamp.colision.check(wall[ii].colision);
			if (bana != 0)
			{
				lamp.revert(wall[ii], bana);
			}
		}
	
}
void ColisionManager::lampWonlampAttck(Lamp& lamp, std::vector<Wonlamp> wonlamp)
{
	for (int ii = 0; ii < wonlamp.size(); ii++)
	{
		int bana = lamp.colision.check(wonlamp[ii].attackBox);
		if (bana != 0)
		{
			lamp.setLife(lamp.getLife() - 1);
			std::cout << lamp.getLife() << std::endl;
		}
	}
}
