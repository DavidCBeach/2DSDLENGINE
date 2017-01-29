#include "InputManager.h"

namespace Piston {

	InputManager::InputManager():_mouseCoords(0.0f)
	{
	}


	InputManager::~InputManager()
	{
	}

	void InputManager::update()
	{
		//for (auto it = _keyMap.begin(); it != _keyMap.end(); it++)
		//same as
		for(auto& it : _keyMap)
		{
			_previouskeyMap[it.first] = it.second;
		}
	}
	void InputManager::pressKey(unsigned int keyID)
	{
		_keyMap[keyID] = true;
	}
	void InputManager::releaseKey(unsigned int keyID)
	{
		_keyMap[keyID] = false;
	}
	bool InputManager::isKeyDown(unsigned int keyID)
	{
		auto it = _keyMap.find(keyID);
		if (it != _keyMap.end())
		{
			return it->second;
		}
		else
		{
			return false;
		}
	}
	void  InputManager::setMouseCoords(float x, float y)
	{
		_mouseCoords.x = x;
		_mouseCoords.y = y;
	}
	bool InputManager::isKeyPressed(unsigned int keyID)
	{
		bool isPressed;
		if (isKeyDown(keyID) == true && waskeyDown(keyID) == false)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool InputManager::waskeyDown(unsigned int keyID)
	{
		auto it = _previouskeyMap.find(keyID);
		if (it != _previouskeyMap.end())
		{
			return it->second;
		}
		else
		{
			return false;
		}
	}
}