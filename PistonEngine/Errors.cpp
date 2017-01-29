#include "Errors.h"
#include <iostream>
#include <cstdlib>
#include <SDL/SDL.h>
namespace Piston {

	void fatalError(std::string errorString)
	{
		std::cout << errorString << std::endl;
		std::cout << "Enter key..";
		int tmp;
		std::cin >> tmp;
		SDL_Quit();
		exit(69);
	}
}