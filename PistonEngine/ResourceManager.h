#pragma once
#include "TextureCashe.h"
#include <string>
namespace Piston {

	class ResourceManager
	{
	public:
		static GLTexture  getTexture(std::string texturePath);

	private:
		static TextureCashe _textureCashe;
	};
}

