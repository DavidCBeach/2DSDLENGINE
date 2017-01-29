#pragma once
#include <map>
#include "GLTexture.h"
namespace Piston {

	class TextureCashe
	{
	public:
		TextureCashe();
		~TextureCashe();
		GLTexture getTexture(std::string texturePath);
	private:
		std::map<std::string, GLTexture>_textureMap;
	};
}
