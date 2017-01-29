#include "TextureCashe.h"
#include "ImageLoader.h"

namespace Piston {

	TextureCashe::TextureCashe()
	{
	}


	TextureCashe::~TextureCashe()
	{
	}

	GLTexture TextureCashe::getTexture(std::string texturePath)
	{
		//auto automatically initializes the type
		auto mit = _textureMap.find(texturePath);

		//check if it not in the map
		if (mit == _textureMap.end())
		{
			//load the tesure
			GLTexture newTexture = ImageLoader::loadPNG(texturePath);


			//inster it into the map
			_textureMap.insert(make_pair(texturePath, newTexture));
			return newTexture;
		}
		return mit->second;//returns the val
	}
}