#pragma once
#include "Day.h"
#include "Time.h"

class ClassTime
{
public:
	ClassTime(Day day, string startTime, string endTime);
private:
	Time start;
	Time end;
	int priority;
	Day day;
};

