#pragma once
#include "Time.h"

class ClassTime
{
public:
	ClassTime();
	ClassTime(char day, string startTime, string endTime);
	char getDay();
	Time getStart();
	Time getEnd();
	bool overlaps(ClassTime t);
	Time duration();
	string durationStr();
	string rangeStr();
private:
	Time start;
	Time end;
	int priority;
	char day;
};

