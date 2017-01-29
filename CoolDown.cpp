#include "CoolDown.h"



CoolDown::CoolDown()
{
	_ready = true;
	_time = 0.0f;
}


CoolDown::~CoolDown()
{
}

bool CoolDown::check(float timelimit)
{
	if (_time < timelimit)
	{
		return false;
	}	
	else
	{
		_time = 0.0f;
		return true;
	}
}
void CoolDown::timeUpdate()
{
	_time += 1.0f;
}