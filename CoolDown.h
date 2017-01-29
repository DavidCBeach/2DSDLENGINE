#pragma once
class CoolDown
{
public:
	CoolDown();
	~CoolDown();
	bool check(float timelimit);
	void timeUpdate();
private:
	bool _ready;
	int _time;
};

