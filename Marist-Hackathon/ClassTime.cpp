#include "ClassTime.h"
#include "Time.h"
#include <string>
#include <iostream>

using namespace std;

ClassTime::ClassTime(int day, string startTime, string endTime){

	this->start = new Time(startTime);
	this->end = new Time(endTime);
	this->day = day;
}

int ClassTime::getDay(){
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
		return new Time(hourDiff + ":" + minDiff);
	}
	else{
		cout << "End time is before the Start time. FIX" << endl;
		return NULL;
	}
}

string ClassTime::durationStr(){
	return duration()->toString();
}