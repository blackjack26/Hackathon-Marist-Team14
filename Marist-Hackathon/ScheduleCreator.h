#pragma once
#include <unordered_map>
#include "Course.h"
#include "Schedule.h"

using namespace std;

class ScheduleCreator
{
public:
	ScheduleCreator();
	void startCreator();
	void addCourse(string name);
	void addSection(string cName, string sName, vector<ClassTime> times);
private:
	Schedule schedule;
	vector<unordered_map<string, vector<ClassTime>>> combos;
	void createSchedule();
	void getInput();
	bool isExtra(unordered_map<string, vector<ClassTime>>, int index);
	void permutation(unordered_map<string, vector<ClassTime>> selectedSec, vector<Course> unusedCourses);
	bool isAllowed(vector<ClassTime> times);
	bool checkOverlapWithExisting(unordered_map<string, vector<ClassTime>> selectedSec, ClassTime t);
	string getDayName(int day);
};

