
#pragma once
#include <GL/glew.h>
#include "GLTexture.h"
#include <string>
namespace Piston {

	class Twist
	{
	public:

		Twist();
		~Twist();
		void init(float x, float y, float w, float h, std::string texturePath);
		void draw();
	private:
		float _x;
		float _y;
		float _w;
		float _h;
		GLuint _vboID;//unsigned int guanteed to be 32 bit
		GLTexture _texture;
	};
}

