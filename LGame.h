#pragma once
#include <vector>
#include <PistonEngine/Twist.h>
#include <PistonEngine/GLTexture.h>
#include <PistonEngine/GLSLProgram.h>
#include <GL/glew.h>
#include <SDL/SDL.h>
#include <PistonEngine/Window.h>
#include <PistonEngine/InputManager.h>
#include <PistonEngine/TwistBatch.h>
#include <PistonEngine/Timing.h>
#include <PistonEngine/Camera2D.h>
#include "Lamp.h"
#include "Light.h"
#include "CoolDown.h"
#include"Wonlamp.h"
#include "Wall.h"
#include "ColisionManager.h"
#include "Button.h"
enum class GameState { PLAY, EXIT, PAUSE };
class LGame
{
public:
	LGame();
	~LGame();

	void run();

private:
	void bacon();
	int _width;
	int _height;
	float _maxFPS;
	GameState _gameState;
	Piston::Camera2D _camera;
	void initSystem();
	void gameloop();
	void initShaders();
	void input();
	void drawGame();
	float _fps;
	Lamp _Lamp;
	Piston::Window _window;
	Piston::GLSLProgram _colorProgram;
	Piston::FpsLimiter _fpsLimiter;
	Piston::TwistBatch _twistBatch;
	Piston::InputManager _inputManager;
	CoolDown _lightcool;
	CoolDown _autocool;
	std::vector<Light> _light;
	std::vector<Wonlamp> _Wonlamp;
	std::vector<Wall> _wall;
	ColisionManager _cm;
	std::vector<Button> _button;
};

