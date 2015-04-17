#pragma once
#include <string>

using namespace std;

class Time
{
public:
	Time(string time);
	float getHourTime();
	string toString();
	int minute;
	int hour;
};

