#pragma once
#include <vector>
#include "Course.h"
#include "Time.h"
using namespace std;

class Schedule
{
public:
	Schedule();
	Schedule(Time earlyTime, Time lateTime, int totalCredits);
	void addCourse(Course c);
	Course* getCourse(string name);
	vector<Course> getCourses();
	Time earlyTime;
	Time lateTime;
	int totalCredits;
private:
	vector<Course> courses;
};

