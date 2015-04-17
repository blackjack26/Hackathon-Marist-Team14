#pragma once
#include "Day.h"
#include "Time.h"

class ClassTime
{
public:
	ClassTime(Day *day, string startTime, string endTime);
	Day * getDay();
	Time * getStart();
	Time * getEnd();
	bool overlaps(ClassTime * t);
	Time * duration();
	string durationStr();
private:
	Time *start;
	Time *end;
	int priority;
	Day *day;
};

