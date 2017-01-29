#include "LGame.h"

#include <PistonEngine/Errors.h>
#include <iostream>
#include <string>
#include <PistonEngine/Piston.h>
#include <PistonEngine/ResourceManager.h>
#include <PistonEngine/GLTexture.h>
void LGame::bacon()
{
	
}
LGame::LGame()
{
	_width = 786;
	_height = 786;
	_gameState = GameState::PLAY;
	_maxFPS = 60.0f;
	_camera.init(_width, _height);
}


LGame::~LGame()
{
}

void LGame::run()
{
	initSystem();
	gameloop();
}
void LGame::initSystem()
{
	Piston::init();
	_window.create("Lamsp0", _width, _height, 0);
	_fpsLimiter.init(_maxFPS);
	initShaders();
	_twistBatch.init();
	_Lamp.setLife(500);
	for (int i = 0; i < 10; i++)
		_Wonlamp.emplace_back(glm::vec2(i*20,i*20));
	
	_wall.emplace_back(glm::vec2(-250, -250), glm::vec2(50, 500), "Textures/jimmyJump_pack/PNG/Background.png");
	_wall.emplace_back(glm::vec2(250, -250), glm::vec2(50, 550), "Textures/jimmyJump_pack/PNG/Background.png");
	_wall.emplace_back(glm::vec2(-200, -250), glm::vec2(500, 50), "Textures/jimmyJump_pack/PNG/Background.png");
	_wall.emplace_back(glm::vec2(-250, 250), glm::vec2(500, 50), "Textures/jimmyJump_pack/PNG/Background.png");
	_button.emplace_back("Textures/jimmyJump_pack/PNG/Background.png");
	_button[0].setPos(glm::vec2(300, -300));
}
void LGame::gameloop()
{
	while (_gameState != GameState::EXIT)
	{
		
		_fpsLimiter.begin();
		input();
		_camera.update();
		_fps = _fpsLimiter.end();
		//killing 
		for (int i = 0; i < _light.size(); )
		{
			if (_light[i].update() == true)
			{
				_light[i] = _light.back();
				_light.pop_back();
			}
			else
			{
				i++;
			}
		}
		for (int i = 0; i < _Wonlamp.size(); )
		{
			if (_Wonlamp[i].update() == true)
			{
				_Wonlamp[i] = _Wonlamp.back();
				_Wonlamp.pop_back();
			}
			else
			{
				i++;
			}
		}
		if (_Lamp.getLife() <= 0)
		{
			
		}
		//timer updates
		_lightcool.timeUpdate();
		_autocool.timeUpdate();

		//colisions
		_cm.lampWallColision(_Lamp, _wall);
		_cm.wonlampWonlampColision(_Wonlamp);
		_cm.lightWonlampColision(_light, _Wonlamp);
		_cm.wonlampWallColision(_Wonlamp, _wall);
		_cm.lightWallColision(_light, _wall);
		_cm.lampWonlampColision(_Lamp, _Wonlamp);
		_cm.lampWonlampAttck(_Lamp, _Wonlamp);
		if (_autocool.check(10.0f))
		for (int i = 0; i < _Wonlamp.size(); i++)
		{
			_Wonlamp[i].automation(_Lamp);
		}
		
		drawGame();
		
	}
}
void LGame::initShaders()
{
	_colorProgram.compileShaders("Shaders/colorShading.vert", "Shaders/colorShading.frag");
	_colorProgram.addAttribute("vertexPosition");
	_colorProgram.addAttribute("vertexColor");
	_colorProgram.addAttribute("vertexUV");
	_colorProgram.linkShaders();
}
void LGame::input()
{
	SDL_Event happening;
	const float CAMERA_SPEED = 10.0f;
	const float SCALE_SPEED = 0.1f;
	const float COOL_DOWN = 10.0f;
	while (SDL_PollEvent(&happening))
	{
		switch (happening.type)
		{
		case SDL_QUIT:
			_gameState = GameState::EXIT;
			break;
		case SDL_MOUSEMOTION:
			_inputManager.setMouseCoords(happening.motion.x, happening.motion.y);
			break;;
		case SDL_KEYDOWN:
			_inputManager.pressKey(happening.key.keysym.sym);

			break;
		case SDL_KEYUP:
			_inputManager.releaseKey(happening.key.keysym.sym);
			break;
		case SDL_MOUSEBUTTONDOWN:
			_inputManager.pressKey(happening.button.button);
			break;
		case SDL_MOUSEBUTTONUP:
			_inputManager.releaseKey(happening.button.button);
			break;

		}
	}
	if (_inputManager.isKeyDown(SDLK_n)) {
		
			_Wonlamp.emplace_back(glm::vec2(1 * 20, 1 * 20));
		
	}
	if (_inputManager.isKeyDown(SDLK_w)) {
		_Lamp.animation(0);
		_Lamp.update(glm::vec2(0.0, CAMERA_SPEED));
	}
	if (_inputManager.isKeyDown(SDLK_a)) {
		
		_Lamp.update(glm::vec2(-CAMERA_SPEED, 0.0));
	}
	if (_inputManager.isKeyDown(SDLK_s)) {
		
		_Lamp.update(glm::vec2(0.0, -CAMERA_SPEED));
	}
	if (_inputManager.isKeyDown(SDLK_d)) {
		
		_Lamp.update(glm::vec2(CAMERA_SPEED, 0.0));
	}
	if (_inputManager.isKeyDown(SDLK_q)) {
		_camera.setScale(_camera.getScale() + SCALE_SPEED);
	}
	if (_inputManager.isKeyDown(SDLK_e)) {
		_camera.setScale(_camera.getScale() - SCALE_SPEED);
	}
	if (_inputManager.isKeyDown(SDL_BUTTON_LEFT)) {
		glm::vec2 mouseCoords = _inputManager.getMouseCoords();
		_camera.convertScreenToWorld(mouseCoords);

		
		glm::vec2 direction = mouseCoords - _Lamp.getPosition();
		direction = glm::normalize(direction);
		direction.y = -direction.y;
		if(_lightcool.check(COOL_DOWN))
		_light.emplace_back(_Lamp.getPosition(), direction, 10.0f, 1000);
		//std::cout << mouseCoords.x << " " << mouseCoords.y << std::endl;
	}
	_camera.setPosition(_Lamp.getPosition());
	_button[0].setPos(_camera.getPosition());
}

