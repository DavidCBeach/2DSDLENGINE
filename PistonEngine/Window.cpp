#include "Window.h"
#include "Errors.h"

namespace Piston {

	Window::Window()
	{
	}


	Window::~Window()
	{
	}

	int Window::create(std::string windowName, int screenWidth, int screenHeight, unsigned int currentFlags)
	{

		Uint32 flags = SDL_WINDOW_OPENGL;

		if (currentFlags & INVISABLE)
		{
			flags |= SDL_WINDOW_HIDDEN;
		}
		if (currentFlags & FULLSCREEN)
			flags |= SDL_WINDOW_FULLSCREEN_DESKTOP;

		if (currentFlags & BORDERLESS)
		{
			flags |= SDL_WINDOW_BORDERLESS;
		}
		//creates window
		_sdlWindow = SDL_CreateWindow(windowName.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, flags);
		if (_sdlWindow == nullptr)
		{
			fatalError("Window could not be created");
		}

		SDL_GLContext glContext = SDL_GL_CreateContext(_sdlWindow);
		if (glContext == nullptr)
		{
			fatalError("SDL_GL context could not be created");
		}

		GLenum error = glewInit();
		if (error != GLEW_OK)
		{
			fatalError("glewInit Error");
		}

		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);//This makes two windows. one to clear and one to draw so that no flickering.
													//check the open gl version
		std::printf("*** OpenGL Version %s ***", glGetString(GL_VERSION));


		glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
		//enables vsync
		SDL_GL_SetSwapInterval(1);
		//enable alpha blending
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);



		return 0;
	}
	void  Window::swapBuffer()
	{
		SDL_GL_SwapWindow(_sdlWindow);
	}
}