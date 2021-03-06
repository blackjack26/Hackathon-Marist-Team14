#include "Time.h"
#include <string>
#include <iostream>

using namespace std;

Time::Time(){

}

Time::Time(string time)
{
	this->hour = stoi(time.substr(0, time.find(":")));
	this->minute = stoi(time.substr(time.find(":") + 1));
}

float Time::getHourTime(){
	return this->hour + this->minute / 60.0;
}

string Time::toString(){
	string min = "" + to_string(this->minute);
	if (this->minute == 0)
		min = "00";

	return to_string(this->hour) + ":" + min;
}