#include "ClassTime.h"
#include "Time.h"
#include <string>

using namespace std;

ClassTime::ClassTime(Day *day, string startTime, string endTime){

	int sH = stoi(startTime.substr(0, startTime.find(":")));
	int sM = stoi(startTime.substr(startTime.find(":") + 1));

	this->start = new Time(sH + ":" + sM);

	int eH = stoi(endTime.substr(0, endTime.find(":")));
	int eM = stoi(endTime.substr(endTime.find(":") + 1));

	this->end = new Time(eH + ":" + eM);
	this->day = day;
}

Day * ClassTime::getDay(){
	return day;
}

Time * ClassTime::getStart(){
	return start;
}

Time * ClassTime::getEnd(){
	return end;
}

bool ClassTime::overlaps(ClassTime * t){
	if (t->getDay() != this->getDay())
		return false;
	if (t->getStart()->getHourTime() >= start->getHourTime()){
		if (t->getStart()->getHourTime() <= end->getHourTime()){
			return true;
		}
	}
	else if (t->getEnd()->getHourTime() >= start->getHourTime()){
		if (t->getEnd()->getHourTime() <= end->getHourTime()){
			return true;
		}
	}
	return false;
}

Time * ClassTime::duration(){
	int hourDiff = 0, minDiff = 0;
	if (end->hour > start->hour){
		hourDiff = end->hour - start->hour;
		minDiff = end->minute - start->minute;
		if (minDiff < 0){
			hourDiff--;
			minDiff += 60;
		}
	}
}