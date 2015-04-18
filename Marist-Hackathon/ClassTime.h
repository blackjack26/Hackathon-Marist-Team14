#pragma once
#include "Time.h"

class ClassTime
{
public:
	ClassTime();
	ClassTime(int day, string startTime, string endTime);
	int getDay();
	Time * getStart();
	Time * getEnd();
	bool overlaps(ClassTime * t);
	Time * duration();
	string durationStr();
private:
	Time *start;
	Time *end;
	int priority;
	int day;
};