void LGame::drawGame()
{

	glClearDepth(1.0);
	//watchout for that bitwise or
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	_colorProgram.use();
	glActiveTexture(GL_TEXTURE0);
	//glBindTexture(GL_TEXTURE_2D, _playerTexture.id);
	GLint textureLocation = _colorProgram.getUniformLocation("mySampler");
	glUniform1i(textureLocation, 0);
	//GLuint timeLocation = _colorProgram.getUniformLocation("time");
	//glUniform1f(timeLocation, _time);
	//set the camera matrix
	GLuint pLocation = _colorProgram.getUniformLocation("P");
	glm::mat4 cameraMatrix = _camera.getCameraMatrix();
	glUniformMatrix4fv(pLocation, 1, GL_FALSE, &(cameraMatrix[0][0]));

	_twistBatch.begin();
	glm::vec4 pos2(-2500.0f, -2500.0f, 5000.0f, 5000.0f);
	glm::vec4 uv(0.0f, 0.0f, 1.0f, 1.0f);

	static Piston::GLTexture texture = Piston::ResourceManager::getTexture("Textures/jimmyJump_pack/PNG/Banada.png");
	Piston::Color color;
	color.r = 255;
	color.g = 255;
	color.b = 255;
	color.a = 255;
	
	_twistBatch.draw(pos2, uv, texture.id, 0.0f, color);
	
	for (int i = 0; i < _Wonlamp.size(); i++)
	{
		_Wonlamp[i].draw(_twistBatch);
	}
	_Lamp.draw(_twistBatch);
	
	for (int i = 0; i < _light.size(); i++)
	{
		_light[i].draw(_twistBatch);
	}
	for (int i = 0; i < _wall.size(); i++)
	{
		_wall[i].draw(_twistBatch);
	}
	_button[0].draw(_twistBatch);
	_twistBatch.end();
	_twistBatch.renderBatch();
	_colorProgram.unuse();

	_window.swapBuffer();
}
