#include "Course.h"
#include "ClassTime.h"

using namespace std;

Course::Course(string courseName, int credits)
{
	this->courseName = courseName;
	this->credits = credits;
}

void Course::addSection(string name, vector<ClassTime> times){
	if (times.size() == 0){
		return;
	}
	sections[name] = times;
}

vector<ClassTime> Course::getSection(string name){
	return sections[name];
}

unordered_map<string, vector<ClassTime>> Course::getSections(){
	return sections;
}

string Course::toString(){
	return courseName;
}