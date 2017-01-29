#pragma once
#include <unordered_map>
#include <glm/glm.hpp>
namespace Piston {


	class InputManager
	{
	public:
		InputManager();
		~InputManager();
		void update();
		void pressKey(unsigned int keyID);
		void releaseKey(unsigned int keyID);
		bool isKeyDown(unsigned int keyID);
		bool isKeyPressed(unsigned int keyID);
		void setMouseCoords(float x, float y);

		//get
		glm::vec2 getMouseCoords() const { return _mouseCoords; }

	private:
		bool waskeyDown(unsigned int keyID);
		std::unordered_map<unsigned int, bool> _keyMap;
		std::unordered_map<unsigned int, bool> _previouskeyMap;
		glm::vec2 _mouseCoords;
	};
}
