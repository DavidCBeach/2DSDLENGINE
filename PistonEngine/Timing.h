#pragma once



namespace Piston
{
	class FpsLimiter {
	public:
		FpsLimiter();
		void begin();
		void setMaxFPS(float maxFPS);
		void init(float maxFPS);
		float end();
	private:
		float _maxFPS;
		float _fps;
		float _frameTime;
		void calculateFPS();
		unsigned int _startTicks;
	};




}