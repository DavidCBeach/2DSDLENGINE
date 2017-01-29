#include "PausedState.h"
#include <SDL/SDL.h>


PausedState::PausedState()
{
}


PausedState::~PausedState()
{
}
bool PausedState::input()
{
	SDL_Event happening;
	while (SDL_PollEvent(&happening))
	{
		switch (happening.type)
		{

		}
	}
	return 0;
}