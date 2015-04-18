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
	void addSection(string cName, string sName, ClassTime times[]);
private:
	Schedule schedule;
	unordered_map<string, vector<ClassTime>> combos;
	void createSchedule();
	void permutation(unordered_map<string, vector<ClassTime>> selectedSec, vector<Course> unusedCourses);
	bool isAllowed(vector<ClassTime> times);
	bool checkOverlapWithExisting(unordered_map<string, vector<ClassTime>> selectedSec, ClassTime t);
};

